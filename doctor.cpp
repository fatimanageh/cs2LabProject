#include "doctor.h"
#include "ui_doctor.h"
#include "admindata.h"
#include "doctorslots.h"
#include <QFile>
#include <QPixmap>

Doctor::Doctor( QString name, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doctor)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Downloads/composition-medical-objects-with-copyspace.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();
    this->name=name;
}

Doctor::~Doctor()
{
    delete ui;
}

QString Doctor::getName()
{
    return name;
}

QString Doctor::getAvaliableTimeSlots()
{
    return name;
}

void Doctor::on_patientrecord_clicked()
{
    QString filename = "C:/Users/HP/Desktop/CS2 Lab Project/Patient.txt";
    AdminData* admindata= new AdminData(filename);
    this->hide();
    admindata->show();
}

void Doctor::on_setslots_clicked()
{
    QString fileName= "C:/Users/HP/Desktop/CS2 Lab Project/Doctor slots.txt";
    Doctorslots* doctordata= new Doctorslots(fileName);
    this->hide();
    doctordata->show();
}

