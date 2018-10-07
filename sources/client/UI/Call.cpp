/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <QtCore/QCoreApplication>
#include <includes/client/PaOutput.hpp>
#include <includes/client/PaInput.hpp>
#include <includes/client/UI/Call.hpp>
#include <QtCore/QDateTime>

#include "includes/client/UI/Call.hpp"

Babel::UI::Call::Call(QStackedWidget *stack) : _stack(stack)
{
	_timeElapsed  = new QLabel();
	_time         = new QTimer();
	_timer        = new QElapsedTimer();
	_hangout      = new QPushButton("Hangout");
	_buttonLayout = new QHBoxLayout();
	_layout       = new QVBoxLayout();
	_hangout->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/media/call_end.png"));
	_hangout->setIconSize(QSize(30, 30));
	_buttonLayout->addWidget(_hangout);
	_buttonLayout->addWidget(_timeElapsed);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
	_output = new Babel::PaOutput();
	_udp    = new Babel::Network::UDPNetwork(_output);
	_input  = new Babel::PaInput(_udp);
	QObject::connect(_hangout, SIGNAL(clicked()), this,
			 SLOT(hangoutCall()));
	QObject::connect(_time, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

void Babel::UI::Call::makeCall(const std::string &ip)
{
	_udp->setHost(ip);
	_timeElapsed->setText("Time elapsed: 00:00:00");
	_time->start(1000);
	_timer->start();
	_output->start();
	_input->start();
}

void Babel::UI::Call::hangoutCall()
{
	_output->stop();
	_input->stop();
	_stack->setCurrentIndex(1);
}

void Babel::UI::Call::updateTimer()
{
	QTime time(0, 0, 0);

	time = time.addSecs((int)_timer->elapsed() / 1000);
	_timeElapsed->setText("Time elapsed: " + time.toString("hh:mm:ss"));
	_time->start(1000);
}
