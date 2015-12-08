#include "homescreen.h"
#include "ui_homescreen.h"
#include <QDateTime>

Homescreen::Homescreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Homescreen)
{
    ui->setupUi(this);

    //load eventView on open
    QSqlQueryModel * modal = new QSqlQueryModel();
    connectionOpen();
    QSqlQuery* query = new QSqlQuery(plannerDB);
    query->prepare("SELECT eventName AS Name, eventType as Type, startDate as Date, startTime as Time FROM events");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_eventView->setModel(modal);
    connectionClose();
    qDebug() << (modal->rowCount());

    ui->eventDateEnd->setEnabled(false);
    ui->eventDateEndLabel->setEnabled(false);
    ui->eventDateEnd_3->setEnabled(false);
    ui->eventDateEndLabel_3->setEnabled(false);
    ui->groupBox_addEvent->hide();
    ui->groupBox_editEvent->hide();
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

Homescreen::~Homescreen()
{
    delete ui;
}

void Homescreen::on_addEvent_clicked()
{
    ui->groupBox_addEvent->show();
    ui->groupBox_editEvent->hide();
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->hide();
}

void Homescreen::on_editEvent_clicked()
{
    ui->groupBox_addEvent->hide();
    ui->groupBox_editEvent->show();
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->hide();
}

void Homescreen::on_removeEvent_clicked()
{
    ui->groupBox_confirmDeleteEvent->show();
    ui->groupBox_addEvent->hide();
    ui->groupBox_editEvent->hide();
    ui->groupBox_eventDetailDisplay->hide();
    int rowNum = ui->tableView_eventView->selectionModel()->currentIndex().row();
    QString eventName = ui->tableView_eventView->model()->data(ui->tableView_eventView->model()->index(rowNum, 0)).toString();
    ui->label_eventDelete->setText(eventName);
}



void Homescreen::on_checkBox_multipleDay_clicked()
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

void Homescreen::on_checkBox_allDay_clicked()
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

void Homescreen::on_saveEvent_clicked()
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

    refreshEventTable();
    ui->groupBox_addEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

void Homescreen::refreshEventTable()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    connectionOpen();
    QSqlQuery* query = new QSqlQuery(plannerDB);
    query->prepare("SELECT eventName AS Name, eventType as Type, startDate as Date, startTime as Time FROM events");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_eventView->setModel(modal);
    connectionClose();
    qDebug() << (modal->rowCount());
}

void Homescreen::on_cancel_clicked()
{
    ui->groupBox_addEvent->hide();
    ui->groupBox_editEvent->hide();
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

void Homescreen::on_tableView_eventView_clicked(const QModelIndex &index)
{
    QString eventName = "", eventType = "", eventStartDate = "", eventEndDate = "", eventStartTime = "", eventEndTime = "", eventDetails = "", eventMultipleDay = "", eventAllDay = "";

    int rowNum = ui->tableView_eventView->selectionModel()->currentIndex().row();
    eventName = ui->tableView_eventView->model()->data(ui->tableView_eventView->model()->index(rowNum, 0)).toString();
    ui->eventName_3->setText(eventName);
    connectionOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM events WHERE eventName = :eventName");
    query.bindValue(":eventName", eventName);
    if(!query.exec())
        QMessageBox::critical(this,tr("Error."),query.lastError().text());
    while(query.next())
    {
        eventName = query.value(0).toString();
        eventType = query.value(1).toString();
        eventStartDate = query.value(2).toString();
        eventEndDate = query.value(3).toString();
        eventStartTime = query.value(4).toString();
        eventEndTime = query.value(5).toString();
        eventDetails = query.value(6).toString();
        eventMultipleDay = query.value(7).toString();
        eventAllDay = query.value(8).toString();
    }
    connectionClose();

    if(eventMultipleDay == "N")
    {
        eventEndDate = "N/A";
    }
    if(eventAllDay == "Y")
    {
        eventStartTime = "All Day";
        eventEndTime = "All Day";
    }

    ui->eventName_3->setText(eventName);
    ui->eventType_3->setText(eventType);
    ui->textEdit_details_3->setText(eventDetails);
    ui->label_nameDisplay->setText(eventName);
    ui->label_typeDisplay->setText(eventType);
    ui->label_startDateDisplay->setText(eventStartDate);
    ui->label_endDateDisplay->setText(eventEndDate);
    ui->label_startTimeDisplay->setText(eventStartTime);
    ui->label_endTimeDisplay->setText(eventEndTime);
    ui->textEdit_detailsDisplay->setText(eventDetails);

}

void Homescreen::on_checkBox_multipleDay_3_clicked()
{
    if(ui->checkBox_multipleDay_3->isChecked())
    {
        ui->eventDateEnd_3->setEnabled(true);
        ui->eventDateEndLabel_3->setEnabled(true);
        ui->eventDateLabel_3->setText("Start Date:");
    }
    else
    {
        ui->eventDateEnd_3->setEnabled(false);
        ui->eventDateEndLabel_3->setEnabled(false);
        ui->eventDateLabel_3->setText("Event Date:");
    }
}

void Homescreen::on_checkBox_allDay_3_clicked()
{
    if(ui->checkBox_allDay_3->isChecked())
    {
        ui->startTimeLabel_3->setEnabled(false);
        ui->endTimeLabel_3->setEnabled(false);
        ui->timeEdit_eventStart_3->setEnabled(false);
        ui->timeEdit_eventEnd_3->setEnabled(false);
    }
    else
    {
        ui->startTimeLabel_3->setEnabled(true);
        ui->endTimeLabel_3->setEnabled(true);
        ui->timeEdit_eventStart_3->setEnabled(true);
        ui->timeEdit_eventEnd_3->setEnabled(true);
    }
}

void Homescreen::on_saveEvent_3_clicked()
{
    QString eventName = "", eventType = "", startDate = "", endDate = "", startTime = "", endTime = "", eventDetails = "", multipleDay = "", allDay = "";
    eventName = ui->eventName_3->text();
    eventType = ui->eventType_3->text();
    startDate = ui->eventDate_3->text();
    endDate = ui->eventDateEnd_3->text();
    startTime = ui->timeEdit_eventStart_3->text();
    endTime = ui->timeEdit_eventEnd_3->text();
    eventDetails = ui->textEdit_details_3->toPlainText();

    if(ui->checkBox_multipleDay->isChecked())
    {multipleDay = "Y";}
    else
    {multipleDay= "N";}

    if(ui->checkBox_allDay->isChecked())
    {allDay = "Y";}
    else
    {allDay= "N";}

    Homescreen conn;
    conn.connectionOpen();                                  //opens database
    if(!conn.connectionOpen())                              //checks for connection to database
    {
        qDebug()<<"Failed to open database";
        return;
    }

    QSqlQuery query;

    query.prepare("UPDATE events SET eventType = :eventType, startDate = :startDate, endDate = :endDate, startTime = :startTime, endTime = :endTime, eventDetails = :eventDetails, multipleDay = :multipleDay, allDay = :allDay WHERE eventName = :eventName");
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

    refreshEventTable();
    ui->groupBox_editEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

void Homescreen::on_cancel_3_clicked()
{
    ui->groupBox_addEvent->hide();
    ui->groupBox_editEvent->hide();
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

void Homescreen::on_pushButton_deleteEvent_clicked()
{
    int rowNum = ui->tableView_eventView->selectionModel()->currentIndex().row();
    QString eventName = ui->tableView_eventView->model()->data(ui->tableView_eventView->model()->index(rowNum, 0)).toString();
    connectionOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM events WHERE eventName = :eventName");
    query.bindValue(":eventName", eventName);
    query.exec();
    refreshEventTable();
    QMessageBox::warning(this,tr("Confirm"), tr("Your Event has been deleted."));
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

void Homescreen::on_pushButton_cancelDeleteEvent_clicked()
{
    ui->groupBox_addEvent->hide();
    ui->groupBox_editEvent->hide();
    ui->groupBox_confirmDeleteEvent->hide();
    ui->groupBox_eventDetailDisplay->show();
}

void Homescreen::on_Homescreen_2_tabBarClicked(int index)
{
    if(index == 2)
    {
        //Populates gradebook tab courses upon tab change
        ui->groupBox_courses->show();
        ui->groupBox_confirmDelete->hide();
        connectionOpen();
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery* query = new QSqlQuery(plannerDB);
        query->prepare("Select courseNumber from courses");
        query->exec();
        modal->setQuery(*query);
        ui->comboBox_courses->setModel(modal);
        connectionClose();
        qDebug() << (modal->rowCount());
    }
}

void Homescreen::on_comboBox_courses_currentTextChanged(const QString &arg1)
{
    QString courseNumberInfo = ui->comboBox_courses->currentText();
    QString gradeCalculation;
    double pointsGradeEarned, pointsGradePossible;

    Homescreen conn;
    conn.connectionOpen();
    if(!conn.connectionOpen())                              //checks for connection to database
    {
        qDebug()<<"Failed to open database";
        return;
    }
    QSqlQuery query;

    query.prepare("SELECT * FROM courses WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumberInfo);
    if(query.exec())
    {
        while(query.next())
        {
            ui->label_courseNumberInfo->setText(query.value(0).toString());
            ui->label_courseNameInfo->setText(query.value(1).toString());
            ui->label_instructorInfo->setText(query.value(2).toString());
            ui->label_gradingInfo->setText(query.value(3).toString());
            ui->label_locationInfo->setText(query.value(4).toString());
            if(query.value(1) == "")
                ui->label_courseNameInfo->setText("N/A");
            if(query.value(2) == "")
                ui->label_instructorInfo->setText("N/A");
            if(query.value(3) == "pointBased")
            {
                ui->label_gradingInfo->setText("Point Based");
                gradeCalculation = "pointBased";
            }
            else
            {
                ui->label_gradingInfo->setText("Weighted");
                gradeCalculation = "weighted";
            }
            if(query.value(4) == "")
                ui->label_locationInfo->setText("N/A");
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),query.lastError().text());
    }

    query.prepare("SELECT * FROM courseTimes WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumberInfo);
    if(query.exec())
    {
        while(query.next())
        {
            ui->label_sundayTime->setText(query.value(1).toString());
            ui->label_sundayTimeEnd->setText(query.value(2).toString());
            ui->label_mondayTime->setText(query.value(3).toString());
            ui->label_mondayTimeEnd->setText(query.value(4).toString());
            ui->label_tuesdayTime->setText(query.value(5).toString());
            ui->label_tuesdayTimeEnd->setText(query.value(6).toString());
            ui->label_wednesdayTime->setText(query.value(7).toString());
            ui->label_wednesdayTimeEnd->setText(query.value(8).toString());
            ui->label_thursdayTime->setText(query.value(9).toString());
            ui->label_thursdayTimeEnd->setText(query.value(10).toString());
            ui->label_fridayTime->setText(query.value(11).toString());
            ui->label_fridayTimeEnd->setText(query.value(12).toString());
            ui->label_saturdayTime->setText(query.value(13).toString());
            ui->label_saturdayTimeEnd->setText(query.value(14).toString());

            if(query.value(1) == "")
                ui->label_sundayTime->setText("N/A");
            if(query.value(2) == "")
                ui->label_sundayTimeEnd->setText("N/A");
            if(query.value(3) == "")
                ui->label_mondayTime->setText("N/A");
            if(query.value(4) == "")
                ui->label_mondayTimeEnd->setText("N/A");
            if(query.value(5) == "")
                ui->label_tuesdayTime->setText("N/A");
            if(query.value(6) == "")
                ui->label_tuesdayTimeEnd->setText("N/A");
            if(query.value(7) == "")
                ui->label_wednesdayTime->setText("N/A");
            if(query.value(8) == "")
                ui->label_wednesdayTimeEnd->setText("N/A");
            if(query.value(9) == "")
                ui->label_thursdayTime->setText("N/A");
            if(query.value(10) == "")
                ui->label_thursdayTimeEnd->setText("N/A");
            if(query.value(11) == "")
                ui->label_fridayTime->setText("N/A");
            if(query.value(12) == "")
                ui->label_fridayTimeEnd->setText("N/A");
            if(query.value(13) == "")
                ui->label_saturdayTime->setText("N/A");
            if(query.value(14) == "")
                ui->label_saturdayTimeEnd->setText("N/A");
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),query.lastError().text());
    }

    if(gradeCalculation == "weighted")
    {
        QString category1, category2, category3, category4, category5, category6, category7;
        query.prepare("SELECT * FROM weightedGrades WHERE courseName = :courseNumber");
        query.bindValue(":courseNumber", courseNumberInfo);
        if(query.exec())
        {
            while(query.next())
            {
                category1 = query.value(1).toString();category2 = query.value(2).toString();category3 = query.value(3).toString();category4 = query.value(4).toString();category5 = query.value(5).toString();category6 = query.value(6).toString();category7 = query.value(7).toString();
                ui->label_category1->setText(category1);
                ui->label_category2->setText(category2);
                ui->label_category3->setText(category3);
                ui->label_category4->setText(category4);
                ui->label_category5->setText(category5);
                ui->label_category6->setText(category6);
                ui->label_category7->setText(category7);
                ui->label_weight1->setText(query.value(8).toString());
                ui->label_weight2->setText(query.value(9).toString());
                ui->label_weight3->setText(query.value(10).toString());
                ui->label_weight4->setText(query.value(11).toString());
                ui->label_weight5->setText(query.value(12).toString());
                ui->label_weight6->setText(query.value(13).toString());
                ui->label_weight7->setText(query.value(14).toString());

                if(query.value(1).toString() == "")
                {
                    ui->label_category1->setText("N/A");
                    ui->label_earned1->setText("N/A");ui->label_earned2->setText("");ui->label_earned3->setText("");ui->label_earned4->setText("");ui->label_earned5->setText("");ui->label_earned6->setText("");ui->label_earned7->setText("");
                    ui->label_possible1->setText("N/A");ui->label_possible2->setText("");ui->label_possible3->setText("");ui->label_possible4->setText("");ui->label_possible5->setText("");ui->label_possible6->setText("");ui->label_possible7->setText("");
                }
                if(query.value(8) == "0")
                    ui->label_weight1->setText("N/A");
                if(query.value(9) == "0")
                    ui->label_weight2->setText("");
                if(query.value(10) == "0")
                    ui->label_weight3->setText("");
                if(query.value(11) == "0")
                    ui->label_weight4->setText("");
                if(query.value(12) == "0")
                    ui->label_weight5->setText("");
                if(query.value(13) == "0")
                    ui->label_weight6->setText("");
                if(query.value(14) == "0")
                    ui->label_weight7->setText("");
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),query.lastError().text());
        }
        QString category1Weight = "", category2Weight = "", category3Weight = "", category4Weight = "", category5Weight = "", category6Weight = "", category7Weight = "", gradeType = "";
        double weightedGradeTotal = 0;
        if(category1 != "")
        {
            ui->label_categories->setText("Categories:");
            ui->label_weight->setText("Weight:");
            ui->label_overall->setText("Overall:");
            ui->label_outOf->setText("Possible:");
            ui->label_percentageEarned->setText("Category %:");
            ui->label_percentagePossible->setText("Possible %:");
            query.prepare("SELECT category1Weight, category2Weight, category3Weight, category4Weight, category5Weight, category6Weight, category7Weight FROM weightedGrades WHERE courseName = :courseNumber");
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    category1Weight = query.value(0).toString();
                    category2Weight = query.value(1).toString();
                    category3Weight = query.value(2).toString();
                    category4Weight = query.value(3).toString();
                    category5Weight = query.value(4).toString();
                    category6Weight = query.value(5).toString();
                    category7Weight = query.value(6).toString();
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            QString earned1, possible1;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category1 AND courseNumber = :courseNumber");
            query.bindValue(":category1", category1);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned1 = query.value(0).toString();
                    ui->label_earned1->setText(earned1);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned1->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category1 AND courseNumber = :courseNumber");
            query.bindValue(":category1", category1);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible1 = query.value(0).toString();
                    ui->label_possible1->setText(possible1);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible1->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category1->setText(category1);
            ui->label_weight1->setText(category1Weight);
            double c1Earned = earned1.toDouble();
            double c1Percent;
            if(c1Earned == 0)
                c1Percent = 0;
            else
            {
                double c1Possible = possible1.toDouble();
                double c1PercentEarned = category1Weight.toDouble();
                c1Percent = c1Earned / c1Possible * c1PercentEarned;
            }
            QString percent1 = QString::number(c1Percent, 'f', 2);
            ui->label_percentage1->setText(percent1 + ' %');
            ui->label_percentageEarned1->setText(category1Weight + ' %');
            weightedGradeTotal += c1Percent;
            ui->label_category2->setText("");ui->label_category3->setText("");ui->label_category4->setText("");ui->label_category5->setText("");ui->label_category6->setText("");ui->label_category7->setText("");
            ui->label_weight2->setText("");ui->label_weight3->setText("");ui->label_weight4->setText("");ui->label_weight5->setText("");ui->label_weight6->setText("");ui->label_weight7->setText("");
            ui->label_earned2->setText("");ui->label_earned3->setText("");ui->label_earned4->setText("");ui->label_earned5->setText("");ui->label_earned6->setText("");ui->label_earned7->setText("");
            ui->label_possible2->setText("");ui->label_possible3->setText("");ui->label_possible4->setText("");ui->label_possible5->setText("");ui->label_possible6->setText("");ui->label_possible7->setText("");
            ui->label_percentage2->setText("");ui->label_percentage3->setText("");ui->label_percentage4->setText("");ui->label_percentage5->setText("");ui->label_percentage6->setText("");ui->label_percentage7->setText("");
            ui->label_percentageEarned2->setText("");ui->label_percentageEarned3->setText("");ui->label_percentageEarned4->setText("");ui->label_percentageEarned5->setText("");ui->label_percentageEarned6->setText("");ui->label_percentageEarned7->setText("");
        }
        if(category2 != "")
        {
            QString earned2, possible2;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category2 AND courseNumber = :courseNumber");
            query.bindValue(":category2", category2);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned2 = query.value(0).toString();
                    ui->label_earned2->setText(earned2);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned2->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category2 AND courseNumber = :courseNumber");
            query.bindValue(":category2", category2);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible2 = query.value(0).toString();
                    ui->label_possible2->setText(possible2);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible2->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category2->setText(category2);
            ui->label_weight2->setText(category2Weight);
            double c2Earned = earned2.toDouble();
            double c2Percent;
            if(c2Earned == 0)
                c2Percent = 0;
            else
            {
                double c2Possible = possible2.toDouble();
                double c2PercentEarned = category2Weight.toDouble();
                c2Percent = c2Earned / c2Possible * c2PercentEarned;
            }
            QString percent2 = QString::number(c2Percent, 'f', 2);
            ui->label_percentage2->setText(percent2 + ' %');
            ui->label_percentageEarned2->setText(category2Weight + ' %');
            weightedGradeTotal += c2Percent;
            ui->label_category3->setText("");ui->label_category4->setText("");ui->label_category5->setText("");ui->label_category6->setText("");ui->label_category7->setText("");
            ui->label_weight3->setText("");ui->label_weight4->setText("");ui->label_weight5->setText("");ui->label_weight6->setText("");ui->label_weight7->setText("");
            ui->label_earned3->setText("");ui->label_earned4->setText("");ui->label_earned5->setText("");ui->label_earned6->setText("");ui->label_earned7->setText("");
            ui->label_possible3->setText("");ui->label_possible4->setText("");ui->label_possible5->setText("");ui->label_possible6->setText("");ui->label_possible7->setText("");
            ui->label_percentage3->setText("");ui->label_percentage4->setText("");ui->label_percentage5->setText("");ui->label_percentage6->setText("");ui->label_percentage7->setText("");
            ui->label_percentageEarned3->setText("");ui->label_percentageEarned4->setText("");ui->label_percentageEarned5->setText("");ui->label_percentageEarned6->setText("");ui->label_percentageEarned7->setText("");
        }
        if(category3 != "")
        {
            QString earned3, possible3;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category3 AND courseNumber = :courseNumber");
            query.bindValue(":category3", category3);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned3 = query.value(0).toString();
                    ui->label_earned3->setText(earned3);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned3->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category3 AND courseNumber = :courseNumber");
            query.bindValue(":category3", category3);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible3 = query.value(0).toString();
                    ui->label_possible3->setText(possible3);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible3->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category3->setText(category3);
            ui->label_weight3->setText(category3Weight);
            double c3Earned = earned3.toDouble();
            double c3Percent;
            if(c3Earned == 0)
                c3Percent = 0;
            else
            {
                double c3Possible = possible3.toDouble();
                double c3PercentEarned = category3Weight.toDouble();
                c3Percent = c3Earned / c3Possible * c3PercentEarned;
            }
            QString percent3 = QString::number(c3Percent, 'f', 2);
            ui->label_percentage3->setText(percent3 + ' %');
            ui->label_percentageEarned3->setText(category3Weight + ' %');
            weightedGradeTotal += c3Percent;
            ui->label_category4->setText("");ui->label_category5->setText("");ui->label_category6->setText("");ui->label_category7->setText("");
            ui->label_weight4->setText("");ui->label_weight5->setText("");ui->label_weight6->setText("");ui->label_weight7->setText("");
            ui->label_earned4->setText("");ui->label_earned5->setText("");ui->label_earned6->setText("");ui->label_earned7->setText("");
            ui->label_possible4->setText("");ui->label_possible5->setText("");ui->label_possible6->setText("");ui->label_possible7->setText("");
            ui->label_percentage4->setText("");ui->label_percentage5->setText("");ui->label_percentage6->setText("");ui->label_percentage7->setText("");
            ui->label_percentageEarned4->setText("");ui->label_percentageEarned5->setText("");ui->label_percentageEarned6->setText("");ui->label_percentageEarned7->setText("");
        }
        if(category4 != "")
        {
            QString earned4, possible4;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category4 AND courseNumber = :courseNumber");
            query.bindValue(":category4", category4);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned4 = query.value(0).toString();
                    ui->label_earned4->setText(earned4);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned4->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category4 AND courseNumber = :courseNumber");
            query.bindValue(":category4", category4);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible4 = query.value(0).toString();
                    ui->label_possible4->setText(possible4);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible4->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category4->setText(category4);
            ui->label_weight4->setText(category4Weight);
            double c4Earned = earned4.toDouble();
            double c4Percent;
            if(c4Earned == 0)
                c4Percent = 0;
            else
            {
                double c4Possible = possible4.toDouble();
                double c4PercentEarned = category4Weight.toDouble();
                c4Percent = c4Earned / c4Possible * c4PercentEarned;
            }
            QString percent4 = QString::number(c4Percent, 'f', 2);
            ui->label_percentage4->setText(percent4 + ' %');
            ui->label_percentageEarned4->setText(category4Weight + ' %');
            weightedGradeTotal += c4Percent;
            ui->label_category5->setText("");ui->label_category6->setText("");ui->label_category7->setText("");
            ui->label_weight5->setText("");ui->label_weight6->setText("");ui->label_weight7->setText("");
            ui->label_earned5->setText("");ui->label_earned6->setText("");ui->label_earned7->setText("");
            ui->label_possible5->setText("");ui->label_possible6->setText("");ui->label_possible7->setText("");
            ui->label_percentage5->setText("");ui->label_percentage6->setText("");ui->label_percentage7->setText("");
            ui->label_percentageEarned5->setText("");ui->label_percentageEarned6->setText("");ui->label_percentageEarned7->setText("");
        }
        if(category5 != "")
        {
            QString earned5, possible5;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category5 AND courseNumber = :courseNumber");
            query.bindValue(":category5", category5);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned5 = query.value(0).toString();
                    ui->label_earned5->setText(earned5);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned5->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category5 AND courseNumber = :courseNumber");
            query.bindValue(":category5", category5);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible5 = query.value(0).toString();
                    ui->label_possible5->setText(possible5);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible5->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category5->setText(category5);
            ui->label_weight5->setText(category5Weight);
            double c5Earned = earned5.toDouble();
            double c5Percent;
            if(c5Earned == 0)
                c5Percent = 0;
            else
            {
                double c5Possible = possible5.toDouble();
                double c5PercentEarned = category5Weight.toDouble();
                c5Percent = c5Earned / c5Possible * c5PercentEarned;
            }
            QString percent5 = QString::number(c5Percent, 'f', 2);
            ui->label_percentage5->setText(percent5 + ' %');
            ui->label_percentageEarned5->setText(category5Weight + ' %');
            weightedGradeTotal += c5Percent;
            ui->label_category6->setText("");ui->label_category7->setText("");
            ui->label_weight6->setText("");ui->label_weight7->setText("");
            ui->label_earned6->setText("");ui->label_earned7->setText("");
            ui->label_possible6->setText("");ui->label_possible7->setText("");
            ui->label_percentage6->setText("");ui->label_percentage7->setText("");
            ui->label_percentageEarned6->setText("");ui->label_percentageEarned7->setText("");
        }
        if(category6 != "")
        {
            QString earned6, possible6;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category6 AND courseNumber = :courseNumber");
            query.bindValue(":category6", category6);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned6 = query.value(0).toString();
                    ui->label_earned6->setText(earned6);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned6->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category6 AND courseNumber = :courseNumber");
            query.bindValue(":category6", category6);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible6 = query.value(0).toString();
                    ui->label_possible6->setText(possible6);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible6->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category6->setText(category6);
            ui->label_weight6->setText(category6Weight);
            double c6Earned = earned6.toDouble();
            double c6Percent;
            if(c6Earned == 0)
                c6Percent = 0;
            else
            {
                double c6Possible = possible6.toDouble();
                double c6PercentEarned = category6Weight.toDouble();
                c6Percent = c6Earned / c6Possible * c6PercentEarned;
            }
            QString percent6 = QString::number(c6Percent, 'f', 2);
            ui->label_percentage6->setText(percent6 + ' %');
            ui->label_percentageEarned6->setText(category6Weight + ' %');
            weightedGradeTotal += c6Percent;
            ui->label_category7->setText("");
            ui->label_weight7->setText("");
            ui->label_earned7->setText("");
            ui->label_possible7->setText("");
            ui->label_percentage7->setText("");
            ui->label_percentageEarned7->setText("");
        }
        if(category7 != "")
        {
            QString earned7, possible7;
            query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE assignmentCategory = :category7 AND courseNumber = :courseNumber");
            query.bindValue(":category7", category7);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    earned7 = query.value(0).toString();
                    ui->label_earned7->setText(earned7);
                    if(query.value(0).toDouble() == 0)
                        ui->label_earned7->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE assignmentCategory = :category7 AND courseNumber = :courseNumber");
            query.bindValue(":category7", category7);
            query.bindValue(":courseNumber", courseNumberInfo);
            if(query.exec())
            {
                while(query.next())
                {
                    possible7 = query.value(0).toString();
                    ui->label_possible7->setText(possible7);
                    if(query.value(0).toDouble() == 0)
                        ui->label_possible7->setText("0");
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
            ui->label_category7->setText(category7);
            ui->label_weight7->setText(category7Weight);
            double c7Earned = earned7.toDouble();
            double c7Percent;
            if(c7Earned == 0)
                c7Percent = 0;
            else
            {
                double c7Possible = possible7.toDouble();
                double c7PercentEarned = category7Weight.toDouble();
                c7Percent = c7Earned / c7Possible * c7PercentEarned;
            }
            QString percent7 = QString::number(c7Percent, 'f', 2);
            ui->label_percentage7->setText(percent7 + ' %');
            ui->label_percentageEarned7->setText(category7Weight + ' %');
            weightedGradeTotal += c7Percent;
        }
        QString weightedGradeTotalDisplay = QString::number(weightedGradeTotal, 'f', 2);
        ui->label_totalGrade->setText(weightedGradeTotalDisplay + ' %');
    }
    else
    {
        query.prepare("SELECT SUM(pointsEarned) FROM assignment WHERE courseNumber = :courseNumber");
        query.bindValue(":courseNumber", courseNumberInfo);
        if(query.exec())
        {
            while(query.next())
            {
                pointsGradeEarned = query.value(0).toDouble();
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),query.lastError().text());
        }
        query.prepare("SELECT SUM(pointsPossible) FROM assignment WHERE courseNumber = :courseNumber");
        query.bindValue(":courseNumber", courseNumberInfo);
        if(query.exec())
        {
            while(query.next())
            {
                pointsGradePossible = query.value(0).toDouble();
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),query.lastError().text());
        }
        double pointsGradeTotal;
        pointsGradeTotal = pointsGradeEarned / pointsGradePossible * 100;
        QString pointsGrade = QString::number(pointsGradeTotal, 'f', 2);
        QString pointsGradeEarnedString = QString::number(pointsGradeEarned);
        QString pointsGradePossibleString = QString::number(pointsGradePossible);
        if(pointsGradeEarned == 0)
            pointsGrade = "0";
        ui->label_totalGrade->setText(pointsGrade + ' %');
        ui->label_categories->setText("Earned:");
        ui->label_category1->setText(pointsGradeEarnedString);
        ui->label_category2->setText("");
        ui->label_category3->setText("");
        ui->label_category4->setText("");
        ui->label_category5->setText("");
        ui->label_category6->setText("");
        ui->label_category7->setText("");
        ui->label_weight->setText("Possible:");
        ui->label_weight1->setText(pointsGradePossibleString);
        ui->label_weight2->setText("");
        ui->label_weight3->setText("");
        ui->label_weight4->setText("");
        ui->label_weight5->setText("");
        ui->label_weight6->setText("");
        ui->label_weight7->setText("");
        ui->label_overall->setText("");
        ui->label_earned1->setText("");
        ui->label_earned2->setText("");
        ui->label_earned3->setText("");
        ui->label_earned4->setText("");
        ui->label_earned5->setText("");
        ui->label_earned6->setText("");
        ui->label_earned7->setText("");
        ui->label_outOf->setText("");
        ui->label_possible1->setText("");
        ui->label_possible2->setText("");
        ui->label_possible3->setText("");
        ui->label_possible4->setText("");
        ui->label_possible5->setText("");
        ui->label_possible6->setText("");
        ui->label_possible7->setText("");
        ui->label_percentageEarned->setText("");
        ui->label_percentage1->setText("");
        ui->label_percentage2->setText("");
        ui->label_percentage3->setText("");
        ui->label_percentage4->setText("");
        ui->label_percentage5->setText("");
        ui->label_percentage6->setText("");
        ui->label_percentage7->setText("");
        ui->label_percentagePossible->setText("");
        ui->label_percentageEarned1->setText("");
        ui->label_percentageEarned2->setText("");
        ui->label_percentageEarned3->setText("");
        ui->label_percentageEarned4->setText("");
        ui->label_percentageEarned5->setText("");
        ui->label_percentageEarned6->setText("");
        ui->label_percentageEarned7->setText("");
    }
    conn.connectionClose();
}


void Homescreen::on_pushButton_addCourse_clicked()
{
    if(!connectionOpen())                              //checks for connection to database
        connectionClose();
    addCourse addcourse;
    addcourse.setModal(true);
    addcourse.exec();
}

void Homescreen::on_pushButton_assignmentGrades_clicked()
{
    if(!connectionOpen())                              //checks for connection to database
        connectionClose();
    assignments assignmentPage;
    assignmentPage.setModal(true);
    assignmentPage.exec();
}

void Homescreen::on_Homescreen_2_currentChanged(int index)
{
    if(index == 3)
    {
        ui->groupBox_addToDo->show();
        ui->groupBox_editToDo->hide();
        ui->radioButton_viewAll->setChecked(true);
        QDate currentdate = QDate::currentDate();
        ui->dateEdit_toDo->setDate(QDate::currentDate());
        QSqlQueryModel * modal = new QSqlQueryModel();
        connectionOpen();
        QSqlQuery* query = new QSqlQuery(plannerDB);
        query->prepare("SELECT name AS Name, date AS Date, time AS Time, completed AS Completed FROM toDoList");
        query->exec();
        modal->setQuery(*query);
        ui->tableView_toDo->setModel(modal);
        connectionClose();
        qDebug() << (modal->rowCount());

    }
}

void Homescreen::on_radioButton_viewAll_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    connectionOpen();
    QSqlQuery* query = new QSqlQuery(plannerDB);
    query->prepare("SELECT name AS Name, date AS Date, time AS Time, completed FROM toDoList");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_toDo->setModel(modal);
    connectionClose();
    qDebug() << (modal->rowCount());
}

void Homescreen::on_radioButton_completed_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    connectionOpen();
    QSqlQuery* query = new QSqlQuery(plannerDB);
    query->prepare("SELECT name AS Name, date AS Date, time AS Time FROM toDoList WHERE completed = 'yes'");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_toDo->setModel(modal);
    connectionClose();
    qDebug() << (modal->rowCount());
}

void Homescreen::on_radioButton_uncompleted_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    connectionOpen();
    QSqlQuery* query = new QSqlQuery(plannerDB);
    query->prepare("SELECT name AS Name, date AS Date, time AS Time FROM toDoList WHERE completed = 'no'");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_toDo->setModel(modal);
    connectionClose();
    qDebug() << (modal->rowCount());
}

void Homescreen::on_pushButton_addToDo_clicked()
{
    ui->groupBox_addToDo->show();
    ui->groupBox_editToDo->hide();
}

void Homescreen::on_pushButton_insertToDo_clicked()
{
    QString toDoName = "", toDoDate = "", toDoTime = "", toDoCompleted = "no";
    QDate currentdate = QDate::currentDate();
    QDate enteredDate = ui->dateEdit_toDo->date();
    QTime currenttime = QTime::currentTime();
    QTime enteredTime = ui->timeEdit_toDo->time();
    toDoName = ui->lineEdit_toDoName->text();
    toDoDate = ui->dateEdit_toDo->text();
    toDoTime = ui->timeEdit_toDo->text();
    if(toDoName == "")
    {
        QMessageBox::warning(this,tr("Error"), tr("To-Do Name must be entered."));
    }
    else if(enteredDate < currentdate)
    {
        QMessageBox::warning(this,tr("Error"), tr("To-Do Date cannot be earlier than today." ));
    }
    else if((enteredDate == currentdate) && (enteredTime < currenttime))
    {
        QMessageBox::warning(this,tr("Error"), tr("To-Do Time cannot be earlier than current Time." ));
    }
    else
    {
        connectionOpen();
        QSqlQuery query;
        int rowCount = 0;
        query.prepare("SELECT COUNT(*) FROM toDoList WHERE name = :toDoName");
        query.bindValue(":toDoName", toDoName);
        query.exec();
        while(query.next())
            rowCount = query.value(0).toInt();
        connectionClose();
        if(rowCount == 1)
        {
            QMessageBox::warning(this,tr("Error"), tr("A To-Do Item with this name already exists. Please enter a new name."));
        }
        else
        {
            connectionOpen();
            QSqlQuery query;

            query.prepare("INSERT INTO toDoList (name, date, time, completed) VALUES (:toDoName, :toDoDate, :toDoTime, :toDoCompleted)");
            query.bindValue(":toDoName", toDoName);
            query.bindValue(":toDoDate", toDoDate);
            query.bindValue(":toDoTime", toDoTime);
            query.bindValue(":toDoCompleted", toDoCompleted);
            if(query.exec())
            {
                connectionClose();
                ui->lineEdit_toDoName->setText("");
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
        }
    }
    reloadToDoTable();
}

void Homescreen::on_dateEdit_toDo_editingFinished()
{
    QDate currentdate = QDate::currentDate();
    QDate enteredDate = ui->dateEdit_toDo->date();
    if(currentdate == enteredDate)
    {
        QTime currenttime = QTime::currentTime();
        ui->timeEdit_toDo->setTime(currenttime);
    }
}

void Homescreen::on_pushButton_editToDo_clicked()
{
    ui->groupBox_addToDo->hide();
    ui->groupBox_editToDo->show();
}

void Homescreen::on_pushButton_deleteToDo_clicked()
{
    ui->groupBox_addToDo->hide();
    ui->groupBox_editToDo->hide();
    QString toDoName = "";

    int rowNum = ui->tableView_toDo->selectionModel()->currentIndex().row();
    toDoName = ui->tableView_toDo->model()->data(ui->tableView_toDo->model()->index(rowNum, 0)).toString();
    connectionOpen();
    QSqlQuery query;

    query.prepare("DELETE FROM toDoList WHERE name = :toDoName");
    query.bindValue(":toDoName", toDoName);
    if(!query.exec())
        QMessageBox::critical(this,tr("Error."),query.lastError().text());
    connectionClose();
    reloadToDoTable();

}

void Homescreen::on_tableView_toDo_clicked(const QModelIndex &index)
{
    QString toDoName = "";
    QString toDoDate = "", toDoTime = "";

    int rowNum = ui->tableView_toDo->selectionModel()->currentIndex().row();
    toDoName = ui->tableView_toDo->model()->data(ui->tableView_toDo->model()->index(rowNum, 0)).toString();
    ui->lineEdit_toDoName_2->setText(toDoName);
    connectionOpen();
    QSqlQuery query;

    query.prepare("SELECT name, date, time FROM toDoList WHERE name = :toDoName");
    query.bindValue(":toDoName", toDoName);
    if(!query.exec())
        QMessageBox::critical(this,tr("Error."),query.lastError().text());
    while(query.next())
    {
        toDoName = query.value(0).toString();
        toDoDate = query.value(1).toString();
        toDoTime = query.value(2).toString();
    }
    connectionClose();
    QDate date_toDoDate = QDate::currentDate();
    ui->lineEdit_toDoName_2->setText(toDoName);
    ui->dateEdit_toDo_2->setDate(date_toDoDate);
}

void Homescreen::on_pushButton_toDoCompleted_clicked()
{
    QString toDoName = "";

    int rowNum = ui->tableView_toDo->selectionModel()->currentIndex().row();
    toDoName = ui->tableView_toDo->model()->data(ui->tableView_toDo->model()->index(rowNum, 0)).toString();

    connectionOpen();
    QSqlQuery query;

    query.prepare("UPDATE toDoList SET completed = 'yes' WHERE name = :toDoName");
    query.bindValue(":toDoName", toDoName);
    query.exec();
    connectionClose();
    reloadToDoTable();
}

void Homescreen::on_pushButton_toDoUncompleted_clicked()
{
    QString toDoName = "";

    int rowNum = ui->tableView_toDo->selectionModel()->currentIndex().row();
    toDoName = ui->tableView_toDo->model()->data(ui->tableView_toDo->model()->index(rowNum, 0)).toString();

    connectionOpen();
    QSqlQuery query;

    query.prepare("UPDATE toDoList SET completed = 'no' WHERE name = :toDoName");
    query.bindValue(":toDoName", toDoName);
    query.exec();
    connectionClose();
    reloadToDoTable();
}

void Homescreen::on_pushButton_updateToDo_clicked()
{
    QString toDoName = "", toDoDate = "", toDoTime = "", toDoCompleted = "no";
    QDate currentdate = QDate::currentDate();
    QDate enteredDate = ui->dateEdit_toDo->date();
    QTime currenttime = QTime::currentTime();
    QTime enteredTime = ui->timeEdit_toDo->time();
    toDoName = ui->lineEdit_toDoName->text();
    toDoDate = ui->dateEdit_toDo->text();
    toDoTime = ui->timeEdit_toDo->text();
    if(toDoName == "")
    {
        QMessageBox::warning(this,tr("Error"), tr("To-Do Name must be entered."));
    }
    else if(enteredDate < currentdate)
    {
        QMessageBox::warning(this,tr("Error"), tr("To-Do Date cannot be earlier than today." ));
    }
    else if((enteredDate == currentdate) && (enteredTime < currenttime))
    {
        QMessageBox::warning(this,tr("Error"), tr("To-Do Time cannot be earlier than current Time." ));
    }
    else
    {
        connectionOpen();
        QSqlQuery query;
        int rowCount = 0;
        query.prepare("SELECT COUNT(*) FROM toDoList WHERE name = :toDoName");
        query.bindValue(":toDoName", toDoName);
        query.exec();
        while(query.next())
            rowCount = query.value(0).toInt();
        connectionClose();
        if(rowCount == 1)
        {
            QMessageBox::warning(this,tr("Error"), tr("A To-Do Item with this name already exists. Please enter a new name."));
        }
        else
        {
            connectionOpen();
            QSqlQuery query;

            query.prepare("UPDATE toDoList SET date = :toDoDate, time = :toDoTime WHERE name = :toDoName ");
            query.bindValue(":toDoName", toDoName);
            query.bindValue(":toDoDate", toDoDate);
            query.bindValue(":toDoTime", toDoTime);
            query.bindValue(":toDoCompleted", toDoCompleted);
            if(query.exec())
            {
                connectionClose();
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),query.lastError().text());
            }
        }
    }
    reloadToDoTable();
}

void Homescreen::reloadToDoTable()
{
    if(ui->radioButton_viewAll->isChecked())
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        connectionOpen();
        QSqlQuery* query = new QSqlQuery(plannerDB);
        query->prepare("SELECT name AS Name, date AS Date, time AS Time, completed FROM toDoList");
        query->exec();
        modal->setQuery(*query);
        ui->tableView_toDo->setModel(modal);
        connectionClose();
        qDebug() << (modal->rowCount());
    }
    if(ui->radioButton_completed->isChecked())
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        connectionOpen();
        QSqlQuery* query = new QSqlQuery(plannerDB);
        query->prepare("SELECT name AS Name, date AS Date, time AS Time FROM toDoList WHERE completed = 'yes'");
        query->exec();
        modal->setQuery(*query);
        ui->tableView_toDo->setModel(modal);
        connectionClose();
        qDebug() << (modal->rowCount());
    }
    if(ui->radioButton_uncompleted->isChecked())
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        connectionOpen();
        QSqlQuery* query = new QSqlQuery(plannerDB);
        query->prepare("SELECT name AS Name, date AS Date, time AS Time FROM toDoList WHERE completed = 'no'");
        query->exec();
        modal->setQuery(*query);
        ui->tableView_toDo->setModel(modal);
        connectionClose();
        qDebug() << (modal->rowCount());
    }
}
void Homescreen::on_pushButton_deleteCourse_clicked()
{
    ui->groupBox_courses->hide();
    ui->groupBox_confirmDelete->show();
    ui->label_courseDelete->setText(ui->comboBox_courses->currentText());
}

void Homescreen::on_pushButton_deleteCourse_2_clicked()
{
    QString courseNumDelete = ui->comboBox_courses->currentText();
    connectionOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM courses WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumDelete);
    query.exec();
    query.prepare("DELETE FROM courseTimes WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumDelete);
    query.exec();
    query.prepare("DELETE FROM assignment WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumDelete);
    query.exec();
    query.prepare("DELETE FROM weightedGrades WHERE courseName = :courseNumber");
    query.bindValue(":courseNumber", courseNumDelete);
    query.exec();

    ui->groupBox_courses->show();
    ui->groupBox_confirmDelete->hide();

    QMessageBox::warning(this,tr("Course Deleted"), tr("Your course has been deleted."));

    refreshCourseList();
}

void Homescreen::on_pushButton_cancel_clicked()
{
    ui->groupBox_courses->show();
    ui->groupBox_confirmDelete->hide();
}

void Homescreen::refreshCourseList()
{
    connectionOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(plannerDB);
    query->prepare("Select courseNumber from courses");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_courses->setModel(modal);
    connectionClose();
    qDebug() << (modal->rowCount());
}
