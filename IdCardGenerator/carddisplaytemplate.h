#ifndef CARDDISPLAYTEMPLATE_H
#define CARDDISPLAYTEMPLATE_H

#include <QPixmap>
#include <QString>
#include <QFileInfo>
#include <array>

// Template class for card displays
template <size_t Size>
class CardDisplayTemplate {
public:
    // Constructor initializes logo array
    CardDisplayTemplate(const QString &logoPathTemplate)
        : logoPathTemplate(logoPathTemplate) {
        initializeLogos();
    }


    // Get logo by index
    const QPixmap &getLogo(size_t index) const {
        return (index < Size) ? logos[index] : emptyPixmap;
    }

private:
    QString logoPathTemplate;       // Template path for logos
    std::array<QPixmap, Size> logos; // Fixed-size array of logos
    QPixmap emptyPixmap;            // Placeholder for invalid logos

    // Initialize logos array
    void initializeLogos() {
        for (size_t i = 0; i < logos.size(); ++i) {
            QString logoPath = logoPathTemplate.arg(i);
            QPixmap logo;
            QFileInfo checkFile(logoPath);

            if (checkFile.exists() && checkFile.isFile()) {
                logo.load(logoPath);
            }
            logos[i] = logo; // Either a loaded logo or an empty QPixmap
        }
    }
};

#endif // CARDDISPLAYTEMPLATE_H
