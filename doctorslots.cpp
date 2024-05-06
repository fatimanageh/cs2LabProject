#include "doctorslots.h"
#include "ui_doctorslots.h"
#include <QFile>

Doctorslots::Doctorslots(QString file, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doctorslots)
{
    ui->setupUi(this);
    this->file = file;
    // QFile file1(file);

    // if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    // {
    //     qDebug() << "Could not open file for reading:" << file;
    //     return;
    // }

    // QString fileContent;
    // QTextStream in(&file1);
    // while (!in.atEnd())
    // {
    //     QString line = in.readLine();
    //     fileContent.append(line).append('\n');
    // }
    // file1.close();

  // ui->textEdit->
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
    QString fileContent = ui->textEdit->toPlainText(); // Get the content from the text edit

    QFile file1(file);
    if (!file1.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Could not open file for appending:" << file;
        return;
    }

    QTextStream out(&file1);
    out << fileContent << '\n'; // Write the content to the file

    file1.close();

    ui->textEdit->clear();
}


void Doctorslots::on_textEdit_copyAvailable(bool b)
{

}

