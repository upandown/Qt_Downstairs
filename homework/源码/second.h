#ifndef SECOND_H
#define SECOND_H

#include <QDialog>
#include "form.h"
#include <QPixmap>

extern int BGMvolume;
extern int Gamevolume;
extern int closenum;
extern int whichplayer;
extern int gamespade;

extern QString name;
namespace Ui {
class Second;
}

class Second : public QDialog
{
    Q_OBJECT

public:
    explicit Second(QWidget *parent = 0);
    ~Second();
Form *game;
 void paintEvent(QPaintEvent *event);
 void closeEvent(QCloseEvent *event);
 virtual void timerEvent(QTimerEvent*event);
private:
    Ui::Second *ui;

    QPixmap Backgpic;

    QPixmap player;
    QPixmap player2;
    QPixmap player3;
    QPixmap player4;
    QPixmap player5;

private slots:
    void OnletsStart();

    void setBGMvolume();
    void recoverBGM();

    void setGamevolume();
    void recoverGame();

    void setGameclass();
    void reGameclass();

    void choiceplayer1();
    void choiceplayer2();
    void choiceplayer3();
    void choiceplayer4();
    void choiceplayer5();

    void Usernamew();
    void Userclear();
};

#endif // SECOND_H
