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

class TCPNetwork : public QObject {
Q_OBJECT
public:
	TCPNetwork(const QString &ip, int port, int timeToWait = 5000);
	void writeData(const std::string &msg);

private slots:
	void displayError(QAbstractSocket::SocketError socketError);
	void readData();
	void connected();
	void disconnected();

private:
	const QString &_ip;
	int           _port;
	int           _timeToWait;
	QTcpSocket    *_socket = nullptr;
	QString       _data;
};

#endif //CPP_BABEL_2018_TCPNETWORK_HPP
