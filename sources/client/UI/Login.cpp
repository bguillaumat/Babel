/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "UI/Login.hpp"

Babel::UI::Login::Login(QStackedWidget *stack)
	: QWidget(), _width(500), _height(400), _stack(stack)
{
	_signin       = new QPushButton("Sign In");
	_signup       = new QPushButton("Sign Up");
	_id           = new QLineEdit();
	_pwd          = new QLineEdit();
	_form         = new QFormLayout();
	_layout       = new QVBoxLayout();
	_buttonLayout = new QHBoxLayout();
	setFixedSize(_width, _height);
	setWindowTitle("Skipe");
	_background.setColor(QPalette::Background, Qt::cyan);
	setAutoFillBackground(true);
	setPalette(_background);
	_form->addRow("ID:", _id);
	_form->addRow("Password:", _pwd);
	_form->setSpacing(20);
	_form->setFormAlignment(Qt::AlignCenter);
	_buttonLayout->addWidget(_signup);
	_buttonLayout->addWidget(_signin);
	_layout->addLayout(_form);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
	_signin->setCursor(Qt::PointingHandCursor);
	_id->setEchoMode(QLineEdit::Normal);
	_pwd->setEchoMode(QLineEdit::Password);
	_pwd->setInputMethodHints(Qt::ImhHiddenText | Qt::ImhNoPredictiveText |
					  Qt::ImhNoAutoUppercase);
	QObject::connect(_signin, SIGNAL(clicked()), this, SLOT(tryLogin()));
	QObject::connect(_id, SIGNAL(returnPressed()), _signin,
			 SIGNAL(clicked()));
	QObject::connect(_pwd, SIGNAL(returnPressed()), _signin,
			 SIGNAL(clicked()));
}

void Babel::UI::Login::tryLogin()
{
	std::cout << _id->text().toStdString() << "\t"
		<< _pwd->text().toStdString() << std::endl;
	if (_id->text().isEmpty()) {
		_id->setPlaceholderText("Please enter an id");
	}
	if (_pwd->text().isEmpty()) {
		_pwd->setPlaceholderText("Please enter a password");
	}
	if (!_id->text().isEmpty() && !_pwd->text().isEmpty()) {
		_stack->setCurrentIndex(1);
	}
}
