/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#ifndef CPP_BABEL_2018_UDPNETWORK_HPP
#define CPP_BABEL_2018_UDPNETWORK_HPP

#include <QtNetwork/QUdpSocket>

namespace Babel {

	namespace Network {
		class UDPNetwork : public QUdpSocket {
		Q_OBJECT

		public:
			UDPNetwork();

		public slots:
			void sendDatagram();

		private slots:
			void readDatagram();

		private:
			QUdpSocket *_socket;
		};
	}
}

#endif //CPP_BABEL_2018_UDPNETWORK_HPP
