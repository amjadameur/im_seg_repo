#include "im_seg_win.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    im_seg_win w;
    w.show();

    return a.exec();
}
