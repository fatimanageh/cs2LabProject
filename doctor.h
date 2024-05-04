#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>
#include <QList>

class Doctor
{
public:
    Doctor(const QString& name, const QString& specialization);

    QString getName() const;
    QString getSpecialization() const;

    void loadAppointmentsFromFile(const QString& fileName);
    void viewAppointments() const;
    void editAppointment(int index, const QString& updatedDetails);
    void acceptAppointment(int index);
    void declineAppointment(int index);

private:
    QString name;
    QString specialization;
    QList<QString> appointments;
};

#endif // DOCTOR_H
