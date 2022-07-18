#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio boombox;
    //criando um array de pointers
    Station* channels[3];

    //criando canais
    //como estou enviando o boombox como parent (que está na stack), quando ele for
    //automaticamente destruído, o array na heap também será.
    channels[0] = new Station(&boombox, 94, "Rock and Roll");
    channels[1] = new Station(&boombox, 87, "Hip Hop");
    channels[2] = new Station(&boombox, 104, "News");

    //fechando a aplicação quando o quit for emitido
    boombox.connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

//    for(int i = 0; i < 3; i++){
//        Station* channel = channels[i];
//        boombox.connect(channel, &Station::send, &boombox, &Radio::listen);
//    }

    do
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin); //cin
        QString line = qtin.readLine().trimmed().toUpper(); //ler a linha, tirar o espaço e upper

        if(line == "ON"){
            qInfo() << "Turning the radio on";
            for(int i = 0; i < 3; i++){
                Station* channel = channels[i];
                //conecta os canais
                boombox.connect(channel, &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio is on";
        }

        if(line == "OFF"){
            qInfo() << "Turning the radio off";
            for(int i = 0; i < 3; i++){
                Station* channel = channels[i];
                //desconectando os objetos
                boombox.disconnect(channel, &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio is off";
        }

        if(line == "TEST"){
            qInfo() << "Testing";
            for(int i = 0; i < 3; i++){
                Station* channel = channels[i];
                channel->broadcast("Broadcasting live!");
            }
            qInfo() << "Test complete";
        }

        if(line == "QUIT"){
            qInfo() << "Quitting";
            emit boombox.quit(); //não é preciso estar no objeto para emitir o sinal
            break;
        }

    } while(true);
    return a.exec();
}
