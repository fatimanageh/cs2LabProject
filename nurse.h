#ifndef NURSE_H
#define NURSE_H

#include <QDialog>

namespace Ui {
class Nurse;
}

class Nurse : public QDialog
{
    Q_OBJECT

public:
    explicit Nurse(QWidget *parent = nullptr);
    ~Nurse();

private:
    Ui::Nurse *ui;
};

#endif // NURSE_H
