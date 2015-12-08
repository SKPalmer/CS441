#ifndef UPDATEEVENT_H
#define UPDATEEVENT_H

#include <QDialog>

namespace Ui {
class updateEvent;
}

class updateEvent : public QDialog
{
    Q_OBJECT

public:
    explicit updateEvent(QWidget *parent = 0);
    ~updateEvent();

private:
    Ui::updateEvent *ui;
};

#endif // UPDATEEVENT_H
