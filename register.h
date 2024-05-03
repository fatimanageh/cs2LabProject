#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT


public:
    explicit Register(QWidget *parent = nullptr);
    void saveVariables(const QString& filename, const QString& variable1, const QString& variable2);

    ~Register();

private slots:
    void on_LoginPB_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
