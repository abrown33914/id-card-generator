#include "facultyform.h"
#include "ui_facultyform.h"
#include "facultycarddisplay.h"
#include "faculty.h"
#include "globalstorage.h"
#include "QMessageBox" // For input warnings
#include <QString>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <stdexcept> // For invalid employment year warning>

// Overloaded function for int processing (COMPILE TIME POLYMORPHISM)
void processEmploymentYear(int year) {
    if (year <= 0) {
        throw std::invalid_argument("Employment year must be a positive number.");
    }
    if (year < 1000 || year > 9999) { // Check if the year is a 4-digit number
        throw std::invalid_argument("Employment year must be a 4-digit number.");
    }
}

// Overloaded function for std::string processing (COMPILE TIME POLYMORPHISM)
void processEmploymentYear(const std::string& tempYear) {
    // Check if the input string length is 4 digits
    if (tempYear.length() != 4) {
        throw std::invalid_argument("Employment year must be exactly 4 digits.");
    }
    // Try-Catch block (EXCEPTION HANDLING)
    try {
        int year = std::stoi(tempYear); // Convert std::string to int
        processEmploymentYear(year);    // Delegate to the int version
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument("Employment year is not a valid number.");
    } catch (const std::out_of_range&) {
        throw std::invalid_argument("Employment year is out of range.");
    }
}

// Constructor
facultyForm::facultyForm(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::facultyForm) {
    ui->setupUi(this); // Creates window
    ui->lineEdit_facultyOtherCollege->setReadOnly(true); // Makes other college line edit read only

    // STYLE SHEETS FOR FORM
    this->setStyleSheet("background-color: #f7f7f7;");
    // Style labels
    ui->label_facultyInfo->setStyleSheet("color: #0661B6; font-size: 16px; font-weight: bold; text-decoration: underline;");
    ui->label_position->setStyleSheet("color: #0661B6;");
    ui->label_collegeEmployed->setStyleSheet("color: #0661B6;");
    ui->label_facultyOtherCollege->setStyleSheet("color: #0661B6;");
    ui->label_yearsEmployed->setStyleSheet("color: #0661B6;");
    // Style line edits
    ui->lineEdit_position->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->lineEdit_facultyOtherCollege->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->lineEdit_yearsEmployed->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    // Style combo box
    ui->comboBox_facultyColleges->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    // Style buttons
    ui->pushButton_create->setStyleSheet(
        "QPushButton {"
        "background-color: white;"
        "border: 2px solid #039367;"
        "color: #039367;"
        "padding: 5px 10px;"
        "border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "background-color: #039367;"
        "color: white;"
        "}"
        );
    ui->pushButton_cancel->setStyleSheet(
        "QPushButton {"
        "background-color: white;"
        "border: 2px solid #039367;"
        "color: #039367;"
        "padding: 5px 10px;"
        "border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "background-color: #039367;"
        "color: white;"
        "}"
        );
    // Style margins
    ui->verticalLayout->setContentsMargins(30, 30, 30, 30);
}

// Destructor
facultyForm::~facultyForm() {
    delete ui;
}

// Method to set temporary name variable
void facultyForm::sendName(QString &tempName) {
    transferName = tempName; // Sets name from previous window to temporary name variable
}

// Cancel button handler
void facultyForm::on_pushButton_cancel_clicked() {
    this->hide(); // Hides current window
}

// Create button handler
void facultyForm::on_pushButton_create_clicked() {


    // ####### REPLACE WITH YOUR FGCU LOGO IMAGE PATH #############################
    QString globalLogoPath = "C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png";
    // ############################################################################


    if (!ui->lineEdit_position->text().isEmpty()) { // If position entered

        tempPosition = ui->lineEdit_position->text(); // Sets temporary Position Title variable

        if (!ui->lineEdit_yearsEmployed->text().isEmpty()) { // If years employed entered

            tempYear = ui->lineEdit_yearsEmployed->text(); // Sets temporary employment year variable

            try {
                // Validate years employed using the overloaded function
                processEmploymentYear(tempYear.toStdString());
            } catch (const std::invalid_argument& e) {
                QMessageBox::warning(this, "Invalid Input", e.what()); // Show error if validation fails
                return; // Exit the function
            }

            // If/If Else chain for colleges combobox
            if (ui->comboBox_facultyColleges->currentIndex() == 0) { // If "please specify" selected
                QMessageBox::warning(this, "Warning", "You must select a college.");
                return;
            } else if (ui->comboBox_facultyColleges->currentIndex() == 1) {
                tempCollege = "U.A. Whitaker College of Engineering";
            } else if (ui->comboBox_facultyColleges->currentIndex() == 2) {
                tempCollege = "College of Arts and Sciences";
            } else if (ui->comboBox_facultyColleges->currentIndex() == 3) {
                tempCollege = "Lutgert College of Business";
            } else if (ui->comboBox_facultyColleges->currentIndex() == 4) {
                tempCollege = "College of Education";
            } else if (ui->comboBox_facultyColleges->currentIndex() == 5) {
                tempCollege = "Marieb College of Health & Human Services";
            } else if (ui->comboBox_facultyColleges->currentIndex() == 6) {
                if (!ui->lineEdit_facultyOtherCollege->text().isEmpty()) {
                    tempCollege = ui->lineEdit_facultyOtherCollege->text();
                } else {
                    QMessageBox::warning(this, "Warning", "You must enter the name of your college.");
                    return;
                }
            }

            // Create new faculty object and set attributes
            Faculty newFaculty;
            newFaculty.setAttributes(transferName, tempCollege, tempPosition, tempYear);
            GlobalStorage::facultyVector.append(newFaculty); // Add to vector

            // Ask the user if they want to save the ID as a PDF
            QMessageBox::StandardButton reply = QMessageBox::question(
                this,
                "Save as PDF",
                "Would you like to save the faculty ID as a PDF?",
                QMessageBox::Yes | QMessageBox::No
                );

            if (reply == QMessageBox::Yes) {
                QString fileName = QFileDialog::getSaveFileName(this, "Save as PDF", "", "PDF Files (*.pdf)");
                if (fileName.isEmpty()) {
                    return; // Exit if no file is chosen
                }

                // Inside your function that exports the PDF
                QPrinter printer(QPrinter::HighResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName(fileName);
                printer.setPageOrientation(QPageLayout::Portrait);  // Correct orientation
                printer.setPageSize(QPageSize::A4);  // Correct page size
                printer.setPageMargins(QMargins(20, 20, 20, 20), QPageLayout::Millimeter);  // Adjust margins
                QPainter painter;
                if (!painter.begin(&printer)) {
                    QMessageBox::warning(this, "Error", "Failed to open file for writing.");
                    return;
                }
                // Draw Logo (scaled larger)
                QString logoPath = globalLogoPath; // Replace this with your actual path
                QImage logo(logoPath);
                if (logo.isNull()) {
                    QMessageBox::warning(this, "Error", "Failed to load logo image.");
                } else {
                    int logoWidth = 3000;  // Set desired width for the logo
                    int logoHeight = 1500; // Set desired height for the logo
                    painter.drawImage(200, 500, logo.scaled(logoWidth, logoHeight, Qt::KeepAspectRatio));
                }
                // Initialize starting Y position for text below the logo
                int yPos = 500;  // Start position after the logo
                int textXPos = 200 + 3000 + 50;  // Start text 50px to the right of the logo
                // Set text font and alignment
                QFont textFont("Arial", 14);
                painter.setFont(textFont);
                // Set up spacing
                int lineSpacing = 800; // Increased spacing between lines (larger)
                // Add title or header
                painter.setFont(QFont("Arial", 18, QFont::Bold)); // Larger font for header
                painter.drawText(textXPos, yPos, "Faculty Information");
                yPos += lineSpacing; // Add space after the header
                // Set back to normal font for the information
                painter.setFont(textFont);
                // Draw faculty info
                painter.drawText(textXPos, yPos, "Faculty Name: " + transferName);
                yPos += lineSpacing; // Increase Y position for next line
                painter.drawText(textXPos, yPos, "Position: " + tempPosition);
                yPos += lineSpacing; // Increase Y position for next line
                painter.drawText(textXPos, yPos, "College: " + tempCollege);
                yPos += lineSpacing; // Increase Y position for next line
                painter.drawText(textXPos, yPos, "Year Employed: " + tempYear);
                yPos += lineSpacing; // Increase Y position for next line
                painter.end();
            }

            // Display the faculty card
            facultyCardDisplay card;
            card.setInfo(tempCollege, transferName, tempPosition, tempYear);
            this->hide(); // Hide current window
            card.setModal(true);
            card.exec();

        } else { // If no year entered
            QMessageBox::warning(this, "Warning", "You must enter your starting year of employment.");
        }
    } else { // If no position entered
        QMessageBox::warning(this, "Warning", "You must enter your position.");
    }
}

// Combo box change handler
void facultyForm::on_comboBox_facultyColleges_currentIndexChanged(int index) {
    if (index == 6) { // If user selects "other college"
        ui->lineEdit_facultyOtherCollege->setReadOnly(false); // Allow user to type
    } else {
        ui->lineEdit_facultyOtherCollege->setReadOnly(true); // Disable typing otherwise
    }
}
