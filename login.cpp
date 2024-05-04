#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "patient.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    role = new MainWindow;
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginPB_clicked()
{
    QString name = ui->UsernameLE->text();
    QString pass = ui->PasswordLE->text();
    QString selectedRole = role->sendSelectedRole();
    QString filename;

    // if (selectedRole == "Patient")
    // {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt";
    // }
  if (selectedRole == "Doctor")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Doctor.txt";
    }
    else if (selectedRole == "Nurse")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Nurse.txt";
    }
    else if (selectedRole == "Admin")
    {
        qDebug() << "Admin role selected";
        return;
    }

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file for reading:" << filename;
        return;
    }

    bool found = false;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data = line.split(" ");
        if (data.size() >= 2 && data[0] == name && data[1] == pass)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
    {
        if (selectedRole == "Patient")
        {
            Patient *patient = new Patient;
            patient->setUsername(name);
            this->hide();
            patient->show();
        }
        else if (selectedRole == "Doctor")
        {

        }
        else if (selectedRole == "Nurse")
        {

        }
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Username or password is not correct. Please try again or register a new account.");
    }
}

void Login::on_RegisterPB_clicked()
{
    this->hide();
    Register *rr = new Register;
    rr->show();
}
