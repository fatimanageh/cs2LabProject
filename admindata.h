#ifndef ADMINDATA_H
#define ADMINDATA_H

#include <QDialog>

namespace Ui {
class AdminData;
}

class AdminData : public QDialog
{
    Q_OBJECT

public:
    explicit AdminData(QString file, QWidget *parent = nullptr);
    ~AdminData();
    QString file;
private slots:
    void on_viewData_cursorPositionChanged(int arg1, int arg2);

    void on_back_clicked();

    void on_save_clicked();

private:
    Ui::AdminData *ui;
};

#endif // ADMINDATA_H
