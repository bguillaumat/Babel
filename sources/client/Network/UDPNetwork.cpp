/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <QNetworkInterface>
#include "includes/client/Network/NetworkConfig.hpp"
#include "includes/client/Network/UDPNetwork.hpp"

Babel::Network::UDPNetwork::UDPNetwork()
{
	bool error;

		foreach (const QHostAddress &address,
			 QNetworkInterface::allAddresses()) {
			if (address.protocol() ==
				QAbstractSocket::IPv4Protocol && address !=
				QHostAddress(QHostAddress::LocalHost))
				std::cout << address.toString().toStdString()
					<< std::endl;
		}
	_socket = new QUdpSocket(this);
	error   = _socket->bind(QHostAddress::LocalHost, Babel::Network::port);
	if (!error) {
		throw std::runtime_error("Cannot bind");
	}
	QObject::connect(_socket, SIGNAL(readyRead()), this,
			 SLOT(readDatagram()));
	sendDatagram();
}

void Babel::Network::UDPNetwork::readDatagram()
{
	while (_socket->hasPendingDatagrams()) {
		QByteArray   buffer;
		QHostAddress sender;
		quint16      senderPort;

		buffer.resize(_socket->pendingDatagramSize());
		_socket->readDatagram(buffer.data(), buffer.size(), &sender,
				      &senderPort);
		std::cout << "Message receive from: "
			<< sender.toString().toStdString() << std::endl;
		std::cout << buffer.toStdString() << std::endl;
	}
}

void Babel::Network::UDPNetwork::sendDatagram()
{

	QString    word("Hello world !");
	QByteArray buffer;
	buffer = word.toUtf8();
	QHostAddress sender;
	_socket->writeDatagram(buffer.data(), QHostAddress::LocalHost,
			       Babel::Network::port);
}
