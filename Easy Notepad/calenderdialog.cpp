#include "calenderdialog.h"
#include "ui_calenderdialog.h"

CalenderDialog::CalenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalenderDialog)
{
    ui->setupUi(this);
}

CalenderDialog::~CalenderDialog()
{
    delete ui;
}
