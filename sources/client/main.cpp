/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <PaOutput.hpp>
#include <PaInput.hpp>

int main(int ac, char *av[])
{
	try {
		QApplication  app(ac, av);
		QPushButton   button("Salut les Zéros, la forme ?");
		//		Babel::ICompressor *compressor = new Babel::Opus();
		Babel::IAudio *audio1 = new Babel::PaOutput();
		Babel::IAudio *audio  = new Babel::PaInput();

		audio->start();
		audio1->start();
		button.show();
		app.exec();
		audio->stop();
		audio1->stop();
	} catch (const std::runtime_error &runtimeError) {
		std::cerr << "A runtime error occur:" << std::endl << "\t"
			<< runtimeError.what() << std::endl;
		return 84;
	}
	return 0;
}
