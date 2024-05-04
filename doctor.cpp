#include "doctor.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

Doctor::Doctor(const QString& name, const QString& specialization)
    : name(name), specialization(specialization)
{
}

QString Doctor::getName() const
{
    return name;
}

QString Doctor::getSpecialization() const
{
    return specialization;
}

void Doctor::loadAppointmentsFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString appointment = in.readLine();
            appointments.append(appointment);
        }
        file.close();
    }
}

void Doctor::viewAppointments() const
{
    qDebug() << "Appointments for Doctor" << getName() << ":";
    for (int i = 0; i < appointments.size(); ++i)
    {
        qDebug() << i + 1 << appointments[i];
    }
}

void Doctor::editAppointment(int index, const QString& updatedDetails)
{
    if (index >= 0 && index < appointments.size())
    {
        appointments[index] = updatedDetails;
        qDebug() << "Appointment" << index + 1 << "updated.";
    }
}

void Doctor::acceptAppointment(int index)
{
    if (index >= 0 && index < appointments.size())
    {
        qDebug() << "Appointment" << index + 1 << "accepted.";
    }
}

void Doctor::declineAppointment(int index)
{
    if (index >= 0 && index < appointments.size())
    {
        qDebug() << "Appointment" << index + 1 << "declined.";
    }
}
