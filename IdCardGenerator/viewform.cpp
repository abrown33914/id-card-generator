#include "viewform.h"
#include "ui_viewform.h"
#include "globalstorage.h"
#include "student.h"
#include "faculty.h"
#include "studentcarddisplay.h"
#include "facultycarddisplay.h"
#include <QMessageBox>

// Constructor
ViewForm::ViewForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewForm) // ("NEW" = MEMORY MANAGEMENT)
{
    ui->setupUi(this); // Creates window

    // STYLE SHEETS FOR FORM:
    this->setStyleSheet("background-color: #f7f7f7;");
    // Style label & combo box
    ui->label_select->setStyleSheet("color: #0661B6; font-size: 14px; font-weight: bold; text-align: center;");
    ui->comboBox_objects->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    // Style buttons
    ui->pushButton_view->setStyleSheet(
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
    ui->pushButton_back->setStyleSheet(
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
    ui->horizontalLayout_2->setContentsMargins(10, 10, 10, 10);

    // Clear any items in the combo box
    ui->comboBox_objects->clear();
    // For loops iterates through STUDENT vector to add into combobox
    for (Student& student : GlobalStorage::studentsVector) {
        ui->comboBox_objects->addItem(student.getName());
    }
    // For loops iterates through FACULTY vector to add into combobox
    for (Faculty& faculty : GlobalStorage::facultyVector) { // Add names from the faculty array
        ui->comboBox_objects->addItem(faculty.getName());
    }

}

// Destructor
ViewForm::~ViewForm()
{
    delete ui;
}

// Back button handler
void ViewForm::on_pushButton_back_clicked()
{
    this->hide();
}

// View button handler
void ViewForm::on_pushButton_view_clicked()
{
    bool found = false; // Bool for if user found in either vector

    QString selectedName = ui->comboBox_objects->currentText();  // Get selected name from combo box
    QString tempName, tempCollege, positionOrId, tempYear; // Define temporary variables

    // For loops searches through student vector for matched name
    for (Student &searchStudent : GlobalStorage::studentsVector)
    {
        if (searchStudent.getName() == selectedName) // If selected name matches a student
        {
            tempName = searchStudent.getName(); tempCollege = searchStudent.getCollege(); // Set temp variables to send to card
            positionOrId = searchStudent.getId(); tempYear = searchStudent.getYear();

            studentCardDisplay card; // Create new card
            card.setInfo(tempCollege, positionOrId, tempName, tempYear); // Set card info

            this->hide(); // Hide current window
            card.setModal(true);
            card.exec(); // Open new window
            found = true; // Set bool to true
        }
    }
    // For loops searches through faculty vector for matched name
    for (Faculty &searchFaculty : GlobalStorage::facultyVector)
    {
        if (searchFaculty.getName() == selectedName) // If selected name matches a faculty
        {
            tempName = searchFaculty.getName(); tempCollege = searchFaculty.getCollege(); // Set temp variables to send to card
            positionOrId = searchFaculty.getPosition(); tempYear = searchFaculty.getYear();

            facultyCardDisplay card; // Create new card
            card.setInfo(tempCollege, tempName, positionOrId, tempYear); // Set card info

            this->hide(); // Hide current window
            card.setModal(true);
            card.exec(); // Open new window
            found = true; // Set bool to true
        }
    }
    if (!found) // If user not found
    {
        QMessageBox::warning(this, "Error", "No matching card found!"); // If no match found
    }

    this ->hide(); // Hide current window

}

