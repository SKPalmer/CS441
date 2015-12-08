#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QTimeEdit>

namespace Ui {
class addCourse;
}

class addCourse : public QDialog
{
    Q_OBJECT

public:
    explicit addCourse(QWidget *parent = 0);
    ~addCourse();

private slots:
    void on_saveCourses_clicked();
    void on_groupBox_weighted_clicked();
    void on_checkBox_pointBased_clicked();
    void on_checkBox_Sunday_clicked();
    void on_checkBox_Monday_clicked();
    void on_checkBox_Tuesday_clicked();
    void on_checkBox_Wednesday_clicked();
    void on_checkBox_Thursday_clicked();
    void on_checkBox_Friday_clicked();
    void on_checkBox_Saturday_clicked();

    void on_checkBox_category1_clicked();

    void on_checkBox_category2_clicked();

    void on_checkBox_category7_clicked();

    void on_checkBox_category3_clicked();

    void on_checkBox_category4_clicked();

    void on_checkBox_category5_clicked();

    void on_checkBox_category6_clicked();

    void on_cancelCourses_clicked();

private:
    Ui::addCourse *ui;
    QString gradeType;
};

#endif // ADDCOURSE_H
