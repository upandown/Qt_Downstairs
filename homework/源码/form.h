#ifndef FORM_H
#define FORM_H

#include <QWidget>

extern int Fclose;
extern int gameover2;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void keyPressEvent(QKeyEvent  *event);
    virtual void timerEvent(QTimerEvent*event);

private:
    Ui::Form *ui;

    void closeEvent(QCloseEvent *event);

private slots:
    void Onpause();

    void Rebegin();

};

#endif // FORM_H
