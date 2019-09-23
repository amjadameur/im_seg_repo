#ifndef IM_SEG_WIN_H
#define IM_SEG_WIN_H

#include <QMainWindow>

namespace Ui {
class im_seg_win;
}

class im_seg_win : public QMainWindow
{
    Q_OBJECT

public:
    explicit im_seg_win(QWidget *parent = 0);
    ~im_seg_win();

private:
    Ui::im_seg_win *ui;
};

#endif // IM_SEG_WIN_H
