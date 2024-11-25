#include "studentcarddisplay.h"
#include "ui_studentcarddisplay.h"
#include <QPixmap>
#include <QFileInfo>

// Constructor
studentCardDisplay::studentCardDisplay(QWidget *parent) : QDialog(parent), ui(new Ui::studentCardDisplay)
{


    // ####### REPLACE WITH YOUR FGCU LOGO IMAGE PATH #############################
    QString globalLogoPath = "C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png";
    // ############################################################################


    ui->setupUi(this); // Creates student card

    // STYLE SHEETS FOR CARD:
    this->setStyleSheet("background-color: white; border-radius: 15px;");
    // Style header
    ui->label_student->setStyleSheet("color: white; background-color: #039367; font-size: 22px; font-weight: bold; padding: 10px;");
    // Style labels
    ui->label_studentCollege->setStyleSheet("color: #0661B6; font-size: 18px; padding: 5px 0;");
    ui->label_studentName->setStyleSheet("color: #333333; font-size: 20px; font-weight: bold; padding: 5px 0;");
    ui->label_studentID->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");
    ui->label_studentGraduation->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");
    // Create FGCU logo with error handling for loading
    ui->label_logo->setFixedSize(150, 110); // Set label size
    QString logoPath = globalLogoPath; // Logo path
    QPixmap logo;
    // Check if the image file exists before setting
    QFileInfo checkFile(logoPath);
    if (checkFile.exists() && checkFile.isFile()) {
        logo.load(logoPath); // Load logo
        ui->label_logo->setPixmap(logo.scaled(ui->label_logo->size(), Qt::KeepAspectRatio)); // Scale logo to label
    } else {
        // If logo file doesn't exist
        ui->label_logo->setText("Logo Not Available"); // Set default text
        ui->label_logo->setStyleSheet("background-color: #D3D3D3; color: #333333; font-size: 16px; font-weight: bold; padding: 5px;");
    }
    // Style margins
    ui->verticalLayout->setContentsMargins(30, 30, 30, 30);
    ui->verticalLayout->setSpacing(15);

}

// Deconstructor
studentCardDisplay::~studentCardDisplay()
{
    delete ui;
}

// Method to get variables from previous form
void studentCardDisplay::setInfo(QString &tempCollege, QString &tempId, QString &tempName, QString &tempYear)
{
    // Set variables
    college = tempCollege;
    id = tempId;
    name = tempName;
    year = tempYear;
    // Set ID card text to temporary variables
    ui->label_studentCollege->setText(college);
    ui->label_studentName->setText(name);
    ui->label_studentID->setText(id);
    ui->label_studentGraduation->setText(year);
}



