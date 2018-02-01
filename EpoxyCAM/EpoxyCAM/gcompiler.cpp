#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::startCode() {

    //calculate speed
    double t = ui->thicknessField->text().toDouble();
    double nozzleX = POINTNOZZLESPREAD;
    if (ui->RectangularNozzle->isChecked()) {
        nozzleX = ui->nozzleWidth->text().toDouble();
    }
    double feedrate = 60 * IN3PERSEC / (t * nozzleX);

    out << "N01 G00 G17 G20 G40 G80 G90" << endl;
    out << "G54 X" << XREF << " Y" << YREF << endl;
    out << "M05" << endl;
    out << "G94 F" << feedrate << endl;
    out << "G28" << endl;
    out << "G04 P1000" << endl;
    out << "G30 P1" << endl;
    out << "G04 P1000" << endl << endl;

    return;
}

void MainWindow::endCode() {

    out << "M05" << endl;
    out << "G28" << endl;
    out << "M30" << endl << endl;

}

void MainWindow::writeGcode() {

    startCode();

    int Rows = ui->Rows->value();
    int Cols = ui->Cols->value();

    for (int i = 0; i < Cols; ++i) {
        for (int j = 0; j < Rows; ++j) {
            codeOneUnit(j, i);
        }
    }

    endCode();

    return;

}

void MainWindow::codeOneUnit(int row, int column) {

    vector<point> p;
    p = hitPoints(row, column);

    //rapid to start location and optional stop
    out << "G00 X" << -p.at(0).getX() << " Y" << -p.at(0).getY() << endl;
    out << "M01" << endl << endl;

    //turn on epoxy, dwell, and start motion
    out << "M03" << endl;
    out << "G04 P" << DWELLTIME << endl;
    for (unsigned int i = 1; i < p.size(); ++i) {
        out << "G01 X" << -p.at(i).getX() << " Y" << -p.at(i).getY() << endl;
    }

    //shut off epoxy and dwell
    out << "M05" << endl;
    out << "G04 P" << DWELLTIME << endl << endl;

}

