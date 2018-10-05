/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <QtCore/QCoreApplication>
#include "includes/client/UI/Home.hpp"

Babel::UI::Home::Home(QStackedWidget *stack)
	: QWidget(), _width(300), _height(300), _stack(stack)
{
	_signin = new QPushButton("Call me");
	_signin->setIcon(QIcon(QCoreApplication::applicationDirPath() +
				       "/media/call.png"));
	_signin->setIconSize(QSize(30, 30));
	_buttonLayout = new QHBoxLayout();
	_layout       = new QVBoxLayout();
	_buttonLayout->addWidget(_signin);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
	connect(_signin, SIGNAL(clicked()), this, SLOT(makeCall()));
}

void Babel::UI::Home::makeCall()
{
	_stack->setCurrentIndex(2);
}
