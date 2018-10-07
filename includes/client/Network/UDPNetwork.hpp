/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#ifndef CPP_BABEL_2018_UDPNETWORK_HPP
#define CPP_BABEL_2018_UDPNETWORK_HPP

#include <QtNetwork/QUdpSocket>
#include "includes/client/PaOutput.hpp"
#include "includes/client/DecodedSound.hpp"

namespace Babel {

	namespace Network {
		class UDPNetwork : public QUdpSocket {
		Q_OBJECT

		public:
			explicit UDPNetwork(Babel::IAudio *out);
			void setHost(const std::string &host);

		public slots:
			void sendDatagram(const DecodedSound &sound);

		private slots:
			void readDatagram();

		private:
			Babel::IAudio *_output;
			QUdpSocket    *_socket;
			QHostAddress  _host;
		};
	}
}

#endif //CPP_BABEL_2018_UDPNETWORK_HPP
