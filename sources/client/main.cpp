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
#include <ICompressor.hpp>
#include <Opus.hpp>
#include <PaOutput.hpp>
#include <PaInput.hpp>

int	main(int ac, char *av[])
{
	QApplication	app(ac, av);
	QPushButton		button("Salut les Zéros, la forme ?");
	Babel::ICompressor	*compressor = new Babel::Opus();
	Babel::IAudio		*audio = new Babel::PaOutput();
	Babel::IAudio		*audio1 = new Babel::PaInput();

	audio->start();
	audio1->start();
	button.show();
	app.exec();
	audio->stop();
	audio1->stop();
	return 0;
}
