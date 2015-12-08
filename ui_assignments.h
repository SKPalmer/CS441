/********************************************************************************
** Form generated from reading UI file 'assignments.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENTS_H
#define UI_ASSIGNMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_assignments
{
public:
    QGroupBox *groupBox;
    QTableView *tableView_assignments;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_courses;
    QGroupBox *groupBox_addAssignment;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_pointsEarned;
    QCheckBox *checkBox_percentage;
    QTextEdit *textEdit_additional;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_saveAssignment;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox_courses_2;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_categories;
    QDoubleSpinBox *doubleSpinBox_pointsEarned;
    QDoubleSpinBox *doubleSpinBox_percentage;
    QDoubleSpinBox *doubleSpinBox_pointsPossible;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_editAssignment;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_saveAssignment_2;
    QPushButton *pushButton_cancel_2;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_courseNumber;
    QLineEdit *lineEdit_name_2;
    QComboBox *comboBox_categories_2;
    QDoubleSpinBox *doubleSpinBox_pointsEarned_2;
    QDoubleSpinBox *doubleSpinBox_percentage_2;
    QDoubleSpinBox *doubleSpinBox_pointsPossible_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *checkBox_pointsEarned_2;
    QCheckBox *checkBox_percentage_2;
    QTextEdit *textEdit_additional_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_deleteAssignment;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_addAssignment;
    QPushButton *pushButton_editAssignment;
    QGroupBox *groupBox_deleteAssignment;
    QWidget *widget;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLabel *label_assignmentDelete;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *assignments)
    {
        if (assignments->objectName().isEmpty())
            assignments->setObjectName(QStringLiteral("assignments"));
        assignments->resize(823, 530);
        groupBox = new QGroupBox(assignments);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(12, 8, 881, 509));
        tableView_assignments = new QTableView(groupBox);
        tableView_assignments->setObjectName(QStringLiteral("tableView_assignments"));
        tableView_assignments->setGeometry(QRect(25, 87, 483, 410));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 28, 159, 52));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox_courses = new QComboBox(layoutWidget);
        comboBox_courses->setObjectName(QStringLiteral("comboBox_courses"));

        verticalLayout->addWidget(comboBox_courses);

        groupBox_addAssignment = new QGroupBox(groupBox);
        groupBox_addAssignment->setObjectName(QStringLiteral("groupBox_addAssignment"));
        groupBox_addAssignment->setEnabled(true);
        groupBox_addAssignment->setGeometry(QRect(514, 86, 290, 335));
        layoutWidget_2 = new QWidget(groupBox_addAssignment);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(8, 101, 16, 58));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_pointsEarned = new QCheckBox(layoutWidget_2);
        checkBox_pointsEarned->setObjectName(QStringLiteral("checkBox_pointsEarned"));

        verticalLayout_2->addWidget(checkBox_pointsEarned);

        checkBox_percentage = new QCheckBox(layoutWidget_2);
        checkBox_percentage->setObjectName(QStringLiteral("checkBox_percentage"));

        verticalLayout_2->addWidget(checkBox_percentage);

        textEdit_additional = new QTextEdit(groupBox_addAssignment);
        textEdit_additional->setObjectName(QStringLiteral("textEdit_additional"));
        textEdit_additional->setGeometry(QRect(26, 213, 254, 80));
        layoutWidget_3 = new QWidget(groupBox_addAssignment);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(63, 300, 173, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_saveAssignment = new QPushButton(layoutWidget_3);
        pushButton_saveAssignment->setObjectName(QStringLiteral("pushButton_saveAssignment"));

        horizontalLayout_2->addWidget(pushButton_saveAssignment);

        pushButton_cancel = new QPushButton(layoutWidget_3);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);

        layoutWidget_4 = new QWidget(groupBox_addAssignment);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(26, 27, 255, 180));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_2 = new QLabel(layoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        comboBox_courses_2 = new QComboBox(layoutWidget_4);
        comboBox_courses_2->setObjectName(QStringLiteral("comboBox_courses_2"));

        verticalLayout_4->addWidget(comboBox_courses_2);

        lineEdit_name = new QLineEdit(layoutWidget_4);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        verticalLayout_4->addWidget(lineEdit_name);

        comboBox_categories = new QComboBox(layoutWidget_4);
        comboBox_categories->setObjectName(QStringLiteral("comboBox_categories"));

        verticalLayout_4->addWidget(comboBox_categories);

        doubleSpinBox_pointsEarned = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_pointsEarned->setObjectName(QStringLiteral("doubleSpinBox_pointsEarned"));

        verticalLayout_4->addWidget(doubleSpinBox_pointsEarned);

        doubleSpinBox_percentage = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_percentage->setObjectName(QStringLiteral("doubleSpinBox_percentage"));

        verticalLayout_4->addWidget(doubleSpinBox_percentage);

        doubleSpinBox_pointsPossible = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_pointsPossible->setObjectName(QStringLiteral("doubleSpinBox_pointsPossible"));
        doubleSpinBox_pointsPossible->setMaximum(999.99);

        verticalLayout_4->addWidget(doubleSpinBox_pointsPossible);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);

        layoutWidget_2->raise();
        textEdit_additional->raise();
        layoutWidget_3->raise();
        layoutWidget_4->raise();
        groupBox_editAssignment = new QGroupBox(groupBox);
        groupBox_editAssignment->setObjectName(QStringLiteral("groupBox_editAssignment"));
        groupBox_editAssignment->setEnabled(true);
        groupBox_editAssignment->setGeometry(QRect(514, 86, 290, 335));
        layoutWidget_7 = new QWidget(groupBox_editAssignment);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(54, 300, 206, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_saveAssignment_2 = new QPushButton(layoutWidget_7);
        pushButton_saveAssignment_2->setObjectName(QStringLiteral("pushButton_saveAssignment_2"));

        horizontalLayout_5->addWidget(pushButton_saveAssignment_2);

        pushButton_cancel_2 = new QPushButton(layoutWidget_7);
        pushButton_cancel_2->setObjectName(QStringLiteral("pushButton_cancel_2"));

        horizontalLayout_5->addWidget(pushButton_cancel_2);

        layoutWidget_5 = new QWidget(groupBox_editAssignment);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(26, 27, 254, 179));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(layoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(layoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(layoutWidget_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(layoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_5->addWidget(label_13);

        label_14 = new QLabel(layoutWidget_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_5->addWidget(label_14);

        label_15 = new QLabel(layoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_5->addWidget(label_15);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lineEdit_courseNumber = new QLineEdit(layoutWidget_5);
        lineEdit_courseNumber->setObjectName(QStringLiteral("lineEdit_courseNumber"));
        lineEdit_courseNumber->setReadOnly(true);

        verticalLayout_6->addWidget(lineEdit_courseNumber);

        lineEdit_name_2 = new QLineEdit(layoutWidget_5);
        lineEdit_name_2->setObjectName(QStringLiteral("lineEdit_name_2"));
        lineEdit_name_2->setMaxLength(20);
        lineEdit_name_2->setReadOnly(true);

        verticalLayout_6->addWidget(lineEdit_name_2);

        comboBox_categories_2 = new QComboBox(layoutWidget_5);
        comboBox_categories_2->setObjectName(QStringLiteral("comboBox_categories_2"));

        verticalLayout_6->addWidget(comboBox_categories_2);

        doubleSpinBox_pointsEarned_2 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_pointsEarned_2->setObjectName(QStringLiteral("doubleSpinBox_pointsEarned_2"));

        verticalLayout_6->addWidget(doubleSpinBox_pointsEarned_2);

        doubleSpinBox_percentage_2 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_percentage_2->setObjectName(QStringLiteral("doubleSpinBox_percentage_2"));

        verticalLayout_6->addWidget(doubleSpinBox_percentage_2);

        doubleSpinBox_pointsPossible_2 = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_pointsPossible_2->setObjectName(QStringLiteral("doubleSpinBox_pointsPossible_2"));
        doubleSpinBox_pointsPossible_2->setMaximum(999.99);

        verticalLayout_6->addWidget(doubleSpinBox_pointsPossible_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_6);

        layoutWidget_6 = new QWidget(groupBox_editAssignment);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(8, 101, 16, 58));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        checkBox_pointsEarned_2 = new QCheckBox(layoutWidget_6);
        checkBox_pointsEarned_2->setObjectName(QStringLiteral("checkBox_pointsEarned_2"));

        verticalLayout_7->addWidget(checkBox_pointsEarned_2);

        checkBox_percentage_2 = new QCheckBox(layoutWidget_6);
        checkBox_percentage_2->setObjectName(QStringLiteral("checkBox_percentage_2"));

        verticalLayout_7->addWidget(checkBox_percentage_2);

        textEdit_additional_2 = new QTextEdit(groupBox_editAssignment);
        textEdit_additional_2->setObjectName(QStringLiteral("textEdit_additional_2"));
        textEdit_additional_2->setGeometry(QRect(26, 213, 254, 80));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(412, 55, 339, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_deleteAssignment = new QPushButton(layoutWidget1);
        pushButton_deleteAssignment->setObjectName(QStringLiteral("pushButton_deleteAssignment"));

        horizontalLayout->addWidget(pushButton_deleteAssignment);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_addAssignment = new QPushButton(layoutWidget1);
        pushButton_addAssignment->setObjectName(QStringLiteral("pushButton_addAssignment"));

        horizontalLayout->addWidget(pushButton_addAssignment);

        pushButton_editAssignment = new QPushButton(layoutWidget1);
        pushButton_editAssignment->setObjectName(QStringLiteral("pushButton_editAssignment"));

        horizontalLayout->addWidget(pushButton_editAssignment);

        groupBox_deleteAssignment = new QGroupBox(groupBox);
        groupBox_deleteAssignment->setObjectName(QStringLiteral("groupBox_deleteAssignment"));
        groupBox_deleteAssignment->setGeometry(QRect(514, 86, 290, 151));
        widget = new QWidget(groupBox_deleteAssignment);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 230, 86));
        verticalLayout_9 = new QVBoxLayout(widget);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_8->addWidget(label_16);

        label_assignmentDelete = new QLabel(widget);
        label_assignmentDelete->setObjectName(QStringLiteral("label_assignmentDelete"));

        verticalLayout_8->addWidget(label_assignmentDelete);

        label_18 = new QLabel(widget);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_8->addWidget(label_18);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);


        verticalLayout_9->addLayout(horizontalLayout_6);

        QWidget::setTabOrder(comboBox_courses, pushButton_editAssignment);
        QWidget::setTabOrder(pushButton_editAssignment, pushButton_deleteAssignment);
        QWidget::setTabOrder(pushButton_deleteAssignment, tableView_assignments);

        retranslateUi(assignments);

        QMetaObject::connectSlotsByName(assignments);
    } // setupUi

    void retranslateUi(QDialog *assignments)
    {
        assignments->setWindowTitle(QApplication::translate("assignments", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("assignments", "Assignments:", 0));
        label->setText(QApplication::translate("assignments", "View Assignments:", 0));
        groupBox_addAssignment->setTitle(QApplication::translate("assignments", "Add New Assignment:", 0));
        checkBox_pointsEarned->setText(QString());
        checkBox_percentage->setText(QString());
        pushButton_saveAssignment->setText(QApplication::translate("assignments", "Save Assignment", 0));
        pushButton_cancel->setText(QApplication::translate("assignments", "Cancel", 0));
        label_7->setText(QApplication::translate("assignments", "Course Number:", 0));
        label_2->setText(QApplication::translate("assignments", "Assignment Name:", 0));
        label_3->setText(QApplication::translate("assignments", "Assignment Category:", 0));
        label_5->setText(QApplication::translate("assignments", "Points Earned:", 0));
        label_6->setText(QApplication::translate("assignments", "Percentage:", 0));
        label_4->setText(QApplication::translate("assignments", "Points Possible:", 0));
        label_8->setText(QApplication::translate("assignments", "Additional Information:", 0));
        groupBox_editAssignment->setTitle(QApplication::translate("assignments", "Edit Assignment:", 0));
        pushButton_saveAssignment_2->setText(QApplication::translate("assignments", "Update Assignment", 0));
        pushButton_cancel_2->setText(QApplication::translate("assignments", "Cancel", 0));
        label_9->setText(QApplication::translate("assignments", "Course Number:", 0));
        label_10->setText(QApplication::translate("assignments", "Assignment Name:", 0));
        label_11->setText(QApplication::translate("assignments", "Assignment Category:", 0));
        label_12->setText(QApplication::translate("assignments", "Points Earned:", 0));
        label_13->setText(QApplication::translate("assignments", "Percentage:", 0));
        label_14->setText(QApplication::translate("assignments", "Points Possible:", 0));
        label_15->setText(QApplication::translate("assignments", "Additional Information:", 0));
        checkBox_pointsEarned_2->setText(QString());
        checkBox_percentage_2->setText(QString());
        pushButton_deleteAssignment->setText(QApplication::translate("assignments", "Delete Assignment", 0));
        pushButton_addAssignment->setText(QApplication::translate("assignments", "Add Assignment", 0));
        pushButton_editAssignment->setText(QApplication::translate("assignments", "Edit Assignment", 0));
        groupBox_deleteAssignment->setTitle(QApplication::translate("assignments", "Confirm Assignment Delete:", 0));
        label_16->setText(QApplication::translate("assignments", "CONFIRM DELETE OF ASSIGNMENT:", 0));
        label_assignmentDelete->setText(QApplication::translate("assignments", "+assignmentNumber", 0));
        label_18->setText(QApplication::translate("assignments", "ASSIGNMENT WILL BE PERMANENTLY DELETED", 0));
        pushButton->setText(QApplication::translate("assignments", "Delete", 0));
        pushButton_2->setText(QApplication::translate("assignments", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class assignments: public Ui_assignments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENTS_H
