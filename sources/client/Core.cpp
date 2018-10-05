/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include "Core.hpp"
#include "includes/client/UI/Login.hpp"
#include "includes/client/UI/Home.hpp"
#include "includes/client/UI/Call.hpp"

Core::Core() : QWidget()
{
	_stackedWidget = new QStackedWidget();
	_loginScreen   = new Babel::UI::Login(_stackedWidget);
	_homeScreen    = new Babel::UI::Home(_stackedWidget);
	_callScreen    = new Babel::UI::Call(_stackedWidget);
	_stackedWidget->addWidget(_loginScreen);
	_stackedWidget->addWidget(_homeScreen);
	_stackedWidget->addWidget(_callScreen);
	_stackedWidget->show();
	QObject::connect(_stackedWidget, SIGNAL(currentChanged(int)), this,
			 SLOT(checkForCall(int)));
}

void Core::checkForCall(int index)
{
	if (index == _stackedWidget->indexOf(_callScreen)) {
		reinterpret_cast<Babel::UI::Call *>(_callScreen)->makeCall("");
	}
}
