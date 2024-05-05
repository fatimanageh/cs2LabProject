#include "doctor.h"
#include "ui_doctor.h"

Doctor::Doctor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doctor)
{
    ui->setupUi(this);
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
