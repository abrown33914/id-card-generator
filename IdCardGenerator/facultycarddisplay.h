#ifndef FACULTYCARDDISPLAY_H
#define FACULTYCARDDISPLAY_H

#include <QDialog>

namespace Ui {
class facultyCardDisplay;
}

class facultyCardDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit facultyCardDisplay(QWidget *parent = nullptr);
    ~facultyCardDisplay();

private:
    Ui::facultyCardDisplay *ui;
};

#endif // FACULTYCARDDISPLAY_H
