#ifndef STUDENTCARDDISPLAY_H
#define STUDENTCARDDISPLAY_H

#include <QDialog>

namespace Ui {
class studentCardDisplay;
}

class studentCardDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit studentCardDisplay(QWidget *parent = nullptr);
    ~studentCardDisplay();

private:
    Ui::studentCardDisplay *ui;
};

#endif // STUDENTCARDDISPLAY_H
