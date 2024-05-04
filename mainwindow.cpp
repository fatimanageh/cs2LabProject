#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    selectedRole = Patient;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PatientPB_clicked()
{
    selectedRole = Patient;
    this->hide();
    Login *login = new Login;
    login->show();
}

void MainWindow::on_DoctorPB_clicked()
{
    selectedRole = Doctor;
    this->hide();
    Login *login = new Login;
    login->show();
}

void MainWindow::on_NursePB_clicked()
{
    selectedRole = Nurse;
    this->hide();
    Login *login = new Login;
    login->show();
}

void MainWindow::on_pushButton_clicked()
{
    selectedRole = Admin;
    this->hide();
    Login *login = new Login;
    login->show();
}

QString MainWindow::sendSelectedRole()
{
    switch (selectedRole) {
    case Patient: return "Patient";
    case Nurse: return "Nurse";
    case Doctor: return "Doctor";
    case Admin: return "Admin";
    }
    return "";
}
