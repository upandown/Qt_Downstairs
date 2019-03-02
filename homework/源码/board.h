#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPixmap>
#include <QTimerEvent>
#include <QTime>

extern int pause2;
extern int Bclose;
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

     void paintEvent(QPaintEvent *event);

     void closeEvent(QCloseEvent *event);
     QPixmap m_boardpic;
     QPixmap m_hp1pic;
     QPixmap m_hp2pic;
     QPixmap m_hp3pic;

     QPixmap m_bar;

private:
      virtual void timerEvent(QTimerEvent*event);

     int times;

     int timeId2;

     int long nowtime;
signals:

public slots:

};

#endif // BOARD_H
