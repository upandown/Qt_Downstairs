#include "gameover.h"
#include "ui_gameover.h"
#include "QPainter"
#include "second.h"
#include "form.h"
#include "mainwindow.h"
#include "normalban.h"
#include "QString"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <list.h>
int times=0;
int title=0;                     //控制标题循环

int gcloundrun1=0;                //这六个都是控制云移动的参数
int gcloundrun2=0;
int gcloundrun3=1;

int gcloundtimes1=0;
int gcloundtimes2=0;
int gcloundtimes3=0;

Gameover::Gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gameover)
{
    if(gameover2>0)
    {
        close();
      //  gameover2=0;
    }
setWindowTitle("是男人(比利)就下一百层");
setFixedSize(1201,751);
    ui->setupUi(this);
    GameOverpic.load(":/new/prefix1/resource/gameover.png");
    back.load(":/new/prefix1/resource/back.jpg");

    startTimer(120);

    connect(ui->tbtnGameover,SIGNAL(clicked(bool)),this,SLOT(reBegin()));
    connect(ui->tbtnclose,SIGNAL(clicked(bool)),this,SLOT(closegame()));
    gameover2++;

   if(!name.isEmpty())                                                       //没有输入名字则不记录成绩
   {
    QFile file("E://homework//score.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))   //追加写入
    {
        QMessageBox::information(this,"error","No such file");               //打开失败报告
    }
    QTextStream write(&file);
    write<<name<<":";
    write<<score<<endl;
    file.close();
   }
   clound1.load(":/new/prefix1/resource/clound1.png");
   clound2.load(":/new/prefix1/resource/clound2.png");
   clound3.load(":/new/prefix1/resource/clound3.png");
   health=3;
}

Gameover::~Gameover()
{
    delete ui;
}

void Gameover::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int backwidth=back.width();
    int backheight=back.height();

    int Overwidth=GameOverpic.width();
    int Overheight=GameOverpic.height();
    int clound1width=clound1.width();
    int clound1height=clound1.height();
    int clound2width=clound2.width();
    int clound2height=clound2.height();
    int clound3width=clound3.width();
    int clound3height=clound3.height();

    QRect sourceclound1(0,0,clound1width,clound1height);
    QRect sourceclound2(0,0,clound2width,clound2height);
    QRect sourceclound3(0,0,clound3width,clound3height);

    if(50+gcloundtimes1>300)
 {
    gcloundrun1=1;
}
    if(50+gcloundtimes1<20)
    {
        gcloundrun1=0;
    }
    if(500+gcloundtimes2>=800)
 {
    gcloundrun2=1;
}
    if(500+gcloundtimes2<500)
    {
        gcloundrun2=0;
    }
    if(720-gcloundtimes3>=720)
 {
   gcloundrun3=1;
}
    if(720-gcloundtimes3<600)
    {
        gcloundrun3=0;
    }

    QRect targetclound1(50+gcloundtimes1,130,clound1width,clound1height);   //80  130
    QRect targetclound2(500+gcloundtimes2,52,clound2width,clound2height);                  //774,52
    QRect targetclound3(720-gcloundtimes3,225,clound3width,clound3height);


    QRect sourceback(0,0,backwidth, backheight);
    QRect targetback(0,0,1201,751);

    QRect sourceOver(0,0,Overwidth,Overheight);
    if(times*20>800)
 {
    title=1;
}
    if(times*20<20)
    {
        title=0;
    }
    QRect targetOver(times*20,40,400,200);

    painter.drawPixmap(targetback,back,sourceback);

    painter.drawPixmap( targetclound1,clound1,sourceclound1);
     painter.drawPixmap( targetclound2,clound2,sourceclound2);
     painter.drawPixmap( targetclound3,clound3,sourceclound3);
    painter.drawPixmap(targetOver,GameOverpic,sourceOver);


   QColor black(times,times,times);

    QFont font("Times",45,QFont::Bold,false);
      painter.setFont(font);
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
      Score="你的最后得分为： "+Score;
       painter.drawText(100,200,1000,200,
                       Qt::AlignCenter,
                      Score);
       QString caofeng;
       painter.setPen(QPen (QColor(times,times,times)));
       if(score<10)
       {
          caofeng="你还能不能再菜一点？！";

       }
       else if(score<100)
       {
            caofeng="小样~这才多少分？";

       }
       else if(score<1000)
       {
           caofeng="勉强算个比利~哦不 男人";

       }
       else if(score>=1000)
       {
          caofeng="牛逼咯，这破游戏都能玩1000分";

       }
       painter.drawText(200,300,800,200,
                       Qt::AlignCenter,
                      caofeng);

}
 void Gameover::timerEvent(QTimerEvent*event)
{
    update();
    if(title==0)
    {
        times++;
    }
    else
    {
        times--;
    }
    if(gcloundrun1==0)
    {
        gcloundtimes1+=1;
    }
    else
    {
        gcloundtimes1-=1;
    }
    if(gcloundrun2==0)
    {
        gcloundtimes2+=1;
    }
    else
    {
        gcloundtimes2-=2;
    }
    if(gcloundrun3==1)
    {
        gcloundtimes3+=2;
    }
    else
    {
        gcloundtimes3-=1;
    }
 }
 void Gameover::reBegin()
 {

     close();
     Fclose=1;
     closenum=1;
 }
 void Gameover::closeEvent(QCloseEvent *event)
 {

 }
 void Gameover::closegame()
 {
    Fclose=1;
    closenum=1;
    mainclose=1;
    close();
 }
