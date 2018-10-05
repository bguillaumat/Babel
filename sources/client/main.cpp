/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <QApplication>
#include "Core.hpp"

int main(int ac, char *av[])
{
	try {
		QApplication _app(ac, av);
		Core         core;

		_app.exec();
	} catch (const std::runtime_error &runtimeError) {
		std::cerr << "A runtime error occur:" << std::endl << "\t"
			<< runtimeError.what() << std::endl;
		return 84;
	} catch (const std::exception &exception) {
		std::cerr << "An unexpected error occur:" << std::endl << "\t"
			<< exception.what() << std::endl;
		return 84;
	}
	return 0;
}
