#include "im_seg_win.h"
#include "ui_im_seg_win.h"

im_seg_win::im_seg_win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::im_seg_win)
{
    ui->setupUi(this);
}

im_seg_win::~im_seg_win()
{
    delete ui;
}
