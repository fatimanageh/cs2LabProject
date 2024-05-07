#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "patient.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
Login::Login(QString selectedRole, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    role = new MainWindow;
    this->selectedRole=selectedRole;
    QPixmap pix("C:/Users/HP/Downloads/cs2LabProject-main/cs2LabProject-main/3632097.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginPB_clicked()
{
    QString name = ui->UsernameLE->text();
    // Doctor* doctor=new Doctor(name);
    QString pass = ui->PasswordLE->text();
    // QString selectedRole = role->sendSelectedRole();
       qDebug()<<selectedRole;

    QString filename;

    if (selectedRole == "Patient")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt";
    }
  if (selectedRole == "Doctor")
    {
        filename ="C:/Users/HP/Desktop/CS2 Lab Project/Doctor.txt";
    }
    else if (selectedRole == "Nurse")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Nurse.txt";
    }
    else if (selectedRole == "aa")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Admin.txt";
    }

    qDebug()<<filename;

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
            Doctor* doctor=new Doctor(name);
            this->hide();
            doctor->show();
        }

        else if( selectedRole== "aa"){
            Admin* admin= new Admin;
            this->hide();
            admin->show();
        }
        else if (selectedRole == "Nurse")
        {
            Nurse* nurse= new Nurse;
            this->hide();
            nurse->show();

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
    Register *rr = new Register(selectedRole);
    rr->show();
}
