#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "user.h"
#include <QString>

class Student : public virtual User, public virtual Person { // Student class inherits from both Person and User (MULTILEVEL INHERITANCE)
// ENCAPSULATION (PRIVATE ATTRIBUTES)
private:
    QString idNumber; // Define attribute for ID Number
    QString gradYear; // Define attribute for Graduation Year

public:
    Student(); // Constructor

    // VIRTUAL FUNCTION OVERRIDES "USER" CLASS FUNCTION (RUN TIME POLYMORPHISM)
    virtual void setAttributes(const QString &name, const QString &college, const QString &positionOrId, const QString &year) override;

    // Getters
    QString getName();
    QString getCollege();
    QString getId();
    QString getYear();

    ~Student(); // Destructor
};

#endif
