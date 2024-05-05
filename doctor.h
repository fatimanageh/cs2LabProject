#ifndef DOCTOR_H
#define DOCTOR_H

#include <QDialog>

namespace Ui {
class Doctor;
}

class Doctor : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor(QWidget *parent = nullptr);
    ~Doctor();
    QString getName();
    QString getAvaliableTimeSlots();

private:
    Ui::Doctor *ui;
    QString name;

};

#endif // DOCTOR_H
