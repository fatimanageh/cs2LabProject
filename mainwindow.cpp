#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PatientPB_clicked()
{
    this->hide();
    Login* login=new Login;
    login->show();
}


void MainWindow::on_DoctorPB_clicked()
{
    this->hide();
    Login* login=new Login;
    login->show();
}


void MainWindow::on_NursePB_clicked()
{
    this->hide();
    Login* login=new Login;
    login->show();
}


void MainWindow::on_pushButton_clicked()
{
    this->hide();
    Login* login=new Login;
    login->show();
}

