/********************************************************************************
** Form generated from reading UI file 'resizedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEDIALOG_H
#define UI_RESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ResizeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelHeight;
    QLabel *labelWidth;
    QSpinBox *heightSpinBox;
    QSpinBox *widthSpinBox;

    void setupUi(QDialog *ResizeDialog)
    {
        if (ResizeDialog->objectName().isEmpty())
            ResizeDialog->setObjectName("ResizeDialog");
        ResizeDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ResizeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        labelHeight = new QLabel(ResizeDialog);
        labelHeight->setObjectName("labelHeight");
        labelHeight->setGeometry(QRect(250, 90, 61, 16));
        labelWidth = new QLabel(ResizeDialog);
        labelWidth->setObjectName("labelWidth");
        labelWidth->setGeometry(QRect(140, 90, 61, 16));
        heightSpinBox = new QSpinBox(ResizeDialog);
        heightSpinBox->setObjectName("heightSpinBox");
        heightSpinBox->setGeometry(QRect(250, 110, 61, 31));
        heightSpinBox->setMinimum(1);
        heightSpinBox->setMaximum(1000000);
        widthSpinBox = new QSpinBox(ResizeDialog);
        widthSpinBox->setObjectName("widthSpinBox");
        widthSpinBox->setGeometry(QRect(140, 110, 61, 31));
        widthSpinBox->setMinimum(1);
        widthSpinBox->setMaximum(1000000);

        retranslateUi(ResizeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ResizeDialog, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ResizeDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(ResizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeDialog)
    {
        ResizeDialog->setWindowTitle(QCoreApplication::translate("ResizeDialog", "Dialog", nullptr));
        labelHeight->setText(QCoreApplication::translate("ResizeDialog", "Height(px):", nullptr));
        labelWidth->setText(QCoreApplication::translate("ResizeDialog", "Width(px):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResizeDialog: public Ui_ResizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
