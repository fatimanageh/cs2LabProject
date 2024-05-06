#ifndef NURSE_H
#define NURSE_H

#include <QDialog>
#include <QLabel>
namespace Ui {
class Nurse;
}

class Nurse : public QDialog
{
    Q_OBJECT

public:
    explicit Nurse(QWidget *parent = nullptr);
    ~Nurse();
    QLabel* backgroundLabel;
private slots:
    void on_patientRecord_clicked();

private:
    Ui::Nurse *ui;
};

#endif // NURSE_H
