/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <includes/client/Network/TCPNetwork.hpp>
#include <QtWidgets/QMessageBox>
#include <iostream>

TCPNetwork::TCPNetwork() : _socket(new QTcpSocket(this))
{
	_in.setDevice(_socket);
	_in.setVersion(QDataStream::Qt_5_11);
	connect(_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &TCPNetwork::displayError);
	connect(_socket, &QIODevice::readyRead, this, &TCPNetwork::readData);
	_socket->connectToHost("127.0.0.1", 8080);
}

void TCPNetwork::displayError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, tr("Fortune Client"),
					 tr("The host was not found. Please check the "
					    "host name and port settings."));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Fortune Client"),
					 tr("The connection was refused by the peer. "
					    "Make sure the fortune server is running, "
					    "and check that the host name and port "
					    "settings are correct."));
		break;
	default:
		QMessageBox::information(this, tr("Fortune Client"),
					 tr("The following error occurred: %1.")
						 .arg(_socket->errorString()));
	}

}

void TCPNetwork::readData()
{
	QString nextData;

	_in.startTransaction();
	_in >> nextData;
	if (!_in.commitTransaction())
		return;
	std::cout << "Message: " << nextData.toStdString() << std::endl;
}
