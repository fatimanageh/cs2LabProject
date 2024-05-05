#include "requestappoint.h"
#include "ui_requestappoint.h"


RequestAppoint::RequestAppoint(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RequestAppoint)
{
    ui->setupUi(this);
    loadDoctorData();
}

RequestAppoint::~RequestAppoint()
{
    delete ui;
}

void RequestAppoint::loadDoctorData()
{


}

void RequestAppoint::handleAppointmentRequest()
{


}
