#ifndef REQUESTAPPOINT_H
#define REQUESTAPPOINT_H

#include <QDialog>

namespace Ui {
class RequestAppoint;
}

class RequestAppoint : public QDialog
{
    Q_OBJECT

public:
    explicit RequestAppoint(QWidget *parent = nullptr);
    ~RequestAppoint();

private:
    Ui::RequestAppoint *ui;
};

#endif // REQUESTAPPOINT_H
