#include "addcourse.h"
#include "ui_addcourse.h"
#include "homescreen.h"

addCourse::addCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCourse)
{
    ui->setupUi(this);
    Homescreen conn;
    //grading groupBox initial set
    ui->checkBox_pointBased->setChecked(true);

    //Days/Times lineEdits initial set

    ui->timeEdit_SunStart->setEnabled(false);
    ui->timeEdit_SunEnd->setEnabled(false);
    ui->timeEdit_MonStart->setEnabled(false);
    ui->timeEdit_MonEnd->setEnabled(false);
    ui->timeEdit_TuesStart->setEnabled(false);
    ui->timeEdit_TuesEnd->setEnabled(false);
    ui->timeEdit_WedStart->setEnabled(false);
    ui->timeEdit_WedEnd->setEnabled(false);
    ui->timeEdit_ThursStart->setEnabled(false);
    ui->timeEdit_ThursEnd->setEnabled(false);
    ui->timeEdit_FriStart->setEnabled(false);
    ui->timeEdit_FriEnd->setEnabled(false);
    ui->timeEdit_SatStart->setEnabled(false);
    ui->timeEdit_SatEnd->setEnabled(false);

    //category lineEdits/spinBoxes setEnabled(false) default
    ui->lineEdit_category1->setEnabled(false);
    ui->lineEdit_category2->setEnabled(false);
    ui->lineEdit_category3->setEnabled(false);
    ui->lineEdit_category4->setEnabled(false);
    ui->lineEdit_category5->setEnabled(false);
    ui->lineEdit_category6->setEnabled(false);
    ui->lineEdit_category7->setEnabled(false);

    ui->spinBox_category1->setEnabled(false);
    ui->spinBox_category2->setEnabled(false);
    ui->spinBox_category3->setEnabled(false);
    ui->spinBox_category4->setEnabled(false);
    ui->spinBox_category5->setEnabled(false);
    ui->spinBox_category6->setEnabled(false);
    ui->spinBox_category7->setEnabled(false);

    ui->checkBox_category2->setEnabled(false);
    ui->checkBox_category3->setEnabled(false);
    ui->checkBox_category4->setEnabled(false);
    ui->checkBox_category5->setEnabled(false);
    ui->checkBox_category6->setEnabled(false);
    ui->checkBox_category7->setEnabled(false);


    ui->errorLabel->setText("");                        //error message will not initially show
}

addCourse::~addCourse()
{
    delete ui;
}

void addCourse::on_groupBox_weighted_clicked()
{
    if(ui->groupBox_weighted->isChecked())
    {
        ui->checkBox_pointBased->setChecked(false);
    }
    else
    {
        ui->checkBox_pointBased->setChecked(true);
    }
}

void addCourse::on_checkBox_pointBased_clicked()
{

    if(ui->checkBox_pointBased->isChecked())
    {
        ui->groupBox_weighted->setChecked(false);
    }
    else
    {
        ui->groupBox_weighted->setChecked(true);
    }
}


void addCourse::on_checkBox_Sunday_clicked()
{
    if(ui->checkBox_Sunday->isChecked())
    {
        ui->timeEdit_SunStart->setEnabled(true);
        ui->timeEdit_SunEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_SunStart->setEnabled(false);
        ui->timeEdit_SunEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_Monday_clicked()
{
    if(ui->checkBox_Monday->isChecked())
    {
        ui->timeEdit_MonStart->setEnabled(true);
        ui->timeEdit_MonEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_MonStart->setEnabled(false);
        ui->timeEdit_MonEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_Tuesday_clicked()
{
    if(ui->checkBox_Tuesday->isChecked())
    {
        ui->timeEdit_TuesStart->setEnabled(true);
        ui->timeEdit_TuesEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_TuesStart->setEnabled(false);
        ui->timeEdit_TuesEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_Wednesday_clicked()
{
    if(ui->checkBox_Wednesday->isChecked())
    {
        ui->timeEdit_WedStart->setEnabled(true);
        ui->timeEdit_WedEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_WedStart->setEnabled(false);
        ui->timeEdit_WedEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_Thursday_clicked()
{
    if(ui->checkBox_Thursday->isChecked())
    {
        ui->timeEdit_ThursStart->setEnabled(true);
        ui->timeEdit_ThursEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_ThursStart->setEnabled(false);
        ui->timeEdit_ThursEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_Friday_clicked()
{
    if(ui->checkBox_Friday->isChecked())
    {
        ui->timeEdit_FriStart->setEnabled(true);
        ui->timeEdit_FriEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_FriStart->setEnabled(false);
        ui->timeEdit_FriEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_Saturday_clicked()
{
    if(ui->checkBox_Saturday->isChecked())
    {
        ui->timeEdit_SatStart->setEnabled(true);
        ui->timeEdit_SatEnd->setEnabled(true);
    }
    else
    {
        ui->timeEdit_SatStart->setEnabled(false);
        ui->timeEdit_SatEnd->setEnabled(false);
    }
}

void addCourse::on_checkBox_category1_clicked()
{
    if(ui->checkBox_category1->isChecked())
    {
        ui->checkBox_category1->setText("1*");
        ui->lineEdit_category1->setEnabled(true);
        ui->spinBox_category1->setEnabled(true);
        ui->checkBox_category2->setEnabled(true);

    }
    else
    {
        //handles line edits
        ui->lineEdit_category1->setEnabled(false);
        ui->lineEdit_category1->setText("");
        ui->lineEdit_category2->setEnabled(false);
        ui->lineEdit_category2->setText("");
        ui->lineEdit_category3->setEnabled(false);
        ui->lineEdit_category3->setText("");
        ui->lineEdit_category4->setEnabled(false);
        ui->lineEdit_category4->setText("");
        ui->lineEdit_category5->setEnabled(false);
        ui->lineEdit_category5->setText("");
        ui->lineEdit_category6->setEnabled(false);
        ui->lineEdit_category6->setText("");
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");

        //handles higher checkboxes
        ui->checkBox_category2->setEnabled(false);
        ui->checkBox_category3->setEnabled(false);
        ui->checkBox_category4->setEnabled(false);
        ui->checkBox_category5->setEnabled(false);
        ui->checkBox_category6->setEnabled(false);
        ui->checkBox_category7->setEnabled(false);
        ui->checkBox_category2->setChecked(false);
        ui->checkBox_category3->setChecked(false);
        ui->checkBox_category4->setChecked(false);
        ui->checkBox_category5->setChecked(false);
        ui->checkBox_category6->setChecked(false);
        ui->checkBox_category7->setChecked(false);
        ui->checkBox_category1->setText("1");
        ui->checkBox_category2->setText("2");
        ui->checkBox_category3->setText("3");
        ui->checkBox_category4->setText("4");
        ui->checkBox_category5->setText("5");
        ui->checkBox_category6->setText("6");
        ui->checkBox_category7->setText("7");
        //handles spinbox values
        ui->spinBox_category1->setEnabled(false);
        ui->spinBox_category1->setValue(0);
        ui->spinBox_category2->setEnabled(false);
        ui->spinBox_category2->setValue(0);
        ui->spinBox_category3->setEnabled(false);
        ui->spinBox_category3->setValue(0);
        ui->spinBox_category4->setEnabled(false);
        ui->spinBox_category4->setValue(0);
        ui->spinBox_category5->setEnabled(false);
        ui->spinBox_category5->setValue(0);
        ui->spinBox_category6->setEnabled(false);
        ui->spinBox_category6->setValue(0);
        ui->spinBox_category7->setEnabled(false);
        ui->spinBox_category7->setValue(0);
    }

}

void addCourse::on_checkBox_category2_clicked()
{
    if(ui->checkBox_category2->isChecked())
    {
        ui->checkBox_category2->setText("2*");
        ui->lineEdit_category2->setEnabled(true);
        ui->spinBox_category2->setEnabled(true);
        ui->checkBox_category3->setEnabled(true);
    }
    else
    {
        //handles line edits
        ui->lineEdit_category2->setEnabled(false);
        ui->lineEdit_category2->setText("");
        ui->lineEdit_category3->setEnabled(false);
        ui->lineEdit_category3->setText("");
        ui->lineEdit_category4->setEnabled(false);
        ui->lineEdit_category4->setText("");
        ui->lineEdit_category5->setEnabled(false);
        ui->lineEdit_category5->setText("");
        ui->lineEdit_category6->setEnabled(false);
        ui->lineEdit_category6->setText("");
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");

        //handles higher checkboxes
        ui->checkBox_category3->setEnabled(false);
        ui->checkBox_category4->setEnabled(false);
        ui->checkBox_category5->setEnabled(false);
        ui->checkBox_category6->setEnabled(false);
        ui->checkBox_category7->setEnabled(false);
        ui->checkBox_category3->setChecked(false);
        ui->checkBox_category4->setChecked(false);
        ui->checkBox_category5->setChecked(false);
        ui->checkBox_category2->setText("2");
        ui->checkBox_category3->setText("3");
        ui->checkBox_category4->setText("4");
        ui->checkBox_category5->setText("5");
        ui->checkBox_category6->setText("6");
        ui->checkBox_category7->setText("7");

        //handles spinbox values
        ui->spinBox_category2->setEnabled(false);
        ui->spinBox_category3->setEnabled(false);
        ui->spinBox_category3->setValue(0);
        ui->spinBox_category4->setEnabled(false);
        ui->spinBox_category4->setValue(0);
        ui->spinBox_category5->setEnabled(false);
        ui->spinBox_category5->setValue(0);
        ui->spinBox_category6->setEnabled(false);
        ui->spinBox_category6->setValue(0);
        ui->spinBox_category7->setEnabled(false);
        ui->spinBox_category7->setValue(0);
    }
}

void addCourse::on_checkBox_category3_clicked()
{
    if(ui->checkBox_category3->isChecked())
    {
        ui->checkBox_category3->setText("3*");
        ui->lineEdit_category3->setEnabled(true);
        ui->spinBox_category3->setEnabled(true);
        ui->checkBox_category4->setEnabled(true);
    }
    else
    {
        //handles line edits
        ui->lineEdit_category3->setEnabled(false);
        ui->lineEdit_category3->setText("");
        ui->lineEdit_category4->setEnabled(false);
        ui->lineEdit_category4->setText("");
        ui->lineEdit_category5->setEnabled(false);
        ui->lineEdit_category5->setText("");
        ui->lineEdit_category6->setEnabled(false);
        ui->lineEdit_category6->setText("");
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");

        //handles higher checkboxes
        ui->checkBox_category4->setEnabled(false);
        ui->checkBox_category5->setEnabled(false);
        ui->checkBox_category6->setEnabled(false);
        ui->checkBox_category7->setEnabled(false);
        ui->checkBox_category4->setChecked(false);
        ui->checkBox_category5->setChecked(false);
        ui->checkBox_category6->setChecked(false);
        ui->checkBox_category7->setChecked(false);
        ui->checkBox_category3->setText("3");
        ui->checkBox_category4->setText("4");
        ui->checkBox_category5->setText("5");
        ui->checkBox_category6->setText("6");
        ui->checkBox_category7->setText("7");

        //handles spinbox values
        ui->spinBox_category3->setEnabled(false);
        ui->spinBox_category3->setValue(0);
        ui->spinBox_category4->setEnabled(false);
        ui->spinBox_category4->setValue(0);
        ui->spinBox_category5->setEnabled(false);
        ui->spinBox_category5->setValue(0);
        ui->spinBox_category6->setEnabled(false);
        ui->spinBox_category6->setValue(0);
        ui->spinBox_category7->setEnabled(false);
        ui->spinBox_category7->setValue(0);
    }
}

void addCourse::on_checkBox_category4_clicked()
{
    if(ui->checkBox_category4->isChecked())
    {
        ui->checkBox_category4->setText("4*");
        ui->lineEdit_category4->setEnabled(true);
        ui->spinBox_category4->setEnabled(true);
        ui->checkBox_category5->setEnabled(true);
    }
    else
    {
        //handles line edits
        ui->lineEdit_category4->setEnabled(false);
        ui->lineEdit_category4->setText("");
        ui->lineEdit_category5->setEnabled(false);
        ui->lineEdit_category5->setText("");
        ui->lineEdit_category6->setEnabled(false);
        ui->lineEdit_category6->setText("");
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");

        //handles higher checkboxes
        ui->checkBox_category5->setEnabled(false);
        ui->checkBox_category6->setEnabled(false);
        ui->checkBox_category7->setEnabled(false);
        ui->checkBox_category5->setChecked(false);
        ui->checkBox_category6->setChecked(false);
        ui->checkBox_category7->setChecked(false);
        ui->checkBox_category4->setText("4");
        ui->checkBox_category5->setText("5");
        ui->checkBox_category6->setText("6");
        ui->checkBox_category7->setText("7");

        //handles spinbox values
        ui->spinBox_category4->setEnabled(false);
        ui->spinBox_category4->setValue(0);
        ui->spinBox_category5->setEnabled(false);
        ui->spinBox_category5->setValue(0);
        ui->spinBox_category6->setEnabled(false);
        ui->spinBox_category6->setValue(0);
        ui->spinBox_category7->setEnabled(false);
        ui->spinBox_category7->setValue(0);
    }
}

void addCourse::on_checkBox_category5_clicked()
{
    if(ui->checkBox_category5->isChecked())
    {
        ui->checkBox_category5->setText("5*");
        ui->lineEdit_category5->setEnabled(true);
        ui->spinBox_category5->setEnabled(true);
        ui->checkBox_category6->setEnabled(true);
    }
    else
    {
        //handles line edits
        ui->lineEdit_category5->setEnabled(false);
        ui->lineEdit_category5->setText("");
        ui->lineEdit_category6->setEnabled(false);
        ui->lineEdit_category6->setText("");
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");

        //handles higher checkboxes
        ui->checkBox_category6->setEnabled(false);
        ui->checkBox_category7->setEnabled(false);
        ui->checkBox_category6->setChecked(false);
        ui->checkBox_category7->setChecked(false);
        ui->checkBox_category5->setText("5");
        ui->checkBox_category6->setText("6");
        ui->checkBox_category7->setText("7");

        //handles spinbox values
        ui->spinBox_category5->setEnabled(false);
        ui->spinBox_category5->setValue(0);
        ui->spinBox_category6->setEnabled(false);
        ui->spinBox_category6->setValue(0);
        ui->spinBox_category7->setEnabled(false);
        ui->spinBox_category7->setValue(0);

    }
}

void addCourse::on_checkBox_category6_clicked()
{
    if(ui->checkBox_category6->isChecked())
    {
        ui->checkBox_category6->setText("6*");
        ui->lineEdit_category6->setEnabled(true);
        ui->spinBox_category6->setEnabled(true);
        ui->checkBox_category7->setEnabled(true);
    }
    else
    {
        //handles line edits
        ui->lineEdit_category6->setEnabled(false);
        ui->lineEdit_category6->setText("");
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");

        //handles higher checkboxes
        ui->checkBox_category7->setEnabled(false);
        ui->checkBox_category7->setChecked(false);
        ui->checkBox_category6->setText("6");
        ui->checkBox_category7->setText("7");

        //handles spinbox values
        ui->spinBox_category6->setEnabled(false);
        ui->spinBox_category6->setValue(0);
        ui->checkBox_category7->setChecked(false);
        ui->spinBox_category7->setValue(0);
    }
}

void addCourse::on_checkBox_category7_clicked()
{
    if(ui->checkBox_category7->isChecked())
    {
        ui->checkBox_category7->setText("7*");
        ui->lineEdit_category7->setEnabled(true);
        ui->spinBox_category7->setEnabled(true);
    }
    else
    {
        //handles line edit
        ui->lineEdit_category7->setEnabled(false);
        ui->lineEdit_category7->setText("");
        ui->checkBox_category7->setText("7");

        //handles spinbox value
        ui->spinBox_category7->setEnabled(false);
        ui->spinBox_category7->setValue(0);
    }
}

void addCourse::on_saveCourses_clicked()
{

    Homescreen conn;                                            //link MainWindow for connection

    QString courseName = "", courseNumber = "", courseInstructor = "", courseLocation = "", gradeType = "";

    //Initialize values for weighted grade categories
    QString cat1Name = "", cat2Name = "", cat3Name = "", cat4Name = "", cat5Name = "", cat6Name = "", cat7Name = "";

    //Initialize values for weighted grade weights
    int cat1Weight = 0, cat2Weight = 0, cat3Weight = 0, cat4Weight = 0, cat5Weight = 0, cat6Weight = 0, cat7Weight = 0, categoryTotal = 100;

    //Initialize values for course times
    QString timeSunStart = "", timeSunEnd = "", timeMonStart = "", timeMonEnd = "", timeTuesStart = "", timeTuesEnd = "", timeWedStart = "", timeWedEnd = "", timeThursStart = "", timeThursEnd = "", timeFriStart = "", timeFriEnd = "", timeSatStart = "", timeSatEnd = "";


    courseName = ui->lineEdit_courseName->text();               //sets lineEdits to string variables
    courseNumber = ui->lineEdit_courseNumber->text();
    courseInstructor = ui->lineEdit_instructor->text();
    courseLocation= ui->lineEdit_location->text();

    //Assigns values for category names
    cat1Name = ui->lineEdit_category1->text();
    cat2Name = ui->lineEdit_category2->text();
    cat3Name = ui->lineEdit_category3->text();
    cat4Name = ui->lineEdit_category4->text();
    cat5Name = ui->lineEdit_category5->text();
    cat6Name = ui->lineEdit_category6->text();
    cat7Name = ui->lineEdit_category7->text();

    //Assign values for category weights
    cat1Weight = ui->spinBox_category1->value();
    cat2Weight = ui->spinBox_category2->value();
    cat3Weight = ui->spinBox_category3->value();
    cat4Weight = ui->spinBox_category4->value();
    cat5Weight = ui->spinBox_category5->value();
    cat6Weight = ui->spinBox_category6->value();
    cat7Weight = ui->spinBox_category7->value();
    if(courseNumber == "")
    {
        ui->errorLabel->setText("*Please Fill Out Required Fields");
        QMessageBox::warning(this,tr("Error"), tr("Course Number must be entered."));
    }
    else if((ui->checkBox_category1->isChecked() && ui->lineEdit_category1->text() == "") || (ui->checkBox_category2->isChecked() && ui->lineEdit_category2->text() == "") || (ui->checkBox_category3->isChecked() && ui->lineEdit_category3->text() == "") || (ui->checkBox_category4->isChecked() && ui->lineEdit_category4->text() == "") || (ui->checkBox_category5->isChecked() && ui->lineEdit_category6->text() == "") || (ui->checkBox_category7->isChecked() && ui->lineEdit_category7->text() == ""))
    {
        ui->errorLabel->setText("*Please Fill Out Required Fields");
        QMessageBox::warning(this,tr("Error"), tr("Categories must be named."));
    }
    else if((ui->checkBox_category1->isChecked() && ((cat1Name == cat2Name) || (cat1Name == cat3Name) || (cat1Name == cat4Name) || (cat1Name == cat5Name) || (cat1Name == cat6Name) || (cat1Name == cat7Name))) || (ui->checkBox_category2->isChecked() && ((cat2Name == cat3Name) || (cat2Name == cat4Name) || (cat2Name == cat5Name) || (cat2Name == cat6Name) || (cat2Name == cat7Name))) || (ui->checkBox_category3->isChecked() && ((cat3Name == cat4Name) || (cat3Name == cat5Name) || (cat3Name == cat6Name) || (cat3Name == cat7Name))) || (ui->checkBox_category4->isChecked() && ((cat4Name == cat5Name) || (cat4Name == cat6Name) || (cat4Name == cat7Name))) || (ui->checkBox_category5->isChecked() && ((cat5Name == cat6Name) || (cat5Name == cat7Name))) || (ui->checkBox_category6->isChecked() && ((cat6Name == cat7Name))))
    {
        ui->errorLabel->setText("*Please Fill Out Required Fields");
        QMessageBox::warning(this,tr("Error"), tr("Categories may not have the same name."));
    }
    else if((cat1Name != "" && cat1Weight == 0) || (cat2Name != "" && cat2Weight == 0) || (cat3Name != "" && cat3Weight == 0) || (cat4Name != "" && cat4Weight == 0) || (cat5Name != "" && cat5Weight == 0) || (cat6Name != "" && cat6Weight == 0) || (cat7Name != "" && cat7Weight == 0))
    {
        ui->errorLabel->setText("*Please Fill Out Required Fields");
        QMessageBox::warning(this,tr("Error"), tr("Category weight may not be 0%."));
    }
    else
    {
        if(ui->checkBox_pointBased->isChecked())
            gradeType = "pointBased";
        if(ui->groupBox_weighted->isChecked())
        {
            gradeType = "weighted";

            //Gets category weight total
            categoryTotal = cat1Weight + cat2Weight + cat3Weight + cat4Weight + cat5Weight + cat6Weight + cat7Weight;
        }
        if(categoryTotal != 100)                                        //verifies total of categories is 100%
        {
            QMessageBox::warning(this,tr("Error"), tr("Category percentages must total 100%."));
        }
        else
        {
            if(ui->checkBox_Sunday->isChecked() || ui->checkBox_Monday->isChecked() || ui->checkBox_Tuesday->isChecked() || ui->checkBox_Wednesday->isChecked() || ui->checkBox_Thursday->isChecked() || ui->checkBox_Friday->isChecked() || ui->checkBox_Saturday->isChecked())
            {
                if(ui->checkBox_Sunday->isChecked())
                {
                    timeSunStart = ui->timeEdit_SunStart->text();
                    timeSunEnd = ui->timeEdit_SunEnd->text();
                }
                else
                {
                    timeSunStart = "";
                    timeSunEnd = "";
                }
                if(ui->checkBox_Monday->isChecked())
                {
                    timeMonStart = ui->timeEdit_MonStart->text();
                    timeMonEnd = ui->timeEdit_MonEnd->text();
                }
                else
                {
                    timeMonStart = "";
                    timeMonEnd = "";
                }
                if(ui->checkBox_Tuesday->isChecked())
                {
                    timeTuesStart = ui->timeEdit_TuesStart->text();
                    timeTuesEnd = ui->timeEdit_TuesEnd->text();
                }
                else
                {
                    timeTuesStart = "";
                    timeTuesEnd = "";
                }
                if(ui->checkBox_Wednesday->isChecked())
                {
                    timeWedStart = ui->timeEdit_WedStart->text();
                    timeWedEnd = ui->timeEdit_WedEnd->text();
                }
                else
                {
                    timeWedStart = "";
                    timeWedEnd = "";
                }
                if(ui->checkBox_Thursday->isChecked())
                {
                    timeThursStart = ui->timeEdit_ThursStart->text();
                    timeThursEnd = ui->timeEdit_ThursEnd->text();
                }
                else
                {
                    timeThursStart = "";
                    timeThursEnd = "";
                }
                if(ui->checkBox_Friday->isChecked())
                {
                    timeFriStart = ui->timeEdit_FriStart->text();
                    timeFriEnd = ui->timeEdit_FriEnd->text();
                }
                else
                {
                    timeFriStart = "";
                    timeFriEnd = "";
                }
                if(ui->checkBox_Saturday->isChecked())
                {
                    timeSatStart = ui->timeEdit_SatStart->text();
                    timeSatEnd= ui->timeEdit_SunEnd->text();
                }
                else
                {
                    timeSatStart = "";
                    timeSatEnd = "";
                }
            }

            conn.connectionOpen();                                  //opens database
            if(!conn.connectionOpen())                              //checks for connection to database
            {
                qDebug()<<"Failed to open database";
                return;
            }
            QSqlQuery query;

            query.prepare("INSERT INTO courses (courseNumber, courseName, instructor, grading, location) VALUES (:courseNumber, :courseName, :courseInstructor, :gradeType, :courseLocation)");
            query.bindValue(":courseNumber", courseNumber);
            query.bindValue(":courseName", courseName);
            query.bindValue(":courseInstructor", courseInstructor);
            query.bindValue(":courseLocation", courseLocation);
            query.bindValue(":gradeType", gradeType);
            query.exec();

            query.prepare("INSERT INTO courseTimes (courseNumber, sunStartTime, sunEndTime, monStartTime, monEndTime, tuesStartTime, tuesEndTime, wedStartTime, wedEndTime, thursStartTime, thursEndTime, friStartTime, friEndTime, satStartTime, satEndTime) VALUES (:courseNumber, :timeSunStart, :timeSunEnd, :timeMonStart, :timeMonEnd, :timeTuesStart, :timeTuesEnd, :timeWedStart, :timeWedEnd, :timeThursStart, :timeThursEnd, :timeFriStart, :timeFriEnd, :timeSatStart, :timeSatEnd)");
            query.bindValue(":courseNumber", courseNumber);
            query.bindValue(":timeSunStart", timeSunStart);
            query.bindValue(":timeSunEnd", timeSunEnd);
            query.bindValue(":timeMonStart", timeMonStart);
            query.bindValue(":timeMonEnd", timeMonEnd);
            query.bindValue(":timeTuesStart", timeTuesStart);
            query.bindValue(":timeTuesEnd", timeTuesEnd);
            query.bindValue(":timeWedStart", timeWedStart);
            query.bindValue(":timeWedEnd", timeWedEnd);
            query.bindValue(":timeThursStart", timeThursStart);
            query.bindValue(":timeThursEnd", timeThursEnd);
            query.bindValue(":timeFriStart", timeFriStart);
            query.bindValue(":timeFriEnd", timeFriEnd);
            query.bindValue(":timeSatStart", timeSatStart);
            query.bindValue(":timeSatEnd", timeSatEnd);
            query.exec();

            query.prepare("INSERT INTO weightedGrades (courseName, category1Name, category2Name, category3Name, category4Name, category5Name, category6Name, category7Name, category1Weight, category2Weight, category3Weight, category4Weight, category5Weight, category6Weight, category7Weight) VALUES (:courseNumber, :cat1Name, :cat2Name, :cat3Name, :cat4Name, :cat5Name, :cat6Name, :cat7Name, :cat1Weight, :cat2Weight, :cat3Weight, :cat4Weight, :cat5Weight, :cat6Weight, :cat7Weight)");
            query.bindValue(":courseNumber", courseNumber);
            query.bindValue(":cat1Name", cat1Name);
            query.bindValue(":cat2Name", cat2Name);
            query.bindValue(":cat3Name", cat3Name);
            query.bindValue(":cat4Name", cat4Name);
            query.bindValue(":cat5Name", cat5Name);
            query.bindValue(":cat6Name", cat6Name);
            query.bindValue(":cat7Name", cat7Name);
            query.bindValue(":cat1Weight", cat1Weight);
            query.bindValue(":cat2Weight", cat2Weight);
            query.bindValue(":cat3Weight", cat3Weight);
            query.bindValue(":cat4Weight", cat4Weight);
            query.bindValue(":cat5Weight", cat5Weight);
            query.bindValue(":cat6Weight", cat6Weight);
            query.bindValue(":cat7Weight", cat7Weight);
            query.exec();

            QMessageBox::StandardButton reply;
              reply = QMessageBox::question(this, "Test", "Quit?",
                                            QMessageBox::Yes|QMessageBox::No);
              if (reply == QMessageBox::Yes) {
                qDebug() << "Yes was clicked";
                QApplication::quit();
              } else {
                qDebug() << "Yes was *not* clicked";
              }
            this->close();
        }
    }
}

void addCourse::on_cancelCourses_clicked()
{
    this->close();
}
