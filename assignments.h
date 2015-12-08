#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QDialog>
#include "addassignment.h"

namespace Ui {
class assignments;
}

class assignments : public QDialog
{
    Q_OBJECT

public:
    explicit assignments(QWidget *parent = 0);

    ~assignments();

private slots:
    void on_pushButton_addAssignment_clicked();

    void on_comboBox_courses_currentTextChanged(const QString &arg1);

    void on_pushButton_editAssignment_clicked();

    void on_checkBox_pointsEarned_clicked();

    void on_checkBox_percentage_clicked();

    void on_checkBox_pointsEarned_2_clicked();

    void on_checkBox_percentage_2_clicked();

    void on_pushButton_saveAssignment_clicked();

    void on_comboBox_courses_2_currentTextChanged(const QString &arg1);

    void on_tableView_assignments_clicked(const QModelIndex &index);

    void on_pushButton_saveAssignment_2_clicked();

    void on_pushButton_deleteAssignment_clicked();

    void on_pushButton_cancel_2_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_clicked();

    void refreshAssignmentTable();

private:
    Ui::assignments *ui;
};

#endif // ASSIGNMENTS_H
