#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>

class Radio : public QObject
{
    Q_OBJECT
public:
    explicit Radio(QObject *parent = nullptr);

signals:
    //signal que vai fechar a aplicação
    void quit();

public slots:
    //slot que vai receber o signal da classe station (send)
    void listen(const int &channel, const QString &name, const QString &message);

};

#endif // RADIO_H
