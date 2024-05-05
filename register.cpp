#include "register.h"
#include "ui_register.h"
#include "patient.h"
#include "login.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    role = new MainWindow;

    QFile patientData("C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt");
    if (!patientData.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing: PatientData.txt";
        return;
    }

    QFile doctorData("C:/Users/HP/Desktop/CS2 Lab Project/Doctor.txt");
    if (!doctorData.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing: DoctorData.txt";
        return;
    }

    QFile nurseData("C:/Users/HP/Desktop/CS2 Lab Project/Nurse.txt");
    if (!nurseData.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing: NurseData.txt";
        return;
    }

    patientData.close();
    doctorData.close();
    nurseData.close();
}

Register::~Register()
{
    delete ui;
}

void Register::saveVariables(const QString &filename, const QString &variable1, const QString &variable2)
{
    QFile file(filename);


    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing:" << filename;
        return;
    }
    QTextStream out(&file);
    out << variable1 << " " << variable2 << "\n";

    file.close();
}

void Register::on_LoginPB_clicked()
{
    QString name = ui->UsernameLE->text();


    role = new MainWindow;

    QString selectedRole = role->sendSelectedRole();
    QString filename;

    QString pass = ui->PasswordLE->text();
    QString retype = ui->confirmLE->text();

    if (pass != retype) {
        QMessageBox::critical(this, tr(""), tr("Password is not be equal"));
    } else if (pass==retype) {
    if (selectedRole == "Patient")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt";

        saveVariables(filename, name, pass);
        this->hide();
        Login *ll = new Login;
        ll->show();
    }
    else if (selectedRole == "Doctor")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Doctor.txt";

        saveVariables(filename, name, pass);
        this->hide();
        Login *ll = new Login;
        ll->show();
    }
    else if (selectedRole == "Nurse")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Nurse.txt";

        saveVariables(filename, name, pass);
        this->hide();
        Login *ll = new Login;
        ll->show();
    }
    else if (selectedRole == "Admin")
    {
        qDebug() << "Admin role selected";
        return;
    }
    }

}

void Register::on_Register_accepted()
{


}

