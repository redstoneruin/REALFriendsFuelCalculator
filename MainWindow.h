#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "Calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread telemThread;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleTelemMessage(const QString& str);

    void on_raceTimeInput_valueChanged(int arg1);

    void on_timedRaceCheck_stateChanged(int arg1);

    void on_lapTimeInput_textChanged(const QString &arg1);

    void on_maxFuelInput_valueChanged(double arg1);

    void on_fuelUsageInput_valueChanged(double arg1);

    void on_extraLapSlider_valueChanged(int value);

    void on_paceLapCheck_stateChanged(int arg1);

signals:
    void startTelemThread();
    void stopTelemThread();

private:
    Ui::MainWindow *ui;

    Calculator c;

    void updateOutputs();
};
#endif // MAINWINDOW_H
