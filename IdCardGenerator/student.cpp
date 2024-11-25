#include "student.h"

// Constructor
Student::Student() : User(), Person() {} // MULTILEVEL INHERITANCE

// Overrides base class to set student object attributes
void Student::setAttributes(const QString &name, const QString &college, const QString &positionOrId, const QString &year)
{
    fullName = name;
    personCollege = college;
    idNumber = positionOrId;
    gradYear = year;
}

// Getters
QString Student::getName() { return fullName; }
QString Student::getCollege() { return personCollege; }
QString Student::getId() { return idNumber; }
QString Student::getYear() { return gradYear; }

// Destructor
Student::~Student() {}
