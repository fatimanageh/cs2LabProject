#include "login.h"
#include "ui_login.h"
#include"register.h"
#include "patient.h"
#include<QFile>
#include<QTextStream>
#include<QtDebug>
#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    mainwindow=new MainWindow;
}


Login::~Login()
{


    delete ui;
}




void Login::on_LoginPB_clicked()
{

    QString name=ui->UsernameLE->text();
    QString pass=ui->PasswordLE->text();
    QString x=mainwindow->sendSelectedRole();
    qDebug()<< mainwindow->sendSelectedRole();
    // if(x=="Pateint") {

        Patient* patient= new Patient;
        patient->show();
    // }
    QFile file(":/../../../Desktop/Hospital/data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }

    QTextStream in(&file);
    bool found = false;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" "); // Assuming username and password are separated by a space
        if (parts.size() == 2 && parts[0] == name && parts[1] == pass) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        qDebug() << "Login successful";
        // Proceed with login logic
    } else {
        qDebug() << "Login failed";
        // Display error message
    }


}


void Login::on_RegisterPB_clicked()
{
    this->hide();
    Register* rr = new Register;
    rr->show();
}

