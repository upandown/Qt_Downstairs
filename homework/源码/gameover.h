#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QPixmap>
namespace Ui {
class Gameover;
}

class Gameover : public QDialog
{
    Q_OBJECT

public:
    explicit Gameover(QWidget *parent = 0);
    ~Gameover();

    void paintEvent(QPaintEvent *event);
     virtual void timerEvent(QTimerEvent*event);
private:
    Ui::Gameover *ui;

    QPixmap GameOverpic;
    QPixmap back;


    QPixmap clound1;
    QPixmap clound2;
    QPixmap clound3;
    void closeEvent(QCloseEvent *event);
private slots:
    void reBegin();
    void closegame();
};

#endif // GAMEOVER_H
