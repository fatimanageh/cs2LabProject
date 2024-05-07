#include "register.h"
#include "ui_register.h"
#include "patient.h"
#include "login.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
Register::Register(QString selectedRole, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register),
    patientData("C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt")
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/HP/Downloads/cs2LabProject-main/cs2LabProject-main/vintage-grunge-blue-concrete-texture-studio-wall-background-with-vignette.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();
    role = new MainWindow;

    this->selectedRole=selectedRole;

    if (!patientData.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing:";
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
    QFile file1("C:/Users/HP/Desktop/CS2 Lab Project/Medical Record.txt");

    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing:" << filename;
        return;
    }

    QTextStream out(&file);
    out << variable1 << " " << variable2<< "\n";

    if (filename == "C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt")
    {
        if (!file1.open(QIODevice::Append | QIODevice::Text))
        {
            qDebug() << "Could not open file for writing: Medical Record.txt";
            return;
        }

        QTextStream out2(&file1);
        out2 << variable1 << " " <<"\n";

        file1.close();
    }

    file.close();
}

void Register::on_LoginPB_clicked()
{
    QString name = ui->UsernameLE->text();


    role = new MainWindow;

    // QString selectedRole = "None";
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
        Login *ll = new Login(selectedRole);
        ll->show();
    }
    else if (selectedRole == "Doctor")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Doctor.txt";

        saveVariables(filename, name, pass);
        this->hide();
        Login *ll = new Login(selectedRole);
        ll->show();
    }
    else if (selectedRole == "Nurse")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Nurse.txt";

        saveVariables(filename, name, pass);
        this->hide();
        Login *ll = new Login(selectedRole);
        ll->show();
    }
    else if (selectedRole == "aa")
    {
        filename = "C:/Users/HP/Desktop/CS2 Lab Project/Admin.txt";

        saveVariables(filename, name, pass);
        this->hide();
        Login *ll = new Login(selectedRole);
        ll->show();
    }
    }

}

void Register::on_Register_accepted()
{


}

