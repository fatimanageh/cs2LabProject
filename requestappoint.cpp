#include "requestappoint.h"
#include "ui_requestappoint.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

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

    // QFile file("C:/Users/HP/Desktop/CS2 Lab Project/Doctor slots.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Could not open the file in the request appoint to request an appointment";
        return;
    }

    QTextStream stream(&file);
    QString line;
    QString updatedFileContents;

    while (!stream.atEnd()) {
        line = stream.readLine();
        if (line.startsWith(doctorName)) {
            QStringList parts = line.split(':');
            QString availability = parts.value(1).trimmed();
            if (availability != "Yes") {
                QHBoxLayout *layout = qobject_cast<QHBoxLayout *>(widget->layout());
                QPushButton *cancelButton = new QPushButton("Cancel");
                cancelButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                cancelButton->setFixedSize(80, 30);
                layout->replaceWidget(button, cancelButton);
                layout->addWidget(label);

                connect(cancelButton, &QPushButton::clicked, this, &RequestAppoint::handleCancelButtonClicked);

                parts[1] = "Yes";
                line = parts.join(':');
            }
        }
        updatedFileContents += line + "\n";
    }

    file.resize(0);
    stream << updatedFileContents;
    file.close();
}

void RequestAppoint::handleCancelButtonClicked()
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

    // QFile file("C:/Users/HP/Desktop/CS2 Lab Project/Doctor slots.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Could not open the file in the request appoint to cancelan appointment";
        return;
    }

    QTextStream stream(&file);
    QString line;
    QString updatedFileContents;

    while (!stream.atEnd()) {
        line = stream.readLine();
        if (line.startsWith(doctorName)) {
            QStringList parts = line.split(':');
            QString availability = parts.value(1).trimmed();
            if (availability == "Yes") {
                QHBoxLayout *layout = qobject_cast<QHBoxLayout *>(widget->layout());
                QPushButton *requestButton = new QPushButton("Request");
                requestButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                requestButton->setFixedSize(80, 30);
                layout->replaceWidget(button, requestButton);
                layout->addWidget(label);
                connect(requestButton, &QPushButton::clicked, this, &RequestAppoint::handleSlotButtonClicked);

                parts[1] = "No";
                line = parts.join(':');
            }
        }
        updatedFileContents += line + "\n";
    }

    file.resize(0);
    stream << updatedFileContents;
    file.close();
}
