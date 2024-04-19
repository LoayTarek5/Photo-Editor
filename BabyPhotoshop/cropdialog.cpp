// cropdialog.cpp
#include "cropdialog.h"
#include "ui_cropdialog.h"
#include <QMessageBox>

CropDialog::CropDialog(int imgWidth, int imgHeight, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CropDialog),
    imgWidth(imgWidth),
    imgHeight(imgHeight)
{
    ui->setupUi(this);

    // Set range for spin boxes
    ui->spinBoxX->setRange(0, imgWidth);
    ui->spinBoxY->setRange(0, imgHeight);
    ui->spinBoxWidth->setRange(1, imgWidth);
    ui->spinBoxHeight->setRange(1, imgHeight);

    // Connect the valueChanged signals of spin boxes to the validation slot
    connect(ui->spinBoxX, QOverload<int>::of(&QSpinBox::valueChanged), this, &CropDialog::validateInputs);
    connect(ui->spinBoxY, QOverload<int>::of(&QSpinBox::valueChanged), this, &CropDialog::validateInputs);
    connect(ui->spinBoxWidth, QOverload<int>::of(&QSpinBox::valueChanged), this, &CropDialog::validateInputs);
    connect(ui->spinBoxHeight, QOverload<int>::of(&QSpinBox::valueChanged), this, &CropDialog::validateInputs);
}

CropDialog::~CropDialog()
{
    delete ui;
}

int CropDialog::getX() const {
    return ui->spinBoxX->value();
}

int CropDialog::getY() const {
    return ui->spinBoxY->value();
}

int CropDialog::getWidth() const {
    return ui->spinBoxWidth->value();
}

int CropDialog::getHeight() const {
    return ui->spinBoxHeight->value();
}

void CropDialog::validateInputs() {
    int x = getX();
    int y = getY();
    int width = getWidth();
    int height = getHeight();

    if (x + width > imgWidth || y + height > imgHeight) {
        QMessageBox::critical(this, tr("Error"), tr("Invalid crop parameters: The crop region exceeds the image boundaries."));
        return;
    }
}
