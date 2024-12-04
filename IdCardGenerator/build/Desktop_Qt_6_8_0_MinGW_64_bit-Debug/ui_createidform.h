/********************************************************************************
** Form generated from reading UI file 'createidform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEIDFORM_H
#define UI_CREATEIDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_createIdForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_create;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_firstName;
    QLineEdit *lineEdit_firstName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_lastName;
    QLineEdit *lineEdit_lastName;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioButton_student;
    QRadioButton *radioButton_faculty;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_next;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *createIdForm)
    {
        if (createIdForm->objectName().isEmpty())
            createIdForm->setObjectName("createIdForm");
        createIdForm->resize(558, 284);
        verticalLayout_2 = new QVBoxLayout(createIdForm);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_create = new QLabel(createIdForm);
        label_create->setObjectName("label_create");
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setUnderline(true);
        label_create->setFont(font);
        label_create->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_create);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_firstName = new QLabel(createIdForm);
        label_firstName->setObjectName("label_firstName");

        horizontalLayout->addWidget(label_firstName);

        lineEdit_firstName = new QLineEdit(createIdForm);
        lineEdit_firstName->setObjectName("lineEdit_firstName");

        horizontalLayout->addWidget(lineEdit_firstName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_lastName = new QLabel(createIdForm);
        label_lastName->setObjectName("label_lastName");

        horizontalLayout_2->addWidget(label_lastName);

        lineEdit_lastName = new QLineEdit(createIdForm);
        lineEdit_lastName->setObjectName("lineEdit_lastName");

        horizontalLayout_2->addWidget(lineEdit_lastName);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        radioButton_student = new QRadioButton(createIdForm);
        radioButton_student->setObjectName("radioButton_student");

        horizontalLayout_4->addWidget(radioButton_student);

        radioButton_faculty = new QRadioButton(createIdForm);
        radioButton_faculty->setObjectName("radioButton_faculty");

        horizontalLayout_4->addWidget(radioButton_faculty);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_next = new QPushButton(createIdForm);
        pushButton_next->setObjectName("pushButton_next");

        horizontalLayout_3->addWidget(pushButton_next);

        pushButton_cancel = new QPushButton(createIdForm);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout_3->addWidget(pushButton_cancel);


        verticalLayout_2->addLayout(horizontalLayout_3);

#if QT_CONFIG(shortcut)
        label_firstName->setBuddy(lineEdit_firstName);
        label_lastName->setBuddy(lineEdit_lastName);
#endif // QT_CONFIG(shortcut)

        retranslateUi(createIdForm);

        QMetaObject::connectSlotsByName(createIdForm);
    } // setupUi

    void retranslateUi(QDialog *createIdForm)
    {
        createIdForm->setWindowTitle(QCoreApplication::translate("createIdForm", "Dialog", nullptr));
        label_create->setText(QCoreApplication::translate("createIdForm", "Create an ID Card", nullptr));
        label_firstName->setText(QCoreApplication::translate("createIdForm", "First Name:", nullptr));
        label_lastName->setText(QCoreApplication::translate("createIdForm", "Last Name:", nullptr));
        radioButton_student->setText(QCoreApplication::translate("createIdForm", "Student", nullptr));
        radioButton_faculty->setText(QCoreApplication::translate("createIdForm", "Faculty", nullptr));
        pushButton_next->setText(QCoreApplication::translate("createIdForm", "Next", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("createIdForm", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createIdForm: public Ui_createIdForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEIDFORM_H
