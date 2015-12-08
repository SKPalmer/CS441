#ifndef REMOVEEVENT_H
#define REMOVEEVENT_H

#include <QDialog>

namespace Ui {
class removeEvent;
}

class removeEvent : public QDialog
{
    Q_OBJECT

public:
    explicit removeEvent(QWidget *parent = 0);
    ~removeEvent();

private:
    Ui::removeEvent *ui;
};

#endif // REMOVEEVENT_H
