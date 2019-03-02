#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPixmap>
class Mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit Mywidget(QWidget *parent = 0);

      void paintEvent(QPaintEvent *event);
private:

     QPixmap m_picture;
signals:

public slots:
};

#endif // MYWIDGET_H
