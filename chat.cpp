
#include "chat.h"
#include "ui_chat.h"
#include <QMessageBox>

Chat::Chat( QWidget *parent)
    : QDialog(parent), ui(new Ui::Chat) /*userType(userType)*/
{
    ui->setupUi(this);
    userType=Patient;
    connect(ui->sendMessage, &QPushButton::clicked, this, &Chat::sendMessage);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::sendMessage()
{

}

void Chat::on_sendMessage_clicked()
{
    QString message = ui->messageLineEdit->text();
    if (message.isEmpty()) {
        QMessageBox::warning(this, "Empty Message", "Please enter a message.");
        return;
    }


    QString sender;
    if (userType == Patient) {
        sender = "Patient:";
    } else if (userType == Nurse) {
        sender = "Nurse:";
    } else if (userType == Doctor) {
        sender = "Doctor:";
    }

    ui->messageTextEdit->append(sender + " " + message);
    ui->messageLineEdit->clear();
}

