#ifndef LIST_H
#define LIST_H

#include <QDialog>
#include <QPixmap>


extern int mainlist;
namespace Ui {
class List;
}

class List : public QDialog
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = 0);
    ~List();

    void paintEvent(QPaintEvent *event);
     virtual void timerEvent(QTimerEvent*event);
    void closeEvent(QCloseEvent *event);
private:
    Ui::List *ui;

    QPixmap Backgpic;

    QPixmap clound1;
    QPixmap clound2;
    QPixmap clound3;

    QPixmap starpic;
    int startimes;

    //QString *pcontent;
    QString *pname;
    int *pscore;
   int *max;
 private slots:

};

#endif // LIST_H
