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
    explicit Doctorslots(QString name, QString file, QWidget *parent = nullptr);
    ~Doctorslots();
    QString file;
     QString name;
    bool found;

private slots:
    void on_slots_copyAvailable(bool b);

    void on_Add_clicked();


    void on_textEdit_copyAvailable(bool b);

    void on_Back_clicked();

private:
    Ui::Doctorslots *ui;
};

#endif // DOCTORSLOTS_H
