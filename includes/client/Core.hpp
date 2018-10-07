/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_CORE_HPP
#define CPP_BABEL_2018_CORE_HPP

#include <QtWidgets/QStackedWidget>
#include "includes/client/Network/TCPNetwork.hpp"
#include "includes/client/UI/Login.hpp"
#include "includes/client/UI/Home.hpp"
#include "includes/client/UI/Call.hpp"
#include "includes/client/Settings.hpp"

class Core : public QWidget {
Q_OBJECT
public:
	Core(Settings const &settings);

public slots:
	void checkForCall(int);

private:
	QStackedWidget *_stackedWidget;
	QWidget        *_loginScreen;
	QWidget        *_homeScreen;
	QWidget        *_callScreen;
	TCPNetwork     *_tcpNetwork;
};

#endif //CPP_BABEL_2018_CORE_HPP
