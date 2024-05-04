#include "requestappoint.h"
#include "ui_requestappoint.h"

RequestAppoint::RequestAppoint(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RequestAppoint)
{
    ui->setupUi(this);
}

RequestAppoint::~RequestAppoint()
{
    delete ui;
}
