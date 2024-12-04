#ifndef FACULTYCARDDISPLAY_H
#define FACULTYCARDDISPLAY_H

#include <QDialog>
#include "cardDisplayTemplate.h"

namespace Ui {
class facultyCardDisplay;
}

class facultyCardDisplay : public QDialog {
    Q_OBJECT

public:
    explicit facultyCardDisplay(QWidget *parent = nullptr);
    ~facultyCardDisplay();

    void setInfo(const QString &tempCollege, const QString &tempName, const QString &tempPosition, const QString &tempYear);

private:
    Ui::facultyCardDisplay *ui;
    QString college, name, position, year;

    // Template for logo handling
    CardDisplayTemplate<10> logoManager;
};

#endif // FACULTYCARDDISPLAY_H
