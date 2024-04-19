/********************************************************************************
** Form generated from reading UI file 'mergeoptionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEOPTIONSDIALOG_H
#define UI_MERGEOPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_MergeOptionsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *radioButtonResize;
    QRadioButton *radioButtonMagnify;
    QRadioButton *radioButtonCrop;

    void setupUi(QDialog *MergeOptionsDialog)
    {
        if (MergeOptionsDialog->objectName().isEmpty())
            MergeOptionsDialog->setObjectName("MergeOptionsDialog");
        MergeOptionsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MergeOptionsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        radioButtonResize = new QRadioButton(MergeOptionsDialog);
        radioButtonResize->setObjectName("radioButtonResize");
        radioButtonResize->setGeometry(QRect(20, 40, 181, 22));
        radioButtonMagnify = new QRadioButton(MergeOptionsDialog);
        radioButtonMagnify->setObjectName("radioButtonMagnify");
        radioButtonMagnify->setGeometry(QRect(20, 80, 291, 22));
        radioButtonCrop = new QRadioButton(MergeOptionsDialog);
        radioButtonCrop->setObjectName("radioButtonCrop");
        radioButtonCrop->setGeometry(QRect(20, 120, 301, 22));

        retranslateUi(MergeOptionsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MergeOptionsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MergeOptionsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MergeOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *MergeOptionsDialog)
    {
        MergeOptionsDialog->setWindowTitle(QCoreApplication::translate("MergeOptionsDialog", "Dialog", nullptr));
        radioButtonResize->setText(QCoreApplication::translate("MergeOptionsDialog", "Reduce the biggest", nullptr));
        radioButtonMagnify->setText(QCoreApplication::translate("MergeOptionsDialog", "Magnify the smallest", nullptr));
        radioButtonCrop->setText(QCoreApplication::translate("MergeOptionsDialog", "Crop the common area", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MergeOptionsDialog: public Ui_MergeOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEOPTIONSDIALOG_H
