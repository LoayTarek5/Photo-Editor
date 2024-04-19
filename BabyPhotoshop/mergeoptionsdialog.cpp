// MergeOptionsDialog.cpp
#include "mergeoptionsdialog.h"
#include "ui_mergeoptionsdialog.h"

MergeOptionsDialog::MergeOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MergeOptionsDialog)
{
    ui->setupUi(this);
}

MergeOptionsDialog::~MergeOptionsDialog()
{
    delete ui;
}

void MergeOptionsDialog::on_buttonBox_accepted()
{
    if (ui->radioButtonResize->isChecked()) {
        emit mergeOptionSelected("1"); // Reduce the biggest to the smallest
    } else if (ui->radioButtonMagnify->isChecked()) {
        emit mergeOptionSelected("2"); // Magnify the smallest to the biggest
    } else if (ui->radioButtonCrop->isChecked()) {
        emit mergeOptionSelected("3"); // Crop the common area
    }
}
