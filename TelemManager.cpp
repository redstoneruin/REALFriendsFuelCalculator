#include "TelemManager.h"

#include <QThread>

TelemManager::TelemManager(QObject *parent) : QObject(parent),
    endTelemLoop(false),
    client(irsdkClient::instance())
{

}


/**
 * Starts main telemetry loop
 * @brief TelemManager::startTelemetry
 */
void TelemManager::startTelemetry()
{

    emit printMessage("Starting telemetry...");

    bool connected = false;


    // enter telemetry loop
    while(!endTelemLoop) {

        emit printMessage("Attempting to connect");

        while (!connected) {
            if(!client.isConnected()) {
                QThread::sleep(1);
            } else {
                connected = true;
            }
        }

        while(connected) {

            // TODO: switch to waitfordata and actual telem gathering
            QThread::sleep(1);
        }
    }

}


/**
 * Slot to stop the main telemetry loop
 * @brief TelemManager::stopTelemetry
 */
void TelemManager::stopTelemetry()
{
    endTelemLoop = true;
}
