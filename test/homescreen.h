#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QMainWindow>

namespace Ui {
class homescreen;
}

class MainWindow;

class homescreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit homescreen(MainWindow *parent);
    ~homescreen();

private slots:
    void on_pushButton_clicked();

    //void on_tabWidget_destroyed();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::homescreen *ui;
    MainWindow *m_pMainWindow;
};

#endif // HOMESCREEN_H
