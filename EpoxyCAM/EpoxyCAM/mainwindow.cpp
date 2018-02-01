#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initialization Code
    setupPlots();
    on_centeredCheckBox_clicked();
    replotDiagrams();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_A_editingFinished() { replotDiagrams(); }
void MainWindow::on_B_editingFinished() { replotDiagrams(); }
void MainWindow::on_C_editingFinished() { replotDiagrams(); }
void MainWindow::on_D_editingFinished() { replotDiagrams(); }
void MainWindow::on_Rows_valueChanged(int arg1) { arg1 = arg1; replotDiagrams(); }
void MainWindow::on_Cols_valueChanged(int arg1) { arg1 = arg1; replotDiagrams(); }
void MainWindow::on_E_editingFinished() { replotDiagrams(); }
void MainWindow::on_F_editingFinished() { replotDiagrams(); }
void MainWindow::on_G_editingFinished() { replotDiagrams(); recalcApplicationFields();}
void MainWindow::on_H_editingFinished() { replotDiagrams(); recalcApplicationFields();}
void MainWindow::on_I_editingFinished() { replotDiagrams(); }
void MainWindow::on_J_editingFinished() { replotDiagrams(); }
void MainWindow::on_K_editingFinished() { replotDiagrams(); }
void MainWindow::on_L_editingFinished() { replotDiagrams(); }
void MainWindow::on_centeredCheckBox_clicked() {
    if (ui->centeredCheckBox->isChecked()) {
        ui->I->setVisible(0);
        ui->Ilabel->setVisible(0);
        ui->Iunit->setVisible(0);
        ui->J->setVisible(0);
        ui->Jlabel->setVisible(0);
        ui->Junit->setVisible(0);
        ui->orientationNote->setVisible(0);
    } else {
        ui->I->setVisible(1);
        ui->Ilabel->setVisible(1);
        ui->Iunit->setVisible(1);
        ui->J->setVisible(1);
        ui->Jlabel->setVisible(1);
        ui->Junit->setVisible(1);
        ui->orientationNote->setVisible(1);
    }
    replotDiagrams();
}


void MainWindow::selectAplicationField() {
    if (ui->thickness->isChecked()) {
        ui->thicknessField->setEnabled(1);
        ui->volumeField->setEnabled(0);
        ui->timeField->setEnabled(0);
    } else if (ui->volume->isChecked()) {
        ui->thicknessField->setEnabled(0);
        ui->volumeField->setEnabled(1);
        ui->timeField->setEnabled(0);
    } else if (ui->time->isChecked()) {
        ui->thicknessField->setEnabled(0);
        ui->volumeField->setEnabled(0);
        ui->timeField->setEnabled(1);
    }
    return;
}

void MainWindow::recalcApplicationFields() {

    double G = ui->G->text().toDouble();
    double H = ui->H->text().toDouble();
    double t = ui->thicknessField->text().toDouble();
    double V = ui->volumeField->text().toDouble();
    double time = ui->timeField->text().toDouble();

    if (ui->thickness->isChecked()) {
        ui->volumeField->setText(QString::number(t*G*H));
        ui->timeField->setText(QString::number(t*G*H / IN3PERSEC));
    } else if (ui->volume->isChecked()) {
        ui->thicknessField->setText(QString::number(V/(G*H)));
        ui->timeField->setText(QString::number(V / IN3PERSEC));
    } else if (ui->time->isChecked()) {
        ui->thicknessField->setText(QString::number(time * IN3PERSEC /(G*H)));
        ui->volumeField->setText(QString::number(time * IN3PERSEC));
    }



}



void MainWindow::on_generateButton_clicked()
{
    ui->StatusLine->setText("Verifying Geometry...");
    QString result = verifyGeometry();
    ui->StatusLine->setText(result);

    if (result != "Geometry Verified") {

        //warning dialog
        QMessageBox::warning(this, "Geometry Error", result);
        return;

    } else {

        //save file location window
        saveFileName = QFileDialog::getSaveFileName(this, tr("SaveAs"), saveFileName, tr("G-Code files (.gcode)"));
        if(saveFileName.endsWith(".gcode")) {
            saveFile.setFileName(saveFileName);
        } else {
            saveFile.setFileName(saveFileName.append(".gcode"));
        }

        if(!saveFile.open(QFile::WriteOnly)) {
            ui->StatusLine->setText("Could not open file");
            return;
        }

        out.setDevice(&saveFile);

        ui->StatusLine->setText("Exporting G-Code to file location");
        writeGcode();
        ui->StatusLine->setText("G-Code Exported");

        saveFile.close();
    }

    return;
}

void MainWindow::on_thickness_clicked() { selectAplicationField(); }
void MainWindow::on_volume_clicked() { selectAplicationField(); }
void MainWindow::on_time_clicked() { selectAplicationField(); }

void MainWindow::on_thicknessField_editingFinished() { recalcApplicationFields(); }
void MainWindow::on_volumeField_editingFinished() { recalcApplicationFields(); }
void MainWindow::on_timeField_editingFinished() { recalcApplicationFields(); }

void MainWindow::on_MD295_clicked()
{
    ui->A->setText("11.875");
    ui->B->setText("7.75");
    ui->C->setText("0.0825");
    ui->D->setText("0.0825");
    replotDiagrams();
}

void MainWindow::on_MD61_clicked()
{
    ui->A->setText("17.86");
    ui->B->setText("12.5");
    ui->C->setText("0.25");
    ui->D->setText("0.25");
    replotDiagrams();
}

void MainWindow::on_FD_clicked()
{
    ui->E->setText("1.63");
    ui->F->setText("2.49");
    ui->G->setText("1");
    ui->H->setText("0.6");
    ui->centeredCheckBox->setChecked(0);
    on_centeredCheckBox_clicked();
    ui->I->setText("0.315");
    ui->J->setText("0.545");
    replotDiagrams();
    recalcApplicationFields();
}

void MainWindow::on_FD1_clicked()
{
    ui->E->setText("1.63");
    ui->F->setText("2.49");
    ui->G->setText("1");
    ui->H->setText("2.3");
    ui->centeredCheckBox->setChecked(1);
    on_centeredCheckBox_clicked();
    replotDiagrams();
    recalcApplicationFields();
}

void MainWindow::on_KF_clicked()
{
    ui->E->setText("2");
    ui->F->setText("3.6");
    ui->G->setText("1.1");
    ui->H->setText("3.3");
    ui->centeredCheckBox->setChecked(1);
    on_centeredCheckBox_clicked();
    replotDiagrams();
    recalcApplicationFields();
}

void MainWindow::on_KK_clicked()
{
    ui->E->setText("3");
    ui->F->setText("3.15");
    ui->G->setText("1");
    ui->H->setText("1.2");
    ui->centeredCheckBox->setChecked(0);
    on_centeredCheckBox_clicked();
    ui->I->setText("1");
    ui->J->setText("1.1");
    replotDiagrams();
    recalcApplicationFields();
}
