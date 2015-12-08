#ifndef ADDASSIGNMENT_H
#define ADDASSIGNMENT_H

#include <QDialog>

namespace Ui {
class addAssignment;
}

class addAssignment : public QDialog
{
    Q_OBJECT

public:
    explicit addAssignment(QWidget *parent = 0);
    ~addAssignment();

private slots:
    void on_checkBox_pointsEarned_clicked();

    void on_checkBox_percentage_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_saveAssignment_clicked();

    void on_comboBox_courses_currentTextChanged(const QString &arg1);

private:
    Ui::addAssignment *ui;
};

#endif // ADDASSIGNMENT_H
