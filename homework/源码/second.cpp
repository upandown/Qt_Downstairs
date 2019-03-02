#include "second.h"
#include "ui_second.h"
#include "form.h"
#include "QPainter"
#include "mainwindow.h"
#include "c++/fstream"
#include "string"
#include "GBK.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTimerEvent>

QString name;
int BGMvolume=100;            //设置BGM参数
int Gamevolume=100;           //设置游戏音效参数
int closenum=0;               //设置关闭参数
int gamespade=500;                                      //定义游戏难度
int whichplayer=1;            //定义角色参数，默认选角色1


Second::Second(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Second)
{
    ui->setupUi(this);
    setWindowTitle("是男人(比利)就下一百层");
    setFixedSize(this->width(),this->height());
    game=new Form(this);
    game->setWindowFlags(Qt::Window);

    startTimer(100);

Backgpic.load("E:/Qt/Resource/back - 副本.jpg");          //加载背景

    player.load(":/new/prefix1/resource/player.png");      //加载角色
    player2.load(":/new/prefix1/resource/player2.png");
    player3.load(":/new/prefix1/resource/player3.png");
    player4.load(":/new/prefix1/resource/player4.png");
    player5.load(":/new/prefix1/resource/player5.png");

    connect(ui->tbnLetsstart,SIGNAL(clicked(bool)),this,SLOT(OnletsStart()));    //开始游戏
    connect(ui->tbtnback,SIGNAL(clicked(bool)),this,SLOT(close()));              //返回首页
    connect(ui->SdBGM,SIGNAL(valueChanged(int)),this,SLOT(setBGMvolume()));      //调节BGM
    connect(ui->btnBGM,SIGNAL(clicked(bool)),this,SLOT(recoverBGM()));           //还原默认BGM
    connect(ui->SdGame,SIGNAL(valueChanged(int)),this,SLOT(setGamevolume()));      //调节游戏音效
    connect(ui->BtnGame,SIGNAL(clicked(bool)),this,SLOT(recoverGame()));           //还原默认游戏音效
    connect(ui->Sdgameclass,SIGNAL(valueChanged(int)),this,SLOT(setGameclass()));  //设置游戏难度
    connect(ui->btngameclass,SIGNAL(clicked(bool)),this,SLOT(reGameclass()));      //还原默认难度
    connect(ui->tbtnp1yes,SIGNAL(clicked(bool)),this,SLOT(choiceplayer1()));      //选择角色
    connect(ui->tbtnp2yes,SIGNAL(clicked(bool)),this,SLOT(choiceplayer2()));
    connect(ui->tbtnp3yes,SIGNAL(clicked(bool)),this,SLOT(choiceplayer3()));
    connect(ui->tbtnp4yes,SIGNAL(clicked(bool)),this,SLOT(choiceplayer4()));
    connect(ui->tbtnp5yes,SIGNAL(clicked(bool)),this,SLOT(choiceplayer5()));

    connect(ui->tbtnUseryes,SIGNAL(clicked(bool)),this,SLOT(Usernamew()));        //保存用户名
    connect(ui->tbtnUserclear,SIGNAL(clicked(bool)),this,SLOT(Userclear()));      //清除


}

Second::~Second()
{
    delete ui;
}

void Second::OnletsStart()
{
    game->show();
}

void Second::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int backwidth=Backgpic.width();
    int backheight=Backgpic.height();

    QRect sourceback(0,0,backwidth, backheight);
    QRect targetback(0,0,1201,751);

    painter.drawPixmap(targetback,Backgpic,sourceback);

    int playerwidth=player.width();
    int playerheigh=player.height();
    int player2width=player2.width();
    int player2heigh=player2.height();
    int player3width=player3.width();
    int player3heigh=player3.height();
    int player4width=player4.width();
    int player4heigh=player4.height();
    int player5width=player5.width();
    int player5heigh=player5.height();

    QRect sourceplayer(0,0,playerwidth, playerheigh);
      QRect sourceplayer2(0,0,player2width, player2heigh);
        QRect sourceplayer3(0,0,player3width, player3heigh);
          QRect sourceplayer4(0,0,player4width, player4heigh);
            QRect sourceplayer5(0,0,player5width, player5heigh);

     QRect targetplayer(70,160,150,180);
      QRect targetplayer2(320,160,150,180);
       QRect targetplayer3(570,160,150,180);
        QRect targetplayer4(820,160,150,180);
         QRect targetplayer5(1030,160,150,180);

       painter.drawPixmap(targetplayer,player,sourceplayer);
        painter.drawPixmap(targetplayer2,player2,sourceplayer2);
         painter.drawPixmap(targetplayer3,player3,sourceplayer3);
          painter.drawPixmap(targetplayer4,player4,sourceplayer4);
           painter.drawPixmap(targetplayer5,player5,sourceplayer5);


}

void Second::closeEvent(QCloseEvent *event)
{

}

void Second::setBGMvolume()
{
    BGMvolume=ui->SdBGM->value();
}

 void Second::recoverBGM()
 {
     ui->SdBGM->setValue(100);
 }

 void Second::setGamevolume()
 {
     Gamevolume=ui->SdGame->value();
 }

 void Second::recoverGame()
 {
     ui->SdGame->setValue(100);
 }



 void Second::choiceplayer1()
 {
     whichplayer=1;
 }

 void Second::choiceplayer2()
 {
     whichplayer=2;
 }
 void Second::choiceplayer3()
 {
     whichplayer=3;
 }
 void Second::choiceplayer4()
 {
     whichplayer=4;
 }
 void Second::choiceplayer5()
 {
     whichplayer=5;
 }


 void Second::Usernamew()
 {
     name=ui->Leduser->text();
     name=":"+name;

     /*QFile file("E://Qt//Resource//score.txt");
     if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))   //追加写入
     {
         QMessageBox::information(this,"error","No such file");               //打开失败报告
     }
     QTextStream write(&file);
     write<<name<<":";
     file.close();*/
 }

 void Second::Userclear()
 {
     ui->Leduser->clear();
 }

void Second::timerEvent(QTimerEvent*event)
 {
     if(closenum==1)    //如果关闭参数改变则关闭窗口
     {
         closenum=0;
         close();
     }
 }

void Second::setGameclass()
{
    gamespade=ui->Sdgameclass->value();
}

void Second::reGameclass()
{
    ui->Sdgameclass->setValue(500);
}
