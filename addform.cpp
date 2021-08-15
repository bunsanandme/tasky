#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddForm)
{
    ui->setupUi(this);

    ui->date_input->setDate(QDate::currentDate());
    ui->time_input->setTime(QTime::currentTime());
}


AddForm::~AddForm()
{
    delete ui;
}


void AddForm::on_add_button_clicked()
{
    if(checkInput()) {
        QList<QString> task = {ui->date_input->text(),
                              ui->time_input->text(),
                              ui->place_input->toPlainText(),
                              ui->task_input->toPlainText(),
                              ui->note_input->toPlainText()};
        emit mySignal(task);
        ui->date_input->setDate(QDate::currentDate());
        ui->time_input->setTime(QTime::currentTime());
        ui->place_input->setPlainText("");
        ui->task_input->setPlainText("");
        ui->note_input->setPlainText("");
    }
}


bool AddForm::checkInput()
{
    if(ui->date_input->date() < QDate::currentDate()) {
        QMessageBox msgbox;
        msgbox.critical(this, "Ошибка",
                                   "Дата не может быть меньше нынешней!");
        return false;
    }

    if(ui->task_input->toPlainText() == "")
    {
        QMessageBox msgbox;
        msgbox.critical(this, "Ошибка",
                        "Поле задания пусто!");
        return false;
    }

    return true;
}

void AddForm::on_back_button_clicked()
{
    this->close();
}


