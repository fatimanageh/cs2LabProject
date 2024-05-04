#include "patient.h"
#include "ui_patient.h"
#include "chat.h"
#include "requestappoint.h"
#include <QFileDialog>
#include <QMessageBox>

Patient::Patient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Patient)
{
    ui->setupUi(this);
}

Patient::~Patient()
{
    delete ui;
}

void Patient::setUsername(const QString &username)
{
    this->username1=username;

}
void Patient::on_medicalRecord_clicked()
{
    QString filePath= "C:/Users/HP/Desktop/Hospital/Medical Record.txt";
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString line;
            bool found = false;
            while (!in.atEnd()) {
                line = in.readLine();
                qDebug()<<username1;
                if (line.startsWith(username1)) {
                    found = true;
                    break;
                }
            }
            file.close();
            if (found) {

                QMessageBox::information(this, tr("Medical Record"), line);
            } else {

                QMessageBox::information(this, tr("Error"), tr("Username not found in the file."));
            }
        } else {

            QMessageBox::critical(this, tr("Error"), tr("Failed to open the file."));
        }
    }
}



void Patient::on_Appointment_clicked()
{
    RequestAppoint* request=new RequestAppoint;
    request->show();
}


void Patient::on_chat_clicked()
{

    Chat* chat=new Chat;
  chat->show();
}

