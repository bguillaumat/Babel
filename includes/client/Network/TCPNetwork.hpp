/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_TCPNETWORK_HPP
#define CPP_BABEL_2018_TCPNETWORK_HPP

#include <QWidget>
#include <QtNetwork/QTcpSocket>

class TCPNetwork : public QWidget {
public:
	TCPNetwork();

private slots:
	void displayError(QAbstractSocket::SocketError socketError);
	void readData();

private:
	QTcpSocket  *_socket = nullptr;
	QDataStream _in;
	QString     _data;
};

#endif //CPP_BABEL_2018_TCPNETWORK_HPP
