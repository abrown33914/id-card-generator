#include "facultycarddisplay.h"
#include "ui_facultycarddisplay.h"

facultyCardDisplay::facultyCardDisplay(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::facultyCardDisplay),
    logoManager("C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png") { // Template path for logos
    ui->setupUi(this);

    // Set background color and styles
    this->setStyleSheet("background-color: #f7f7f7; border-radius: 15px;");
    ui->label_faculty->setStyleSheet("color: white; background-color: #0661B6; font-size: 22px; font-weight: bold; padding: 10px;");
    ui->label_facultyCollege->setStyleSheet("color: #039367; font-size: 18px; padding: 5px 0;");
    ui->label_facultyName->setStyleSheet("color: #333333; font-size: 20px; font-weight: bold; padding: 5px 0;");
    ui->label_facultyPosition->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");
    ui->label_facultyStarted->setStyleSheet("color: #333333; font-size: 16px; padding: 5px 0;");

    // Configure logo
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

facultyCardDisplay::~facultyCardDisplay() {
    delete ui;
}

void facultyCardDisplay::setInfo(const QString &tempCollege, const QString &tempName, const QString &tempPosition, const QString &tempYear) {
    // Set text values
    college = tempCollege;
    name = tempName;
    position = tempPosition;
    year = tempYear;

    ui->label_facultyCollege->setText(college);
    ui->label_facultyName->setText(name);
    ui->label_facultyPosition->setText(position);
    ui->label_facultyStarted->setText(year);
}
