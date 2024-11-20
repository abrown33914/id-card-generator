#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include <QDialog>

namespace Ui {
class studentForm;
}

class studentForm : public QDialog
{
    Q_OBJECT

public:
    explicit studentForm(QWidget *parent = nullptr);
    ~studentForm();

private slots:
    void on_pushButton_cancelStudent_clicked();

private:
    Ui::studentForm *ui;
};

#endif // STUDENTFORM_H
