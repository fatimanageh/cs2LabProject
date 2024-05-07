#include "requestappoint.h"
#include "ui_requestappoint.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

RequestAppoint::RequestAppoint(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::RequestAppoint),
    file("C:/Users/HP/Desktop/CS2 Lab Project/Doctor slots.txt")
{
    ui->setupUi(this);
    QVBoxLayout *scrollLayout = new QVBoxLayout(ui->scrollArea);
    QWidget *scrollWidget = new QWidget(ui->scrollArea);
    ui->scrollArea->setWidget(scrollWidget);
    layout = new QVBoxLayout(scrollWidget);
    scrollLayout->addWidget(scrollWidget);
    loadDoctorData();
}


RequestAppoint::~RequestAppoint()
{
    delete ui;
    delete layout;
}

void RequestAppoint::loadDoctorData()
{
    // QFile file("C:/Users/HP/Desktop/CS2 Lab Project/Doctor slots.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file in the request appoint";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(':');
        QString doctorName = parts.value(0).trimmed();
        QString availability = parts.value(1).trimmed();

        if (availability == "Yes") {
            continue;
        }

        QWidget *widget = new QWidget();
        QHBoxLayout *hLayout = new QHBoxLayout(widget);

        QPushButton *button = new QPushButton("Request");
        QLabel *label = new QLabel(line);

        button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button->setFixedSize(80, 30);

        hLayout->addWidget(button);
        hLayout->addWidget(label);

        layout->addWidget(widget);

        connect(button, &QPushButton::clicked, this, &RequestAppoint::handleSlotButtonClicked);
    }

    file.close();
}



void RequestAppoint::handleSlotButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    QWidget *widget = button->parentWidget();
    QLabel *label = widget->findChild<QLabel *>();
    if (!label)
        return;

    QString labelText = label->text();
    QString doctorName = labelText.left(labelText.indexOf(':')).trimmed();

    if (alreadyRequested.contains(doctorName)) {
        QMessageBox::information(this, "Already Requested", "You have already requested an appointment for this doctor.");
        return;
    }

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Could not open the file in the request appoint to search and update the line";
        return;
    }

    QString updatedFileContents;
    QTextStream stream(&file);

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList parts = line.split(':');
        QString currentDoctorName = parts.value(0).trimmed();
        QString availability = parts.value(1).trimmed();

        if (currentDoctorName == doctorName && availability != "Yes") {
            line = currentDoctorName + ": Yes";
            alreadyRequested.insert(doctorName); // Add doctorName to the set of already requested doctors
        }

        updatedFileContents += line + "\n";
    }

    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file for writing in the request appoint to update the line";
        return;
    }
    QTextStream out(&file);
    out << updatedFileContents;
    file.close();
}
