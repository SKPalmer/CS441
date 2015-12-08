#include "assignments.h"
#include "ui_assignments.h"
#include "homescreen.h"
#include <QWidget>

assignments::assignments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assignments)
{
    ui->setupUi(this);

    //Populates Grades Table
    Homescreen conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connectionOpen();
    QSqlQuery* query = new QSqlQuery(conn.plannerDB);
    query->prepare("SELECT courseNumber FROM courses");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_courses->setModel(modal);
    ui->comboBox_courses_2->setModel(modal);
    conn.connectionClose();
    qDebug() << (modal->rowCount());

    //Add/Edit Assignments Groupbox
    ui->groupBox_editAssignment->hide();
    ui->groupBox_addAssignment->show();
    ui->groupBox_deleteAssignment->hide();

    //Add Assignment Groupbox
    ui->checkBox_pointsEarned->setChecked(true);
    ui->doubleSpinBox_pointsEarned->setEnabled(true);
    ui->checkBox_percentage->setChecked(false);
    ui->doubleSpinBox_percentage->setEnabled(false);

    //Edit Assignment Groupbox
    ui->checkBox_pointsEarned_2->setChecked(true);
    ui->doubleSpinBox_pointsEarned_2->setEnabled(true);
    ui->checkBox_percentage_2->setChecked(false);
    ui->doubleSpinBox_percentage_2->setEnabled(false);
}

assignments::~assignments()
{
    delete ui;
}

void assignments::on_pushButton_addAssignment_clicked()
{
    ui->groupBox_editAssignment->hide();
    ui->groupBox_addAssignment->show();
}

void assignments::on_pushButton_editAssignment_clicked()
{
    ui->groupBox_addAssignment->hide();
    ui->groupBox_editAssignment->show();
}

void assignments::on_comboBox_courses_currentTextChanged(const QString &arg1)
{
    Homescreen conn;
    QString courseNumber = ui->comboBox_courses->currentText();
    QString gradeType;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connectionOpen();
    QSqlQuery* query = new QSqlQuery(conn.plannerDB);
    query->prepare("SELECT grading FROM courses WHERE courseNumber = :courseNumber");
    query->bindValue(":courseNumber", courseNumber);
    query->exec();
    while(query->next())
        gradeType = query->value(0).toString();
    if(gradeType == "weighted")
    {
        query->prepare("SELECT assignmentName AS Assignment, assignmentCategory AS Category, pointsEarned AS Grade, pointsPossible AS Possible FROM assignment WHERE courseNumber = :courseNumber ");
        query->bindValue(":courseNumber", courseNumber);
        query->exec();
        modal->setQuery(*query);
        ui->tableView_assignments->setModel(modal);
        conn.connectionClose();
        qDebug() << (modal->rowCount());
    }
    else
    {
        query->prepare("SELECT assignmentName AS Assignment, pointsEarned AS Grade, pointsPossible AS Possible FROM assignment WHERE courseNumber = :courseNumber ");
        query->bindValue(":courseNumber", courseNumber);
        query->exec();
        modal->setQuery(*query);
        ui->tableView_assignments->setModel(modal);
        conn.connectionClose();
        qDebug() << (modal->rowCount());
    }
}

void assignments::on_checkBox_pointsEarned_clicked()
{
    if(ui->checkBox_pointsEarned->isChecked())
    {
        ui->checkBox_percentage->setChecked(false);
        ui->doubleSpinBox_percentage->setEnabled(false);
        ui->doubleSpinBox_pointsEarned->setEnabled(true);
    }
    else
    {
        ui->checkBox_pointsEarned->setChecked(true);
        ui->doubleSpinBox_pointsEarned->setEnabled(true);
    }
}

void assignments::on_checkBox_percentage_clicked()
{
    if(ui->checkBox_percentage->isChecked())
    {
        ui->checkBox_pointsEarned->setChecked(false);
        ui->doubleSpinBox_pointsEarned->setEnabled(false);
        ui->doubleSpinBox_percentage->setEnabled(true);
    }
    else
    {
        ui->checkBox_percentage->setChecked(true);
        ui->doubleSpinBox_percentage->setEnabled(true);
    }
}

void assignments::on_checkBox_pointsEarned_2_clicked()
{
    if(ui->checkBox_pointsEarned_2->isChecked())
    {
        ui->checkBox_percentage_2->setChecked(false);
        ui->doubleSpinBox_percentage_2->setEnabled(false);
        ui->doubleSpinBox_pointsEarned_2->setEnabled(true);
    }
    else
    {
        ui->checkBox_pointsEarned_2->setChecked(true);
        ui->doubleSpinBox_pointsEarned_2->setEnabled(true);
    }
}

void assignments::on_checkBox_percentage_2_clicked()
{
    if(ui->checkBox_percentage_2->isChecked())
    {
        ui->checkBox_pointsEarned_2->setChecked(false);
        ui->doubleSpinBox_pointsEarned_2->setEnabled(false);
        ui->doubleSpinBox_percentage_2->setEnabled(true);
    }
    else
    {
        ui->checkBox_percentage_2->setChecked(true);
        ui->doubleSpinBox_percentage_2->setEnabled(true);
    }
}

void assignments::on_tableView_assignments_clicked(const QModelIndex &index)
{
    Homescreen conn;
    if(!conn.connectionOpen())                              //checks for connection to database
        conn.connectionClose();
    QString assignmentName, additionalInfo, assignmentCategory, gradeType;
    double  pointsEarned, pointsPossible;
    ui->comboBox_categories_2->clear();

    int rowNum = ui->tableView_assignments->currentIndex().row();
    QString rowNum2 = QString::number(rowNum);
    assignmentName = ui->tableView_assignments->model()->data(ui->tableView_assignments->model()->index(rowNum, 0)).toString();

    QString courseNumber = ui->comboBox_courses->currentText();
    conn.connectionOpen();
    QSqlQuery query;

    query.prepare("SELECT grading FROM courses WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumber);
    if(!query.exec())
        QMessageBox::critical(this,tr("first."),query.lastError().text());
    while(query.next())
        gradeType = query.value(0).toString();
    conn.connectionClose();

    if(gradeType == "pointBased")
    {
        conn.connectionOpen();
        QSqlQuery query;
        query.prepare("SELECT pointsEarned, pointsPossible, additionalInfo FROM assignment WHERE courseNumber = :courseNumber AND assignmentName = :assignmentName");
        query.bindValue(":courseNumber", courseNumber);
        query.bindValue(":assignmentName", assignmentName);
        if(!query.exec())
            QMessageBox::critical(this,tr("second."),query.lastError().text());

        while(query.next())
        {
            pointsEarned = query.value(0).toDouble();
            pointsPossible = query.value(1).toDouble();
            additionalInfo = query.value(2).toString();
        }
        conn.connectionClose();
        ui->comboBox_categories_2->setEnabled(false);
        ui->lineEdit_courseNumber->setText(courseNumber);
        ui->lineEdit_name_2->setText(assignmentName);
        ui->doubleSpinBox_pointsEarned_2->setValue(pointsEarned);
        ui->doubleSpinBox_pointsPossible_2->setValue(pointsPossible);
        ui->textEdit_additional_2->setText(additionalInfo);
    }
    else
    {
        ui->comboBox_categories_2->setEnabled(true);
        courseNumber = ui->comboBox_courses->currentText();
        conn.connectionOpen();
        QSqlQuery query;
        query.prepare("SELECT category1Name, category2Name, category3Name, category4Name, category5Name, category6Name, category7Name FROM weightedGrades WHERE courseName = :courseNumber");
        query.bindValue(":courseNumber", courseNumber);
        if(!query.exec())
            QMessageBox::critical(this,tr("third."),query.lastError().text());

        while(query.next())
        {
            QString cat1Name = query.value(0).toString();
            QString cat2Name = query.value(1).toString();
            QString cat3Name = query.value(2).toString();
            QString cat4Name = query.value(3).toString();
            QString cat5Name = query.value(4).toString();
            QString cat6Name = query.value(5).toString();
            QString cat7Name = query.value(6).toString();
            if(cat1Name != "")
                ui->comboBox_categories_2->addItem(cat1Name, 1);
            if(cat2Name != "")
                ui->comboBox_categories_2->addItem(cat2Name, 2);
            if(cat3Name != "")
                ui->comboBox_categories_2->addItem(cat3Name, 3);
            if(cat4Name != "")
                ui->comboBox_categories_2->addItem(cat4Name, 4);
            if(cat5Name != "")
                ui->comboBox_categories_2->addItem(cat5Name, 5);
            if(cat6Name != "")
                ui->comboBox_categories_2->addItem(cat6Name, 6);
            if(cat7Name != "")
                ui->comboBox_categories_2->addItem(cat7Name, 7);
        }

        //courseNumber = ui->comboBox_courses->currentText();
        //int catIndex = ui->comboBox_categories_2->findText(assignmentCategory);
        //ui->comboBox_categories_2->setCurrentIndex(catIndex);
        query.prepare("SELECT assignmentCategory, pointsEarned, pointsPossible, additionalInfo FROM assignment WHERE courseNumber = :courseNumber AND assignmentName = :assignmentName");
        query.bindValue(":courseNumber", courseNumber);
        query.bindValue(":assignmentName", assignmentName);
        if(!query.exec())
            QMessageBox::critical(this,tr("fourth."),query.lastError().text());

        while(query.next())
        {
            assignmentCategory = query.value(0).toString();
            pointsEarned = query.value(1).toDouble();
            pointsPossible = query.value(2).toDouble();
            additionalInfo = query.value(3).toString();
        }
        conn.connectionClose();
        ui->lineEdit_courseNumber->setText(courseNumber);
        ui->lineEdit_name_2->setText(assignmentName);
        ui->doubleSpinBox_pointsEarned_2->setValue(pointsEarned);
        ui->doubleSpinBox_pointsPossible_2->setValue(pointsPossible);
        ui->textEdit_additional_2->setText(additionalInfo);
    }

}

void assignments::on_pushButton_saveAssignment_clicked()
{
    Homescreen conn;

    QString courseNumber = ui->comboBox_courses_2->currentText();
    QString assignmentName = ui->lineEdit_name->text();
    QString assignmentCategory = ui->comboBox_categories->currentText();
    QString additionalInfo = ui->textEdit_additional->toPlainText();
    double pointsPossible = ui->doubleSpinBox_pointsPossible->value();
    double pointsEarned = 0;
    if(ui->checkBox_percentage->isChecked())
    {
        double percentage = ui->doubleSpinBox_percentage->value();
        pointsEarned = (percentage / 100) * pointsPossible;
    }
    else
        pointsEarned = ui->doubleSpinBox_pointsEarned->value();

    conn.connectionOpen();
    //opens database
    if(!conn.connectionOpen())                              //checks for connection to database
    {
        qDebug()<<"Failed to open database";
        return;
    }
    if(assignmentName == "" || pointsEarned == 0)
    {
        QMessageBox::warning(this,tr("Error"), tr("All fields required except additional information."));
    }
    else
    {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM assignment WHERE courseNumber = :courseNumber AND assignmentName = :assignmentName");
        query.bindValue(":courseNumber", courseNumber);
        query.bindValue(":assignmentName", assignmentName);
        query.exec();
        int rowCount = 0;
        while(query.next())
            rowCount = query.value(0).toInt();
        if(rowCount == 1)
        {
            QMessageBox::warning(this,tr("Error"), tr("An assignment with this name already exists. Please enter a new name."));
        }
        else
        {
            //insert query for event information
            query.prepare("INSERT INTO assignment (courseNumber, assignmentName, assignmentCategory, pointsEarned, pointsPossible, additionalInfo) VALUES (:courseNumber, :assignmentName, :assignmentCategory, :pointsEarned, :pointsPossible, :additionalInfo)");
            query.bindValue(":courseNumber", courseNumber);
            query.bindValue(":assignmentName", assignmentName);
            query.bindValue(":assignmentCategory", assignmentCategory);
            query.bindValue(":pointsEarned", pointsEarned);
            query.bindValue(":pointsPossible", pointsPossible);
            query.bindValue(":additionalInfo", additionalInfo);

            query.exec();
        }
    }
    conn.connectionClose();
}


void assignments::on_comboBox_courses_2_currentTextChanged(const QString &arg1)
{
    Homescreen conn;
    conn.connectionOpen();
    ui->comboBox_categories->clear();
    QString courseNumber = ui->comboBox_courses_2->currentText();
    QSqlQuery query;
    query.prepare("SELECT grading FROM courses WHERE courseNumber = :courseNumber");
    query.bindValue(":courseNumber", courseNumber);
    query.exec();
    conn.connectionClose();
    QString gradeType;
    while(query.next())
        gradeType = query.value(0).toString();

    if(gradeType == "pointBased")
    {
        ui->comboBox_categories->setEnabled(false);
    }
    else
    {
        conn.connectionOpen();
        QSqlQuery query;
        ui->comboBox_categories->clear();
        ui->comboBox_categories->setEnabled(true);
        query.prepare("SELECT category1Name, category2Name, category3Name, category4Name, category5Name, category6Name, category7Name FROM weightedGrades WHERE courseName = :courseNumber");
        query.bindValue(":courseNumber", courseNumber);
        if(!query.exec())
            QMessageBox::critical(this,tr("xxxxxxx."),query.lastError().text());

        while(query.next())
        {
            QString cat1Name = query.value(0).toString();
            QString cat2Name = query.value(1).toString();
            QString cat3Name = query.value(2).toString();
            QString cat4Name = query.value(3).toString();
            QString cat5Name = query.value(4).toString();
            QString cat6Name = query.value(5).toString();
            QString cat7Name = query.value(6).toString();
            if(cat1Name != "")
                ui->comboBox_categories->addItem(cat1Name, 1);
            if(cat2Name != "")
                ui->comboBox_categories->addItem(cat2Name, 2);
            if(cat3Name != "")
                ui->comboBox_categories->addItem(cat3Name, 3);
            if(cat4Name != "")
                ui->comboBox_categories->addItem(cat4Name, 4);
            if(cat5Name != "")
                ui->comboBox_categories->addItem(cat5Name, 5);
            if(cat6Name != "")
                ui->comboBox_categories->addItem(cat6Name, 6);
            if(cat7Name != "")
                ui->comboBox_categories->addItem(cat7Name, 7);
        }
    }
    conn.connectionClose();
}

void assignments::on_pushButton_saveAssignment_2_clicked()
{
    Homescreen conn;

    QString courseNumber = ui->lineEdit_courseNumber->text();
    QString assignmentName = ui->lineEdit_name_2->text();
    QString assignmentCategory = ui->comboBox_categories_2->currentText();
    QString additionalInfo = ui->textEdit_additional_2->toPlainText();

    double pointsPossible = ui->doubleSpinBox_pointsPossible_2->value();
    double pointsEarned = 0;
    if(ui->checkBox_percentage_2->isChecked())
    {
        double percentage = ui->doubleSpinBox_percentage_2->value();
        pointsEarned = (percentage / 100) * pointsPossible;
    }
    else
        pointsEarned = ui->doubleSpinBox_pointsEarned_2->value();

    conn.connectionOpen();
    //opens database
    if(!conn.connectionOpen())                              //checks for connection to database
    {
        qDebug()<<"Failed to open database";
        return;
    }
    if(assignmentName == "" || pointsEarned == 0)
    {
        QMessageBox::warning(this,tr("Error"), tr("All fields required except additional information."));
    }
    else
    {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM assignments WHERE courseNumber = :courseNumber AND assignmentName = :assignmentName");
        query.bindValue(":courseNumber", courseNumber);
        query.bindValue(":assignmentName", assignmentName);
        query.exec();
        int rowCount = 0;
        while(query.next())
            rowCount = query.value(0).toInt();
        if(rowCount == 1)
        {
            QMessageBox::warning(this,tr("Error"), tr("A To-Do Item with this name already exists. Please enter a new name."));
        }
        else
        {
            //insert query for event information
            query.prepare("UPDATE assignment SET assignmentCategory = :assignmentCategory, pointsEarned = :pointsEarned, pointsPossible = :pointsPossible, additionalInfo = :additionalInfo WHERE courseNumber = :courseNumber AND assignmentName = :assignmentName");
            query.bindValue(":courseNumber", courseNumber);
            query.bindValue(":assignmentName", assignmentName);
            query.bindValue(":assignmentCategory", assignmentCategory);
            query.bindValue(":pointsEarned", pointsEarned);
            query.bindValue(":pointsPossible", pointsPossible);
            query.bindValue(":additionalInfo", additionalInfo);

            if(!query.exec())
                QMessageBox::warning(this,tr("Error"), tr("A To-Do Item with this name already exists. Please enter a new name."));

        }
    }
    conn.connectionClose();
}

void assignments::on_pushButton_deleteAssignment_clicked()
{
    ui->groupBox_deleteAssignment->show();
    ui->groupBox_addAssignment->hide();
    ui->groupBox_editAssignment->hide();
}

void assignments::on_pushButton_cancel_2_clicked()
{
    ui->groupBox_deleteAssignment->hide();
    ui->groupBox_addAssignment->show();
    ui->groupBox_editAssignment->hide();
}

void assignments::on_pushButton_cancel_clicked()
{
    ui->lineEdit_name->clear();
    ui->doubleSpinBox_percentage->clear();
    ui->doubleSpinBox_pointsEarned->clear();
    ui->doubleSpinBox_pointsPossible->clear();
    ui->textEdit_additional->clear();
}

void assignments::on_pushButton_clicked()
{
    QString courseNumber = ui->comboBox_courses->currentText();
    int rowNum = ui->tableView_assignments->currentIndex().row();
    QString assignmentName = ui->tableView_assignments->model()->data(ui->tableView_assignments->model()->index(rowNum, 0)).toString();
    Homescreen conn;
    conn.connectionOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM assignment WHERE courseNumber = :courseNumber AND assignmentName = :assignmentName");
    query.bindValue(":courseNumber", courseNumber);
    query.bindValue(":assignmentName", assignmentName);
    query.exec();
    refreshAssignmentTable();
    QMessageBox::warning(this,tr("Confirm"), tr("This Assignment has been deleted."));

}

void assignments::refreshAssignmentTable()
{
    Homescreen conn;
    QString courseNumber = ui->comboBox_courses->currentText();
    QString gradeType;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connectionOpen();
    QSqlQuery* query = new QSqlQuery(conn.plannerDB);
    query->prepare("SELECT grading FROM courses WHERE courseNumber = :courseNumber");
    query->bindValue(":courseNumber", courseNumber);
    query->exec();
    while(query->next())
        gradeType = query->value(0).toString();
    if(gradeType == "weighted")
    {
        query->prepare("SELECT assignmentName AS Assignment, assignmentCategory AS Category, pointsEarned AS Grade, pointsPossible AS Possible FROM assignment WHERE courseNumber = :courseNumber ");
        query->bindValue(":courseNumber", courseNumber);
        query->exec();
        modal->setQuery(*query);
        ui->tableView_assignments->setModel(modal);
        conn.connectionClose();
        qDebug() << (modal->rowCount());
    }
    else
    {
        query->prepare("SELECT assignmentName AS Assignment, pointsEarned AS Grade, pointsPossible AS Possible FROM assignment WHERE courseNumber = :courseNumber ");
        query->bindValue(":courseNumber", courseNumber);
        query->exec();
        modal->setQuery(*query);
        ui->tableView_assignments->setModel(modal);
        conn.connectionClose();
        qDebug() << (modal->rowCount());
    }
}
