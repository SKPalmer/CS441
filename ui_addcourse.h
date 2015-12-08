/********************************************************************************
** Form generated from reading UI file 'addcourse.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOURSE_H
#define UI_ADDCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addCourse
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_basicInfo;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_6;
    QLabel *courseNumberLabel;
    QLabel *courseNameLabel;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_courseNumber;
    QLineEdit *lineEdit_courseName;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_4;
    QLabel *locationLabel;
    QLabel *instructorLabel;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_location;
    QLineEdit *lineEdit_instructor;
    QGroupBox *groupBox_daysTimes;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_Sunday;
    QTimeEdit *timeEdit_SunStart;
    QTimeEdit *timeEdit_SunEnd;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBox_Monday;
    QTimeEdit *timeEdit_MonStart;
    QTimeEdit *timeEdit_MonEnd;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_Tuesday;
    QTimeEdit *timeEdit_TuesStart;
    QTimeEdit *timeEdit_TuesEnd;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_Wednesday;
    QTimeEdit *timeEdit_WedStart;
    QTimeEdit *timeEdit_WedEnd;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *checkBox_Thursday;
    QTimeEdit *timeEdit_ThursStart;
    QTimeEdit *timeEdit_ThursEnd;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox_Friday;
    QTimeEdit *timeEdit_FriStart;
    QTimeEdit *timeEdit_FriEnd;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *checkBox_Saturday;
    QTimeEdit *timeEdit_SatStart;
    QTimeEdit *timeEdit_SatEnd;
    QLabel *label_6;
    QGroupBox *groupBox_grading;
    QCheckBox *checkBox_pointBased;
    QGroupBox *groupBox_weighted;
    QSplitter *splitter;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *checkBox_category1;
    QCheckBox *checkBox_category2;
    QCheckBox *checkBox_category3;
    QCheckBox *checkBox_category4;
    QCheckBox *checkBox_category5;
    QCheckBox *checkBox_category6;
    QCheckBox *checkBox_category7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_category1;
    QLineEdit *lineEdit_category2;
    QLineEdit *lineEdit_category3;
    QLineEdit *lineEdit_category4;
    QLineEdit *lineEdit_category5;
    QLineEdit *lineEdit_category6;
    QLineEdit *lineEdit_category7;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *spinBox_category1;
    QSpinBox *spinBox_category2;
    QSpinBox *spinBox_category3;
    QSpinBox *spinBox_category4;
    QSpinBox *spinBox_category5;
    QSpinBox *spinBox_category6;
    QSpinBox *spinBox_category7;
    QLabel *requiredLabel;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveCourses;
    QPushButton *cancelCourses;
    QLabel *errorLabel;

    void setupUi(QDialog *addCourse)
    {
        if (addCourse->objectName().isEmpty())
            addCourse->setObjectName(QStringLiteral("addCourse"));
        addCourse->resize(606, 482);
        groupBox = new QGroupBox(addCourse);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 7, 586, 473));
        groupBox_basicInfo = new QGroupBox(groupBox);
        groupBox_basicInfo->setObjectName(QStringLiteral("groupBox_basicInfo"));
        groupBox_basicInfo->setGeometry(QRect(20, 34, 544, 86));
        layoutWidget = new QWidget(groupBox_basicInfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 21, 428, 52));
        horizontalLayout_20 = new QHBoxLayout(layoutWidget);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        courseNumberLabel = new QLabel(layoutWidget);
        courseNumberLabel->setObjectName(QStringLiteral("courseNumberLabel"));

        verticalLayout_6->addWidget(courseNumberLabel);

        courseNameLabel = new QLabel(layoutWidget);
        courseNameLabel->setObjectName(QStringLiteral("courseNameLabel"));

        verticalLayout_6->addWidget(courseNameLabel);


        horizontalLayout_18->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_courseNumber = new QLineEdit(layoutWidget);
        lineEdit_courseNumber->setObjectName(QStringLiteral("lineEdit_courseNumber"));

        verticalLayout_5->addWidget(lineEdit_courseNumber);

        lineEdit_courseName = new QLineEdit(layoutWidget);
        lineEdit_courseName->setObjectName(QStringLiteral("lineEdit_courseName"));

        verticalLayout_5->addWidget(lineEdit_courseName);


        horizontalLayout_18->addLayout(verticalLayout_5);


        horizontalLayout_20->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        locationLabel = new QLabel(layoutWidget);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        verticalLayout_4->addWidget(locationLabel);

        instructorLabel = new QLabel(layoutWidget);
        instructorLabel->setObjectName(QStringLiteral("instructorLabel"));

        verticalLayout_4->addWidget(instructorLabel);


        horizontalLayout_19->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_location = new QLineEdit(layoutWidget);
        lineEdit_location->setObjectName(QStringLiteral("lineEdit_location"));

        verticalLayout_3->addWidget(lineEdit_location);

        lineEdit_instructor = new QLineEdit(layoutWidget);
        lineEdit_instructor->setObjectName(QStringLiteral("lineEdit_instructor"));

        verticalLayout_3->addWidget(lineEdit_instructor);


        horizontalLayout_19->addLayout(verticalLayout_3);


        horizontalLayout_20->addLayout(horizontalLayout_19);

        groupBox_daysTimes = new QGroupBox(groupBox);
        groupBox_daysTimes->setObjectName(QStringLiteral("groupBox_daysTimes"));
        groupBox_daysTimes->setGeometry(QRect(264, 136, 300, 286));
        layoutWidget_2 = new QWidget(groupBox_daysTimes);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 62, 281, 213));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBox_Sunday = new QCheckBox(layoutWidget_2);
        checkBox_Sunday->setObjectName(QStringLiteral("checkBox_Sunday"));

        horizontalLayout_10->addWidget(checkBox_Sunday);

        timeEdit_SunStart = new QTimeEdit(layoutWidget_2);
        timeEdit_SunStart->setObjectName(QStringLiteral("timeEdit_SunStart"));

        horizontalLayout_10->addWidget(timeEdit_SunStart);

        timeEdit_SunEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_SunEnd->setObjectName(QStringLiteral("timeEdit_SunEnd"));

        horizontalLayout_10->addWidget(timeEdit_SunEnd);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        checkBox_Monday = new QCheckBox(layoutWidget_2);
        checkBox_Monday->setObjectName(QStringLiteral("checkBox_Monday"));

        horizontalLayout_11->addWidget(checkBox_Monday);

        timeEdit_MonStart = new QTimeEdit(layoutWidget_2);
        timeEdit_MonStart->setObjectName(QStringLiteral("timeEdit_MonStart"));

        horizontalLayout_11->addWidget(timeEdit_MonStart);

        timeEdit_MonEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_MonEnd->setObjectName(QStringLiteral("timeEdit_MonEnd"));

        horizontalLayout_11->addWidget(timeEdit_MonEnd);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        checkBox_Tuesday = new QCheckBox(layoutWidget_2);
        checkBox_Tuesday->setObjectName(QStringLiteral("checkBox_Tuesday"));

        horizontalLayout_12->addWidget(checkBox_Tuesday);

        timeEdit_TuesStart = new QTimeEdit(layoutWidget_2);
        timeEdit_TuesStart->setObjectName(QStringLiteral("timeEdit_TuesStart"));

        horizontalLayout_12->addWidget(timeEdit_TuesStart);

        timeEdit_TuesEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_TuesEnd->setObjectName(QStringLiteral("timeEdit_TuesEnd"));

        horizontalLayout_12->addWidget(timeEdit_TuesEnd);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        checkBox_Wednesday = new QCheckBox(layoutWidget_2);
        checkBox_Wednesday->setObjectName(QStringLiteral("checkBox_Wednesday"));

        horizontalLayout_13->addWidget(checkBox_Wednesday);

        timeEdit_WedStart = new QTimeEdit(layoutWidget_2);
        timeEdit_WedStart->setObjectName(QStringLiteral("timeEdit_WedStart"));

        horizontalLayout_13->addWidget(timeEdit_WedStart);

        timeEdit_WedEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_WedEnd->setObjectName(QStringLiteral("timeEdit_WedEnd"));

        horizontalLayout_13->addWidget(timeEdit_WedEnd);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        checkBox_Thursday = new QCheckBox(layoutWidget_2);
        checkBox_Thursday->setObjectName(QStringLiteral("checkBox_Thursday"));

        horizontalLayout_14->addWidget(checkBox_Thursday);

        timeEdit_ThursStart = new QTimeEdit(layoutWidget_2);
        timeEdit_ThursStart->setObjectName(QStringLiteral("timeEdit_ThursStart"));

        horizontalLayout_14->addWidget(timeEdit_ThursStart);

        timeEdit_ThursEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_ThursEnd->setObjectName(QStringLiteral("timeEdit_ThursEnd"));

        horizontalLayout_14->addWidget(timeEdit_ThursEnd);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        checkBox_Friday = new QCheckBox(layoutWidget_2);
        checkBox_Friday->setObjectName(QStringLiteral("checkBox_Friday"));

        horizontalLayout_15->addWidget(checkBox_Friday);

        timeEdit_FriStart = new QTimeEdit(layoutWidget_2);
        timeEdit_FriStart->setObjectName(QStringLiteral("timeEdit_FriStart"));

        horizontalLayout_15->addWidget(timeEdit_FriStart);

        timeEdit_FriEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_FriEnd->setObjectName(QStringLiteral("timeEdit_FriEnd"));

        horizontalLayout_15->addWidget(timeEdit_FriEnd);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        checkBox_Saturday = new QCheckBox(layoutWidget_2);
        checkBox_Saturday->setObjectName(QStringLiteral("checkBox_Saturday"));

        horizontalLayout_16->addWidget(checkBox_Saturday);

        timeEdit_SatStart = new QTimeEdit(layoutWidget_2);
        timeEdit_SatStart->setObjectName(QStringLiteral("timeEdit_SatStart"));

        horizontalLayout_16->addWidget(timeEdit_SatStart);

        timeEdit_SatEnd = new QTimeEdit(layoutWidget_2);
        timeEdit_SatEnd->setObjectName(QStringLiteral("timeEdit_SatEnd"));

        horizontalLayout_16->addWidget(timeEdit_SatEnd);


        verticalLayout->addLayout(horizontalLayout_16);

        label_6 = new QLabel(groupBox_daysTimes);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(13, 23, 260, 25));
        groupBox_grading = new QGroupBox(groupBox);
        groupBox_grading->setObjectName(QStringLiteral("groupBox_grading"));
        groupBox_grading->setGeometry(QRect(20, 136, 232, 286));
        checkBox_pointBased = new QCheckBox(groupBox_grading);
        checkBox_pointBased->setObjectName(QStringLiteral("checkBox_pointBased"));
        checkBox_pointBased->setGeometry(QRect(10, 20, 154, 17));
        checkBox_pointBased->setAutoExclusive(true);
        groupBox_weighted = new QGroupBox(groupBox_grading);
        groupBox_weighted->setObjectName(QStringLiteral("groupBox_weighted"));
        groupBox_weighted->setGeometry(QRect(2, 46, 228, 238));
        groupBox_weighted->setCheckable(true);
        groupBox_weighted->setChecked(false);
        splitter = new QSplitter(groupBox_weighted);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(45, 18, 187, 16));
        splitter->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter->addWidget(label_4);
        label_5 = new QLabel(splitter);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter->addWidget(label_5);
        widget = new QWidget(groupBox_weighted);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(8, 40, 213, 180));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        checkBox_category1 = new QCheckBox(widget);
        checkBox_category1->setObjectName(QStringLiteral("checkBox_category1"));

        verticalLayout_8->addWidget(checkBox_category1);

        checkBox_category2 = new QCheckBox(widget);
        checkBox_category2->setObjectName(QStringLiteral("checkBox_category2"));

        verticalLayout_8->addWidget(checkBox_category2);

        checkBox_category3 = new QCheckBox(widget);
        checkBox_category3->setObjectName(QStringLiteral("checkBox_category3"));

        verticalLayout_8->addWidget(checkBox_category3);

        checkBox_category4 = new QCheckBox(widget);
        checkBox_category4->setObjectName(QStringLiteral("checkBox_category4"));

        verticalLayout_8->addWidget(checkBox_category4);

        checkBox_category5 = new QCheckBox(widget);
        checkBox_category5->setObjectName(QStringLiteral("checkBox_category5"));

        verticalLayout_8->addWidget(checkBox_category5);

        checkBox_category6 = new QCheckBox(widget);
        checkBox_category6->setObjectName(QStringLiteral("checkBox_category6"));

        verticalLayout_8->addWidget(checkBox_category6);

        checkBox_category7 = new QCheckBox(widget);
        checkBox_category7->setObjectName(QStringLiteral("checkBox_category7"));

        verticalLayout_8->addWidget(checkBox_category7);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_category1 = new QLineEdit(widget);
        lineEdit_category1->setObjectName(QStringLiteral("lineEdit_category1"));

        verticalLayout_2->addWidget(lineEdit_category1);

        lineEdit_category2 = new QLineEdit(widget);
        lineEdit_category2->setObjectName(QStringLiteral("lineEdit_category2"));

        verticalLayout_2->addWidget(lineEdit_category2);

        lineEdit_category3 = new QLineEdit(widget);
        lineEdit_category3->setObjectName(QStringLiteral("lineEdit_category3"));

        verticalLayout_2->addWidget(lineEdit_category3);

        lineEdit_category4 = new QLineEdit(widget);
        lineEdit_category4->setObjectName(QStringLiteral("lineEdit_category4"));

        verticalLayout_2->addWidget(lineEdit_category4);

        lineEdit_category5 = new QLineEdit(widget);
        lineEdit_category5->setObjectName(QStringLiteral("lineEdit_category5"));

        verticalLayout_2->addWidget(lineEdit_category5);

        lineEdit_category6 = new QLineEdit(widget);
        lineEdit_category6->setObjectName(QStringLiteral("lineEdit_category6"));

        verticalLayout_2->addWidget(lineEdit_category6);

        lineEdit_category7 = new QLineEdit(widget);
        lineEdit_category7->setObjectName(QStringLiteral("lineEdit_category7"));

        verticalLayout_2->addWidget(lineEdit_category7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        spinBox_category1 = new QSpinBox(widget);
        spinBox_category1->setObjectName(QStringLiteral("spinBox_category1"));
        spinBox_category1->setSingleStep(1);

        verticalLayout_7->addWidget(spinBox_category1);

        spinBox_category2 = new QSpinBox(widget);
        spinBox_category2->setObjectName(QStringLiteral("spinBox_category2"));

        verticalLayout_7->addWidget(spinBox_category2);

        spinBox_category3 = new QSpinBox(widget);
        spinBox_category3->setObjectName(QStringLiteral("spinBox_category3"));

        verticalLayout_7->addWidget(spinBox_category3);

        spinBox_category4 = new QSpinBox(widget);
        spinBox_category4->setObjectName(QStringLiteral("spinBox_category4"));

        verticalLayout_7->addWidget(spinBox_category4);

        spinBox_category5 = new QSpinBox(widget);
        spinBox_category5->setObjectName(QStringLiteral("spinBox_category5"));

        verticalLayout_7->addWidget(spinBox_category5);

        spinBox_category6 = new QSpinBox(widget);
        spinBox_category6->setObjectName(QStringLiteral("spinBox_category6"));

        verticalLayout_7->addWidget(spinBox_category6);

        spinBox_category7 = new QSpinBox(widget);
        spinBox_category7->setObjectName(QStringLiteral("spinBox_category7"));

        verticalLayout_7->addWidget(spinBox_category7);


        horizontalLayout_2->addLayout(verticalLayout_7);

        groupBox_weighted->raise();
        checkBox_pointBased->raise();
        requiredLabel = new QLabel(groupBox);
        requiredLabel->setObjectName(QStringLiteral("requiredLabel"));
        requiredLabel->setGeometry(QRect(436, -1, 134, 46));
        layoutWidget_4 = new QWidget(groupBox);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(17, 434, 357, 27));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        saveCourses = new QPushButton(layoutWidget_4);
        saveCourses->setObjectName(QStringLiteral("saveCourses"));

        horizontalLayout_3->addWidget(saveCourses);

        cancelCourses = new QPushButton(layoutWidget_4);
        cancelCourses->setObjectName(QStringLiteral("cancelCourses"));

        horizontalLayout_3->addWidget(cancelCourses);


        horizontalLayout_17->addLayout(horizontalLayout_3);

        errorLabel = new QLabel(layoutWidget_4);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        errorLabel->setFont(font);

        horizontalLayout_17->addWidget(errorLabel);

        layoutWidget_4->raise();
        groupBox_basicInfo->raise();
        groupBox_daysTimes->raise();
        groupBox_grading->raise();
        requiredLabel->raise();

        retranslateUi(addCourse);

        QMetaObject::connectSlotsByName(addCourse);
    } // setupUi

    void retranslateUi(QDialog *addCourse)
    {
        addCourse->setWindowTitle(QApplication::translate("addCourse", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("addCourse", "Course Information:", 0));
        groupBox_basicInfo->setTitle(QApplication::translate("addCourse", "Basic Info:", 0));
        courseNumberLabel->setText(QApplication::translate("addCourse", "Course Number: *", 0));
        courseNameLabel->setText(QApplication::translate("addCourse", "Course Name:", 0));
        locationLabel->setText(QApplication::translate("addCourse", "Location:", 0));
        instructorLabel->setText(QApplication::translate("addCourse", "Instructor:", 0));
        groupBox_daysTimes->setTitle(QApplication::translate("addCourse", "Schedule:", 0));
        label->setText(QApplication::translate("addCourse", "Days:", 0));
        label_2->setText(QApplication::translate("addCourse", "Start:", 0));
        label_3->setText(QApplication::translate("addCourse", "End:", 0));
        checkBox_Sunday->setText(QApplication::translate("addCourse", "Sunday", 0));
        checkBox_Monday->setText(QApplication::translate("addCourse", "Monday", 0));
        checkBox_Tuesday->setText(QApplication::translate("addCourse", "Tuesday", 0));
        checkBox_Wednesday->setText(QApplication::translate("addCourse", "Wednesday", 0));
        checkBox_Thursday->setText(QApplication::translate("addCourse", "Thursday", 0));
        checkBox_Friday->setText(QApplication::translate("addCourse", "Friday", 0));
        checkBox_Saturday->setText(QApplication::translate("addCourse", "Saturday", 0));
        label_6->setText(QApplication::translate("addCourse", "Select Days of week and times that this class meets.", 0));
        groupBox_grading->setTitle(QApplication::translate("addCourse", "Grading: *", 0));
#ifndef QT_NO_TOOLTIP
        checkBox_pointBased->setToolTip(QApplication::translate("addCourse", "Courses bases solely on points.", 0));
#endif // QT_NO_TOOLTIP
        checkBox_pointBased->setText(QApplication::translate("addCourse", "Point Based", 0));
#ifndef QT_NO_TOOLTIP
        groupBox_weighted->setToolTip(QApplication::translate("addCourse", "Courses with weighted (%) categories.", 0));
#endif // QT_NO_TOOLTIP
        groupBox_weighted->setTitle(QApplication::translate("addCourse", "Weighted", 0));
        label_4->setText(QApplication::translate("addCourse", "Category", 0));
        label_5->setText(QApplication::translate("addCourse", "%", 0));
        checkBox_category1->setText(QApplication::translate("addCourse", "1   ", 0));
        checkBox_category2->setText(QApplication::translate("addCourse", "2   ", 0));
        checkBox_category3->setText(QApplication::translate("addCourse", "3   ", 0));
        checkBox_category4->setText(QApplication::translate("addCourse", "4   ", 0));
        checkBox_category5->setText(QApplication::translate("addCourse", "5   ", 0));
        checkBox_category6->setText(QApplication::translate("addCourse", "6   ", 0));
        checkBox_category7->setText(QApplication::translate("addCourse", "7   ", 0));
        spinBox_category1->setSuffix(QString());
        spinBox_category1->setPrefix(QString());
        spinBox_category2->setSuffix(QString());
        spinBox_category2->setPrefix(QString());
        spinBox_category3->setSuffix(QString());
        spinBox_category3->setPrefix(QString());
        spinBox_category4->setSuffix(QString());
        spinBox_category4->setPrefix(QString());
        spinBox_category5->setSuffix(QString());
        spinBox_category5->setPrefix(QString());
        spinBox_category6->setSuffix(QString());
        spinBox_category6->setPrefix(QString());
        spinBox_category7->setSuffix(QString());
        spinBox_category7->setPrefix(QString());
        requiredLabel->setText(QApplication::translate("addCourse", "* indicates a required field", 0));
        saveCourses->setText(QApplication::translate("addCourse", "Save", 0));
        cancelCourses->setText(QApplication::translate("addCourse", "Cancel", 0));
        errorLabel->setText(QApplication::translate("addCourse", "+ERROR", 0));
    } // retranslateUi

};

namespace Ui {
    class addCourse: public Ui_addCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOURSE_H
