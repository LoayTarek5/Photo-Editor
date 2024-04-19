// MergeOptionsDialog.h
#ifndef MERGEOPTIONSDIALOG_H
#define MERGEOPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class MergeOptionsDialog;
}

class MergeOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MergeOptionsDialog(QWidget *parent = nullptr);
    ~MergeOptionsDialog();

signals:
    void mergeOptionSelected(QString option);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MergeOptionsDialog *ui;
};

#endif // MERGEOPTIONSDIALOG_H
