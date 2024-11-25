#ifndef USER_H
#define USER_H

#include <QString>

class User { // Base class "User" inherited by "Person" "Student" and "Faculty" (HIERARCHICAL INHERITANCE)

protected:
    QString fullName; // Define attribute for full name

public:
    User(); // Constructor

    // PURE VIRTUAL FUNCTION TO SET ATTRIBUTES (ABSTRACT CLASS)
    virtual void setAttributes(const QString &name, const QString &college, const QString &positionOrId, const QString &year) = 0;

    virtual ~User(); // Destructor
};

#endif
