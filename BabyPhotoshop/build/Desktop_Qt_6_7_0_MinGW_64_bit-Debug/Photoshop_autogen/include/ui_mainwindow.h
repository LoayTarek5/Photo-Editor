/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnGray;
    QPushButton *btnTV;
    QPushButton *btnClearRslt;
    QPushButton *btnBlur;
    QPushButton *btnResize;
    QPushButton *btnInvertClr;
    QPushButton *btnPixelate;
    QPushButton *btnPurble;
    QPushButton *btnSkew;
    QPushButton *btnFancyFrame;
    QSlider *blurSlider;
    QPushButton *btnFlipH;
    QLabel *insertImg;
    QPushButton *btnLoadImg;
    QPushButton *btnInfraRed;
    QPushButton *btnFlipV;
    QPushButton *btnCrop;
    QPushButton *btnBlackWhite;
    QPushButton *btnSunlight;
    QPushButton *btnSaveImg;
    QLabel *resultImg;
    QPushButton *btnRotat;
    QPushButton *btnEdgeDetection;
    QPushButton *btnHue;
    QPushButton *btnMerge;
    QPushButton *btnOilPnt;
    QSlider *skewSlider;
    QPushButton *btnNormalFrame;
    QPushButton *btnBrightness;
    QSlider *brightnessSlider;
    QSlider *hueSlider;
    QPushButton *pushButton;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1245, 630);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnGray = new QPushButton(centralwidget);
        btnGray->setObjectName("btnGray");
        btnGray->setGeometry(QRect(630, 360, 135, 35));
        btnGray->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnTV = new QPushButton(centralwidget);
        btnTV->setObjectName("btnTV");
        btnTV->setGeometry(QRect(780, 420, 135, 35));
        btnTV->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnClearRslt = new QPushButton(centralwidget);
        btnClearRslt->setObjectName("btnClearRslt");
        btnClearRslt->setGeometry(QRect(530, 10, 80, 24));
        btnClearRslt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnBlur = new QPushButton(centralwidget);
        btnBlur->setObjectName("btnBlur");
        btnBlur->setGeometry(QRect(310, 520, 135, 35));
        btnBlur->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnResize = new QPushButton(centralwidget);
        btnResize->setObjectName("btnResize");
        btnResize->setGeometry(QRect(470, 360, 135, 35));
        btnResize->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnInvertClr = new QPushButton(centralwidget);
        btnInvertClr->setObjectName("btnInvertClr");
        btnInvertClr->setGeometry(QRect(10, 420, 135, 35));
        btnInvertClr->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnPixelate = new QPushButton(centralwidget);
        btnPixelate->setObjectName("btnPixelate");
        btnPixelate->setGeometry(QRect(450, 520, 135, 35));
        btnPixelate->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnPurble = new QPushButton(centralwidget);
        btnPurble->setObjectName("btnPurble");
        btnPurble->setGeometry(QRect(630, 470, 135, 35));
        btnPurble->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnSkew = new QPushButton(centralwidget);
        btnSkew->setObjectName("btnSkew");
        btnSkew->setGeometry(QRect(780, 360, 135, 35));
        btnSkew->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnFancyFrame = new QPushButton(centralwidget);
        btnFancyFrame->setObjectName("btnFancyFrame");
        btnFancyFrame->setGeometry(QRect(160, 470, 135, 35));
        btnFancyFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        blurSlider = new QSlider(centralwidget);
        blurSlider->setObjectName("blurSlider");
        blurSlider->setGeometry(QRect(980, 230, 160, 16));
        blurSlider->setCursor(QCursor(Qt::ArrowCursor));
        blurSlider->setMouseTracking(false);
        blurSlider->setStyleSheet(QString::fromUtf8(""));
        blurSlider->setMinimum(1);
        blurSlider->setSingleStep(2);
        blurSlider->setOrientation(Qt::Horizontal);
        btnFlipH = new QPushButton(centralwidget);
        btnFlipH->setObjectName("btnFlipH");
        btnFlipH->setGeometry(QRect(320, 420, 135, 35));
        btnFlipH->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        insertImg = new QLabel(centralwidget);
        insertImg->setObjectName("insertImg");
        insertImg->setGeometry(QRect(200, 40, 300, 300));
        insertImg->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 200, 197);\n"
"color: rgb(0, 0, 0);\n"
"text-align:center;"));
        btnLoadImg = new QPushButton(centralwidget);
        btnLoadImg->setObjectName("btnLoadImg");
        btnLoadImg->setGeometry(QRect(360, 10, 71, 24));
        btnLoadImg->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 25px;"));
        btnLoadImg->setAutoDefault(false);
        btnInfraRed = new QPushButton(centralwidget);
        btnInfraRed->setObjectName("btnInfraRed");
        btnInfraRed->setGeometry(QRect(780, 470, 135, 35));
        btnInfraRed->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnFlipV = new QPushButton(centralwidget);
        btnFlipV->setObjectName("btnFlipV");
        btnFlipV->setGeometry(QRect(10, 520, 135, 35));
        btnFlipV->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnCrop = new QPushButton(centralwidget);
        btnCrop->setObjectName("btnCrop");
        btnCrop->setGeometry(QRect(160, 420, 135, 35));
        btnCrop->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnBlackWhite = new QPushButton(centralwidget);
        btnBlackWhite->setObjectName("btnBlackWhite");
        btnBlackWhite->setGeometry(QRect(310, 360, 135, 35));
        btnBlackWhite->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnSunlight = new QPushButton(centralwidget);
        btnSunlight->setObjectName("btnSunlight");
        btnSunlight->setGeometry(QRect(460, 470, 135, 35));
        btnSunlight->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnSaveImg = new QPushButton(centralwidget);
        btnSaveImg->setObjectName("btnSaveImg");
        btnSaveImg->setGeometry(QRect(440, 10, 80, 24));
        btnSaveImg->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        resultImg = new QLabel(centralwidget);
        resultImg->setObjectName("resultImg");
        resultImg->setGeometry(QRect(630, 40, 300, 300));
        resultImg->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 200, 197);\n"
"color: rgb(0, 0, 0);\n"
"text-align:center;"));
        btnRotat = new QPushButton(centralwidget);
        btnRotat->setObjectName("btnRotat");
        btnRotat->setGeometry(QRect(10, 470, 135, 35));
        btnRotat->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnEdgeDetection = new QPushButton(centralwidget);
        btnEdgeDetection->setObjectName("btnEdgeDetection");
        btnEdgeDetection->setGeometry(QRect(630, 420, 135, 35));
        btnEdgeDetection->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnHue = new QPushButton(centralwidget);
        btnHue->setObjectName("btnHue");
        btnHue->setGeometry(QRect(310, 470, 135, 35));
        btnHue->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnMerge = new QPushButton(centralwidget);
        btnMerge->setObjectName("btnMerge");
        btnMerge->setGeometry(QRect(160, 360, 135, 35));
        btnMerge->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnOilPnt = new QPushButton(centralwidget);
        btnOilPnt->setObjectName("btnOilPnt");
        btnOilPnt->setGeometry(QRect(470, 420, 135, 35));
        btnOilPnt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        skewSlider = new QSlider(centralwidget);
        skewSlider->setObjectName("skewSlider");
        skewSlider->setGeometry(QRect(980, 140, 160, 16));
        skewSlider->setCursor(QCursor(Qt::ArrowCursor));
        skewSlider->setMouseTracking(false);
        skewSlider->setMinimum(-89);
        skewSlider->setMaximum(89);
        skewSlider->setSingleStep(1);
        skewSlider->setPageStep(0);
        skewSlider->setSliderPosition(0);
        skewSlider->setOrientation(Qt::Horizontal);
        skewSlider->setInvertedAppearance(false);
        skewSlider->setInvertedControls(false);
        btnNormalFrame = new QPushButton(centralwidget);
        btnNormalFrame->setObjectName("btnNormalFrame");
        btnNormalFrame->setGeometry(QRect(170, 520, 135, 35));
        btnNormalFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        btnBrightness = new QPushButton(centralwidget);
        btnBrightness->setObjectName("btnBrightness");
        btnBrightness->setGeometry(QRect(10, 360, 135, 35));
        btnBrightness->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        brightnessSlider = new QSlider(centralwidget);
        brightnessSlider->setObjectName("brightnessSlider");
        brightnessSlider->setGeometry(QRect(980, 170, 160, 16));
        brightnessSlider->setMaximum(5);
        brightnessSlider->setOrientation(Qt::Horizontal);
        hueSlider = new QSlider(centralwidget);
        hueSlider->setObjectName("hueSlider");
        hueSlider->setGeometry(QRect(980, 200, 160, 16));
        hueSlider->setMinimum(1);
        hueSlider->setMaximum(360);
        hueSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(630, 10, 80, 24));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 150, 120, 80));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1245, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnLoadImg->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnGray->setText(QCoreApplication::translate("MainWindow", "Gray", nullptr));
        btnTV->setText(QCoreApplication::translate("MainWindow", "tv_effect", nullptr));
        btnClearRslt->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        btnBlur->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        btnResize->setText(QCoreApplication::translate("MainWindow", "resizeImage", nullptr));
        btnInvertClr->setText(QCoreApplication::translate("MainWindow", "Invert Color", nullptr));
        btnPixelate->setText(QCoreApplication::translate("MainWindow", "Pixelate", nullptr));
        btnPurble->setText(QCoreApplication::translate("MainWindow", "Purble", nullptr));
        btnSkew->setText(QCoreApplication::translate("MainWindow", "skew", nullptr));
        btnFancyFrame->setText(QCoreApplication::translate("MainWindow", "Fancy Fram", nullptr));
        btnFlipH->setText(QCoreApplication::translate("MainWindow", "Flip Image Horizontally", nullptr));
        insertImg->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">insert an image</span></p></body></html>", nullptr));
        btnLoadImg->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        btnInfraRed->setText(QCoreApplication::translate("MainWindow", "InfraRed", nullptr));
        btnFlipV->setText(QCoreApplication::translate("MainWindow", "Flip Image Vertically", nullptr));
        btnCrop->setText(QCoreApplication::translate("MainWindow", "cropImage", nullptr));
        btnBlackWhite->setText(QCoreApplication::translate("MainWindow", "blackWhite", nullptr));
        btnSunlight->setText(QCoreApplication::translate("MainWindow", "Sunlight", nullptr));
        btnSaveImg->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        resultImg->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Result</span></p></body></html>", nullptr));
        btnRotat->setText(QCoreApplication::translate("MainWindow", "Rotat", nullptr));
        btnEdgeDetection->setText(QCoreApplication::translate("MainWindow", "Edge_detction", nullptr));
        btnHue->setText(QCoreApplication::translate("MainWindow", "Hue", nullptr));
        btnMerge->setText(QCoreApplication::translate("MainWindow", "merge", nullptr));
        btnOilPnt->setText(QCoreApplication::translate("MainWindow", "oilPaintingEffect", nullptr));
        btnNormalFrame->setText(QCoreApplication::translate("MainWindow", "Frame", nullptr));
        btnBrightness->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
