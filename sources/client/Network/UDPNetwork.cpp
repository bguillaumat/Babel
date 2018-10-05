/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <QNetworkInterface>
#include <includes/client/DecodedSound.hpp>
#include <QtCore/QDataStream>
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
	error   = _socket->bind(QHostAddress::LocalHost, Babel::Network::port);
	if (!error) {
		throw std::runtime_error("Cannot bind");
	}
	QObject::connect(_socket, SIGNAL(readyRead()), this,
			 SLOT(readDatagram()));
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T, std::allocator<T>> &v)
{
	if (!v.empty()) {
		out << '[';
		std::copy(v.begin(), v.end(),
			  std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}

void Babel::Network::UDPNetwork::readDatagram()
{
	while (_socket->hasPendingDatagrams()) {
		DecodedSound sound = {};
		QByteArray   buffer;
		QHostAddress sender;
		quint16      senderPort;

		buffer.resize(_socket->pendingDatagramSize());
		_socket->readDatagram(buffer.data(), buffer.size(), &sender,
				      &senderPort);
		std::cout << "Message receive from: "
			<< sender.toString().toStdString() << std::endl;
		std::cout << buffer.data() << std::endl;
		QVector<float> data;
		QDataStream    stream(buffer);
		stream >> data;
		std::vector<float> newvec(data.toStdVector());
		sound.buffer = newvec;
		sound.size   = sound.buffer.size();
		_output->setSound(sound);
	}
}

void Babel::Network::UDPNetwork::sendDatagram(const DecodedSound &sound)
{
	QByteArray     buffer;
	QVector<float> tmp = QVector<float>::fromStdVector(sound.buffer);
	QDataStream    stream(&buffer, QIODevice::WriteOnly);
	stream << tmp;
	QVector<float> data;
	QDataStream    nstream(buffer);
	nstream >> data;
	std::vector<float> newvec(data.toStdVector());
	std::cout << "First: " << sound.buffer << std::endl;
	std::cout << (newvec == sound.buffer) << std::endl;

	_socket->writeDatagram(buffer, QHostAddress::LocalHost,
			       Babel::Network::port);
}
