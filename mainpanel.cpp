#include "mainpanel.hpp"
#include "ui_mainpanel.h"

mainpanel::mainpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainpanel)
{
    ui->setupUi(this);
}

mainpanel::~mainpanel()
{
    delete ui;
}

void mainpanel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}
