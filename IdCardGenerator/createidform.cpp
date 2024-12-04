#include "createidform.h"
#include "ui_createidform.h"
#include "studentform.h"
#include "facultyform.h"
#include <QString>
#include <QMessageBox> // For input warnings

createIdForm::createIdForm(QWidget *parent) : QDialog(parent), ui(new Ui::createIdForm) // Constructor (memory management -- new)
{
    ui->setupUi(this); // Creates window

    // STYLE SHEETS FOR FORM:
    this->setStyleSheet("background-color: #f7f7f7;");
    // Style Heading
    ui->label_create->setStyleSheet("color: #0661B6; font-weight: bold;");
    // Style line edits
    ui->lineEdit_firstName->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->lineEdit_lastName->setStyleSheet("background-color: white; border: 2px solid #039367; border-radius: 5px; padding: 5px;");
    ui->radioButton_faculty->setStyleSheet("color: #039367; font-size: 16px;");
    // Style radio buttons
    ui->radioButton_student->setStyleSheet("color: #039367; font-size: 16px;");
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
    ui->pushButton_next->setStyleSheet(
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
    // Add margins/padding for a clean layout
    ui->verticalLayout->setContentsMargins(30, 30, 30, 30);

}

createIdForm::~createIdForm() // Deconstructor
{
    delete ui; // Memory management -- delete
}

void createIdForm::on_pushButton_cancel_clicked() // User presses cancel button on create form
{
    this->hide(); // Hides current window
}

// User presses next button on create form
void createIdForm::on_pushButton_next_clicked()
{
    if(!ui->lineEdit_firstName->text().isEmpty() && !ui->lineEdit_lastName->text().isEmpty()) { // If first/last name entered
        if (ui->radioButton_faculty->isChecked()) { // If selected faulty
            facultyForm faculty; // Create new faculty window
            fullName = ui->lineEdit_firstName->text() + " " + ui->lineEdit_lastName->text(); // Sets temporary fullName = line edit texts
            faculty.sendName(fullName); // Send name to next window class
            this->hide(); // Hide current window
            faculty.setModal(true); // Open new window
            faculty.exec();
        }
        else if (ui->radioButton_student->isChecked()) { // If selected student
            studentForm student; // Create new window
            fullName = ui->lineEdit_firstName->text() + " " + ui->lineEdit_lastName->text(); // Sets temporary fullName = line edit texts
            student.sendName(fullName); // Send name to next window class
            this->hide(); // Hide current window
            student.setModal(true); // Open new student window
            student.exec();
        }
        else { // If no card type chosen
            QMessageBox::warning(this, "Warning", "You must choose a card type.");
        }
    }
    else { // If no first/last name entered
        QMessageBox::warning(this, "Warning", "You must enter a first and last name.");
    }
}

