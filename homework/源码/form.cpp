#include "form.h"
#include "ui_form.h"
#include "QKeyEvent"
#include "second.h"

int Fclose=0;            //设置关闭参数

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    startTimer(1000);
setWindowTitle("是男人(比利)就下一百层");
setFixedSize(1201,751);
    setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);

    connect(ui->tbtnPause,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->tbtnRegin,SIGNAL(clicked(bool)),this,SLOT(Rebegin()));

}

Form::~Form()
{
    delete ui;
}



void Form::keyPressEvent(QKeyEvent  *event)
{
    if(event->key()==Qt::Key_Left)
    {
        state=2;
    }
    if(event->key()==Qt::Key_Right)
    {
        state=1;
    }
   if(event->key()==Qt::Key_Space)
    {
        close();
    }

}

  void Form::closeEvent(QCloseEvent *event)
  {

  }

  void  Form::Onpause()
  {
      close();
  }

  void Form::Rebegin()
  {
      health=3;


      close();
      closenum=1;
  }

void Form::timerEvent(QTimerEvent*event)
{
    if(Fclose==1)
        {
        Fclose=0;
        close();
    }

}
