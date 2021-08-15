#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>
#include <iostream>
#include <QDebug>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

using namespace std;

namespace Ui {
class AddForm;
}

class AddForm : public QWidget
{
    Q_OBJECT

public:
    Ui::AddForm *ui;
    AddForm(QWidget *parent = nullptr);
    ~AddForm();


signals:
    void mySignal(const QList<QString> &text);

public slots:
    void on_add_button_clicked();

    void on_back_button_clicked();

private:
    bool checkInput();

};

#endif // ADDFORM_H
