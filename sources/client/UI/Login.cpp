/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "UI/Login.hpp"

Babel::UI::Login::Login() : QWidget(), _width(200), _height(300)
{
	_signin       = new QPushButton("Sign In");
	_signup       = new QPushButton("Sign Up");
	_id           = new QLineEdit();
	_pwd          = new QLineEdit();
	_form         = new QFormLayout();
	_layout       = new QVBoxLayout();
	_buttonLayout = new QHBoxLayout();
	setFixedSize(_width, _height);
	_background.setColor(QPalette::Background, Qt::darkBlue);
	setAutoFillBackground(true);
	setPalette(_background);
	_form->addRow("ID:", _id);
	_form->addRow("Password:", _pwd);

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
}
