/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <includes/client/UI/Login.hpp>

#include "includes/client/UI/Login.hpp"

Babel::UI::Login::Login(QStackedWidget *stack)
	: QWidget(), _width(500), _height(400), _stack(stack)
{
	_signin       = new QPushButton("Sign In");
	_id           = new QLineEdit();
	_form         = new QFormLayout();
	_layout       = new QVBoxLayout();
	_buttonLayout = new QHBoxLayout();
	setFixedSize(_width, _height);
	setWindowTitle("Skipe");
	_form->addRow("Username:", _id);
	_form->setSpacing(20);
	_form->setFormAlignment(Qt::AlignCenter);
	_buttonLayout->addWidget(_signin);
	_layout->addLayout(_form);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
	_signin->setCursor(Qt::PointingHandCursor);
	_id->setEchoMode(QLineEdit::Normal);
	QObject::connect(_signin, SIGNAL(clicked()), this, SLOT(tryLogin()));
	QObject::connect(_id, SIGNAL(returnPressed()), _signin,
			 SIGNAL(clicked()));
}

void Babel::UI::Login::tryLogin()
{
	if (_id->text().isEmpty())
		_id->setPlaceholderText("Please enter an id");
	else
		_stack->setCurrentIndex(1);
}
