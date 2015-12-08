/********************************************************************************
** Form generated from reading UI file 'removeevent.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEEVENT_H
#define UI_REMOVEEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_removeEvent
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *removeEvent)
    {
        if (removeEvent->objectName().isEmpty())
            removeEvent->setObjectName(QStringLiteral("removeEvent"));
        removeEvent->resize(332, 113);
        layoutWidget = new QWidget(removeEvent);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(53, 10, 228, 96));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        confirm = new QPushButton(layoutWidget);
        confirm->setObjectName(QStringLiteral("confirm"));

        horizontalLayout_6->addWidget(confirm);

        cancel = new QPushButton(layoutWidget);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_6->addWidget(cancel);


        verticalLayout_2->addLayout(horizontalLayout_6);


        retranslateUi(removeEvent);

        QMetaObject::connectSlotsByName(removeEvent);
    } // setupUi

    void retranslateUi(QDialog *removeEvent)
    {
        removeEvent->setWindowTitle(QApplication::translate("removeEvent", "Dialog", 0));
        label->setText(QApplication::translate("removeEvent", "This Event will be permanently deleted. ", 0));
        label_2->setText(QApplication::translate("removeEvent", "Are you sure you would like to continue?", 0));
        confirm->setText(QApplication::translate("removeEvent", "Confirm", 0));
        cancel->setText(QApplication::translate("removeEvent", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class removeEvent: public Ui_removeEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEEVENT_H
