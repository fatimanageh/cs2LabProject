#include "admin.h"
#include "ui_admin.h"
#include "admindata.h"
#include<QPixmap>

Admin::Admin( QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/HP/Downloads/flat-lay-desk-arrangement-with-copy-space.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_PatientData_clicked()
{
     QString filename = "C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt";
    AdminData* admindata= new AdminData(filename);
     this->hide();
     admindata->show();
}


void Admin::on_doctorData_clicked()
{
        QString filename ="C:/Users/HP/Desktop/CS2 Lab Project/Doctor.txt";
        AdminData* admindata= new AdminData(filename);
        this->hide();
    admindata->show();
}


void Admin::on_nurseData_clicked()
{

    QString filename ="C:/Users/HP/Desktop/CS2 Lab Project/Nurse.txt";
    AdminData* admindata= new AdminData(filename);
    this->hide();
    admindata->show();

}


void Admin::on_system_clicked()
{


}

