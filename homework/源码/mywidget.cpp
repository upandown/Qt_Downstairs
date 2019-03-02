#include "mywidget.h"
#include <QPainter>
#include <QTimerEvent>
#include <c++/iostream>
#include <ctime>





int COL=25;
int ROW=32;
int RectWidth=20;
int RectHeight=20;



Mywidget::Mywidget(QWidget *parent) : QWidget(parent)
{
   m_picture.load(":/new/prefix1/resource/timg.jpg");
}

void Mywidget::paintEvent(QPaintEvent *event)
{

    QColor black(0,0,0);                                        //生成颜色

  QPainter painter(this);

  painter.setPen(Qt::NoPen);
    for(int x = 0; x < COL; ++x) {
      for(int y = 0; y < ROW; ++y) {
          painter.drawRect(QRect(x*RectWidth, y*RectHeight, RectHeight, RectHeight));
      }
    }                                                            //画游戏盘

    int m_width=m_picture.width();
         int m_height=m_picture.height();


         QRect target(50,60,500,640);         //目标矩形


         QRect source(0,0,m_width,m_height);     //源矩形


        painter.drawPixmap(target,m_picture,source);

}
