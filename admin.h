#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    QLabel* backgroundLabel;
    ~Admin();

private slots:
    void on_PatientData_clicked();

    void on_doctorData_clicked();

    void on_nurseData_clicked();

    void on_system_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
