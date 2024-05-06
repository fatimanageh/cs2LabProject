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
    QPixmap pix("C:/Users/HP/Downloads/abstract-blur-hospital-clinic-interior.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, geometry().width(), geometry().height());
    backgroundLabel->lower();
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

                QMessageBox::information(this, "Medical Record", line);
            } else {

                QMessageBox::information(this, "Error", "Username not found in the file.");
            }
        } else {

            QMessageBox::critical(this, "Error", "Failed to open the file.");
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

