#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QDebug>

class Station : public QObject
{
    Q_OBJECT
public:
    explicit Station(QObject *parent = nullptr, int channel = 0, QString name = "unknown");
    QString name;
    int channel;

signals:
    //signal que vai chamar o slot da classe radio (listen)
    void send(const int &channel, const QString &name, const QString &message);
public slots:
    //slot que vai emitir a send
    void broadcast(const QString &message);
};

#endif // STATION_H
