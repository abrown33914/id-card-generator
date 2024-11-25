#include "facultycarddisplay.h"
#include "ui_facultycarddisplay.h"
#include <QFileInfo> // For checking if the image exists

// Constructor
facultyCardDisplay::facultyCardDisplay(QWidget *parent) : QDialog(parent), ui(new Ui::facultyCardDisplay) // ("NEW" = MEMORY MANAGEMENT)
{


    // ####### REPLACE WITH YOUR FGCU LOGO IMAGE PATH #############################
    QString globalLogoPath = "C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png";
    // ############################################################################


    ui->setupUi(this); // Creates faculty card

    // STYLE SHEETS FOR CARD:
    this->setStyleSheet("background-color: white; border-radius: 15px;");
    // Style header
    ui->label_faculty->setStyleSheet("color: white; background-color: #0661B6; font-size: 22px; font-weight: bold; padding: 10px;");
    // Style labels
    ui->label_facultyCollege->setStyleSheet("color: #039367; font-size: 18px; padding: 5px 0;");
    ui->label_facultyName->setStyleSheet("color: #333333; font-size: 20px; font-weight: bold; padding: 5px 0;");
    ui->label_facultyPosition->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");
    ui->label_facultyStarted->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");
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

// Destructor
facultyCardDisplay::~facultyCardDisplay()
{
    delete ui; // ("DELETE" = MEMORY MANAGEMENT)
}

// Method to get variables from previous form
void facultyCardDisplay::setInfo(QString &tempCollege, QString &tempName, QString &tempPosition, QString &tempYear)
{
    // Set variables
    college = tempCollege;
    name = tempName;
    position = tempPosition;
    year = tempYear;
    // Set ID card text to temporary variables
    ui->label_facultyCollege->setText(college);
    ui->label_facultyName->setText(name);
    ui->label_facultyPosition->setText(position);
    ui->label_facultyStarted->setText(year);
}

