#include "removeevent.h"
#include "ui_removeevent.h"

removeEvent::removeEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeEvent)
{
    ui->setupUi(this);
}

removeEvent::~removeEvent()
{
    delete ui;
}
