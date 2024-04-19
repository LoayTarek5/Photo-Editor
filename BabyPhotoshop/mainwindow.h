#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mergeoptionsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLoadImg_clicked();

    void on_btnSaveImg_clicked();

    void on_btnGray_clicked();

    void on_btnOilPnt_clicked();

    void on_btnInfraRed_clicked();

    void on_btnHue_clicked();
    void on_hueSlider_actionTriggered(int action);
    void applyHue();

    void on_btnSunlight_clicked();

    void on_btnBlackWhite_clicked();

    void on_btnInvertClr_clicked();

    void on_btnTV_clicked();

    void on_btnEdgeDetection_clicked();

    void on_btnPixelate_clicked();

    void on_btnPurble_clicked();

    void on_btnBlur_clicked();

    void on_blurSlider_actionTriggered(int action);
    void applyBlurEffect();
    void on_btnRotat_clicked();

    void on_btnFlipH_clicked();

    void on_btnFlipV_clicked();

    void on_btnResize_clicked();
    void onResizeDialogAccepted();
    void onResizeDialogRejected();
    void on_btnCrop_clicked();

    void on_btnSkew_clicked();
    void on_skewSlider_actionTriggered(int action);
    void applySkew();

    void handleMergeOptionSelected(QString mergeOption);
    void on_btnMerge_clicked();

    void on_btnFancyFrame_clicked();
    void on_btnNormalFrame_clicked();
    void updateResultImage();


    void on_brightnessSlider_actionTriggered(double action);
    void on_btnBrightness_clicked();
    void applyBrightness();


    void on_btnClearRslt_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    // In the MainWindow class definition, add a private member for the MergeOptionsDialog
    MergeOptionsDialog *mergeOptionsDialog;
    int blur_intensity = 1;
    std::string answer = "1";
    float hue_shift = 0;
    double num = 0.3;
    int skew_degree = 0;
    int resizedWidth = 0; // Member variable to store selected width
    int resizedHeight = 0; // Member variable to store selected height
};
#endif // MAINWINDOW_H
