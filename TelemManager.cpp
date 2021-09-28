#include "TelemManager.h"

TelemManager::TelemManager(QObject *parent) : QObject(parent)
{

}


/**
 * Starts main telemetry loop
 * @brief TelemManager::startTelemetry
 */
void TelemManager::startTelemetry() {

    emit printMessage("Starting telemetry...");
}
