// cropdialog.h
#ifndef CROPDIALOG_H
#define CROPDIALOG_H

#include <QDialog>

namespace Ui {
class CropDialog;
}

class CropDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CropDialog(int imgWidth, int imgHeight, QWidget *parent = nullptr);
    ~CropDialog();

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

private slots:
    void validateInputs();

private:
    Ui::CropDialog *ui;
    int imgWidth;
    int imgHeight;
};

#endif // CROPDIALOG_H
