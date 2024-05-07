#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QString>
#include "mainwindow.h"
#include <QLabel>
#include <QFile>
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(  QString selectedRole, QWidget *parent = nullptr);
    ~Register();
    QLabel* backgroundLabel;
    QFile patientData;

private slots:
    void on_LoginPB_clicked();
    void saveVariables(const QString &filename, const QString &variable1, const QString &variable2);

    void on_Register_accepted();

private:
    Ui::Register *ui;
    MainWindow *role;
    QString selectedRole;
};

#endif // REGISTER_H
