#ifndef TELEMMANAGER_H
#define TELEMMANAGER_H

#include <QObject>

class TelemManager : public QObject
{
    Q_OBJECT
public:
    explicit TelemManager(QObject *parent = nullptr);

public slots:
    void startTelemetry();

signals:
    void printMessage(const QString& message);

};

#endif // TELEMMANAGER_H
