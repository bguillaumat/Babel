/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_CALL_HPP
#define CPP_BABEL_2018_CALL_HPP

#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedWidget>
#include <includes/client/Network/UDPNetwork.hpp>
#include <includes/client/DecodedSound.hpp>
#include <includes/client/IAudio.hpp>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QTimer>
#include <QtCore/QElapsedTimer>
#include <QtWidgets/QLabel>

namespace Babel {
	namespace UI {
		class Call : public QWidget {
		Q_OBJECT
		public:
			explicit Call(QStackedWidget *stack);
			void makeCall(const std::string &ip, const std::string &name);

		private slots:
			void updateTimer();
			void hangoutCall();

		private:
			QPushButton                *_hangout;
			QHBoxLayout                *_buttonLayout;
			QVBoxLayout                *_layout;
			QStackedWidget             *_stack;
			QTimer                     *_time;
			QLabel                     *_name;
			QLabel                     *_timeElapsed;
			QElapsedTimer              *_timer;
			Babel::Network::UDPNetwork *_udp;
			Babel::IAudio              *_output;
			Babel::IAudio              *_input;
		};
	}
}
#endif //CPP_BABEL_2018_CALL_HPP
