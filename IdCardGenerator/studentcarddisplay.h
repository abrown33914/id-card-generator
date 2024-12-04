#ifndef STUDENTCARDDISPLAY_H
#define STUDENTCARDDISPLAY_H

#include <QDialog>
#include "cardDisplayTemplate.h" // Include template for logos

namespace Ui {
class studentCardDisplay;
}

class studentCardDisplay : public QDialog {
    Q_OBJECT

public:
    explicit studentCardDisplay(QWidget *parent = nullptr);
    ~studentCardDisplay();

    // Method to set student information
    void setInfo(const QString &tempCollege, const QString &tempId, const QString &tempName, const QString &tempYear);

private:
    Ui::studentCardDisplay *ui;

    // Private member variables to store student data
    QString college;
    QString id;
    QString name;
    QString year;

    // Use CardDisplayTemplate for logo handling
    CardDisplayTemplate<10> logoManager;
};

#endif // STUDENTCARDDISPLAY_H
