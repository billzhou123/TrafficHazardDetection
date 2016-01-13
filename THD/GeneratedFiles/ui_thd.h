/********************************************************************************
** Form generated from reading UI file 'thd.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THD_H
#define UI_THD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_THDClass
{
public:
    QWidget *centralWidget;
    QGroupBox *gBoxOutputFeeds;
    QGroupBox *gBoxLiveFeed;
    QLabel *lblLiveFeed;
    QLabel *lblOutputInformationTitle;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblFramesProcessedTitle;
    QLabel *lblFramesProcessed;
    QLabel *lblTimeElaspedTitle;
    QLabel *lblTimeElapsed;
    QLabel *lblVideoSpeedTitle;
    QLabel *lblVideoSpeed;
    QLabel *lblVehicleSpeedTitle;
    QLabel *lblVehicleSpeed;
    QLabel *lblEngineCallibrationTitle;
    QLabel *lblEngineCallibration;
    QGroupBox *gBoxDetectionFeed;
    QLabel *lblDetectionFeed;
    QSlider *hSliderProgress;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSlowDown;
    QPushButton *btnPlayPause;
    QPushButton *btnSpeedUp;
    QGroupBox *gBoxAnalysisImages;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblHazard1Title;
    QLabel *lblHazard2Title;
    QLabel *lblHazard3Title;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblHazard1;
    QLabel *lblHazard2;
    QLabel *lblHazard3;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblAnalysisImage1;
    QLabel *lblAnalysisImage2;
    QGroupBox *gBoxControlPanel;
    QTabWidget *tWidgetControls;
    QWidget *tabconsole;
    QListWidget *lWidgetConsole;
    QWidget *tabsettings;
    QLineEdit *lEditVideoLocation;
    QLabel *lblSelectVideoTitle;
    QPushButton *btnStart;
    QPushButton *btnBrowse;
    QCheckBox *cBoxRGBCorrection;
    QLabel *lblAdditionalSettingsTitle;
    QPushButton *btnClear;
    QCheckBox *cBoxDetectionPause;
    QCheckBox *cBoxAnnotations;
    QPushButton *btnStop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *THDClass)
    {
        if (THDClass->objectName().isEmpty())
            THDClass->setObjectName(QStringLiteral("THDClass"));
        THDClass->resize(1309, 708);
        THDClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(THDClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        gBoxOutputFeeds = new QGroupBox(centralWidget);
        gBoxOutputFeeds->setObjectName(QStringLiteral("gBoxOutputFeeds"));
        gBoxOutputFeeds->setGeometry(QRect(10, 10, 711, 641));
        gBoxOutputFeeds->setStyleSheet(QLatin1String(" QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }"));
        gBoxLiveFeed = new QGroupBox(gBoxOutputFeeds);
        gBoxLiveFeed->setObjectName(QStringLiteral("gBoxLiveFeed"));
        gBoxLiveFeed->setGeometry(QRect(10, 20, 691, 261));
        lblLiveFeed = new QLabel(gBoxLiveFeed);
        lblLiveFeed->setObjectName(QStringLiteral("lblLiveFeed"));
        lblLiveFeed->setGeometry(QRect(10, 20, 431, 231));
        lblLiveFeed->setAlignment(Qt::AlignCenter);
        lblOutputInformationTitle = new QLabel(gBoxLiveFeed);
        lblOutputInformationTitle->setObjectName(QStringLiteral("lblOutputInformationTitle"));
        lblOutputInformationTitle->setGeometry(QRect(450, 20, 121, 21));
        lblOutputInformationTitle->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(gBoxLiveFeed);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 50, 231, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblFramesProcessedTitle = new QLabel(layoutWidget);
        lblFramesProcessedTitle->setObjectName(QStringLiteral("lblFramesProcessedTitle"));

        gridLayout->addWidget(lblFramesProcessedTitle, 0, 0, 1, 1);

        lblFramesProcessed = new QLabel(layoutWidget);
        lblFramesProcessed->setObjectName(QStringLiteral("lblFramesProcessed"));

        gridLayout->addWidget(lblFramesProcessed, 0, 1, 1, 2);

        lblTimeElaspedTitle = new QLabel(layoutWidget);
        lblTimeElaspedTitle->setObjectName(QStringLiteral("lblTimeElaspedTitle"));

        gridLayout->addWidget(lblTimeElaspedTitle, 1, 0, 1, 1);

        lblTimeElapsed = new QLabel(layoutWidget);
        lblTimeElapsed->setObjectName(QStringLiteral("lblTimeElapsed"));

        gridLayout->addWidget(lblTimeElapsed, 1, 1, 1, 2);

        lblVideoSpeedTitle = new QLabel(layoutWidget);
        lblVideoSpeedTitle->setObjectName(QStringLiteral("lblVideoSpeedTitle"));

        gridLayout->addWidget(lblVideoSpeedTitle, 2, 0, 1, 1);

        lblVideoSpeed = new QLabel(layoutWidget);
        lblVideoSpeed->setObjectName(QStringLiteral("lblVideoSpeed"));

        gridLayout->addWidget(lblVideoSpeed, 2, 1, 1, 2);

        lblVehicleSpeedTitle = new QLabel(layoutWidget);
        lblVehicleSpeedTitle->setObjectName(QStringLiteral("lblVehicleSpeedTitle"));

        gridLayout->addWidget(lblVehicleSpeedTitle, 3, 0, 1, 1);

        lblVehicleSpeed = new QLabel(layoutWidget);
        lblVehicleSpeed->setObjectName(QStringLiteral("lblVehicleSpeed"));

        gridLayout->addWidget(lblVehicleSpeed, 3, 1, 1, 2);

        lblEngineCallibrationTitle = new QLabel(layoutWidget);
        lblEngineCallibrationTitle->setObjectName(QStringLiteral("lblEngineCallibrationTitle"));

        gridLayout->addWidget(lblEngineCallibrationTitle, 4, 0, 1, 1);

        lblEngineCallibration = new QLabel(layoutWidget);
        lblEngineCallibration->setObjectName(QStringLiteral("lblEngineCallibration"));

        gridLayout->addWidget(lblEngineCallibration, 4, 1, 1, 2);

        gBoxDetectionFeed = new QGroupBox(gBoxOutputFeeds);
        gBoxDetectionFeed->setObjectName(QStringLiteral("gBoxDetectionFeed"));
        gBoxDetectionFeed->setGeometry(QRect(10, 350, 691, 281));
        lblDetectionFeed = new QLabel(gBoxDetectionFeed);
        lblDetectionFeed->setObjectName(QStringLiteral("lblDetectionFeed"));
        lblDetectionFeed->setGeometry(QRect(10, 20, 671, 251));
        lblDetectionFeed->setAlignment(Qt::AlignCenter);
        hSliderProgress = new QSlider(gBoxOutputFeeds);
        hSliderProgress->setObjectName(QStringLiteral("hSliderProgress"));
        hSliderProgress->setEnabled(false);
        hSliderProgress->setGeometry(QRect(10, 300, 691, 22));
        hSliderProgress->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"     border: 1px solid #999999;\n"
"     height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"     margin: 2px 0;\n"
" }\n"
"\n"
"QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"     border-radius: 3px;\n"
" }"));
        hSliderProgress->setOrientation(Qt::Horizontal);
        hSliderProgress->setTickPosition(QSlider::TicksAbove);
        layoutWidget1 = new QWidget(gBoxOutputFeeds);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 320, 271, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnSlowDown = new QPushButton(layoutWidget1);
        btnSlowDown->setObjectName(QStringLiteral("btnSlowDown"));

        horizontalLayout->addWidget(btnSlowDown);

        btnPlayPause = new QPushButton(layoutWidget1);
        btnPlayPause->setObjectName(QStringLiteral("btnPlayPause"));

        horizontalLayout->addWidget(btnPlayPause);

        btnSpeedUp = new QPushButton(layoutWidget1);
        btnSpeedUp->setObjectName(QStringLiteral("btnSpeedUp"));

        horizontalLayout->addWidget(btnSpeedUp);

        gBoxAnalysisImages = new QGroupBox(centralWidget);
        gBoxAnalysisImages->setObjectName(QStringLiteral("gBoxAnalysisImages"));
        gBoxAnalysisImages->setGeometry(QRect(740, 10, 561, 401));
        gBoxAnalysisImages->setStyleSheet(QLatin1String(" QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"\n"
"QFrame, QLabel, QToolTip {\n"
"     border: 2px solid gray;\n"
"     border-radius: 4px;\n"
"     padding: 2px;\n"
"     background-image: url(images/welcome.png);\n"
" }"));
        layoutWidget2 = new QWidget(gBoxAnalysisImages);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 521, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblHazard1Title = new QLabel(layoutWidget2);
        lblHazard1Title->setObjectName(QStringLiteral("lblHazard1Title"));
        lblHazard1Title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblHazard1Title);

        lblHazard2Title = new QLabel(layoutWidget2);
        lblHazard2Title->setObjectName(QStringLiteral("lblHazard2Title"));
        lblHazard2Title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblHazard2Title);

        lblHazard3Title = new QLabel(layoutWidget2);
        lblHazard3Title->setObjectName(QStringLiteral("lblHazard3Title"));
        lblHazard3Title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblHazard3Title);

        layoutWidget3 = new QWidget(gBoxAnalysisImages);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 50, 521, 171));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lblHazard1 = new QLabel(layoutWidget3);
        lblHazard1->setObjectName(QStringLiteral("lblHazard1"));
        lblHazard1->setMaximumSize(QSize(169, 169));
        lblHazard1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lblHazard1);

        lblHazard2 = new QLabel(layoutWidget3);
        lblHazard2->setObjectName(QStringLiteral("lblHazard2"));
        lblHazard2->setMaximumSize(QSize(169, 169));
        lblHazard2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lblHazard2);

        lblHazard3 = new QLabel(layoutWidget3);
        lblHazard3->setObjectName(QStringLiteral("lblHazard3"));
        lblHazard3->setMaximumSize(QSize(169, 16777215));
        lblHazard3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lblHazard3);

        layoutWidget4 = new QWidget(gBoxAnalysisImages);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 230, 521, 161));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lblAnalysisImage1 = new QLabel(layoutWidget4);
        lblAnalysisImage1->setObjectName(QStringLiteral("lblAnalysisImage1"));
        lblAnalysisImage1->setMaximumSize(QSize(257, 159));
        lblAnalysisImage1->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lblAnalysisImage1);

        lblAnalysisImage2 = new QLabel(layoutWidget4);
        lblAnalysisImage2->setObjectName(QStringLiteral("lblAnalysisImage2"));
        lblAnalysisImage2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lblAnalysisImage2);

        gBoxControlPanel = new QGroupBox(centralWidget);
        gBoxControlPanel->setObjectName(QStringLiteral("gBoxControlPanel"));
        gBoxControlPanel->setGeometry(QRect(740, 420, 561, 231));
        gBoxControlPanel->setStyleSheet(QLatin1String(" QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"\n"
""));
        tWidgetControls = new QTabWidget(gBoxControlPanel);
        tWidgetControls->setObjectName(QStringLiteral("tWidgetControls"));
        tWidgetControls->setGeometry(QRect(10, 20, 541, 201));
        tWidgetControls->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
"     border-top: 2px solid #C2C7CB;\n"
"     position: absolute;\n"
"     top: -0.5em;\n"
" }\n"
"\n"
" QTabWidget::tab-bar {\n"
"     alignment: center;\n"
" }\n"
"\n"
" /* Style the tab using the tab sub-control. Note that\n"
"     it reads QTabBar _not_ QTabWidget */\n"
" QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"\n"
" QTabBar::tab:selected, QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop:"
                        " 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"     border-bottom-color: #C2C7CB; /* same as pane color */\n"
" }"));
        tWidgetControls->setMovable(true);
        tabconsole = new QWidget();
        tabconsole->setObjectName(QStringLiteral("tabconsole"));
        lWidgetConsole = new QListWidget(tabconsole);
        lWidgetConsole->setObjectName(QStringLiteral("lWidgetConsole"));
        lWidgetConsole->setEnabled(true);
        lWidgetConsole->setGeometry(QRect(0, 0, 541, 181));
        lWidgetConsole->setFrameShape(QFrame::VLine);
        lWidgetConsole->setFrameShadow(QFrame::Plain);
        lWidgetConsole->setAutoScroll(true);
        tWidgetControls->addTab(tabconsole, QString());
        tabsettings = new QWidget();
        tabsettings->setObjectName(QStringLiteral("tabsettings"));
        lEditVideoLocation = new QLineEdit(tabsettings);
        lEditVideoLocation->setObjectName(QStringLiteral("lEditVideoLocation"));
        lEditVideoLocation->setGeometry(QRect(10, 40, 511, 20));
        lEditVideoLocation->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     padding: 0 8px;\n"
"     selection-background-color: darkgray;\n"
" }"));
        lblSelectVideoTitle = new QLabel(tabsettings);
        lblSelectVideoTitle->setObjectName(QStringLiteral("lblSelectVideoTitle"));
        lblSelectVideoTitle->setGeometry(QRect(10, 15, 111, 21));
        btnStart = new QPushButton(tabsettings);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(440, 140, 84, 23));
        btnBrowse = new QPushButton(tabsettings);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));
        btnBrowse->setGeometry(QRect(440, 70, 84, 23));
        cBoxRGBCorrection = new QCheckBox(tabsettings);
        cBoxRGBCorrection->setObjectName(QStringLiteral("cBoxRGBCorrection"));
        cBoxRGBCorrection->setGeometry(QRect(10, 100, 181, 17));
        cBoxRGBCorrection->setStyleSheet(QStringLiteral(""));
        lblAdditionalSettingsTitle = new QLabel(tabsettings);
        lblAdditionalSettingsTitle->setObjectName(QStringLiteral("lblAdditionalSettingsTitle"));
        lblAdditionalSettingsTitle->setGeometry(QRect(10, 75, 101, 21));
        btnClear = new QPushButton(tabsettings);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(360, 70, 84, 23));
        cBoxDetectionPause = new QCheckBox(tabsettings);
        cBoxDetectionPause->setObjectName(QStringLiteral("cBoxDetectionPause"));
        cBoxDetectionPause->setGeometry(QRect(10, 120, 191, 17));
        cBoxDetectionPause->setStyleSheet(QStringLiteral(""));
        cBoxAnnotations = new QCheckBox(tabsettings);
        cBoxAnnotations->setObjectName(QStringLiteral("cBoxAnnotations"));
        cBoxAnnotations->setGeometry(QRect(10, 140, 211, 17));
        btnStop = new QPushButton(tabsettings);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        btnStop->setGeometry(QRect(360, 140, 84, 23));
        tWidgetControls->addTab(tabsettings, QString());
        THDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(THDClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1309, 21));
        THDClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(THDClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        THDClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(THDClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        THDClass->setStatusBar(statusBar);

        retranslateUi(THDClass);

        tWidgetControls->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(THDClass);
    } // setupUi

    void retranslateUi(QMainWindow *THDClass)
    {
        THDClass->setWindowTitle(QApplication::translate("THDClass", "THD", 0));
        gBoxOutputFeeds->setTitle(QApplication::translate("THDClass", "Output Feeds", 0));
        gBoxLiveFeed->setTitle(QApplication::translate("THDClass", "Live Feed", 0));
        lblLiveFeed->setText(QApplication::translate("THDClass", "Live Feed Empty", 0));
        lblOutputInformationTitle->setText(QApplication::translate("THDClass", "Output Information:", 0));
        lblFramesProcessedTitle->setText(QApplication::translate("THDClass", "Frames Processed: ", 0));
        lblFramesProcessed->setText(QApplication::translate("THDClass", "0", 0));
        lblTimeElaspedTitle->setText(QApplication::translate("THDClass", "Time Elasped:", 0));
        lblTimeElapsed->setText(QApplication::translate("THDClass", "0", 0));
        lblVideoSpeedTitle->setText(QApplication::translate("THDClass", "Video Speed:", 0));
        lblVideoSpeed->setText(QApplication::translate("THDClass", "1x", 0));
        lblVehicleSpeedTitle->setText(QApplication::translate("THDClass", "Vehicle Speed:", 0));
        lblVehicleSpeed->setText(QApplication::translate("THDClass", "Not Callibrated", 0));
        lblEngineCallibrationTitle->setText(QApplication::translate("THDClass", "Engine Callibration:", 0));
        lblEngineCallibration->setText(QApplication::translate("THDClass", "N/A", 0));
        gBoxDetectionFeed->setTitle(QApplication::translate("THDClass", "Detection Feed", 0));
        lblDetectionFeed->setText(QApplication::translate("THDClass", "Detection Feed Empty", 0));
        btnSlowDown->setText(QApplication::translate("THDClass", "Slow Down", 0));
        btnPlayPause->setText(QApplication::translate("THDClass", "Pause", 0));
        btnSpeedUp->setText(QApplication::translate("THDClass", "Speed Up", 0));
        gBoxAnalysisImages->setTitle(QApplication::translate("THDClass", "Analysis Images", 0));
        lblHazard1Title->setText(QApplication::translate("THDClass", "Hazard 1", 0));
        lblHazard2Title->setText(QApplication::translate("THDClass", "Hazard 2", 0));
        lblHazard3Title->setText(QApplication::translate("THDClass", "Hazard 3", 0));
        lblHazard1->setText(QApplication::translate("THDClass", "No Hazard", 0));
        lblHazard2->setText(QApplication::translate("THDClass", "No Hazard", 0));
        lblHazard3->setText(QApplication::translate("THDClass", "No Hazard", 0));
        lblAnalysisImage1->setText(QApplication::translate("THDClass", "No Image", 0));
        lblAnalysisImage2->setText(QApplication::translate("THDClass", "No Image", 0));
        gBoxControlPanel->setTitle(QApplication::translate("THDClass", "Control Panel", 0));
        tWidgetControls->setTabText(tWidgetControls->indexOf(tabconsole), QApplication::translate("THDClass", "Console", 0));
        lblSelectVideoTitle->setText(QApplication::translate("THDClass", "Sample Feed Selection", 0));
        btnStart->setText(QApplication::translate("THDClass", "Start", 0));
        btnBrowse->setText(QApplication::translate("THDClass", "Browse", 0));
        cBoxRGBCorrection->setText(QApplication::translate("THDClass", "Disable RGB Channel Correction", 0));
        lblAdditionalSettingsTitle->setText(QApplication::translate("THDClass", "Additionl Settings:", 0));
        btnClear->setText(QApplication::translate("THDClass", "Clear", 0));
        cBoxDetectionPause->setText(QApplication::translate("THDClass", "Pause Upon Hazard Detection", 0));
        cBoxAnnotations->setText(QApplication::translate("THDClass", "Enable Scene Annotations", 0));
        btnStop->setText(QApplication::translate("THDClass", "Stop", 0));
        tWidgetControls->setTabText(tWidgetControls->indexOf(tabsettings), QApplication::translate("THDClass", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class THDClass: public Ui_THDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THD_H
