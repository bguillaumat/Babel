/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#include "includes/client/UI/Home.hpp"

Babel::UI::Home::Home(QStackedWidget &stack)
	: QWidget(), _width(300), _height(300), _stack(stack)
{
	_signin       = new QPushButton("Home Button");
	_buttonLayout = new QHBoxLayout();
	_layout       = new QVBoxLayout();
	_buttonLayout->addWidget(_signin);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
}
