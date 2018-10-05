/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_CORE_HPP
#define CPP_BABEL_2018_CORE_HPP

#include <QtWidgets/QStackedWidget>

class Core : public QWidget {
Q_OBJECT
public:
	Core();

public slots:
	void checkForCall(int);

private:
	QStackedWidget *_stackedWidget;
	QWidget        *_loginScreen;
	QWidget        *_homeScreen;
	QWidget        *_callScreen;
};

#endif //CPP_BABEL_2018_CORE_HPP
