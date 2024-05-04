#ifndef REQUESTAPPOINT_H
#define REQUESTAPPOINT_H

#include <QDialog>
#include <QVector>
#include <QPushButton>
#include "doctor.h"

namespace Ui {
class RequestAppoint;
}

class RequestAppoint : public QDialog
{
    Q_OBJECT

public:
    explicit RequestAppoint(QWidget *parent = nullptr);
    ~RequestAppoint();

private slots:
    void handleAppointmentRequest();

private:
    Ui::RequestAppoint *ui;
    QVector<Doctor> doctors;

    void loadDoctorData();
};

#endif // REQUESTAPPOINT_H
