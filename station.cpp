#include "station.h"

Station::Station(QObject *parent, int channel, QString name)
    : QObject{parent}
{
    this->channel = channel;
    this-> name = name;
}

void Station::broadcast(const QString &message)
{
    //emitindo o signal
    emit send(channel, name, message);
}
