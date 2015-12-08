#include "addassignment.h"
#include "ui_addassignment.h"
#include "homescreen.h"

addAssignment::addAssignment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAssignment)
{
    ui->setupUi(this);
    Homescreen conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connectionOpen();
    QSqlQuery* query = new QSqlQuery(conn.plannerDB);
    query->prepare("SELECT courseNumber FROM courses");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_courses->setModel(modal);
    conn.connectionClose();
    qDebug() << (modal->rowCount());

    ui->checkBox_pointsEarned->setChecked(true);
    ui->doubleSpinBox_pointsEarned->setEnabled(true);
    ui->checkBox_percentage->setChecked(false);
    ui->doubleSpinBox_percentage->setEnabled(false);
}

addAssignment::~addAssignment()
{
    delete ui;
}

void addAssignment::on_checkBox_pointsEarned_clicked()
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

void addAssignment::on_checkBox_percentage_clicked()
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
void addAssignment::on_pushButton_cancel_clicked()
{
    this->close();
}

void addAssignment::on_pushButton_saveAssignment_clicked()
{
    Homescreen conn;

    QString courseNumber = ui->comboBox_courses->currentText();
    QString assignmentName = ui->lineEdit_name->text();
    QString assignmentCategory = ui->comboBox_categories->currentText();
    double pointsPossible = ui->doubleSpinBox_pointsPossible->value();
    double pointsEarned = 0;
    if(ui->checkBox_percentage->isChecked())
    {
        double percentage = ui->doubleSpinBox_percentage->value();
        pointsEarned = (percentage / 100) * pointsPossible;
    }
    else
        pointsEarned = ui->doubleSpinBox_pointsEarned->value();

    conn.connectionOpen();                                  //opens database
    if(!conn.connectionOpen())                              //checks for connection to database
    {
        qDebug()<<"Failed to open database";
        return;
    }

    QSqlQuery query;
    //insert query for event information
    query.prepare("INSERT INTO assignment (courseNumber, assignmentName, assignmentCategory, pointsEarned, pointsPossible) VALUES (:courseNumber, :assignmentName, :assignmentCategory, :pointsEarned, :pointsPossible)");
    query.bindValue(":courseNumber", courseNumber);
    query.bindValue(":assignmentName", assignmentName);
    query.bindValue(":assignmentCategory", assignmentCategory);
    query.bindValue(":pointsEarned", pointsEarned);
    query.bindValue(":pointsPossible", pointsPossible);

    query.exec();

    conn.connectionClose();
    this->close();
}

void addAssignment::on_comboBox_courses_currentTextChanged(const QString &arg1)
{
    Homescreen conn;
    conn.connectionOpen();
    QString courseNumber = ui->comboBox_courses->currentText();
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
        ui->comboBox_categories->setEnabled(true);

        query.prepare("SELECT category1Name, category2Name, category3Name, category4Name, category5Name, category6Name, category7Name FROM weightedGrades WHERE courseName = :courseNumber");
        query.bindValue(":courseNumber", courseNumber);
        query.exec();
        QString cat1Name = query.value(0).toString();
        QString cat2Name = query.value(1).toString();
        QString cat3Name = query.value(2).toString();
        QString cat4Name = query.value(3).toString();
        QString cat5Name = query.value(4).toString();
        QString cat6Name = query.value(5).toString();
        QString cat7Name = query.value(6).toString();
        ui->comboBox_categories->addItem(cat1Name);
        ui->comboBox_categories->addItem(cat1Name);
        ui->comboBox_categories->addItem(cat2Name);
        ui->comboBox_categories->addItem(cat3Name);
        ui->comboBox_categories->addItem(cat4Name);
        ui->comboBox_categories->addItem(cat5Name);
        ui->comboBox_categories->addItem(cat6Name);
        ui->comboBox_categories->addItem(cat7Name);
        conn.connectionClose();
    }
    conn.connectionClose();
}
