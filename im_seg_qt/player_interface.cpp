#include "player_interface.h"

Player_interface::Player_interface()
{

}

Player_interface::~Player_interface()
{

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

}

void Player_interface::gpu_seg() {

}

void Player_interface::save_im_out(const QString file_name) {

}
