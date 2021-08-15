#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "addform.h"

#include <QMainWindow>
#include <QMessageBox>
#include <iostream>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class TaskManager; }
QT_END_NAMESPACE

class TaskManager : public QMainWindow
{
    Q_OBJECT

public:
    TaskManager(QWidget *parent = nullptr);
    ~TaskManager();

public slots:
    void mySlot(const QList<QString> &text);

private slots:

    void on_calendar_activated(const QDate &date);

    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_quit_action_triggered();

    void on_about_action_triggered();


private:
    Ui::TaskManager *ui;
    QSqlDatabase db;
    AddForm* af;
};
#endif // TASKMANAGER_H
