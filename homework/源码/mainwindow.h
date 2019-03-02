#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <form.h>
#include <second.h>
#include <QPixmap>
#include <QMediaPlayer>
#include <QSound>
#include <QMediaPlaylist>
#include <list.h>
extern int mainclose;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     void paintEvent(QPaintEvent *event);
      virtual void timerEvent(QTimerEvent*event);

     QMediaPlayer* player;
     QMediaPlaylist *playlist;
     int pBGMvolume;
private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent  *event);

    QPixmap background;
    QPixmap Backgpic;

    QPixmap clound1;
    QPixmap clound2;
    QPixmap clound3;


    void closeEvent(QCloseEvent *event);

    int wintimer;
    int wintimes;
    int title;
    List *b;

  // QSound *player;
private slots:
    void OnGamestart();

    void Onlist();   //进入排行榜的槽函数

};

#endif // MAINWINDOW_H
