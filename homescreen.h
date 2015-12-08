#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QTimeEdit>
#include <QMessageBox>
#include <QTextEdit>
#include <QSqlRecord>
#include <QAbstractItemView>
#include <QComboBox>
#include <QWidget>
#include "addevent.h"
#include "removeevent.h"
#include "updateevent.h"
#include "addcourse.h"
#include "assignments.h"
#include "addassignment.h"
#include "addcourse.h"

namespace Ui {
class Homescreen;
}

class Homescreen : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase plannerDB;
    void connectionClose()
    {
        plannerDB.close();
        plannerDB.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectionOpen()
    {
        plannerDB = QSqlDatabase :: addDatabase("QSQLITE");
        plannerDB.setDatabaseName("C:/sqlite/planner.db");

        if(!plannerDB.open()){
            qDebug()<<("Database Failed");
            return false;
        }
        else {
            qDebug()<<("Database Connected");
            return true;
        }
    }

public:
    explicit Homescreen(QWidget *parent = 0);
    ~Homescreen();

private slots:

    void on_addEvent_clicked();

    void on_editEvent_clicked();

    void on_removeEvent_clicked();

    void on_checkBox_allDay_clicked();

    void on_checkBox_multipleDay_clicked();

    void on_saveEvent_clicked();

    void on_cancel_clicked();

    void refreshEventTable();

    void on_checkBox_allDay_3_clicked();

    void on_checkBox_multipleDay_3_clicked();

    void on_Homescreen_2_tabBarClicked(int index);

    void on_comboBox_courses_currentTextChanged(const QString &arg1);

    void on_pushButton_addCourse_clicked();

    void on_pushButton_assignmentGrades_clicked();

    void on_Homescreen_2_currentChanged(int index);

    void on_pushButton_insertToDo_clicked();

    void on_dateEdit_toDo_editingFinished();

    void on_radioButton_viewAll_clicked();

    void on_radioButton_completed_clicked();

    void on_radioButton_uncompleted_clicked();

    void on_pushButton_editToDo_clicked();

    void on_pushButton_deleteToDo_clicked();

    void on_pushButton_addToDo_clicked();

    void on_tableView_toDo_clicked(const QModelIndex &index);

    void on_pushButton_toDoCompleted_clicked();

    void on_pushButton_toDoUncompleted_clicked();

    void on_pushButton_updateToDo_clicked();

    void reloadToDoTable();

    void on_pushButton_deleteCourse_clicked();

    void on_pushButton_deleteCourse_2_clicked();

    void on_pushButton_cancel_clicked();

    void refreshCourseList();


    void on_tableView_eventView_clicked(const QModelIndex &index);

    void on_saveEvent_3_clicked();

    void on_cancel_3_clicked();


    void on_pushButton_cancelDeleteEvent_clicked();

    void on_pushButton_deleteEvent_clicked();

private:
    Ui::Homescreen *ui;
};

#endif // HOMESCREEN_H
