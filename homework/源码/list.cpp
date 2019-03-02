#include "list.h"
#include "ui_list.h"
#include "QPainter"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <mainwindow.h>
int mainlist=0;         //防止重复排数
int lcloundrun1=0;                //这六个都是控制云移动的参数
int lcloundrun2=0;
int lcloundrun3=1;

int lcloundtimes1=0;
int lcloundtimes2=0;
int lcloundtimes3=0;

int textline=0;
int h=0;


QString pcontent[30];
/*QString pname[30];
int pscore[30];
int max[30];
int scoremax[30];
*/
List::List(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List)
{

    startTimer(100);
    ui->setupUi(this);
setWindowTitle("是男人(比利)就下一百层");
setFixedSize(this->width(),this->height());
    connect(ui->tbtnlistback,SIGNAL(clicked(bool)),this,SLOT(accept()));

    Backgpic.load(":/new/prefix1/resource/backlist.png");
    clound1.load(":/new/prefix1/resource/clound1.png");
    clound2.load(":/new/prefix1/resource/clound2.png");
    clound3.load(":/new/prefix1/resource/clound3.png");

    QFile file("E://homework//score.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::information(this,"error","No such file");               //打开失败报告
    }
    QTextStream write(&file);

    for(;;)
    {
       pcontent[textline]=write.readLine();

        if(pcontent[textline].isEmpty())              //读出文件一共有多少行
        {
            break;
        }
        if(textline>100)
        {
            break;
        }
        textline++;
    }


  //pcontent=new QString[textline];
   pname=new QString[textline];
   pscore=new int[textline];


    for(int i=0;i<textline;i++)
    {
       // pcontent[i]=write.readLine();
      //  pname[i]=pcontent[i].section(":",1,1);
        pscore[i]=pcontent[i].section(":",2,2).toInt();    //读取文件内容
    }

    if(textline<5)
    {
        h=textline;
    }
    else
    {
        h=5;
    }
        max=new int[h];
        int *scoremax=new int[h];


    for(int i=0;i<h;i++)                        //这是筛选大小的函数
    {
        for(int k=0;k<textline-1;k++)
        {

                if(k==0)
            {

            scoremax[i]=pscore[k];

            max[i]=k;
             }
            if(pscore[k+1]>scoremax[i])
            {
                scoremax[i]=pscore[k+1];
                max[i]=k+1;
            }

        }

        pscore[max[i]]=-1;
    }


    file.close();


}

List::~List()
{
    delete ui;

}

void List::closeEvent(QCloseEvent *event)
{
  mainlist=1;
}

void List::paintEvent(QPaintEvent *event)
{
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

    if(50+lcloundtimes1>300)
 {
    lcloundrun1=1;
}
    if(50+lcloundtimes1<20)
    {
        lcloundrun1=0;
    }
    if(500+lcloundtimes2>=800)
 {
    lcloundrun2=1;
}
    if(500+lcloundtimes2<500)
    {
        lcloundrun2=0;
    }
    if(720-lcloundtimes3>=720)
 {
   lcloundrun3=1;
}
    if(720-lcloundtimes3<600)
    {
        lcloundrun3=0;
    }

    QRect targetclound1(50+lcloundtimes1,130,clound1width,clound1height);   //80  130
    QRect targetclound2(500+lcloundtimes2,52,clound2width,clound2height);                  //774,52
    QRect targetclound3(720-lcloundtimes3,225,clound3width,clound3height);

    int backwidth=Backgpic.width();
    int backheight=Backgpic.height();

    QRect sourceback(0,0,backwidth, backheight);
    QRect targetback(0,0,1201,751);


    painter.drawPixmap(targetback,Backgpic,sourceback);



    painter.drawPixmap( targetclound1,clound1,sourceclound1);
     painter.drawPixmap( targetclound2,clound2,sourceclound2);
     painter.drawPixmap( targetclound3,clound3,sourceclound3);

     QFont font("Times",25,QFont::Bold,false);
     painter.setFont(font);
     QColor black(0,0,0);
     QPen textPen(black);
     painter.setPen(textPen);

     for(int i=0;i<h;i++)
     {
         QString Fcontent=pcontent[max[i]].section(":",1,1);
     painter.drawText(450,75*(i+1)+25,300,51,
                      Qt::AlignLeft,
                     Fcontent);

             painter.drawText(750,75*(i+1)+25,100,51,
                              Qt::AlignLeft,
                             pcontent[max[i]].section(":",2,2));
             painter.drawText(850,75*(i+1)+25,50,51,
                              Qt::AlignLeft,
                             "分");

     }

}
void List::timerEvent(QTimerEvent*event)
{
    update();
    if(lcloundrun1==0)
    {
        lcloundtimes1+=1;
    }
    else
    {
        lcloundtimes1-=1;
    }
    if(lcloundrun2==0)
    {
        lcloundtimes2+=1;
    }
    else
    {
        lcloundtimes2-=2;
    }
    if(lcloundrun3==1)
    {
        lcloundtimes3+=2;
    }
    else
    {
        lcloundtimes3-=1;
    }
}
