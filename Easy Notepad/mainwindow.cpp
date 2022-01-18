#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_calenderdialog.h"
#include "calenderdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

    QMessageBox msgBox;
    msgBox.setText("Do you want to save the changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save:
          on_actionSave_as_triggered();
          break;
      case QMessageBox::Discard:
        currentfile.clear();
        ui->textEdit->setText(QString());
          break;
      default:
          break;
    }




}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open The File");
    QFile file(fileName);
    currentfile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Worning","Cannot open file :" +file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","cannot save file : " +file.errorString());
        return;
    }
    currentfile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<< text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer name");
   QPrintDialog pDialog(&printer, this);
    if(pDialog.exec()==QDialog::Rejected){
        QMessageBox::warning(this,"Warning","Cannot access printer");
    }
    ui->textEdit->print(&printer);
}

void MainWindow::on_actionCopy_triggered()
{
     ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
     ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
     ui->textEdit->redo();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","cannot save file : " +file.errorString());
        return;
    }
    currentfile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<< text;
    file.close();


}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save:
          on_actionSave_as_triggered();
          break;
      case QMessageBox::Discard:
          QApplication ::quit();
          break;
      case QMessageBox::Cancel:
          break;
      default:
          break;
    }


}

void MainWindow::on_actionFont_triggered()
{
    bool fontSalected;
    QFont font = QFontDialog:: getFont(&fontSalected, this);
    if(fontSalected)
        ui->textEdit->setFont(font);
}

void MainWindow::on_calendarWidget_activated(const QDate &date)
{

}


void MainWindow::on_actionCalender_triggered()
{

   CalenderDialog calenderdialog;
   calenderdialog.setModal(true);
   calenderdialog.exec();


}

void MainWindow::on_actionCalculator_triggered()
{

}
