#include "colorselectiondialog.h"

ColorSelectionDialog::ColorSelectionDialog(QWidget *parent)
    : QDialog(parent)
{
    // Initialize the color dialog
    colorDialog = new QColorDialog(this);
    colorDialog->setOption(QColorDialog::ShowAlphaChannel); // Optional: Allow selection of alpha (transparency)
    colorDialog->setWindowTitle(tr("Select Color"));
}

QColor ColorSelectionDialog::selectedColor() const
{
    // Open the color dialog and return the selected color
    return colorDialog->getColor();
}
