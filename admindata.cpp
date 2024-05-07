#include "admindata.h"
#include "ui_admindata.h"
#include "mainwindow.h"
#include "admin.h"
#include <QFile>

AdminData::AdminData(QString file, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminData)
{
    ui->setupUi(this);
    this->file = file;
    QFile file1(file);
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file for reading:" << file;
        return;
    }

    QString fileContent;
    QTextStream in(&file1);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        fileContent.append(line).append('\n');
    }
    file1.close();

    ui->viewData->setPlainText(fileContent);

}

AdminData::~AdminData()
{
    delete ui;
}

void AdminData::on_viewData_cursorPositionChanged(int arg1, int arg2)
{

}


void AdminData::on_back_clicked()
{
    this->hide();
    Admin* admin= new Admin;
    admin->show();
}

void AdminData::on_save_clicked()
{
    QFile file1(file);
    if (!file1.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file for writing:" << file;
        return;
    }

    QTextStream out(&file1);
    QStringList lines = ui->viewData->toPlainText().split('\n');

    for (const QString& line : lines)
    {
        out << line << '\n';
    }

    file1.close();
}

