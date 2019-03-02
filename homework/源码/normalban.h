#ifndef NORMALBAN_H
#define NORMALBAN_H

#include <QWidget>
#include <QPixmap>
#include <QCloseEvent>
#include <QMediaPlayer>
extern int health;

extern int pause;
extern int state;
extern int long score;
extern int m_timerID;
class Normalban : public QWidget
{
    Q_OBJECT
public:
    explicit Normalban(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);
        virtual void timerEvent(QTimerEvent*event);

     // int m_timerID;
      int m_times[8];

      int xwhere[8];

      int hpnow;

      int Fb2now;
      int Fb1now;
      void statechange(int sta);

      void pxlimit(int &where);
private:
      QPixmap m_pictureNb;          //  普通板子
      QPixmap m_pictureTb;           //  陷阱板子
      QPixmap m_pictureSb;            //  弹簧板子
      QPixmap m_pictureSpb;          //  加速板子
      QPixmap m_pictureFb;             //  脆弱板子
      QPixmap m_player;

      int m_playerwidth1;
      int m_playerheight1;

      int m_Nbwidth;
      int m_Nbheight;

      int m_Sbwidth;
      int m_Sbheight;

      int m_Tbwidth;
      int m_Tbheight;

      int m_Fbwidth;
      int m_Fbheight;

      int m_Spbwidth;
      int m_Spbheight;

      int px;
      int py;


      int x[8];
      int y[8];

       void closeEvent(QCloseEvent *event);

      // void keyPressEvent(QKeyEvent  *event);
        QMediaPlayer* player1;
        QMediaPlayer* player2;
        int pGamevolume;

        void gameover();

signals:

public slots:
};




#endif // NORMALBAN_H
