/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QCustomPlot *TrayPlot;
    QSpinBox *Rows;
    QLineEdit *B;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_4;
    QLineEdit *C;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *A;
    QLineEdit *D;
    QLabel *label;
    QLabel *label_9;
    QSpinBox *Cols;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_5;
    QPushButton *MD295;
    QPushButton *MD61;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QPushButton *FD1;
    QPushButton *FD;
    QSpacerItem *verticalSpacer_6;
    QPushButton *KF;
    QCustomPlot *UnitPlot;
    QLabel *Jlabel;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *Iunit;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_15;
    QLabel *orientationNote;
    QLineEdit *E;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *Ilabel;
    QCheckBox *centeredCheckBox;
    QLineEdit *I;
    QLabel *label_13;
    QLabel *Junit;
    QLineEdit *F;
    QLineEdit *G;
    QLabel *label_16;
    QLineEdit *J;
    QLineEdit *H;
    QPushButton *KK;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_24;
    QLineEdit *K;
    QLabel *label_26;
    QCustomPlot *SpacingPlot;
    QLabel *label_25;
    QLineEdit *L;
    QLabel *label_27;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_8;
    QRadioButton *CircularNozzle;
    QRadioButton *RectangularNozzle;
    QLabel *label_32;
    QLineEdit *nozzleWidth;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLineEdit *timeField;
    QLineEdit *volumeField;
    QLineEdit *thicknessField;
    QRadioButton *thickness;
    QRadioButton *volume;
    QRadioButton *time;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QCustomPlot *PreviewPlot;
    QLabel *StatusLine;
    QSpacerItem *horizontalSpacer;
    QPushButton *generateButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(670, 575);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        TrayPlot = new QCustomPlot(tab);
        TrayPlot->setObjectName(QStringLiteral("TrayPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TrayPlot->sizePolicy().hasHeightForWidth());
        TrayPlot->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(TrayPlot, 0, 3, 10, 1);

        Rows = new QSpinBox(tab);
        Rows->setObjectName(QStringLiteral("Rows"));
        Rows->setMinimum(1);
        Rows->setValue(3);

        gridLayout_2->addWidget(Rows, 4, 1, 1, 1);

        B = new QLineEdit(tab);
        B->setObjectName(QStringLiteral("B"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(B->sizePolicy().hasHeightForWidth());
        B->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(B, 1, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);

        C = new QLineEdit(tab);
        C->setObjectName(QStringLiteral("C"));
        sizePolicy1.setHeightForWidth(C->sizePolicy().hasHeightForWidth());
        C->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(C, 2, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 2, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 3, 2, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 0, 1, 1);

        A = new QLineEdit(tab);
        A->setObjectName(QStringLiteral("A"));
        sizePolicy1.setHeightForWidth(A->sizePolicy().hasHeightForWidth());
        A->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(A, 0, 1, 1, 1);

        D = new QLineEdit(tab);
        D->setObjectName(QStringLiteral("D"));
        sizePolicy1.setHeightForWidth(D->sizePolicy().hasHeightForWidth());
        D->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(D, 3, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 4, 0, 1, 1);

        Cols = new QSpinBox(tab);
        Cols->setObjectName(QStringLiteral("Cols"));
        Cols->setMinimum(1);
        Cols->setValue(7);

        gridLayout_2->addWidget(Cols, 5, 1, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 6, 0, 1, 1);

        MD295 = new QPushButton(tab);
        MD295->setObjectName(QStringLiteral("MD295"));

        gridLayout_2->addWidget(MD295, 7, 0, 1, 2);

        MD61 = new QPushButton(tab);
        MD61->setObjectName(QStringLiteral("MD61"));

        gridLayout_2->addWidget(MD61, 8, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        FD1 = new QPushButton(tab_2);
        FD1->setObjectName(QStringLiteral("FD1"));

        gridLayout_3->addWidget(FD1, 10, 0, 1, 2);

        FD = new QPushButton(tab_2);
        FD->setObjectName(QStringLiteral("FD"));

        gridLayout_3->addWidget(FD, 9, 0, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 8, 0, 1, 1);

        KF = new QPushButton(tab_2);
        KF->setObjectName(QStringLiteral("KF"));

        gridLayout_3->addWidget(KF, 11, 0, 1, 2);

        UnitPlot = new QCustomPlot(tab_2);
        UnitPlot->setObjectName(QStringLiteral("UnitPlot"));
        sizePolicy.setHeightForWidth(UnitPlot->sizePolicy().hasHeightForWidth());
        UnitPlot->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(UnitPlot, 0, 3, 14, 1);

        Jlabel = new QLabel(tab_2);
        Jlabel->setObjectName(QStringLiteral("Jlabel"));
        Jlabel->setEnabled(true);

        gridLayout_3->addWidget(Jlabel, 6, 0, 1, 1);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 1, 2, 1, 1);

        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 3, 2, 1, 1);

        Iunit = new QLabel(tab_2);
        Iunit->setObjectName(QStringLiteral("Iunit"));
        Iunit->setEnabled(true);

        gridLayout_3->addWidget(Iunit, 5, 2, 1, 1);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 13, 1, 1, 1);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 2, 0, 1, 1);

        orientationNote = new QLabel(tab_2);
        orientationNote->setObjectName(QStringLiteral("orientationNote"));
        orientationNote->setEnabled(true);
        orientationNote->setWordWrap(true);

        gridLayout_3->addWidget(orientationNote, 7, 0, 1, 3);

        E = new QLineEdit(tab_2);
        E->setObjectName(QStringLiteral("E"));
        sizePolicy1.setHeightForWidth(E->sizePolicy().hasHeightForWidth());
        E->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(E, 0, 1, 1, 1);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 0, 2, 1, 1);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        Ilabel = new QLabel(tab_2);
        Ilabel->setObjectName(QStringLiteral("Ilabel"));
        Ilabel->setEnabled(true);

        gridLayout_3->addWidget(Ilabel, 5, 0, 1, 1);

        centeredCheckBox = new QCheckBox(tab_2);
        centeredCheckBox->setObjectName(QStringLiteral("centeredCheckBox"));
        centeredCheckBox->setChecked(true);

        gridLayout_3->addWidget(centeredCheckBox, 4, 1, 1, 2);

        I = new QLineEdit(tab_2);
        I->setObjectName(QStringLiteral("I"));
        I->setEnabled(true);
        sizePolicy1.setHeightForWidth(I->sizePolicy().hasHeightForWidth());
        I->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(I, 5, 1, 1, 1);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        Junit = new QLabel(tab_2);
        Junit->setObjectName(QStringLiteral("Junit"));
        Junit->setEnabled(true);

        gridLayout_3->addWidget(Junit, 6, 2, 1, 1);

        F = new QLineEdit(tab_2);
        F->setObjectName(QStringLiteral("F"));
        sizePolicy1.setHeightForWidth(F->sizePolicy().hasHeightForWidth());
        F->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(F, 1, 1, 1, 1);

        G = new QLineEdit(tab_2);
        G->setObjectName(QStringLiteral("G"));
        sizePolicy1.setHeightForWidth(G->sizePolicy().hasHeightForWidth());
        G->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(G, 2, 1, 1, 1);

        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 2, 2, 1, 1);

        J = new QLineEdit(tab_2);
        J->setObjectName(QStringLiteral("J"));
        J->setEnabled(true);
        sizePolicy1.setHeightForWidth(J->sizePolicy().hasHeightForWidth());
        J->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(J, 6, 1, 1, 1);

        H = new QLineEdit(tab_2);
        H->setObjectName(QStringLiteral("H"));
        sizePolicy1.setHeightForWidth(H->sizePolicy().hasHeightForWidth());
        H->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(H, 3, 1, 1, 1);

        KK = new QPushButton(tab_2);
        KK->setObjectName(QStringLiteral("KK"));

        gridLayout_3->addWidget(KK, 12, 0, 1, 2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_4->addWidget(label_24, 0, 0, 1, 1);

        K = new QLineEdit(tab_3);
        K->setObjectName(QStringLiteral("K"));
        sizePolicy1.setHeightForWidth(K->sizePolicy().hasHeightForWidth());
        K->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(K, 0, 1, 1, 1);

        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_4->addWidget(label_26, 0, 2, 1, 1);

        SpacingPlot = new QCustomPlot(tab_3);
        SpacingPlot->setObjectName(QStringLiteral("SpacingPlot"));
        sizePolicy.setHeightForWidth(SpacingPlot->sizePolicy().hasHeightForWidth());
        SpacingPlot->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(SpacingPlot, 0, 3, 3, 1);

        label_25 = new QLabel(tab_3);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_4->addWidget(label_25, 1, 0, 1, 1);

        L = new QLineEdit(tab_3);
        L->setObjectName(QStringLiteral("L"));
        sizePolicy1.setHeightForWidth(L->sizePolicy().hasHeightForWidth());
        L->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(L, 1, 1, 1, 1);

        label_27 = new QLabel(tab_3);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_4->addWidget(label_27, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 297, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 2, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_8 = new QGridLayout(groupBox_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        CircularNozzle = new QRadioButton(groupBox_2);
        CircularNozzle->setObjectName(QStringLiteral("CircularNozzle"));

        gridLayout_8->addWidget(CircularNozzle, 0, 0, 1, 1);

        RectangularNozzle = new QRadioButton(groupBox_2);
        RectangularNozzle->setObjectName(QStringLiteral("RectangularNozzle"));
        RectangularNozzle->setChecked(true);

        gridLayout_8->addWidget(RectangularNozzle, 1, 0, 1, 1);

        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_8->addWidget(label_32, 1, 2, 1, 1);

        nozzleWidth = new QLineEdit(groupBox_2);
        nozzleWidth->setObjectName(QStringLiteral("nozzleWidth"));
        sizePolicy1.setHeightForWidth(nozzleWidth->sizePolicy().hasHeightForWidth());
        nozzleWidth->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(nozzleWidth, 1, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 1, 0, 2, 1);

        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        timeField = new QLineEdit(groupBox);
        timeField->setObjectName(QStringLiteral("timeField"));
        sizePolicy1.setHeightForWidth(timeField->sizePolicy().hasHeightForWidth());
        timeField->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(timeField, 2, 1, 1, 1);

        volumeField = new QLineEdit(groupBox);
        volumeField->setObjectName(QStringLiteral("volumeField"));
        volumeField->setEnabled(false);
        sizePolicy1.setHeightForWidth(volumeField->sizePolicy().hasHeightForWidth());
        volumeField->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(volumeField, 1, 1, 1, 1);

        thicknessField = new QLineEdit(groupBox);
        thicknessField->setObjectName(QStringLiteral("thicknessField"));
        thicknessField->setEnabled(false);
        sizePolicy1.setHeightForWidth(thicknessField->sizePolicy().hasHeightForWidth());
        thicknessField->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(thicknessField, 0, 1, 1, 1);

        thickness = new QRadioButton(groupBox);
        thickness->setObjectName(QStringLiteral("thickness"));

        gridLayout_6->addWidget(thickness, 0, 0, 1, 1);

        volume = new QRadioButton(groupBox);
        volume->setObjectName(QStringLiteral("volume"));

        gridLayout_6->addWidget(volume, 1, 0, 1, 1);

        time = new QRadioButton(groupBox);
        time->setObjectName(QStringLiteral("time"));
        time->setChecked(true);

        gridLayout_6->addWidget(time, 2, 0, 1, 1);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_6->addWidget(label_29, 0, 2, 1, 1);

        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_6->addWidget(label_30, 1, 2, 1, 1);

        label_31 = new QLabel(groupBox);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_6->addWidget(label_31, 2, 2, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_4, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        PreviewPlot = new QCustomPlot(tab_5);
        PreviewPlot->setObjectName(QStringLiteral("PreviewPlot"));

        gridLayout_5->addWidget(PreviewPlot, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 3);

        StatusLine = new QLabel(centralWidget);
        StatusLine->setObjectName(QStringLiteral("StatusLine"));

        gridLayout->addWidget(StatusLine, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        generateButton = new QPushButton(centralWidget);
        generateButton->setObjectName(QStringLiteral("generateButton"));

        gridLayout->addWidget(generateButton, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        B->setText(QApplication::translate("MainWindow", "7.75", 0));
        label_3->setText(QApplication::translate("MainWindow", "B", 0));
        label_7->setText(QApplication::translate("MainWindow", "D", 0));
        label_4->setText(QApplication::translate("MainWindow", "in", 0));
        C->setText(QApplication::translate("MainWindow", "0.1", 0));
        label_6->setText(QApplication::translate("MainWindow", "in", 0));
        label_8->setText(QApplication::translate("MainWindow", "in", 0));
        label_5->setText(QApplication::translate("MainWindow", "C", 0));
        label_2->setText(QApplication::translate("MainWindow", "in", 0));
        A->setText(QApplication::translate("MainWindow", "11.875", 0));
        D->setText(QApplication::translate("MainWindow", "0.1", 0));
        label->setText(QApplication::translate("MainWindow", "A", 0));
        label_9->setText(QApplication::translate("MainWindow", "Rows", 0));
        label_10->setText(QApplication::translate("MainWindow", "Columns", 0));
        MD295->setText(QApplication::translate("MainWindow", "MD295 tray (small)", 0));
        MD61->setText(QApplication::translate("MainWindow", "MD61 tray (large)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tray", 0));
        FD1->setText(QApplication::translate("MainWindow", "(MP118) FD-1", 0));
        FD->setText(QApplication::translate("MainWindow", "(MP118) FD", 0));
        KF->setText(QApplication::translate("MainWindow", "(MP104) KF", 0));
        Jlabel->setText(QApplication::translate("MainWindow", "J", 0));
        label_14->setText(QApplication::translate("MainWindow", "in", 0));
        label_18->setText(QApplication::translate("MainWindow", "in", 0));
        Iunit->setText(QApplication::translate("MainWindow", "in", 0));
        label_17->setText(QApplication::translate("MainWindow", "H", 0));
        label_15->setText(QApplication::translate("MainWindow", "G", 0));
        orientationNote->setText(QApplication::translate("MainWindow", "Note: Operator must orient all units identically ", 0));
        E->setText(QApplication::translate("MainWindow", "1.63", 0));
        label_12->setText(QApplication::translate("MainWindow", "in", 0));
        label_11->setText(QApplication::translate("MainWindow", "E", 0));
        Ilabel->setText(QApplication::translate("MainWindow", "I", 0));
        centeredCheckBox->setText(QApplication::translate("MainWindow", "Epoxy Centered on Unit", 0));
        I->setText(QApplication::translate("MainWindow", "0.315", 0));
        label_13->setText(QApplication::translate("MainWindow", "F", 0));
        Junit->setText(QApplication::translate("MainWindow", "in", 0));
        F->setText(QApplication::translate("MainWindow", "2.49", 0));
        G->setText(QApplication::translate("MainWindow", "1", 0));
        label_16->setText(QApplication::translate("MainWindow", "in", 0));
        J->setText(QApplication::translate("MainWindow", "0.245", 0));
        H->setText(QApplication::translate("MainWindow", "2", 0));
        KK->setText(QApplication::translate("MainWindow", "(MP204) KK", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Unit", 0));
        label_24->setText(QApplication::translate("MainWindow", "K", 0));
        K->setText(QApplication::translate("MainWindow", "0.05", 0));
        label_26->setText(QApplication::translate("MainWindow", "in", 0));
        label_25->setText(QApplication::translate("MainWindow", "L", 0));
        L->setText(QApplication::translate("MainWindow", "0.08", 0));
        label_27->setText(QApplication::translate("MainWindow", "in", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Spacing", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Nozzle", 0));
        CircularNozzle->setText(QApplication::translate("MainWindow", "Circular", 0));
        RectangularNozzle->setText(QApplication::translate("MainWindow", "Rectangular - Width:", 0));
        label_32->setText(QApplication::translate("MainWindow", "in", 0));
        nozzleWidth->setText(QApplication::translate("MainWindow", "1", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Epoxy Application", 0));
        timeField->setText(QApplication::translate("MainWindow", "2", 0));
        volumeField->setText(QApplication::translate("MainWindow", "0.25", 0));
        thicknessField->setText(QApplication::translate("MainWindow", "0.125", 0));
        thickness->setText(QApplication::translate("MainWindow", "Epoxy Thickness (wet)", 0));
        volume->setText(QApplication::translate("MainWindow", "Epoxy Volume (wet, per unit)", 0));
        time->setText(QApplication::translate("MainWindow", "Application Time (per unit)", 0));
        label_29->setText(QApplication::translate("MainWindow", "in", 0));
        label_30->setText(QApplication::translate("MainWindow", "in^3", 0));
        label_31->setText(QApplication::translate("MainWindow", "s", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Settings", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Preview", 0));
        StatusLine->setText(QApplication::translate("MainWindow", "Ready", 0));
        generateButton->setText(QApplication::translate("MainWindow", "Generate G Code", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
