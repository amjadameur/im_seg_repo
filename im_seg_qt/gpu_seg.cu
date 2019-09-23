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
}

