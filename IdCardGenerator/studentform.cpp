#include "studentform.h"
#include "ui_studentform.h"
#include "studentcarddisplay.h"
#include "student.h"
#include "globalstorage.h"
#include <QMessageBox> // For warnings
#include <QString>
#include <string>
#include <stdexcept> // For exceptions
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QImage>

// Overloaded function for int processing (COMPILE TIME POLYMORPHISM)
void processStudentID(int id) {
    if (id <= 0) {
        throw std::invalid_argument("Student ID must be a positive number.");
    }
    if (id < 100000000 || id > 999999999) { // Check if the id is a 9-digit number
        throw std::invalid_argument("Employment year must be a 4-digit number.");
    }
}

// Overloaded function for std::string processing
void processStudentID(const std::string& tempID) {
    // Try/Catch block to check if int (EXCEPTION HANDLING)
    try {
        int id = std::stoi(tempID); // Convert std::string to int
        processStudentID(id);      // Delegate to the int version
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument("Student ID is not a valid number.");
    } catch (const std::out_of_range&) {
        throw std::invalid_argument("Student ID is out of range.");
    }
}

// Constructor
studentForm::studentForm(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::studentForm) { // ("NEW" = MEMORY MANAGEMENT)
    ui->setupUi(this); // Create window
    ui->lineEdit_otherCollege->setReadOnly(true);

    //STYLE SHEETS FOR FORM:
    this->setStyleSheet("background-color: #f7f7f7;");
    // Style labels
    ui->label_studentCard->setStyleSheet("color: #0661B6; font-size: 16px; font-weight: bold;");
    ui->label_studentID->setStyleSheet("color: #0661B6;");
    ui->label_collegeEnrolled->setStyleSheet("color: #0661B6;");
    ui->label_other->setStyleSheet("color: #0661B6;");
    ui->label_gradYear->setStyleSheet("color: #0661B6;");
    // Style line edits
    ui->lineEdit_studentID->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->lineEdit_otherCollege->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->comboBox_colleges->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->comboBox_gradYear->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    // Style buttons
    ui->pushButton_createStudent->setStyleSheet(
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
    ui->pushButton_cancelStudent->setStyleSheet(
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
studentForm::~studentForm() {
    delete ui;
}

// Method to set temporary name variable
void studentForm::sendName(QString &tempName) {
    transferName = tempName; // Sets name from previous window to temporary name variable
}

// Cancel button handler
void studentForm::on_pushButton_cancelStudent_clicked() {
    this->hide(); // Hide current window
}

// Create student button handler
void studentForm::on_pushButton_createStudent_clicked() {


    // ####### REPLACE WITH YOUR FGCU LOGO IMAGE PATH #############################
    QString globalLogoPath = "C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png";
    // ############################################################################


    if (!ui->lineEdit_studentID->text().isEmpty()) { // Check if student ID is entered
        tempID = ui->lineEdit_studentID->text(); // Retrieve student ID
        try {
            // Validate student ID using the overloaded function
            processStudentID(tempID.toStdString());
        } catch (const std::invalid_argument& e) {
            QMessageBox::warning(this, "Invalid Input", e.what());
            return; // Exit the function on error
        }

        if (ui->comboBox_gradYear->currentIndex() != 0) { // Check if graduation year is selected
            // Switch-Case to set graduation year temporary variable
            switch (ui->comboBox_gradYear->currentIndex()) {
            case 1: tempYear = "2024"; break;
            case 2: tempYear = "2025"; break;
            case 3: tempYear = "2026"; break;
            case 4: tempYear = "2027"; break;
            case 5: tempYear = "2028"; break;
            }

            // College selection
            if (ui->comboBox_colleges->currentIndex() == 0) { // If no college selected
                QMessageBox::warning(this, "Warning", "You must select a college.");
            } else {
                // Logic to assign college based on selection
                switch (ui->comboBox_colleges->currentIndex()) {
                case 1: tempCollege = "U.A. Whitaker College of Engineering"; break;
                case 2: tempCollege = "College of Arts and Sciences"; break;
                case 3: tempCollege = "Lutgert College of Business"; break;
                case 4: tempCollege = "College of Education"; break;
                case 5: tempCollege = "Marieb College of Health & Human Services"; break;
                case 6: // Handle "Other College" option
                    if (!ui->lineEdit_otherCollege->text().isEmpty()) {
                        tempCollege = ui->lineEdit_otherCollege->text();
                    } else {
                        QMessageBox::warning(this, "Warning", "You must enter the name of your college.");
                        return;
                    }
                    break;
                default:
                    QMessageBox::warning(this, "Error", "Invalid college selection.");
                    return;
                }

                // Create new student object and set attributes
                Student newStudent;
                newStudent.setAttributes(transferName, tempCollege, tempID, tempYear);
                GlobalStorage::studentsVector.append(newStudent); // Add new student to vector

                // Ask the user if they want to save the ID as a PDF
                QMessageBox::StandardButton reply = QMessageBox::question(
                    this,
                    "Save as PDF",
                    "Would you like to save the student ID as a PDF?",
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
                    printer.setPageOrientation(QPageLayout::Portrait);
                    printer.setPageSize(QPageSize::A4);
                    printer.setPageMargins(QMargins(20, 20, 20, 20), QPageLayout::Millimeter);
                    QPainter painter;
                    if (!painter.begin(&printer)) {
                        QMessageBox::warning(this, "Error", "Failed to open file for writing.");
                        return;
                    }
                    // Draw Logo (scaled larger)
                    QString logoPath = globalLogoPath;
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
                    painter.drawText(textXPos, yPos, "Student Information");
                    yPos += lineSpacing; // Add space after the header
                    // Set back to normal font for the information
                    painter.setFont(textFont);
                    // Draw student info
                    painter.drawText(textXPos, yPos, "Student Name: " + transferName);
                    yPos += lineSpacing; // Increase Y position for next line
                    painter.drawText(textXPos, yPos, "Student ID: " + tempID);
                    yPos += lineSpacing; // Increase Y position for next line
                    painter.drawText(textXPos, yPos, "College: " + tempCollege);
                    yPos += lineSpacing; // Increase Y position for next line
                    painter.drawText(textXPos, yPos, "Graduation Year: " + tempYear);
                    yPos += lineSpacing; // Increase Y position for next line
                    // Finalize the painting to the PDF
                    painter.end();
                }

                // Display the student card
                studentCardDisplay card;
                card.setInfo(tempCollege, tempID, transferName, tempYear);
                this->hide(); // Hide current window
                card.setModal(true);
                card.exec();
            }
        } else { // If no grad year selected
            QMessageBox::warning(this, "Warning", "You must select a graduation year.");
        }
    } else { // If no ID number entered
        QMessageBox::warning(this, "Warning", "You must enter your student ID.");
    }
}

// College combo box change handler
void studentForm::on_comboBox_colleges_currentIndexChanged(int index) {
    if (index == 6) { // If user selects "other college"
        ui->lineEdit_otherCollege->setReadOnly(false); // Allow user to type in lineEdit box
    } else {
        ui->lineEdit_otherCollege->setReadOnly(true); // Disable typing otherwise
    }
}
