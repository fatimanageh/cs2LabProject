#ifndef REQUESTAPPOINT_H
#define REQUESTAPPOINT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSet>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class RequestAppoint;
}
QT_END_NAMESPACE

class RequestAppoint : public QDialog
{
    Q_OBJECT

public:
    RequestAppoint(QWidget *parent = nullptr);
    ~RequestAppoint();

private slots:
    void handleSlotButtonClicked();

private:
    Ui::RequestAppoint *ui;
    QVBoxLayout *layout;
    QFile file;
    QSet<QString> alreadyRequested;

    void loadDoctorData();
};

#endif // REQUESTAPPOINT_H
