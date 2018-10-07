/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <QNetworkInterface>
#include <QNetworkDatagram>
#include <QtCore/QDataStream>
#include "includes/common/PrintVector.hpp"
#include "includes/client/Network/NetworkConfig.hpp"
#include "includes/client/DecodedSound.hpp"
#include "includes/client/Network/UDPNetwork.hpp"

Babel::Network::UDPNetwork::UDPNetwork(Babel::IAudio *out) : _output(out)
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
	error   = _socket->bind(Babel::Network::port, QUdpSocket::ShareAddress);
	if (!error) {
		throw std::runtime_error("Cannot bind");
	}
	QObject::connect(_socket, SIGNAL(readyRead()), this,
			 SLOT(readDatagram()));
}

void Babel::Network::UDPNetwork::readDatagram()
{
	while (_socket->hasPendingDatagrams()) {
		DecodedSound sound = {};
		QByteArray   buffer;
		QHostAddress sender;
		quint16      senderPort;

		buffer.resize((int)_socket->pendingDatagramSize());
		_socket->readDatagram(buffer.data(), buffer.size(), &sender,
				      &senderPort);
//		std::cout << "Message receive from: " << sender.toString().toStdString() << std::endl;
//		std::cout << buffer.data() << std::endl;
		QVector<float> data;
		QDataStream    stream(buffer);
		stream >> data;
		sound.buffer = std::vector<float>(data.toStdVector());
		sound.size   = (int)sound.buffer.size();
		_output->setSound(sound);
	}
}

void Babel::Network::UDPNetwork::sendDatagram(const DecodedSound &sound)
{
	QByteArray     buffer;
	QVector<float> tmp = QVector<float>::fromStdVector(sound.buffer);
	QDataStream    stream(&buffer, QIODevice::WriteOnly);
	stream << tmp;
//	std::cout << "First: " << sound.buffer << std::endl;
//	QNetworkDatagram	datagram(buffer, QHostAddress::LocalHost, (qint16)Babel::Network::port);
//	datagram.setDestination(_host, Babel::Network::port);
	_socket->writeDatagram(buffer, buffer.size(), _host, Babel::Network::port);
}

void Babel::Network::UDPNetwork::setHost(const std::string &host)
{
	QString addr = QString::fromStdString(host);
	_host.setAddress(addr);
}
