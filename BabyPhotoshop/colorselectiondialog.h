#ifndef COLORSELECTIONDIALOG_H
#define COLORSELECTIONDIALOG_H

#include <QDialog>
#include <QColorDialog>

class ColorSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    ColorSelectionDialog(QWidget *parent = nullptr);

    // Function to retrieve the selected color
    QColor selectedColor() const;

private:
    QColorDialog *colorDialog;
};

#endif // COLORSELECTIONDIALOG_H
