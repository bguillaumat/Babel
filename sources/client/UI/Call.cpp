/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <QtCore/QCoreApplication>
#include <includes/client/PaOutput.hpp>
#include <includes/client/PaInput.hpp>
#include "includes/client/UI/Call.hpp"

Babel::UI::Call::Call(QStackedWidget *stack) : _stack(stack)
{
	_hangout = new QPushButton("Hangout");
	_hangout->setIcon(QIcon(QCoreApplication::applicationDirPath() +
					"/media/call_end.png"));
	_hangout->setIconSize(QSize(30, 30));
	_buttonLayout = new QHBoxLayout();
	_layout       = new QVBoxLayout();
	_buttonLayout->addWidget(_hangout);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
	_output = new Babel::PaOutput();
	_udp    = new Babel::Network::UDPNetwork(_output);
	_input  = new Babel::PaInput(_udp);
	QObject::connect(_hangout, SIGNAL(clicked()), this,
			 SLOT(hangoutCall()));
}

void Babel::UI::Call::makeCall(const std::string &ip)
{
	_output->start();
	_input->start();
}

void Babel::UI::Call::hangoutCall()
{
	_output->stop();
	_input->stop();
	_stack->setCurrentIndex(1);
}
