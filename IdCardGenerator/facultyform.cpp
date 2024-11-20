#include "facultyform.h"
#include "ui_facultyform.h"

facultyForm::facultyForm(QWidget *parent) : QDialog(parent), ui(new Ui::facultyForm) // Constructor
{
    ui->setupUi(this); // Creates window
}

facultyForm::~facultyForm() // Deconstructor
{
    delete ui;
}

void facultyForm::on_pushButton_cancel_clicked() // User presses cancel button
{
    this->hide(); // Hides current window
}

