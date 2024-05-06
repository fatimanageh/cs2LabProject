#ifndef LOGIN1_H
#define LOGIN1_H

#include <QDialog>

namespace Ui {
class Login1;
}

class Login1 : public QDialog
{
    Q_OBJECT

public:
    explicit Login1(QWidget *parent = nullptr);
    ~Login1();

private:
    Ui::Login1 *ui;
};

#endif // LOGIN1_H
