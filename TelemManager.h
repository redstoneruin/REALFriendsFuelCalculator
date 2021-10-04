#ifndef TELEMMANAGER_H
#define TELEMMANAGER_H

#include <QObject>

#include "irsdk/irsdk_client.h"

class TelemManager : public QObject
{
    Q_OBJECT
public:
    explicit TelemManager(QObject *parent = nullptr);

public slots:
    void startTelemetry();
    void stopTelemetry();

signals:
    void printMessage(const QString& message);

private:
    bool endTelemLoop;

    irsdkClient& client;
};

#endif // TELEMMANAGER_H
