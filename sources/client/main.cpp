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

int	main(int ac, char *av[])
{
	QApplication	app(ac, av);
	QPushButton		bouton("Salut les Zéros, la forme ?");

	bouton.show();
	return app.exec();
}
