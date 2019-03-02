#include "board.h"
#include <QPainter>
#include <QTimer>
#include "normalban.h"
#include <QString>
#include <GBK.h>
#include <string>
#include <time.h>
#include <gameover.h>
#include <second.h>
int pause2=0;

int Bclose=0;                                             //关闭参数
int gameover2=0;

Board::Board(QWidget *parent) : QWidget(parent)
{
    srand((unsigned)time(NULL));                           //随机数声明
    int rand(void);
    times=0;

    nowtime=time(NULL);

    timeId2=startTimer(1000-10*score);

   m_boardpic.load(":/new/prefix1/resource/board1.png");

   m_hp1pic.load(":/new/prefix1/resource/hp1.png");
   m_hp2pic.load(":/new/prefix1/resource/hp2.png");
   m_hp3pic.load(":/new/prefix1/resource/hp3.png");

   m_bar.load(":/new/prefix1/resource/boardbar1.png");


}

void Board::paintEvent(QPaintEvent *event)
{
    /*if(whichplayer==4)
    {
        health=6;
    }*/
    score=(time(NULL)-nowtime);
    QPainter painter(this);

    QColor black(0,0,0);

    int width=this->width();
    int height=this->height();

    int boardwidth=m_boardpic.width();
    int boardheight=m_boardpic.height();

    int hpwidth=m_hp1pic.width();                           //hp图片的大小是一样的；
    int hpheight=m_hp1pic.height();

    int barwight=m_bar.width();
    int barheight=m_bar.height();

    QRect hpsource(0,0,hpwidth,hpheight);

    QRect boardtarget(0,0,width,height);
    QRect boardsource(0,0,boardwidth,boardheight);

    painter.drawPixmap(boardtarget,m_boardpic,boardsource);  //加载边框

    QPen pen(black);
    QBrush brush(black);

    painter.setPen(pen);
    painter.setBrush(brush);

    //painter.drawRect(50,10,40,40);                          //画hp

    QRect hp3target(820,150,40,40);
    QRect hp2target(870,150,40,40);
    QRect hp1target(920,150,40,40);

    if(health>3&&whichplayer!=4)
    {
        health=3;
    }
    if(health>6&&whichplayer==4)
    {
        health=6;
    }
    if(whichplayer==5&&score%30==0)
    {
        health--;
    }
    switch (health) {
           case 6:
           case 5:
           case 4:
                   for(int i=0;i<health;i++)
                   {
                        painter.drawPixmap(QRect(820+50*i,150,40,40),m_hp1pic,hpsource);
                   }
        break;
    case 3:
            painter.drawPixmap(hp1target,m_hp1pic,hpsource);
             painter.drawPixmap(hp2target,m_hp1pic,hpsource);
              painter.drawPixmap(hp3target,m_hp1pic,hpsource);
        break;
   case  2:
       painter.drawPixmap(hp3target,m_hp2pic,hpsource);
       painter.drawPixmap(hp2target,m_hp2pic,hpsource);
        break;
    case 1:
        painter.drawPixmap(hp3target,m_hp3pic,hpsource);
        break;
    case 0:
               killTimer(timeId2);
                gameover2=1;
                close();
        break;
    }


    QRect bartarget1(28,60,22,641);
    QRect bartarget2(553,60,22,641);

    QRect barsource(0,times,barwight,barheight/2);

    painter.drawPixmap(bartarget1,m_bar,barsource);
    painter.drawPixmap(bartarget2,m_bar,barsource);

  times+=2;
  if(barheight/2+times>=barheight)
  {
      times=0;
  }

  QFont font("Times",25,QFont::Bold,false);
  painter.setFont(font);

  //QString Score=score;

  QString Score=QString::number(score,10);       //绘制分数
  QPen textPen(black);
  painter.setPen(textPen);
  if(score<10)
  {
      Score="000"+Score;
  }
  else if(score<100)
  {
      Score="00"+Score;
  }
  else if(score<1000)
  {
      Score="0"+Score;
  }
   painter.drawText(790,50,131,51,
                   Qt::AlignCenter,
                  Score);

}
void Board::closeEvent(QCloseEvent *event)
{

}


void Board::timerEvent(QTimerEvent*event)
{
   if(Bclose==1)
   {
       killTimer(timeId2);
       close();
       Bclose=0;
   }
   if(gameover2==1)
   {
       Gameover a;
       a.exec();
       close();
   }
   update();
}
