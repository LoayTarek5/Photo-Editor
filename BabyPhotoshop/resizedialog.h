
#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QDialog> // Include necessary Qt header(s)

namespace Ui {
class ResizeDialog; // Forward declaration of Ui::ResizeDialog class
}

class ResizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResizeDialog(QWidget *parent = nullptr);
    ~ResizeDialog();

    int selectedWidth() const; // Declaration of member function to retrieve selected width
    int selectedHeight() const; // Declaration of member function to retrieve selected height

private:
    Ui::ResizeDialog *ui; // Pointer to the UI class
};

#endif // RESIZEDIALOG_H
