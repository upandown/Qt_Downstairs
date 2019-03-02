#ifndef A_H
#define A_H

#include <QMainWindow>

namespace Ui {
class a;
}

class a : public QMainWindow
{
    Q_OBJECT

public:
    explicit a(QWidget *parent = 0);
    ~a();

private:
    Ui::a *ui;
};

#endif // A_H
