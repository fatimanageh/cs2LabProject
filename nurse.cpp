#include "nurse.h"
#include "ui_nurse.h"

Nurse::Nurse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Nurse)
{
    ui->setupUi(this);
}

Nurse::~Nurse()
{
    delete ui;
}
