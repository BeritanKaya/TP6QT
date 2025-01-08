#include "client.h"
#include <QHostAddress>

Client::Client(QObject *parent) : QObject(parent)
{
    qDebug() << "Instanciation d'un objet QTcpSocket";
    tcpSocket = new QTcpSocket(this);

    // Connexion des signaux aux slots
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::estConnectee);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::estDeconnectee);
    connect(tcpSocket, &QTcpSocket::errorOccurred, this, &Client::gestionErreur);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::recevoir);
}

Client::~Client()
{
    qDebug() << "Fermeture de la socket";
    tcpSocket->close();
}

void Client::demarrer()
{
    qDebug() << "Connexion au serveur en cours...";
    tcpSocket->connectToHost(QHostAddress::LocalHost, PORT_SERVEUR);
}

void Client::estConnectee()
{
    qDebug() << "Connecté au serveur !";
    envoyer("Bonjour serveur !");
}

void Client::estDeconnectee()
{
    qDebug() << "Déconnecté du serveur.";
}

void Client::gestionErreur(QAbstractSocket::SocketError erreur)
{
    qDebug() << "Erreur détectée :" << tcpSocket->errorString();
}

void Client::recevoir()
{
    QByteArray data = tcpSocket->readAll();
    qDebug() << "Données reçues :" << data;
}

void Client::envoyer(QByteArray message)
{
    qDebug() << "Envoi du message :" << message;
    if (tcpSocket->write(message) == -1)
        qDebug() << "Erreur lors de l'envoi.";
}
