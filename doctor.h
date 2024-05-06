#ifndef DOCTOR_H
#define DOCTOR_H

#include <QDialog>
#include <QLabel>
namespace Ui {
class Doctor;
}

class Doctor : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor(QString name, QWidget *parent = nullptr);
    ~Doctor();
    QString getName();
    QString getAvaliableTimeSlots();
    QLabel* backgroundLabel;
private slots:
    void on_patientrecord_clicked();

    void on_setslots_clicked();

private:
    Ui::Doctor *ui;
    QString name;

};

#endif // DOCTOR_H
