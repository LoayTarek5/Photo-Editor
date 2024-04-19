/********************************************************************************
** Form generated from reading UI file 'cropdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROPDIALOG_H
#define UI_CROPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CropDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBoxY;
    QSpinBox *spinBoxX;
    QSpinBox *spinBoxWidth;
    QSpinBox *spinBoxHeight;
    QLabel *labelX;
    QLabel *labelW;
    QLabel *labelH;
    QLabel *labelX_2;

    void setupUi(QDialog *CropDialog)
    {
        if (CropDialog->objectName().isEmpty())
            CropDialog->setObjectName("CropDialog");
        CropDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(CropDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBoxY = new QSpinBox(CropDialog);
        spinBoxY->setObjectName("spinBoxY");
        spinBoxY->setGeometry(QRect(160, 70, 61, 25));
        spinBoxX = new QSpinBox(CropDialog);
        spinBoxX->setObjectName("spinBoxX");
        spinBoxX->setGeometry(QRect(60, 70, 61, 25));
        spinBoxWidth = new QSpinBox(CropDialog);
        spinBoxWidth->setObjectName("spinBoxWidth");
        spinBoxWidth->setGeometry(QRect(60, 140, 61, 25));
        spinBoxHeight = new QSpinBox(CropDialog);
        spinBoxHeight->setObjectName("spinBoxHeight");
        spinBoxHeight->setGeometry(QRect(160, 140, 61, 25));
        labelX = new QLabel(CropDialog);
        labelX->setObjectName("labelX");
        labelX->setGeometry(QRect(60, 50, 61, 16));
        labelW = new QLabel(CropDialog);
        labelW->setObjectName("labelW");
        labelW->setGeometry(QRect(60, 120, 49, 16));
        labelH = new QLabel(CropDialog);
        labelH->setObjectName("labelH");
        labelH->setGeometry(QRect(160, 120, 49, 16));
        labelX_2 = new QLabel(CropDialog);
        labelX_2->setObjectName("labelX_2");
        labelX_2->setGeometry(QRect(160, 50, 61, 16));

        retranslateUi(CropDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CropDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CropDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CropDialog);
    } // setupUi

    void retranslateUi(QDialog *CropDialog)
    {
        CropDialog->setWindowTitle(QCoreApplication::translate("CropDialog", "Dialog", nullptr));
        labelX->setText(QCoreApplication::translate("CropDialog", "X position ", nullptr));
        labelW->setText(QCoreApplication::translate("CropDialog", "Width", nullptr));
        labelH->setText(QCoreApplication::translate("CropDialog", "Height", nullptr));
        labelX_2->setText(QCoreApplication::translate("CropDialog", "Y position ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CropDialog: public Ui_CropDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROPDIALOG_H
