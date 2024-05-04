#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QString>
#include "mainwindow.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_LoginPB_clicked();
    void saveVariables(const QString &filename, const QString &variable1, const QString &variable2);

    void on_Register_accepted();

private:
    Ui::Register *ui;
    MainWindow *role;
};

#endif // REGISTER_H
