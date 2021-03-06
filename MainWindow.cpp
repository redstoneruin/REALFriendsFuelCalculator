#include <QRegularExpression>

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "TelemManager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up telemetry manager thread
    TelemManager *tm = new TelemManager;
    tm->moveToThread(&telemThread);
    connect(&telemThread, &QThread::finished, tm, &QObject::deleteLater);
    connect(this, &MainWindow::startTelemThread, tm, &TelemManager::startTelemetry);
    connect(this, &MainWindow::stopTelemThread, tm, &TelemManager::stopTelemetry);
    connect(tm, &TelemManager::printMessage, this, &MainWindow::handleTelemMessage);
    telemThread.start();

    // start the thread
    emit startTelemThread();
}

MainWindow::~MainWindow()
{
    emit stopTelemThread();

    telemThread.quit();
    telemThread.terminate();

    delete ui;
}


void MainWindow::handleTelemMessage(const QString& str)
{
    ui->telemTextArea->append(str);
    ui->telemTextArea->append("\n");
}


void MainWindow::on_raceTimeInput_valueChanged(int arg1)
{
    c.raceTime = c.raceLaps = arg1;

    updateOutputs();
}

void MainWindow::on_lapTimeInput_textChanged(const QString &arg1)
{
    // parse number of seconds from string format
    QRegularExpression re("^(?<min>(\\d\\d|\\d)):(?<sec>\\d\\d.(\\d|\\d\\d|\\d\\d\\d))$");

    QRegularExpressionMatch match = re.match(arg1);

    if(match.hasMatch()) {
        c.lapTime = match.captured("sec").toFloat() + match.captured("min").toInt() * 60;
        ui->lapFormatLabel->setText("");
    } else {
        ui->lapFormatLabel->setText("Invalid Lap Time Format");
    }

    updateOutputs();
}


void MainWindow::on_maxFuelInput_valueChanged(double arg1)
{
    c.maxFuel = arg1;

    updateOutputs();
}


void MainWindow::on_fuelUsageInput_valueChanged(double arg1)
{
    c.usage = arg1;

    updateOutputs();
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

    updateOutputs();
}

/**
 * @brief MainWindow::on_paceLapCheck_stateChanged
 * @param arg1
 */
void MainWindow::on_paceLapCheck_stateChanged(int arg1)
{
    c.paceLapModifier = arg1;

    if(!arg1) {
        ui->paceLapCheck->setText("No pace lap");
    } else if(arg1 == 1) {
        ui->paceLapCheck->setText("Reduced pace lap");
    } else {
        ui->paceLapCheck->setText("Full pace lap");
    }

    updateOutputs();
}



/**
 * @brief MainWindow::on_extraLapSlider_valueChanged
 * @param value
 */
void MainWindow::on_extraLapSlider_valueChanged(int value)
{
    // set extra laps
    c.extraLaps = value;
    // change displayed value
    ui->extraLapLabel->setText("+" + QString::number(value) + " Laps");

    updateOutputs();
}


/**
 * Update the outputs on the window
 */
void MainWindow::updateOutputs()
{
    // check for valid values first
    if(!c.raceTime || !c.raceLaps
        || c.maxFuel == 0 || c.usage == 0 || c.lapTime == 0) return;

    if(c.isTimed) {
        ui->lapsResultOutput->setText(QString::number(c.getNumLaps()));
    } else {
        ui->lapsResultOutput->setText(QString::number(c.getRaceTime()));
    }

    ui->lapsPerTankOutput->setText(QString::number(c.getLapsPerTank()));
    ui->totalFuelOutput->setText(QString::number(c.getTotalFuel()));
    ui->numStopsOutput->setText(QString::number(c.getNumStops()));
    ui->fuelOnStopOutput->setText(QString::number(c.getFuelOnStop()));
}
