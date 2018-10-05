/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_CORE_HPP
#define CPP_BABEL_2018_CORE_HPP

#include <QApplication>
#include <QtWidgets/QStackedWidget>

class Core {
public:
	Core(int ac, char *av[]);
	void run();

private:
	QApplication   _app;
	QStackedWidget _stackedWidget;
	QWidget        *_loginScreen;
	QWidget        *_homeScreen;
};

#endif //CPP_BABEL_2018_CORE_HPP
