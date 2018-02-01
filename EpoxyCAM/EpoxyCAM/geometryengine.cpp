#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::replotDiagrams() {
    plotTray();
    plotUnit();
    plotSpacing();
    plotPreview();
}

void MainWindow::plotTray() {

    QCustomPlot *plot = ui->TrayPlot;
    plot->clearItems();

    double A = ui->A->text().toDouble();
    double B = ui->B->text().toDouble();
    double C = ui->C->text().toDouble();
    double D = ui->D->text().toDouble();
    int Rows = ui->Rows->value();
    int Cols = ui->Cols->value();
    int i = 0;
    int j = 0;

    double partWidth = 4 * (A-2*C) / (5 * Cols - 1);
    double partHSpacing = partWidth / 4;
    double partHeight = 4 * (B-2*D) / (5 * Rows - 1);
    double partVSpacing = partHeight / 4;

    QBrush gray(Qt::SolidPattern); gray.setColor(QColor(128,128,100));
    QBrush green(Qt::SolidPattern); green.setColor(QColor(0,128,0));
    QPen blackPen; blackPen.setColor(QColor(0, 0, 0));

    //tray
    plotRect(plot, gray, 0, 0, A, B);
    plotDimH(plot, blackPen, 0, B, A, B/8, "A", 0);
    plotDimV(plot, blackPen, A, 0, A/8, B, "B", 0);
    plotDimH(plot, blackPen, 0, 0, C, -B/8, "C", 1);
    plotDimV(plot, blackPen, 0, 0, -B/8, D, "D", 1);

    //parts
    for (i = 0; i < Rows; ++i) {
        for (j = 0; j < Cols; ++j) {
            plotRect(plot, green, C + j * (partWidth + partHSpacing), D + i * (partHeight + partVSpacing), partWidth, partHeight);
        }
    }

    plot->xAxis->setRange(-2*A/8, 10*A/8);
    plot->yAxis->setRange(-2*B/8, 10*B/8);
    plot->replot();

}

void MainWindow::plotUnit() {

    QCustomPlot *plot = ui->UnitPlot;
    plot->clearItems();

    double E = ui->E->text().toDouble();
    double F = ui->F->text().toDouble();
    double G = ui->G->text().toDouble();
    double H = ui->H->text().toDouble();
    double I = ui->I->text().toDouble();
    double J = ui->J->text().toDouble();
    if (ui->centeredCheckBox->isChecked()) {
        I = (E - G) / 2;
        J = (F - H) / 2;
    }

    QBrush black(Qt::SolidPattern); black.setColor(QColor(0,0,0));
    QBrush green(Qt::SolidPattern); green.setColor(QColor(0,128,0));
    QPen blackPen; blackPen.setColor(QColor(0, 0, 0));
    QPen whitePen; whitePen.setColor(QColor(255,255,255));

    //unit
    plotRect(plot, green, 0, 0, E, F);

    //epoxy
    plotRect(plot, black, I, J, G, H);

    plotDimH(plot, blackPen, 0, F, E, F/8, "E", 0);
    plotDimV(plot, blackPen, E, 0, E/8, F, "F", 0);
    plotDimH(plot, whitePen, I, J, G, H/8, "G", 0);
    plotDimV(plot, whitePen, I, J, G/8, H, "H", 0);

    if (!ui->centeredCheckBox->isChecked()) {
        plotDimH(plot, blackPen, 0, J, I, -J-F/8, "I", 1);
        plotDimV(plot, blackPen, I, 0, -I-F/8, J, "J", 1);

    }

    if (E > F) { F = E; }
    plot->xAxis->setRange(-F/4, 10*F/8);
    plot->yAxis->setRange(-F/4, 10*F/8);


    plot->replot();

}

void MainWindow::plotSpacing() {

    QCustomPlot *plot = ui->SpacingPlot;
    plot->clearItems();

    double K = ui->K->text().toDouble();
    double L = ui->L->text().toDouble();
    double visibleEdge = K*5 + 0.25;

    QBrush gray(Qt::SolidPattern); gray.setColor(QColor(128,128,100));
    QBrush green(Qt::SolidPattern); green.setColor(QColor(0,128,0));
    QPen blackPen; blackPen.setColor(QColor(0, 0, 0));

    //tray
    plotRect(plot, gray, 0, 0, 2*visibleEdge+K, 2*visibleEdge+L);

    //4 units
    plotRect(plot, green, 0, 0, visibleEdge, visibleEdge);
    plotRect(plot, green, visibleEdge+K, 0, visibleEdge, visibleEdge);
    plotRect(plot, green, visibleEdge+K, visibleEdge+L, visibleEdge, visibleEdge);
    plotRect(plot, green, 0, visibleEdge+L, visibleEdge, visibleEdge);

    plotDimH(plot, blackPen, visibleEdge, 1.5*visibleEdge+L, K, 0, "K", 1);
    plotDimV(plot, blackPen, 1.5*visibleEdge+K, visibleEdge, 0, L, "L", 1);

    plot->xAxis->setRange(0, 2*visibleEdge+K);
    plot->yAxis->setRange(0, 2*visibleEdge+L);
    plot->replot();

}

void MainWindow::plotPreview() {

    QCustomPlot *plot = ui->PreviewPlot;
    plot->clearItems();

    double A = ui->A->text().toDouble();
    double B = ui->B->text().toDouble();
    double C = ui->C->text().toDouble();
    double D = ui->D->text().toDouble();
    int Rows = ui->Rows->value();
    int Cols = ui->Cols->value();
    double E = ui->E->text().toDouble();
    double F = ui->F->text().toDouble();
    double G = ui->G->text().toDouble();
    double H = ui->H->text().toDouble();
    double I = ui->I->text().toDouble();
    double J = ui->J->text().toDouble();
    if (ui->centeredCheckBox->isChecked()) {
        I = (E - G) / 2;
        J = (F - H) / 2;
    }
    double K = ui->K->text().toDouble();
    double L = ui->L->text().toDouble();
    int i = 0;
    int j = 0;

    QBrush gray(Qt::SolidPattern); gray.setColor(QColor(128,128,100));
    QBrush green(Qt::SolidPattern); green.setColor(QColor(0,128,0));
    QBrush black(Qt::SolidPattern); black.setColor(QColor(0,0,0));

    //tray
    plotRect(plot, gray, 0, 0, A, B);

    //parts
    for (i = 0; i < Rows; ++i) {
        for (j = 0; j < Cols; ++j) {
            plotRect(plot, green, C + j * (E + K), D + i * (F + L), E, F);
            plotRect(plot, black, C + I + j * (E + K), D + J + i * (F + L), G, H);
        }
    }

    plot->xAxis->setRange(-A/8, 9*A/8);
    plot->yAxis->setRange(-B/8, 9*B/8);
    plot->replot();

}

void MainWindow::setupPlots() {

    ui->PreviewPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);     //drag and zoom abilities

    return;
}

void MainWindow::plotRect(QCustomPlot* plot, QBrush brush, double Xbl, double Ybl, double W, double H) {

    QCPItemRect *rect = new QCPItemRect(plot);
    plot->addItem(rect);
    rect->topLeft->setCoords(Xbl, Ybl+H);
    rect->bottomRight->setCoords(Xbl+W, Ybl);
    rect->setBrush(brush);

}

void MainWindow::plotDimH(QCustomPlot* plot, QPen pen, double Xleft, double Y, double W, double H, QString Text, int small) {

    QCPItemLine *left = new QCPItemLine(plot);
    plot->addItem(left);
    left->start->setCoords(Xleft, Y + H/10);
    left->end->setCoords(Xleft, Y + 11*H/10);
    left->setPen(pen);

    QCPItemLine *right = new QCPItemLine(plot);
    plot->addItem(right);
    right->start->setCoords(Xleft + W, Y + H/10);
    right->end->setCoords(Xleft + W, Y + 11*H/10);
    right->setPen(pen);

    if(small) {
        QCPItemLine *arrowR = new QCPItemLine(plot);
        plot->addItem(arrowR);
        arrowR->start->setCoords(Xleft - W, Y + H);
        arrowR->end->setCoords(Xleft, Y + H);
        arrowR->setHead(QCPLineEnding::esFlatArrow);
        arrowR->setPen(pen);

        QCPItemLine *arrowL = new QCPItemLine(plot);
        plot->addItem(arrowL);
        arrowL->start->setCoords(Xleft + W + W, Y + H);
        arrowL->end->setCoords(Xleft + W, Y + H);
        arrowL->setHead(QCPLineEnding::esFlatArrow);
        arrowL->setPen(pen);

        QCPItemText *text = new QCPItemText(plot);
        plot->addItem(text);
        text->position->setCoords(Xleft + W/2, Y + 14*H/10);
        text->setText(Text);
        text->setColor(pen.color());
    } else {
        QCPItemLine *arrow = new QCPItemLine(plot);
        plot->addItem(arrow);
        arrow->start->setCoords(Xleft, Y + H);
        arrow->end->setCoords(Xleft + W, Y + H);
        arrow->setHead(QCPLineEnding::esFlatArrow);
        arrow->setTail(QCPLineEnding::esFlatArrow);
        arrow->setPen(pen);

        QCPItemText *text = new QCPItemText(plot);
        plot->addItem(text);
        text->position->setCoords(Xleft + W/2, Y + 14*H/10);
        text->setText(Text);
        text->setColor(pen.color());
    }





}

void MainWindow::plotDimV(QCustomPlot* plot, QPen pen, double X, double Ybot, double W, double H, QString Text, int small) {

    QCPItemLine *bot = new QCPItemLine(plot);
    plot->addItem(bot);
    bot->start->setCoords(X + W/10, Ybot);
    bot->end->setCoords(X + 11*W/10, Ybot);
    bot->setPen(pen);

    QCPItemLine *top = new QCPItemLine(plot);
    plot->addItem(top);
    top->start->setCoords(X + W/10, Ybot + H);
    top->end->setCoords(X + 11*W/10, Ybot + H);
    top->setPen(pen);

    if (small) {
        QCPItemLine *arrowT = new QCPItemLine(plot);
        plot->addItem(arrowT);
        arrowT->start->setCoords(X + W, Ybot + H + H);
        arrowT->end->setCoords(X + W, Ybot + H);
        arrowT->setHead(QCPLineEnding::esFlatArrow);
        arrowT->setPen(pen);

        QCPItemLine *arrowB = new QCPItemLine(plot);
        plot->addItem(arrowB);
        arrowB->start->setCoords(X + W, Ybot - H);
        arrowB->end->setCoords(X + W, Ybot);
        arrowB->setHead(QCPLineEnding::esFlatArrow);
        arrowB->setPen(pen);

        QCPItemText *text = new QCPItemText(plot);
        plot->addItem(text);
        text->position->setCoords(X + 14*W/10, Ybot + H/2);
        text->setText(Text);
        text->setColor(pen.color());
    } else {
        QCPItemLine *arrow = new QCPItemLine(plot);
        plot->addItem(arrow);
        arrow->start->setCoords(X + W, Ybot);
        arrow->end->setCoords(X + W, Ybot + H);
        arrow->setHead(QCPLineEnding::esFlatArrow);
        arrow->setTail(QCPLineEnding::esFlatArrow);
        arrow->setPen(pen);

        QCPItemText *text = new QCPItemText(plot);
        plot->addItem(text);
        text->position->setCoords(X + 14*W/10, Ybot + H/2);
        text->setText(Text);
        text->setColor(pen.color());
    }



}

QString MainWindow::verifyGeometry() {

    double A = ui->A->text().toDouble();
    double B = ui->B->text().toDouble();
    double C = ui->C->text().toDouble();
    double D = ui->D->text().toDouble();
    int Rows = ui->Rows->value();
    int Cols = ui->Cols->value();
    double E = ui->E->text().toDouble();
    double F = ui->F->text().toDouble();
    double G = ui->G->text().toDouble();
    double H = ui->H->text().toDouble();
    double I = ui->I->text().toDouble();
    double J = ui->J->text().toDouble();
    if (ui->centeredCheckBox->isChecked()) {
        I = (E - G) / 2;
        J = (F - H) / 2;
    }
    double K = ui->K->text().toDouble();
    double L = ui->L->text().toDouble();
    double nozzleWidth = ui->nozzleWidth->text().toDouble();
    double X = 0;
    double Y = 0;

    //Every dimension must be positive
    if (A < 0) { return "All dimensions must be positive."; }
    if (B < 0) { return "All dimensions must be positive."; }
    if (C < 0) { return "All dimensions must be positive."; }
    if (D < 0) { return "All dimensions must be positive."; }
    if (E < 0) { return "All dimensions must be positive."; }
    if (F < 0) { return "All dimensions must be positive."; }
    if (G < 0) { return "All dimensions must be positive."; }
    if (H < 0) { return "All dimensions must be positive."; }
    if (K < 0) { return "All dimensions must be positive."; }
    if (L < 0) { return "All dimensions must be positive."; }

    //epoxy is contained on each board
    if (I < 0) { return "Epoxy must be contained on each unit."; }
    if (J < 0) { return "Epoxy must be contained on each unit."; }
    if (I+G > E) { return "Epoxy must be contained on each unit."; }
    if (J+H > F) { return "Epoxy must be contained on each unit."; }

    //all parts fit on tray
    for (int i = 0; i < Cols; ++i) {
        for (int j = 0; j < Rows; ++j) {
            //top right corners
            X = C + i*(E+K) + E;
            Y = D + j*(F+L) + F;
            if (X > A) { return "Not all units fit on tray."; }
            if (Y > B) { return "Not all units fit on tray."; }
        }
    }

    //nozzle bigger than epoxy width
    if (nozzleWidth > G) { return "Nozzle is wider than application width."; }

    return "Geometry Verified";

}

vector<point> MainWindow::hitPoints(int row, int column) {

    double C = ui->C->text().toDouble();
    double D = ui->D->text().toDouble();
    double E = ui->E->text().toDouble();
    double F = ui->F->text().toDouble();
    double G = ui->G->text().toDouble();
    double H = ui->H->text().toDouble();
    double I = ui->I->text().toDouble();
    double J = ui->J->text().toDouble();
    if (ui->centeredCheckBox->isChecked()) {
        I = (E - G) / 2;
        J = (F - H) / 2;
    }
    double K = ui->K->text().toDouble();
    double L = ui->L->text().toDouble();
    double nozzleX = POINTNOZZLESPREAD;
    double nozzleY = POINTNOZZLESPREAD;
    if (ui->RectangularNozzle->isChecked()) {
        nozzleX = ui->nozzleWidth->text().toDouble();
    }


    int passesPerUnit = round(G / nozzleX);
    double startComp = 0;          //if above function rounds down, the epoxy width will be slightly smaller than desired. That's okay, as long as it's centered in the same area.
    double passPitch = 1.0;        //center-to-center distance between passes

    //special case - only 1 pass
    if (passesPerUnit <= 1) {
        passPitch = nozzleX;
        startComp = (G - nozzleX) / 2;
    }
    //special case - not enough passes
    else if (nozzleX * passesPerUnit < G) {
        passPitch = nozzleX;
        startComp = (G - nozzleX*passesPerUnit) / 2;
    }
    //normal case
    else {
        passPitch = (G - nozzleX) / (passesPerUnit - 1);
        startComp = 0;
    }

    vector<point> toolpath(0);
    point hitPoint;
    double startX = C + column*(E+K) + I + nozzleX/2 + startComp;
    double startY = D + row*(F+L) + J + nozzleY/2;

    for (int i = 0; i < passesPerUnit; ++i) {
        if (i % 2 == 0) {
            hitPoint.set(startX + i*passPitch, startY);
            toolpath.push_back(hitPoint);
            hitPoint.set(startX + i*passPitch, startY + H - nozzleY);
            toolpath.push_back(hitPoint);
        } else {
            hitPoint.set(startX + i*passPitch, startY + H - nozzleY);
            toolpath.push_back(hitPoint);
            hitPoint.set(startX + i*passPitch, startY);
            toolpath.push_back(hitPoint);
        }
    }

    return toolpath;

}
