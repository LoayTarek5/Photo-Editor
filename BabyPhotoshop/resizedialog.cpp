#include "resizedialog.h"
#include "ui_resizedialog.h"

int ResizeDialog::selectedWidth() const {
    return ui->widthSpinBox->value(); // Assuming you have a QSpinBox named widthSpinBox in your UI
}

int ResizeDialog::selectedHeight() const {
    return ui->heightSpinBox->value(); // Assuming you have a QSpinBox named heightSpinBox in your UI
}

ResizeDialog::ResizeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ResizeDialog)
{
    ui->setupUi(this);
}

ResizeDialog::~ResizeDialog()
{
    delete ui;
}
