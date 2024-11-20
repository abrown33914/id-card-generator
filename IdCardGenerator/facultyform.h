#ifndef FACULTYFORM_H
#define FACULTYFORM_H

#include <QDialog>

namespace Ui {
class facultyForm;
}

class facultyForm : public QDialog
{
    Q_OBJECT

public:
    explicit facultyForm(QWidget *parent = nullptr);
    ~facultyForm();

private slots:
    void on_pushButton_cancel_clicked();

private:
    Ui::facultyForm *ui;
};

#endif // FACULTYFORM_H
