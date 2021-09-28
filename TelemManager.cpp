#include "TelemManager.h"

TelemManager::TelemManager(QObject *parent) : QObject(parent),
    endTelemLoop(false),
    client(irsdkClient::instance())
{

}


/**
 * Starts main telemetry loop
 * @brief TelemManager::startTelemetry
 */
void TelemManager::startTelemetry() {

    emit printMessage("Starting telemetry...");

    // enter telemetry loop
    while(!endTelemLoop) {
        if(!client.isConnected()) {
            emit printMessage("Not connected");
            break;
        }
    }

}
