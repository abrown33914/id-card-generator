#include "studentcarddisplay.h"
#include "ui_studentcarddisplay.h"

studentCardDisplay::studentCardDisplay(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::studentCardDisplay),
    logoManager("C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png") { // Template path for logos
    ui->setupUi(this); // Create student card UI

    // Set background color of card
    this->setStyleSheet("background-color: #f7f7f7; border-radius: 15px;");

    // Style the header label (Student Name) with a vibrant background
    ui->label_student->setStyleSheet("color: white; background-color: #039367; font-size: 22px; font-weight: bold; padding: 10px;");

    // Style other labels for a modern, clean look
    ui->label_studentCollege->setStyleSheet("color: #039367; font-size: 18px; padding: 5px 0;");
    ui->label_studentName->setStyleSheet("color: #333333; font-size: 20px; font-weight: bold; padding: 5px 0;");
    ui->label_studentID->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");
    ui->label_studentGraduation->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");

    // Configure a single logo for the UI as an example
    ui->label_logo->setFixedSize(150, 110);
    const QPixmap &logo = logoManager.getLogo(0); // Get the first logo
    if (!logo.isNull()) {
        ui->label_logo->setPixmap(logo.scaled(ui->label_logo->size(), Qt::KeepAspectRatio));
    } else {
        ui->label_logo->setText("Logo Not Available");
        ui->label_logo->setStyleSheet("background-color: #D3D3D3; color: #333333; font-size: 16px; font-weight: bold; padding: 5px;");
    }

    ui->label_logo->setStyleSheet("border: 3px solid #039367;");
    ui->verticalLayout->setContentsMargins(30, 30, 30, 30);
    ui->verticalLayout->setSpacing(15);
}

studentCardDisplay::~studentCardDisplay() {
    delete ui; // Destructor
}

void studentCardDisplay::setInfo(const QString &tempCollege, const QString &tempId, const QString &tempName, const QString &tempYear) {
    // Assign parameters to local variables
    college = tempCollege;
    id = tempId;
    name = tempName;
    year = tempYear;

    // Set ID card text to temporary variables with style updates
    ui->label_studentCollege->setText(college);
    ui->label_studentName->setText(name);
    ui->label_studentID->setText(id);
    ui->label_studentGraduation->setText(year);
}
