#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createidform.h"

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

void MainWindow::on_pushButton_quitMain_clicked() // Main Menu Quit Button
{
    QApplication::quit();

}


void MainWindow::on_pushButton_createMain_clicked() // Main Menu Create ID Card button (pulls up new window)
{
    createIdForm form;
    form.setModal(true);
    form.exec();
}

