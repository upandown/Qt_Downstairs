#include "a.h"
#include "ui_a.h"

a::a(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::a)
{
    ui->setupUi(this);
}

a::~a()
{
    delete ui;
}
