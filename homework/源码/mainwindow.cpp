#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "QKeyEvent"
#include "normalban.h"
#include "board.h"
#include "mywidget.h"
#include "QPainter"
#include "QTimerEvent"
#include "QSound"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <list.h>
int mainclose=0;       //设置关闭参数

int cloundrun1=0;                //这六个都是控制云移动的参数
int cloundrun2=0;
int cloundrun3=1;

int cloundtimes1=0;
int cloundtimes2=0;
int cloundtimes3=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setWindowTitle("是男人(比利)就下一百层");
    setFixedSize(this->width(),this->height());
   // a=new Second(this);
    setFocusPolicy(Qt::StrongFocus);

    background.load(":/new/prefix1/resource/title.png");
    //Backgpic.load("E:/Qt/Resource/back.jpg");

        Backgpic.load(":/new/prefix1/resource/back.jpg");
        clound1.load(":/new/prefix1/resource/clound1.png");
        clound2.load(":/new/prefix1/resource/clound2.png");
        clound3.load(":/new/prefix1/resource/clound3.png");

    connect(ui->tbnStartgame,SIGNAL(clicked(bool)),this,SLOT(OnGamestart()));
    connect(ui->tbtnTuichu,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->tbtnList,SIGNAL(clicked(bool)),this,SLOT(Onlist()));

    wintimer=startTimer(100);
    wintimes=0;

    title=0;
   // QApplication::beep();
   // player=new QSound("E:\\Qt\\Resource\\BGM.wav");
    //player->setLoops(-1);
   // player->play();



    //QMediaPlaylist *playlist;
    playlist=new QMediaPlaylist;
   // playlist->addMedia(QUrl::fromLocalFile("E:\\Qt\\Resource\\BGM.wav"));    //绝对路径
    playlist->addMedia(QUrl::fromEncoded("qrc:/new/prefix1/resource/BGM.wav"));  //相对路径
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);                    //实现BGM的循环
/**/
    player = new QMediaPlayer(this);
    player->setPlaylist(playlist);
     //  connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));  //设置BGM
       // player->setMedia(QUrl::fromLocalFile("E:\\Qt\\Resource\\BGM.wav"));
        player->setVolume(300);
        player->play();

        pBGMvolume=100;

         b=new List;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnGamestart()
{
 Second a;
 a.exec();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(pBGMvolume!=BGMvolume)
    {
        player->setVolume(BGMvolume);               //检查音量是否改变
        pBGMvolume=BGMvolume;
    }

    QPainter painter(this);

    int clound1width=clound1.width();
    int clound1height=clound1.height();
    int clound2width=clound2.width();
    int clound2height=clound2.height();
    int clound3width=clound3.width();
    int clound3height=clound3.height();

    QRect sourceclound1(0,0,clound1width,clound1height);
    QRect sourceclound2(0,0,clound2width,clound2height);
    QRect sourceclound3(0,0,clound3width,clound3height);

    if(50+cloundtimes1>300)
 {
    cloundrun1=1;
}
    if(50+cloundtimes1<20)
    {
        cloundrun1=0;
    }
    if(500+cloundtimes2>=800)
 {
    cloundrun2=1;
}
    if(500+cloundtimes2<500)
    {
        cloundrun2=0;
    }
    if(720-cloundtimes3>=720)
 {
   cloundrun3=1;
}
    if(720-cloundtimes3<600)
    {
        cloundrun3=0;
    }

    QRect targetclound1(50+cloundtimes1,130,clound1width,clound1height);   //80  130
    QRect targetclound2(500+cloundtimes2,52,clound2width,clound2height);                  //774,52
    QRect targetclound3(720-cloundtimes3,225,clound3width,clound3height);


    int titlewidth=background.width();
    int titlehight=background.height();

    int backwidth=Backgpic.width();
    int backheight=Backgpic.height();

    QRect sourceback(0,0,backwidth, backheight);
    QRect targetback(0,0,1201,751);

    QRect sourcetitle(0,0,titlewidth, titlehight);
   // QRect targettitle(150,100,titlewidth, titlehight);
   QRect targettitle(10+wintimes,10+wintimes,titlewidth, titlehight);

   if(title==0)
   {wintimes+=2;}
   else
     { wintimes-=2;}

   if(wintimes==200)
   {
       title=1;
   }
   if(wintimes==0)
   {
       title=0;
   }

    painter.drawPixmap(targetback,Backgpic,sourceback);

    painter.drawPixmap( targetclound1,clound1,sourceclound1);
     painter.drawPixmap( targetclound2,clound2,sourceclound2);
     painter.drawPixmap( targetclound3,clound3,sourceclound3);
    painter.drawPixmap(targettitle,background,sourcetitle);       //绘制游戏标题文字
}

void MainWindow::keyPressEvent(QKeyEvent  *event)
{
    if(event->key()==Qt::Key_Left)
    {
        state=2;
    }
    if(event->key()==Qt::Key_Right)
    {
        state=1;
    }
   /*if(event->key()==Qt::Key_Space)
    {
        if(pause==1&&pause2==1)
        {
            pause=2;
            pause2=2 ;
            goto finish;
        }
        pause=1;
        pause2=1;
    }
    finish:;
    if(event->key()==Qt::Key_Space)
         {
        if(pause==0)
        {
            killTimer(m_timerID);
            pause=1;
        }
        else if(pause==1)
        {
            m_timerID=startTimer(500);
            pause=0;
        }
         }*/
}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

  void MainWindow::timerEvent(QTimerEvent*event)
  {
      update();
      if(mainclose==1)
      {
          mainclose=0;
          close();
      }
      if(cloundrun1==0)
      {
          cloundtimes1+=1;
      }
      else
      {
          cloundtimes1-=1;
      }
      if(cloundrun2==0)
      {
          cloundtimes2+=1;
      }
      else
      {
          cloundtimes2-=2;
      }
      if(cloundrun3==1)
      {
          cloundtimes3+=2;
      }
      else
      {
          cloundtimes3-=1;
      }
      if(mainlist==1)
      {
         delete b;
      }

  }

  void MainWindow::Onlist()
  {

      //List *b=new List;
      b->exec();

  }
