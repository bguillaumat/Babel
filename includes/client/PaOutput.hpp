/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_PAOUTPUT_HPP
#define CPP_BABEL_2018_PAOUTPUT_HPP

#include <portaudio.h>
#include "IAudio.hpp"

namespace Babel {
	class PaOutput : public IAudio {
	public:
		PaOutput();
		~PaOutput() final;
		static int	callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData);

	private:
		PaStream	*_stream;
	};
}
#endif //CPP_BABEL_2018_PAOUTPUT_HPP
