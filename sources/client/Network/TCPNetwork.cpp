/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <includes/client/Network/TCPNetwork.hpp>
#include <QtWidgets/QMessageBox>
#include <iostream>

TCPNetwork::TCPNetwork(const QString &ip, int port, int timeToWait) : _ip(ip),
	_port(port), _timeToWait(timeToWait), _socket(new QTcpSocket(this))
{
	connect(_socket, QOverload<QAbstractSocket::SocketError>::of(
		&QAbstractSocket::error), this, &TCPNetwork::displayError);
	connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
	connect(_socket, SIGNAL(connected()), this, SLOT(connected()));
	connect(_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	_socket->connectToHost(_ip, _port);
	if (!_socket->waitForConnected(_timeToWait)) {
		throw std::runtime_error("The server doesn't respond !");
	}
}

void TCPNetwork::displayError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(nullptr, tr("Skipe"),
					 tr("The host was not found. Please check the "
					    "host name and port settings."));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(nullptr, tr("Skipe"),
					 tr("The connection was refused by the server. "
					    "Make sure the skipe server is running, "
					    "and check that the host name and port "
					    "settings are correct."));
		break;
	default:
		QMessageBox::information(nullptr, tr("Skipe"),
					 tr("The following error occurred: %1.").arg(
						 _socket->errorString()));
	}
}

void TCPNetwork::readData()
{
	qDebug() << "reading...";
	qDebug() << _socket->readAll();
}

void TCPNetwork::connected()
{
	qDebug() << "connected...";
}

void TCPNetwork::disconnected()
{
	qDebug() << "disconnected...";
}

void TCPNetwork::writeData(const std::string &msg)
{
	_socket->write(std::to_string(msg.size()).append("\n").data());
	_socket->write(msg.data());
}
