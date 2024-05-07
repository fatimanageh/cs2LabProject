#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "QPixmap"
#include "register.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    selectedRole = "None";

    QPixmap pix("C:/Users/HP/Downloads/cs2LabProject-main/cs2LabProject-main/blur-hospital.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PatientPB_clicked()
{
    selectedRole = "Patient";
     Register* register1= new Register(selectedRole);
    this->hide();

    Login *login = new Login(selectedRole);
    login->show();
}

void MainWindow::on_DoctorPB_clicked()
{
    selectedRole = "Doctor";
      Register* register1= new Register(selectedRole);
    this->hide();

    Login *login = new Login(selectedRole);
    login->show();
}

void MainWindow::on_NursePB_clicked()
{
    selectedRole = "Nurse";
     Register* register1= new Register(selectedRole);
    this->hide();
    Login *login = new Login(selectedRole);
    login->show();
}

void MainWindow::on_pushButton_clicked()
{
    selectedRole = "aa";
     Register* register1= new Register(selectedRole);
    this->hide();
    Login *login = new Login(selectedRole);
    login->show();
}

// QString MainWindow::sendSelectedRole()
// {
//     qDebug()<<selectedRole;
//     return selectedRole;
// }
