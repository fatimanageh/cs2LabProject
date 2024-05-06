#ifndef DOCTORSLOTS_H
#define DOCTORSLOTS_H

#include <QDialog>

namespace Ui {
class Doctorslots;
}

class Doctorslots : public QDialog
{
    Q_OBJECT

public:
    explicit Doctorslots(QString file, QWidget *parent = nullptr);
    ~Doctorslots();
    QString file;

private slots:
    void on_slots_copyAvailable(bool b);

    void on_Add_clicked();


    void on_textEdit_copyAvailable(bool b);

private:
    Ui::Doctorslots *ui;
};

#endif // DOCTORSLOTS_H
