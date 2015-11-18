 #include "homescreen.h"
#include "ui_homescreen.h"
#include "mainwindow.h"

homescreen::homescreen(MainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::homescreen)
{
    m_pMainWindow = parent;
    ui->setupUi(this);
}

homescreen::~homescreen()
{
    delete ui;
}

void homescreen::on_pushButton_clicked()
{
    m_pMainWindow->show();
}

void homescreen::on_tabWidget_currentChanged(int index)
{

}
