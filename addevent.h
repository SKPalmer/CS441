#ifndef ADDEVENT_H
#define ADDEVENT_H

#include <QDialog>

namespace Ui {
class addEvent;
}

class addEvent : public QDialog
{
    Q_OBJECT

public:
    explicit addEvent(QWidget *parent = 0);
    ~addEvent();

private slots:
    void on_checkBox_multipleDay_clicked();

    void on_saveEvent_clicked();

    void on_checkBox_allDay_clicked();

    void on_cancel_clicked();

private:
    Ui::addEvent *ui;
};

#endif // ADDEVENT_H
