#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QCustomPlot.h"
#include "point.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#define XREF 19.5              //X coordinate to place nozzle center over bottom left corner of tray
#define YREF 18                //Y coordinate to place nozzle center over bottom left corner of tray
#define DWELLTIME 1000         //milliseconds - dwell time for starting and stopping flow
#define IN3PERSEC 0.125        //cubic inches per second
#define POINTNOZZLESPREAD 0.15 //assuming a point source will spread to about 0.15" in diameter

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString saveFileName;
    QFile saveFile;
    QTextStream out;

    void replotDiagrams();
    void plotTray();
    void plotUnit();
    void plotSpacing();
    void plotPreview();
    void setupPlots();
    void plotRect(QCustomPlot* plot, QBrush brush, double Xbl, double Ybl, double W, double H);
    void plotDimH(QCustomPlot* plot, QPen pen, double Xleft, double Y, double W, double H, QString Text, int small);
    void plotDimV(QCustomPlot* plot, QPen pen, double X, double Ybot, double W, double H, QString Text, int small);
    QString verifyGeometry();
    vector<point> hitPoints(int row, int column);

    void startCode();
    void endCode();
    void writeGcode();
    void codeOneUnit(int row, int column);

    void selectAplicationField();
    void recalcApplicationFields();


private slots:
    void on_A_editingFinished();
    void on_B_editingFinished();
    void on_C_editingFinished();
    void on_D_editingFinished();
    void on_Rows_valueChanged(int arg1);
    void on_Cols_valueChanged(int arg1);
    void on_E_editingFinished();
    void on_F_editingFinished();
    void on_G_editingFinished();
    void on_H_editingFinished();
    void on_centeredCheckBox_clicked();
    void on_I_editingFinished();
    void on_J_editingFinished();
    void on_K_editingFinished();
    void on_L_editingFinished();

    void on_generateButton_clicked();

    void on_thickness_clicked();

    void on_volume_clicked();

    void on_time_clicked();

    void on_thicknessField_editingFinished();

    void on_volumeField_editingFinished();

    void on_timeField_editingFinished();

    void on_MD295_clicked();

    void on_MD61_clicked();

    void on_FD_clicked();

    void on_FD1_clicked();

    void on_KF_clicked();

    void on_KK_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
