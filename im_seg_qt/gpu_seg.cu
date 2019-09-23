#include <iostream>
#include <chrono>

#include "seg_macros.h"

#include <cuda.h>
#include <cuda_runtime.h>

typedef unsigned char uchar;
typedef unsigned int QRgb;

__global__ void seg_kernel(uchar *dev_gray_im, uchar *dev_green_im, int n_pixels) {

}

// Recupere la composante verte de l'image rgb, ceci permettra de ne pas
// sur-consommer la memoire du gpu
void get_green(uchar *green_im, QRgb *rgb_im, int width, int height) {

}

extern "C"
void gpu_im_seg(uchar *gray_im, QRgb *rgb_im, int width, int height) {
    uchar *green_im; // pointeur memoire cpu, pointera sur la composante verte de l'image rgb
    uchar *dev_gray_im, *dev_green_im; // pointeur memoire gpu
    int n_pixels = width*height;
    int size = n_pixels*sizeof(uchar);

    green_im = (uchar*) malloc(size);
    get_green(green_im, rgb_im, width, height);

    // Allocation memoire GPU
    cudaMalloc((void**) &dev_green_im, size);
    cudaMalloc((void**) &dev_gray_im, size);

    cudaMemcpy(dev_green_im, green_im, size, cudaMemcpyHostToDevice);

    // Recuperation des caractéristiques du gpu (nombre de threads par bloc)
    cudaDeviceProp deviceProp;
    cudaGetDeviceProperties(&deviceProp, 0);
    int blockSize = deviceProp.maxThreadsPerBlock;
    int numBlocks = (n_pixels - 1) / blockSize + 1;

    // Appel du kernel cuda pour realiser la segmentation
    seg_kernel<<<numBlocks, blockSize>>>(dev_gray_im, dev_green_im, n_pixels);
    cudaDeviceSynchronize();

    // Recuperation de l'image segmentee
    cudaMemcpy(gray_im, dev_gray_im, size, cudaMemcpyDeviceToHost);

    // Desallocation memoire
    free(green_im);
    cudaFree(dev_gray_im); cudaFree(dev_green_im);
}

