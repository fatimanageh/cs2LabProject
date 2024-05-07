#include "nurse.h"
#include "ui_nurse.h"
#include "admindata.h"
#include "mainwindow.h"
#include <QPixmap>
Nurse::Nurse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Nurse)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Downloads/cs2LabProject-main/cs2LabProject-main/clipboard-stethoscope.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();
}

Nurse::~Nurse()
{
    delete ui;
}

void Nurse::on_patientRecord_clicked()
{
    QString filename = "C:/Users/HP/Desktop/CS2 Lab Project/Medical Record.txt";
    AdminData* admindata= new AdminData(filename);
    this->hide();
    admindata->show();
}


void Nurse::on_Back_clicked()
{
    MainWindow* mainwindow= new MainWindow;
    mainwindow->show();
    this->hide();
}

