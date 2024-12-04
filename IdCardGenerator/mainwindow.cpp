#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createidform.h"
#include "viewform.h"
#include <QPixmap>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // ####### REPLACE WITH YOUR FGCU LOGO IMAGE PATH #############################
    QString globalLogoPath = "C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png";
    // ############################################################################

    ui->setupUi(this);

    // Set background color and central alignment
    this->setStyleSheet("background-color: white;");  // Light background color

    // Apply styles directly to buttons
    ui->pushButton_createMain->setStyleSheet(
        "QPushButton {"
        "background-color: #039367;" // Green Background
        "border: 2px solid #039367;"
        "color: white;" // White text
        "padding: 10px 20px;"
        "border-radius: 10px;"
        "font-size: 16px;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #0661B6;"  // Blue on hover
        "border: 2px solid #0661B6;"
        "}"
        "QPushButton:pressed {"
        "background-color: #044F8C;"  // Dark blue when pressed
        "border: 2px solid #044F8C;"
        "}"
        );
    ui->pushButton_quitMain->setStyleSheet(
        "QPushButton {"
        "background-color: #039367;" // Green Background
        "border: 2px solid #039367;"
        "color: white;" // White text
        "padding: 10px 20px;"
        "border-radius: 10px;"
        "font-size: 16px;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #0661B6;"  // Blue on hover
        "border: 2px solid #0661B6;"
        "}"
        "QPushButton:pressed {"
        "background-color: #044F8C;"  // Dark blue when pressed
        "border: 2px solid #044F8C;"
        "}"
        );
    ui->pushButton_viewCard->setStyleSheet(
        "QPushButton {"
        "background-color: #039367;" // Green Background
        "border: 2px solid #039367;"
        "color: white;" // White text
        "padding: 10px 20px;"
        "border-radius: 10px;"
        "font-size: 16px;"
        "font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "background-color: #0661B6;"  // Blue on hover
        "border: 2px solid #0661B6;"
        "}"
        "QPushButton:pressed {"
        "background-color: #044F8C;"  // Dark blue when pressed
        "border: 2px solid #044F8C;"
        "}"
        );

    // Set style for label
    ui->label_welcome->setStyleSheet("color: #0661B6; font-size: 24px; font-weight: bold;");

    // Create and display logo
    ui->label_logo->setFixedSize(150, 110);
    QPixmap logo(globalLogoPath);
    ui->label_logo->setPixmap(logo.scaled(ui->label_logo->size(), Qt::KeepAspectRatio));

    // Margins
    ui->verticalLayout->setContentsMargins(20, 20, 20, 20);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Quit button handler
void MainWindow::on_pushButton_quitMain_clicked()
{
    QApplication::quit();
}

// Create ID Card button handler
void MainWindow::on_pushButton_createMain_clicked()
{
    createIdForm form;
    form.setModal(true);
    form.exec();
}

// View ID Card button handler
void MainWindow::on_pushButton_viewCard_clicked()
{
    ViewForm form;
    form.setModal(true);
    form.exec();
}
