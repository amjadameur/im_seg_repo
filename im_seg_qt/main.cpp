#include "im_seg_win.h"
#include "player_interface.h"
#include <QApplication>

#include <QString>
#include <QImage>

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    im_seg_win w;
    w.show();

    Player_interface player;
    QElapsedTimer timer;
    QString *name;

    name = NULL;
    if(argc == 2) {
     //   name = new QString(argv [1]);
        cout << "int main :: parametre trouve (" << argv[1] << ")" << endl;
    }
    cout << "int main :: ouveture de l'image rgb à segmenter"<< endl;
    player.openFile(name);

    cout << "int main :: segmentation avec un GPU nvidia"<< endl;
    timer.start();
    player.gpu_seg();
    cout << "int main :: la segmentation de l'image a duré : " << timer.elapsed() << " ms"<< endl;

    cout << "int main :: enregistrement de l'image binarisee"<< endl;
    player.save_im_out("binarisee.jpg");

    return a.exec();
}
