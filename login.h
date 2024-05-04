#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    MainWindow* role;
private slots:
    void on_LoginPB_clicked();

    void on_RegisterPB_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
