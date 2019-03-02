#include "normalban.h"
#include "mywidget.h"
#include <QPainter>
#include <QTimerEvent>
#include <c++/iostream>
#include <ctime>
#include <QMessageBox>
#include <second.h>
#include <gameover.h>
#include <form.h>
#include <board.h>
#include "mainwindow.h"
int state=0;                                            //定义左右移动的参数

int pause=0;                                            //暂停参数

int health=3;                                           //定义血量
int player4hp=0;
int pstate=1;                                           //定义板子状态，是否在板子上，0在，1不在

int long score=0;                                            //定义分数

int movedic=20;

int m_timerID;
//int xwhere=-1;

Normalban::Normalban(QWidget *parent) :QWidget(parent)
{

    player1 = new QMediaPlayer(this);                        //设置游戏音效
    //connect(player1, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));  //设置BGM
    player1->setMedia(QUrl::fromEncoded("qrc:/new/prefix1/resource/yahou.wav"));
     player1->setVolume(300);

     player2 = new QMediaPlayer(this);                        //设置游戏音效
    // connect(player2, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));  //设置BGM
     player2->setMedia(QUrl::fromEncoded("qrc:/new/prefix1/resource/gameover.wav"));
      player2->setVolume(300);

       int pGamevolume=100;

     setFocusPolicy(Qt::StrongFocus);

    srand((unsigned)time(NULL));                           //随机数声明
    int rand(void);


    m_timerID=startTimer(gamespade);                           //启动定时器


    for(int i=0;i<8;i++)                                //定位初始的层数
    {
        m_times[i]=32-4*i;
        y[i]=m_times[i]*20+60;
        py=y[1];
    }

    for(int i=0;i<8;i++)                                //初始化横坐标
    {
        xwhere[i]=(rand()+i*1234)%18;
          x[i]=xwhere[i]*20+50;
          px=x[1];
    }


    m_pictureNb.load(":/new/prefix1/resource/normalban.png");

    m_pictureSb.load(":/new/prefix1/resource/springban.png");

    m_pictureSpb.load(":/new/prefix1/resource/sportban.png");

    m_pictureTb.load(":/new/prefix1/resource/trapban.png");

    m_pictureFb.load(":/new/prefix1/resource/fragileban.png");

     m_playerwidth1=m_player.width();
     m_playerheight1=m_player.height();

     m_Nbwidth=m_pictureNb.width();
     m_Nbheight=m_pictureNb.height();

     m_Sbwidth=m_pictureSb.width();
     m_Sbheight=m_pictureSb.height();

     m_Tbwidth=m_pictureTb.width();
     m_Tbheight=m_pictureTb.height();

     m_Fbwidth=m_pictureFb.width();
     m_Fbheight=m_pictureFb.height();

     m_Spbwidth=m_pictureSpb.width();
     m_Spbheight=m_pictureSpb.height();







}



void Normalban::paintEvent(QPaintEvent *event)
{
    if(pGamevolume!=Gamevolume)
    {
        player1->setVolume(Gamevolume);               //检查音量是否改变
        player2->setVolume(Gamevolume);
        pGamevolume=Gamevolume;
    }

    switch(whichplayer)
    {
     case 1:
    m_player.load(":/new/prefix1/resource/player.png");
        break;
    case 2:
   m_player.load(":/new/prefix1/resource/player2.png");
   movedic=40;                               //加快移动速度
       break;
    case 3:
   m_player.load(":/new/prefix1/resource/player3.png");
       break;
    case 4:
   m_player.load(":/new/prefix1/resource/player4.png");
   if(player4hp==0)
   {
    health=6;
    player4hp=1;                         //初始化血量
   }
       break;
    case 5:
   m_player.load(":/new/prefix1/resource/player5.png");
       break;
}
    if(m_times[3]==20)
    {
  hpnow=x[3];                                                  //将是否在陷阱板子上的状态初始化
    }

    if(m_times[4]==16&&m_times[7]==4)
    {
        Fb2now=1;
        Fb1now=1;
    }


 //  if(xwhere==-1) {xwhere=rand()%1;};                       //生成随机坐标   取17是防止板块超出边界

    QColor black(0,0,0);                                        //生成颜色
    QColor blue(0,0,0xff);


  QPainter painter(this);

  painter.setPen(Qt::NoPen); //画普通板

  QBrush brush2(blue);
  QBrush brush(black);

  painter.setBrush(brush);



    QRect sourceNb(0,0,m_Nbwidth,m_Nbheight);
    //QRect sourceTb(0,0,m_Tbwidth,m_Tbheight);
    QRect sourceTb(111,279,1019,474);
    //QRect sourceSb(0,0,m_Sbwidth,m_Sbheight);
    QRect sourceSb(117,111,1039,383);
    QRect sourceFb(0,0,m_Fbwidth,m_Fbheight);
    QRect sourceSpb(0,0,m_Spbwidth,m_Spbheight);



   for(int i=0;i<8;i++)                                      //画板子的循环，一共有四种
   {
       for(int k=0;k<8;k++)                                 //落在板子上的函数
        {

           if(py==y[k]&&(px>x[k]-100&&px<=x[k]+80))        //100与80是多次实验得出的，具体怎么来的不知道
            {
               player1->play();
                pstate=0;

                if(k==3&&hpnow==x[3])           //陷阱板子
                {
                    if(whichplayer!=3)           //实现蕾姆无视陷阱的功能
                    {
                    health--;
                    hpnow=-100;
                    }
                    break;

                }
               else if(k==5)                        //加速板子
                {
                 if(xwhere[5]%3==0)
                 {
                     px+=5;
                     pxlimit(px);                  //防止滑出边界

                 }
                 else
                 {
                     px-=5;
                     pxlimit(px);
                 }
                   break;
                }
                else if(k==4)                    //脆弱板子
                {
                    Fb2now=0;
                    break;
                }
                else if(k==7)
                {
                    Fb1now=0;
                    break;
                }
                else if(k==2&&m_times[2]%2==0)      //弹簧板子
                {
                    py-=20;
                    health++;
                }
                 break;
            }

        }


               switch (i) {
               case 1:
               case 6:
               {
               QRect targetNb(xwhere[i]*20+50,m_times[i]*20+60,140,20);
               painter.drawPixmap(targetNb,m_pictureNb,sourceNb);
             //  x[i]=xwhere[i]*20;
               y[i]=m_times[i]*20+60;
               m_times[i]--;
                   break;
                }
              case 2:
               //case 7:
               {
               QRect targetSb(xwhere[i]*20+50,m_times[i]*20+60,140,20);
               painter.drawPixmap(targetSb,m_pictureSb,sourceSb);
              // x[i]=xwhere[i]*20;
              y[i]=m_times[i]*20+60;
               m_times[i]--;
                 break;
               }
               case 3:
               {
               QRect targetTb(xwhere[i]*20+50,m_times[i]*20+60,140,20);
               painter.drawPixmap(targetTb,m_pictureTb,sourceTb);
              // x[i]=xwhere[i]*20;
              y[i]=m_times[i]*20+60;
                m_times[i]--;
                  break;
               }
               case 4:
               {
                   if(Fb2now==1)
                   {
                QRect targetFb(xwhere[i]*20+50,m_times[i]*20+60,140,20);
                painter.drawPixmap(targetFb,m_pictureFb,sourceFb);
              //  x[i]=xwhere[i]*20;
               y[i]=m_times[i]*20+60;
                   }
                 m_times[i]--;
                   break;
               }
               case 5:
               {
                 QRect targetSpb(xwhere[i]*20+50,m_times[i]*20+60,140,20);
                 painter.drawPixmap(targetSpb,m_pictureSpb,sourceSpb);
              //   x[i]=xwhere[i]*20;
               y[i]=m_times[i]*20+60;
                  m_times[i]--;
                    break;
               }
               case 7:
               {
                   if(Fb1now==1)
                   {
                QRect targetFb(xwhere[i]*20+50,m_times[i]*20+60,140,20);
                painter.drawPixmap(targetFb,m_pictureFb,sourceFb);
              //  x[i]=xwhere[i]*20;
                y[i]=m_times[i]*20+60;
                   }
                 m_times[i]--;
                   break;
               }


   }
   }

     painter.setBrush(brush2);

    QRect target1(px+40,py-60,60,60);
    QRect source1(0,0,m_playerwidth1,m_playerheight1);
     painter.drawPixmap(target1,m_player,source1);
    // painter.drawRect(px+40,py-60,60,60);                      //绘制角色


    py-=20;                       //上升

    statechange(state);           //调用左右移动的函数

    if(pstate==1)                 //判断是否在板子上
    {
        py+=40;                   //下落
    }

    pstate=1;                     //重置板子的状态

    if(py<-10+60||py>641+60)
    {
        player2->play();
        killTimer(m_timerID);
        gameover2=1;
        Bclose=1;

       // close();

    }

      for(int i=0;i<8;i++)
      {
          if(m_times[i]==-1)
          {
              m_times[i]=32;
               xwhere[i]=(rand()+i*4321)%18;
                x[i]=xwhere[i]*20+50;
               if(i==3)
               {
                   hpnow=x[3];
               }
               else if(i==4||i==7)
               {
                   Fb2now=1;
               }
               break;                                  //每次只会有一个板子到底
          }
      }
  }



   void Normalban::timerEvent(QTimerEvent*event)
  {
      if(event->timerId()==m_timerID)
      {

     update();
      }
  }

   void Normalban::pxlimit(int& where)
   {
       if(where<=-30+50)
       {
           where+=2;
       }
       if(where>=410+50)
       {
           where-=2;
       }
   }


  void Normalban::statechange(int sta )
  {
      if(px>-30+50&&px<410+50)                 //限制角色在界面内移动
      {
      if(state==1)
      {
       px+=movedic;
       state=0;
      }
      if(state==2)
      {
          px-=movedic;
          state=0;
      }
      }
      else                                //将角色拉回界面
      {
         /* if(px<=-30)
          {
              px+=2;
          }
          if(px>=410)
          {
              px-=2;
          }*/
          pxlimit(px);
      }
  }



void Normalban::closeEvent(QCloseEvent *event)
{
     // QMessageBox::information(this,"attention","GameOver");


}





