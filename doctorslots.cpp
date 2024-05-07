#include "doctorslots.h"
#include "ui_doctorslots.h"
#include "doctor.h"
#include <QFile>

Doctorslots::Doctorslots(QString name, QString file, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doctorslots)
{
    ui->setupUi(this);
    this->file = file;
   this->name=name;
    found= false;
}

Doctorslots::~Doctorslots()
{
    delete ui;
}

void Doctorslots::on_slots_copyAvailable(bool b)
{

}

void Doctorslots::on_Add_clicked()
{
    QString fileContent = ui->textEdit->toPlainText();

    QFile file1(file);
    if (!file1.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for appending:" << file;
        return;
    }

    QTextStream in(&file1);
    QString line;
    QString fileData;
    bool found = false;

    while (!in.atEnd()) {
        line = in.readLine();
        if (line.startsWith(name)) {
            found = true;
            fileData += line + '\n';
        } else {
            fileData += line + '\n';
        }
    }

    if (found) {
        fileData += fileContent + '\n';
        file1.resize(0);
        file1.write(fileData.toUtf8());
    }

    file1.close();

    ui->textEdit->clear();
}

void Doctorslots::on_textEdit_copyAvailable(bool b)
{

}


void Doctorslots::on_Back_clicked()
{
    Doctor* doctor= new Doctor("");
    doctor->show();
    this->hide();
}

