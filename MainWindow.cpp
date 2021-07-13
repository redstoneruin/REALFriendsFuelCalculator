#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_raceTimeInput_valueChanged(int arg1)
{

}

void MainWindow::on_lapTimeInput_textChanged(const QString &arg1)
{

}


void MainWindow::on_maxFuelInput_valueChanged(double arg1)
{

}


void MainWindow::on_fuelUsageInput_valueChanged(double arg1)
{

}

/**
 * Called when timed race checkbox is checked
 * @param arg1 0 if unchecked, 2 if checked
 */
void MainWindow::on_timedRaceCheck_stateChanged(int arg1)
{
    // update calculator and labels on the display
    if(!arg1) {
        ui->raceTimeLabel->setText("Race Laps");
        ui->lapsResultLabel->setText("Race Time");
        c.isTimed = false;
    } else {
        ui->raceTimeLabel->setText("Race Time in Minutes");
        ui->lapsResultLabel->setText("Number of Laps");
        c.isTimed = true;
    }
}



/**
 * Update the outputs on the window
 */
void MainWindow::updateOutputs()
{

}
