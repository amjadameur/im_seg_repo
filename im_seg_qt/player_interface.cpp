#include "player_interface.h"

Player_interface::Player_interface() {
    rgb_ptr  = NULL;
    gray_ptr = NULL;
}

Player_interface::~Player_interface() {
    if (gray_ptr != NULL)
        free(gray_ptr);
}

void Player_interface::openFile(QString* name) {
    QString file_name;
    if(name == NULL)
        file_name = QFileDialog::getOpenFileName(this,
            tr("image rgb"), "",
            tr("fichiers images (*.jpg *.png *.gif);;All Files (*)"));
    else
        file_name = *name;

    if(file_name.isEmpty()) exit(0);

    // Lecture de l'image rgb
    QImageReader reader(file_name);
    reader.setAutoTransform(true);
    rgb_im = reader.read();

    width  = rgb_im.width();
    height = rgb_im.height();
}

void Player_interface::cpu_seg() {
    // Recuperation des pointeurs de l'image d'entree et de sortie
    int n_pixels = width*height;
    rgb_ptr = (QRgb*) rgb_im.bits();
    gray_ptr = (uchar*) malloc(width*height*sizeof(uchar));

    QRgb rgb_comp;
    uchar gray_comp;
   for(int i=0; i<n_pixels; i++) {
       rgb_comp = (QRgb) rgb_ptr[i];;
       gray_comp = (GET_GREEN(rgb_comp) > GREEN_TRESH) ? WHITE : BLACK;
       gray_ptr[i] = gray_comp;
   }
   // Creation de l'image binarise
   gray_im = QImage(gray_ptr, width, height, width, QImage::Format::Format_Grayscale8);
}

void Player_interface::gpu_seg() {
    // Recuperation des pointeurs de l'image d'entree et de sortie
    rgb_ptr = (QRgb*) rgb_im.bits();
    gray_ptr = (uchar*) malloc(width*height*sizeof(uchar));

    // Lancement de la segmentation
    gpu_im_seg(gray_ptr, rgb_ptr, width, height);

    // Creation de l'image binarise
    gray_im = QImage(gray_ptr, width, height, width, QImage::Format::Format_Grayscale8);
}

void Player_interface::save_im_out(const QString file_name) {
    gray_im.save("../" + file_name);
}
