#include "addevent.h"
#include "ui_addevent.h"
#include "homescreen.h"

addEvent::addEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEvent)
{
    ui->setupUi(this);
    ui->eventDateEnd->setEnabled(false);
    ui->eventDateEndLabel->setEnabled(false);
}

addEvent::~addEvent()
{
    delete ui;
}

void addEvent::on_checkBox_multipleDay_clicked()
{
    if(ui->checkBox_multipleDay->isChecked())
    {
        ui->eventDateEnd->setEnabled(true);
        ui->eventDateEndLabel->setEnabled(true);
        ui->eventDateLabel->setText("Start Date:");
    }
    else
    {
        ui->eventDateEnd->setEnabled(false);
        ui->eventDateEndLabel->setEnabled(false);
        ui->eventDateLabel->setText("Event Date:");
    }
}

void addEvent::on_checkBox_allDay_clicked()
{
    if(ui->checkBox_allDay->isChecked())
    {
        ui->startTimeLabel->setEnabled(false);
        ui->endTimeLabel->setEnabled(false);
        ui->timeEdit_eventStart->setEnabled(false);
        ui->timeEdit_eventEnd->setEnabled(false);
    }
    else
    {
        ui->startTimeLabel->setEnabled(true);
        ui->endTimeLabel->setEnabled(true);
        ui->timeEdit_eventStart->setEnabled(true);
        ui->timeEdit_eventEnd->setEnabled(true);
    }
}

void addEvent::on_saveEvent_clicked()
{
    QString eventName = "", eventType = "", startDate = "", endDate = "", startTime = "", endTime = "", eventDetails = "", multipleDay = "", allDay = "";
    eventName = ui->eventName->text();
    eventType = ui->eventType->text();
    startDate = ui->eventDate->text();
    endDate = ui->eventDateEnd->text();
    startTime = ui->timeEdit_eventStart->text();
    endTime = ui->timeEdit_eventEnd->text();
    eventDetails = ui->textEdit_details->toPlainText();

    if(ui->checkBox_multipleDay->isChecked())
    {
        multipleDay = "Y";
    }
    else
    {
        multipleDay= "N";
    }

    if(ui->checkBox_allDay->isChecked())
    {
        allDay = "Y";
    }
    else
    {
        allDay= "N";
    }

    Homescreen conn;
    conn.connectionOpen();                                  //opens database
    if(!conn.connectionOpen())                              //checks for connection to database
    {
        qDebug()<<"Failed to open database";
        return;
    }

    QSqlQuery query;

    //creates events table if it does not exist
    query.prepare("CREATE TABLE IF NOT EXISTS events (eventName VARCHAR(15), eventType VARCHAR(15), startDate VARCHAR(15), endDate VARCHAR(15), startTime VARCHAR(15), endTime VARCHAR(15), eventDetails VARCHAR(50), multipleDay VARCHAR(1), allDay VARCHAR(1))");
    query.exec();

    //insert query for event information
    query.prepare("INSERT INTO events (eventName, eventType, startDate, endDate, startTime, endTime, eventDetails, multipleDay, allDay) VALUES (:eventName, :eventType, :startDate, :endDate, :startTime, :endTime, :eventDetails, :multipleDay, :allDay)");
    query.bindValue(":eventName", eventName);
    query.bindValue(":eventType", eventType);
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);
    query.bindValue(":eventDetails", eventDetails);
    query.bindValue(":multipleDay", multipleDay);
    query.bindValue(":allDay", allDay);
    query.exec();

    conn.connectionClose();
    this->close();
}

void addEvent::on_cancel_clicked()
{
    this->close();
}
