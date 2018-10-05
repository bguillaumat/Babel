/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <PaOutput.hpp>
#include <includes/client/Network/UDPNetwork.hpp>
#include "ICompressor.hpp"
#include "Core.hpp"

void audio()
{
	Babel::ICompressor  *compressor = new Babel::Opus();
	Babel::IAudio       *paOutput   = new Babel::PaOutput();
	Babel::IAudio       *paInput    = new Babel::PaInput();
	Babel::DecodedSound sound;
	Babel::EncodedSound encodedSound;

	paInput->start();
	paOutput->start();
	Pa_Sleep(3 * 1000);
	for (size_t i = 0; i < 500; i++) {
		sound        = paInput->getSound();
		encodedSound = compressor->encodeSound(sound);
		paOutput->setSound(compressor->decodeSound(encodedSound));
	}
	Pa_Sleep(3 * 1000);
	paInput->stop();
	paOutput->stop();
}

int main(int ac, char *av[])
{
	try {
		Core                       core(ac, av);
		Babel::Network::UDPNetwork network;

		core.run();
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
