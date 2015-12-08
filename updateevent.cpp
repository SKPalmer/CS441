#include "updateevent.h"
#include "ui_updateevent.h"

updateEvent::updateEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateEvent)
{
    ui->setupUi(this);
}

updateEvent::~updateEvent()
{
    delete ui;
}
