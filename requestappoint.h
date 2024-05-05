#ifndef REQUESTAPPOINT_H
#define REQUESTAPPOINT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class RequestAppoint;
}

class RequestAppoint : public QDialog
{
    Q_OBJECT

public:
    explicit RequestAppoint(QWidget *parent = nullptr);
    ~RequestAppoint();

private slots:
    void handleSlotButtonClicked();
    void handleCancelButtonClicked();

private:
    Ui::RequestAppoint *ui;
    QVBoxLayout *layout;

    void loadDoctorData();
};

#endif // REQUESTAPPOINT_H
