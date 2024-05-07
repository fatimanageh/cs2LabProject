#ifndef PATIENT_H
#define PATIENT_H

#include <QDialog>
#include <QLabel>
namespace Ui {
class Patient;
}

class Patient : public QDialog
{
    Q_OBJECT

public:
    explicit Patient(QWidget *parent = nullptr);
    ~Patient();
  void setUsername(const QString &username);
    QLabel* backgroundLabel;
private slots:
    void on_medicalRecord_clicked();


    void on_Appointment_clicked();

    void on_chat_clicked();

    void on_Back_clicked();

private:
    Ui::Patient *ui;
    QString username1;
};

#endif // PATIENT_H
