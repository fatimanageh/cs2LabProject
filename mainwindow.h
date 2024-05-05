#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum SelectedRole {
        Patient,
        Nurse,
        Doctor,
        Admin
    };

    QString sendSelectedRole();

private slots:
    void on_PatientPB_clicked();
    void on_DoctorPB_clicked();
    void on_NursePB_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SelectedRole selectedRole;
};

#endif // MAINWINDOW_H
