#include "register.h"
#include"login.h"
#include "ui_register.h"
#include "patient.h"
#include<QFile>
#include<QTextStream>
#include <QDebug>


Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
}

void Register::saveVariables(const QString &filename, const QString &variable1, const QString &variable2)
{
    QFile file("C:/Users/HP/Desktop/Hospital/data.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text)){

        qDebug() << "Could not open file for reading";
        return;

    }
    QTextStream out(&file);
    out<<variable1<<" ";
    out<<variable2<<"\n";

    file.close();


}


Register::~Register()
{
    {
        delete ui;
    }
}


void Register::on_LoginPB_clicked()
{
    QString name=ui->UsernameLE->text();
    QString pass=ui->PasswordLE->text();

    saveVariables("data",name,pass);

    Patient* patient;

    patient->setUsername(name);

    this->hide();
    Login* ll=new Login;
    ll->show();
}

