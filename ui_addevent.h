/********************************************************************************
** Form generated from reading UI file 'addevent.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENT_H
#define UI_ADDEVENT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addEvent
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *EventNameLabel;
    QLineEdit *eventName;
    QLabel *eventTypeLabel;
    QLineEdit *eventType;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *saveEvent;
    QPushButton *cancel;
    QTextEdit *textEdit_details;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLabel *eventDateLabel;
    QDateEdit *eventDate;
    QLabel *eventDateEndLabel;
    QDateEdit *eventDateEnd;
    QLabel *startTimeLabel;
    QTimeEdit *timeEdit_eventStart;
    QLabel *endTimeLabel;
    QTimeEdit *timeEdit_eventEnd;
    QLabel *eventEndLabel_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_multipleDay;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox_allDay;
    QTextEdit *textEdit_details_2;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *EventNameLabel_2;
    QLineEdit *eventName_2;
    QLabel *eventTypeLabel_2;
    QLineEdit *eventType_2;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_multipleDay_2;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *checkBox_allDay_2;
    QWidget *layoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *eventDateLabel_2;
    QDateEdit *eventDate_2;
    QLabel *eventDateEndLabel_2;
    QDateEdit *eventDateEnd_2;
    QLabel *startTimeLabel_2;
    QTimeEdit *timeEdit_eventStart_2;
    QLabel *endTimeLabel_2;
    QTimeEdit *timeEdit_eventEnd_2;
    QLabel *eventEndLabel_3;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *saveEvent_2;
    QPushButton *cancel_2;

    void setupUi(QDialog *addEvent)
    {
        if (addEvent->objectName().isEmpty())
            addEvent->setObjectName(QStringLiteral("addEvent"));
        addEvent->setEnabled(true);
        addEvent->resize(295, 345);
        layoutWidget = new QWidget(addEvent);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(17, 14, 203, 48));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        EventNameLabel = new QLabel(layoutWidget);
        EventNameLabel->setObjectName(QStringLiteral("EventNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, EventNameLabel);

        eventName = new QLineEdit(layoutWidget);
        eventName->setObjectName(QStringLiteral("eventName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, eventName);

        eventTypeLabel = new QLabel(layoutWidget);
        eventTypeLabel->setObjectName(QStringLiteral("eventTypeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, eventTypeLabel);

        eventType = new QLineEdit(layoutWidget);
        eventType->setObjectName(QStringLiteral("eventType"));

        formLayout->setWidget(1, QFormLayout::FieldRole, eventType);

        layoutWidget1 = new QWidget(addEvent);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(18, 310, 158, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        saveEvent = new QPushButton(layoutWidget1);
        saveEvent->setObjectName(QStringLiteral("saveEvent"));

        horizontalLayout_6->addWidget(saveEvent);

        cancel = new QPushButton(layoutWidget1);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_6->addWidget(cancel);

        textEdit_details = new QTextEdit(addEvent);
        textEdit_details->setObjectName(QStringLiteral("textEdit_details"));
        textEdit_details->setGeometry(QRect(19, 193, 257, 111));
        layoutWidget2 = new QWidget(addEvent);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 72, 147, 119));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        eventDateLabel = new QLabel(layoutWidget2);
        eventDateLabel->setObjectName(QStringLiteral("eventDateLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, eventDateLabel);

        eventDate = new QDateEdit(layoutWidget2);
        eventDate->setObjectName(QStringLiteral("eventDate"));
        eventDate->setDateTime(QDateTime(QDate(2015, 11, 18), QTime(0, 0, 0)));
        eventDate->setMaximumDateTime(QDateTime(QDate(7000, 12, 31), QTime(23, 59, 59)));
        eventDate->setMaximumTime(QTime(23, 59, 59));
        eventDate->setDate(QDate(2015, 11, 18));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, eventDate);

        eventDateEndLabel = new QLabel(layoutWidget2);
        eventDateEndLabel->setObjectName(QStringLiteral("eventDateEndLabel"));
        eventDateEndLabel->setEnabled(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, eventDateEndLabel);

        eventDateEnd = new QDateEdit(layoutWidget2);
        eventDateEnd->setObjectName(QStringLiteral("eventDateEnd"));
        eventDateEnd->setEnabled(true);
        eventDateEnd->setDateTime(QDateTime(QDate(2015, 11, 18), QTime(0, 0, 0)));
        eventDateEnd->setMaximumDateTime(QDateTime(QDate(7000, 12, 31), QTime(23, 59, 59)));
        eventDateEnd->setMaximumTime(QTime(23, 59, 59));
        eventDateEnd->setDate(QDate(2015, 11, 18));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, eventDateEnd);

        startTimeLabel = new QLabel(layoutWidget2);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, startTimeLabel);

        timeEdit_eventStart = new QTimeEdit(layoutWidget2);
        timeEdit_eventStart->setObjectName(QStringLiteral("timeEdit_eventStart"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, timeEdit_eventStart);

        endTimeLabel = new QLabel(layoutWidget2);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, endTimeLabel);

        timeEdit_eventEnd = new QTimeEdit(layoutWidget2);
        timeEdit_eventEnd->setObjectName(QStringLiteral("timeEdit_eventEnd"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, timeEdit_eventEnd);

        eventEndLabel_2 = new QLabel(layoutWidget2);
        eventEndLabel_2->setObjectName(QStringLiteral("eventEndLabel_2"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, eventEndLabel_2);

        layoutWidget3 = new QWidget(addEvent);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(174, 74, 114, 71));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_multipleDay = new QCheckBox(layoutWidget3);
        checkBox_multipleDay->setObjectName(QStringLiteral("checkBox_multipleDay"));

        verticalLayout->addWidget(checkBox_multipleDay);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        checkBox_allDay = new QCheckBox(layoutWidget3);
        checkBox_allDay->setObjectName(QStringLiteral("checkBox_allDay"));

        verticalLayout->addWidget(checkBox_allDay);

        textEdit_details_2 = new QTextEdit(addEvent);
        textEdit_details_2->setObjectName(QStringLiteral("textEdit_details_2"));
        textEdit_details_2->setGeometry(QRect(2, 179, 257, 111));
        layoutWidget_2 = new QWidget(addEvent);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 203, 48));
        formLayout_3 = new QFormLayout(layoutWidget_2);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        EventNameLabel_2 = new QLabel(layoutWidget_2);
        EventNameLabel_2->setObjectName(QStringLiteral("EventNameLabel_2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, EventNameLabel_2);

        eventName_2 = new QLineEdit(layoutWidget_2);
        eventName_2->setObjectName(QStringLiteral("eventName_2"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, eventName_2);

        eventTypeLabel_2 = new QLabel(layoutWidget_2);
        eventTypeLabel_2->setObjectName(QStringLiteral("eventTypeLabel_2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, eventTypeLabel_2);

        eventType_2 = new QLineEdit(layoutWidget_2);
        eventType_2->setObjectName(QStringLiteral("eventType_2"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, eventType_2);

        layoutWidget_3 = new QWidget(addEvent);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(157, 60, 114, 71));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_multipleDay_2 = new QCheckBox(layoutWidget_3);
        checkBox_multipleDay_2->setObjectName(QStringLiteral("checkBox_multipleDay_2"));

        verticalLayout_2->addWidget(checkBox_multipleDay_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        checkBox_allDay_2 = new QCheckBox(layoutWidget_3);
        checkBox_allDay_2->setObjectName(QStringLiteral("checkBox_allDay_2"));

        verticalLayout_2->addWidget(checkBox_allDay_2);

        layoutWidget_4 = new QWidget(addEvent);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(3, 58, 147, 119));
        formLayout_4 = new QFormLayout(layoutWidget_4);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        eventDateLabel_2 = new QLabel(layoutWidget_4);
        eventDateLabel_2->setObjectName(QStringLiteral("eventDateLabel_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, eventDateLabel_2);

        eventDate_2 = new QDateEdit(layoutWidget_4);
        eventDate_2->setObjectName(QStringLiteral("eventDate_2"));
        eventDate_2->setDateTime(QDateTime(QDate(2015, 11, 18), QTime(0, 0, 0)));
        eventDate_2->setMaximumDateTime(QDateTime(QDate(7000, 12, 31), QTime(23, 59, 59)));
        eventDate_2->setMaximumTime(QTime(23, 59, 59));
        eventDate_2->setDate(QDate(2015, 11, 18));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, eventDate_2);

        eventDateEndLabel_2 = new QLabel(layoutWidget_4);
        eventDateEndLabel_2->setObjectName(QStringLiteral("eventDateEndLabel_2"));
        eventDateEndLabel_2->setEnabled(true);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, eventDateEndLabel_2);

        eventDateEnd_2 = new QDateEdit(layoutWidget_4);
        eventDateEnd_2->setObjectName(QStringLiteral("eventDateEnd_2"));
        eventDateEnd_2->setEnabled(true);
        eventDateEnd_2->setDateTime(QDateTime(QDate(2015, 11, 18), QTime(0, 0, 0)));
        eventDateEnd_2->setMaximumDateTime(QDateTime(QDate(7000, 12, 31), QTime(23, 59, 59)));
        eventDateEnd_2->setMaximumTime(QTime(23, 59, 59));
        eventDateEnd_2->setDate(QDate(2015, 11, 18));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, eventDateEnd_2);

        startTimeLabel_2 = new QLabel(layoutWidget_4);
        startTimeLabel_2->setObjectName(QStringLiteral("startTimeLabel_2"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, startTimeLabel_2);

        timeEdit_eventStart_2 = new QTimeEdit(layoutWidget_4);
        timeEdit_eventStart_2->setObjectName(QStringLiteral("timeEdit_eventStart_2"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, timeEdit_eventStart_2);

        endTimeLabel_2 = new QLabel(layoutWidget_4);
        endTimeLabel_2->setObjectName(QStringLiteral("endTimeLabel_2"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, endTimeLabel_2);

        timeEdit_eventEnd_2 = new QTimeEdit(layoutWidget_4);
        timeEdit_eventEnd_2->setObjectName(QStringLiteral("timeEdit_eventEnd_2"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, timeEdit_eventEnd_2);

        eventEndLabel_3 = new QLabel(layoutWidget_4);
        eventEndLabel_3->setObjectName(QStringLiteral("eventEndLabel_3"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, eventEndLabel_3);

        layoutWidget_5 = new QWidget(addEvent);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(1, 296, 158, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        saveEvent_2 = new QPushButton(layoutWidget_5);
        saveEvent_2->setObjectName(QStringLiteral("saveEvent_2"));

        horizontalLayout_7->addWidget(saveEvent_2);

        cancel_2 = new QPushButton(layoutWidget_5);
        cancel_2->setObjectName(QStringLiteral("cancel_2"));

        horizontalLayout_7->addWidget(cancel_2);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        textEdit_details->raise();
        textEdit_details_2->raise();
        layoutWidget_2->raise();
        layoutWidget_3->raise();
        layoutWidget_4->raise();
        layoutWidget_5->raise();

        retranslateUi(addEvent);

        QMetaObject::connectSlotsByName(addEvent);
    } // setupUi

    void retranslateUi(QDialog *addEvent)
    {
        addEvent->setWindowTitle(QApplication::translate("addEvent", "Dialog", 0));
        EventNameLabel->setText(QApplication::translate("addEvent", "Event Name:", 0));
        eventTypeLabel->setText(QApplication::translate("addEvent", "Event Type:", 0));
        saveEvent->setText(QApplication::translate("addEvent", "Save Event", 0));
        cancel->setText(QApplication::translate("addEvent", "Cancel", 0));
        eventDateLabel->setText(QApplication::translate("addEvent", "Event Date:", 0));
        eventDateEndLabel->setText(QApplication::translate("addEvent", "End Date:", 0));
        startTimeLabel->setText(QApplication::translate("addEvent", "Start Time:", 0));
        endTimeLabel->setText(QApplication::translate("addEvent", "End Time:", 0));
        eventEndLabel_2->setText(QApplication::translate("addEvent", "Details:", 0));
        checkBox_multipleDay->setText(QApplication::translate("addEvent", "Multiple Day Event", 0));
        checkBox_allDay->setText(QApplication::translate("addEvent", "All Day Event", 0));
        EventNameLabel_2->setText(QApplication::translate("addEvent", "Event Name:", 0));
        eventTypeLabel_2->setText(QApplication::translate("addEvent", "Event Type:", 0));
        checkBox_multipleDay_2->setText(QApplication::translate("addEvent", "Multiple Day Event", 0));
        checkBox_allDay_2->setText(QApplication::translate("addEvent", "All Day Event", 0));
        eventDateLabel_2->setText(QApplication::translate("addEvent", "Event Date:", 0));
        eventDateEndLabel_2->setText(QApplication::translate("addEvent", "End Date:", 0));
        startTimeLabel_2->setText(QApplication::translate("addEvent", "Start Time:", 0));
        endTimeLabel_2->setText(QApplication::translate("addEvent", "End Time:", 0));
        eventEndLabel_3->setText(QApplication::translate("addEvent", "Details:", 0));
        saveEvent_2->setText(QApplication::translate("addEvent", "Save Event", 0));
        cancel_2->setText(QApplication::translate("addEvent", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class addEvent: public Ui_addEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENT_H
