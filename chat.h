
#ifndef CHAT_H
#define CHAT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Chat; }
QT_END_NAMESPACE

class Chat : public QDialog
{
    Q_OBJECT

public:
    enum UserType {
        Patient,
        Nurse,
        Doctor
    };

    Chat( QWidget *parent = nullptr);
    ~Chat();

private slots:
    void sendMessage();

    void on_sendMessage_clicked();

private:
    Ui::Chat *ui;
    UserType userType;
};

#endif
