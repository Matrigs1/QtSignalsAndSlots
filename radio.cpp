#include "radio.h"

Radio::Radio(QObject *parent)
    : QObject{parent}
{

}

//implementação do slot, dando cout
void Radio::listen(const int &channel, const QString &name, const QString &message)
{
    qInfo() << channel << " " << name << " - " << message;
}
