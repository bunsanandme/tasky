#include "taskmanager.h"
#include "ui_taskmanager.h"
#include "addform.h"

TaskManager::TaskManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    af = new AddForm;
    connect(af, SIGNAL(mySignal(const QList<QString> &)), this, SLOT(mySlot(const QList<QString> &)));
    ui->table_view->setColumnWidth(0, 75);
    ui->table_view->setColumnWidth(2, 184);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\PROECT\\tmanager.db3");
    if (!db.open()) {
          qDebug() << db.lastError().text();
    }
    QString stylesheet = "::section{Background-color:rgb(64, 191, 138); color: rgb(243, 243, 243); border-style: none;}";
    ui->table_view->horizontalHeader()->setStyleSheet(stylesheet);
    ui->table_view->horizontalHeader()->setFixedHeight(24);
    on_calendar_activated(QDate::currentDate());
}

TaskManager::~TaskManager()
{
    delete ui;
    delete af;
}


void TaskManager::on_add_button_clicked()
{
    af->show();
}



void TaskManager::on_calendar_activated(const QDate &date)
{
    ui->table_view->setRowCount(0);

    if (!db.open()) {
        qDebug() << db.lastError().text();
    }
    else {
        QSqlQuery query(db);
        query.prepare(QString("SELECT TIME,PLACE,TASK,NOTE FROM events WHERE DATE = %1").arg("\"" + date.toString("dd.MM.yyyy") + "\""));
        if(!query.exec()) {
            qDebug() << query.lastError().text();
        }
        else {
            int size_of_query = 0;
            while(query.next()) {
                ui->table_view->insertRow(ui->table_view->rowCount());
                for(int i = 0; i < 4; i++) {
                    QTableWidgetItem* item = new QTableWidgetItem();
                    item->setText(query.value(i).toString());
                    ui->table_view->setItem(ui->table_view->rowCount()-1,i,item);
                size_of_query++;
                }
            }
            if (!(size_of_query > 0)) {
                ui->table_view->insertRow(ui->table_view->rowCount());
                QTableWidgetItem* item = new QTableWidgetItem();
                item->setText(QString("          Тут пока ничего нет"));
                ui->table_view->setItem(ui->table_view->rowCount()-1,2,item);
            }
        }
    }
}


void TaskManager::on_delete_button_clicked()
{
    QString task;
    QModelIndexList selectedRows = ui->table_view->selectionModel()->selectedRows();
    if(!selectedRows.isEmpty()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Внимание", "Уверены, что нужно удалить задание?",
                                          QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          task = ui->table_view->item(ui->table_view->selectionModel()->selectedRows()[0].row(),2)->text();
        }
        if (!db.open()) {
            qDebug() << db.lastError().text();
        }
        else {
            QSqlQuery query(db);
            query.prepare(QString("DELETE FROM events WHERE DATE = %1 AND TASK = %2").arg("\"" + ui->calendar->selectedDate().toString("dd.MM.yyyy") + "\"").arg("\"" + task + "\""));
            query.exec();
            ui->table_view->removeRow(selectedRows[0].row());
            QMessageBox msgbox_suc_del;
            msgbox_suc_del.information(this,"Успех!","Задание успешно убрано!");
        }
    }
}


void TaskManager::on_quit_action_triggered()
{
    this->close();
}


void TaskManager::on_about_action_triggered()
{
    QMessageBox msgbox;
    msgbox.information(this, "О программе",
                               "Tasky 0.1\nCreated by __");
}

void TaskManager::mySlot(const QList<QString> &task) {
    if (!db.open()) {
        qDebug() << db.lastError().text();
    }
    else {
        QSqlQuery query(db);
        query.prepare(QString("INSERT INTO events VALUES (%1, %2, %3, %4, %5);").arg("\"" + task[0] + "\"").arg("\"" + task[1] + "\"").arg("\"" + task[2] + "\"").arg("\"" + task[3] + "\"").arg("\"" + task[4] + "\""));
        query.exec();
    }
    QMessageBox msgbox_suc;
    af->hide();
    on_calendar_activated(ui->calendar->selectedDate());
    msgbox_suc.information(this,"Успех!","Задание успешно добавлено!");

}

