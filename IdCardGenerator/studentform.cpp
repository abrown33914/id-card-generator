#include "studentform.h"
#include "ui_studentform.h"

studentForm::studentForm(QWidget *parent) : QDialog(parent), ui(new Ui::studentForm) // Constructor
{
    ui->setupUi(this); // Creates window

}

studentForm::~studentForm() // Deconstructor
{
  delete ui;
}

void studentForm::on_pushButton_cancelStudent_clicked() // User pressses cancel button on student info form
{
    this->hide(); // Hides current window
}


