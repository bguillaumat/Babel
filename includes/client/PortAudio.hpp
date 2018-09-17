/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#ifndef CPP_BABEL_2018_PORTAUDIO_HPP
#define CPP_BABEL_2018_PORTAUDIO_HPP

#include "IAudio.hpp"

namespace Babel {
	class PortAudio : public IAudio {
	public:
		PortAudio();
		~PortAudio() final;
	};
}

#endif //CPP_BABEL_2018_PORTAUDIO_HPP
