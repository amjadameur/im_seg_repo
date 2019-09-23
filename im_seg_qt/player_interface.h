#ifndef PLAYER_INTERFACE_H
#define PLAYER_INTERFACE_H

#include "seg_macros.h"

#include <QFileDialog>
#include <QWidget>
#include <QColor>
#include <QImageReader>

#include <iostream>
using namespace std;

extern "C"
void gpu_im_seg(uchar *gray_im, QRgb *rgb_im, int width, int height);


class Player_interface : public QWidget
{
    Q_OBJECT
    int width;
    int height;
    QImage rgb_im;
    QImage gray_im;
    QRgb *rgb_ptr;
    uchar *gray_ptr;

public:
    Player_interface();
    ~Player_interface();

    void openFile(QString* name);
    void cpu_seg();
    void gpu_seg();
    void save_im_out(const QString file_name);
};

#endif // PLAYER_INTERFACE_H
