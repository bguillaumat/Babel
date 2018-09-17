/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#include <PortAudio.hpp>
#include <portaudio.h>
#include <iostream>
#include "PortAudio.hpp"

Babel::PortAudio::PortAudio()
{
	PaError	error = Pa_Initialize();

	if (error != paNoError) {
		throw std::runtime_error(Pa_GetErrorText(error));
	}
}

Babel::PortAudio::~PortAudio()
{
	PaError	error = Pa_Terminate();

	if (error != paNoError) {
		throw std::runtime_error(Pa_GetErrorText(error));
	}
}
