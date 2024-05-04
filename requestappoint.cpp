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


    // // doctors = readDoctorDataFromFile();

    // ui->listWidget->clear();


    // for (const Doctor& doctor : doctors)
    // {
    //     QString doctorInfo = doctor.getName() + " - Available Time Slots: ";

    //     for (const QString& timeSlot : doctor.getAvaliableTimeSlots())
    //     {
    //         doctorInfo += timeSlot + ", ";
    //     }


    //     QListWidgetItem* item = new QListWidgetItem(doctorInfo, ui->listWidget);


    //     QPushButton* button = new QPushButton("Request Appointment");
    //     button->setProperty("doctorIndex", QVariant::fromValue(doctors.indexOf(doctor)));


    //     connect(button, &QPushButton::clicked, this, &RequestAppoint::handleAppointmentRequest);


    //     ui->listWidget->setItemWidget(item, button);
    // }
}

void RequestAppoint::handleAppointmentRequest()
{

    // QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    // int doctorIndex = clickedButton->property("doctorIndex").toInt();


    // if (doctorIndex >= 0 && doctorIndex < doctors.size())
    // {
    //     // Doctor selectedDoctor = doctors[doctorIndex];

    //     // Perform the appointment request with the selected doctor
    //     // Example code:
    //     // requestAppointment(selectedDoctor);

    //     qDebug() << "Appointment requested with doctor: " << selectedDoctor.getName();
    // }
}
