/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <portaudio.h>
#include <iostream>
#include <memory>
#include <QApplication>
#include <QPushButton>
#include <IAudio.hpp>
#include <PortAudio.hpp>

int	main(int ac, char *av[])
{
	try {
		std::unique_ptr<Babel::IAudio> audio(new Babel::PaInput());
	} catch (std::runtime_error const &error) {
		std::cerr << error.what() << std::endl;
		return 84;
	}
	QApplication app(ac, av);
	QPushButton bouton("Salut les Zéros, la forme ?");
	bouton.show();
	return app.exec();
}
