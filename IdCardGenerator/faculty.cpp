#include "faculty.h"

// Constructor
Faculty::Faculty() : User(), Person(){}  // MULTILEVEL INHERITANCE

// Overrides base class to set faculty object attributes
void Faculty::setAttributes(const QString &name, const QString &college, const QString &positionOrId, const QString &year)
{
    fullName = name;
    personCollege = college;
    position = positionOrId;
    yearEmployed = year;
}

// Getters (ENCAPSULATION)
QString Faculty::getName() { return fullName; }
QString Faculty::getCollege() { return personCollege; }
QString Faculty::getPosition() { return position; }
QString Faculty::getYear() { return yearEmployed; }

// Destructor
Faculty::~Faculty() {}

