#ifndef CALENDERDIALOG_H
#define CALENDERDIALOG_H

#include <QDialog>

namespace Ui {
class CalenderDialog;
}

class CalenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalenderDialog(QWidget *parent = nullptr);
    ~CalenderDialog();

private:
    Ui::CalenderDialog *ui;
};

#endif
