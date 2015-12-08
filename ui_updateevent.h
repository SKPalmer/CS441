/********************************************************************************
** Form generated from reading UI file 'updateevent.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEEVENT_H
#define UI_UPDATEEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_updateEvent
{
public:

    void setupUi(QDialog *updateEvent)
    {
        if (updateEvent->objectName().isEmpty())
            updateEvent->setObjectName(QStringLiteral("updateEvent"));
        updateEvent->resize(400, 300);

        retranslateUi(updateEvent);

        QMetaObject::connectSlotsByName(updateEvent);
    } // setupUi

    void retranslateUi(QDialog *updateEvent)
    {
        updateEvent->setWindowTitle(QApplication::translate("updateEvent", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class updateEvent: public Ui_updateEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEEVENT_H
