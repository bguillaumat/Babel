/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include "Core.hpp"
#include "includes/client/UI/Login.hpp"
#include "includes/client/UI/Home.hpp"

Core::Core(int ac, char **av) : _app(ac, av), _stackedWidget()
{
	_loginScreen = new Babel::UI::Login(_stackedWidget);
	_homeScreen  = new Babel::UI::Home(_stackedWidget);
	_stackedWidget.addWidget(_loginScreen);
	_stackedWidget.addWidget(_homeScreen);
	_stackedWidget.show();
}

void Core::run()
{
	_app.exec();
}
