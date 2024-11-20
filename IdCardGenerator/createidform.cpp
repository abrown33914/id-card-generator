#include "createidform.h"
#include "ui_createidform.h"
#include "studentform.h"
#include "facultyform.h"
#include <QMessageBox> // For input warnings


createIdForm::createIdForm(QWidget *parent) : QDialog(parent), ui(new Ui::createIdForm) // Constructor
{
    ui->setupUi(this); // Creates window
}

createIdForm::~createIdForm() // Deconstructor
{
    delete ui;
}

void createIdForm::on_pushButton_cancel_clicked() // User presses cancel button on create form
{
    this->hide(); // Hides current window
}


void createIdForm::on_pushButton_next_clicked() // User presses next button on create form
{
    if(!ui->lineEdit_firstName->text().isEmpty() && !ui->lineEdit_lastName->text().isEmpty()) { // If first/last name entered
        if (ui->radioButton_faculty->isChecked()) { // If selected faulty

            // WRITE CODE TO INPUT FIRST/LAST NAME FOR NEW FACULTY

            this->hide(); // Hide current window
            facultyForm faculty; // Open faculty info form
            faculty.setModal(true);
            faculty.exec();
        }
        else if (ui->radioButton_student->isChecked()) { // If selected student

            // WRITE CODE TO INPUT FIRST/LAST NAME FOR NEW STUDENT

            this->hide(); // Hide current window
            studentForm student; // Open student info form
            student.setModal(true);
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

