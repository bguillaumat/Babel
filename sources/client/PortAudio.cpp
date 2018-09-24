/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <PortAudio.hpp>
#include "PortAudio.hpp"

#define SAMPLE_RATE (44100)

Babel::PaInput::PaInput()
{
	PaError	error;

	error = Pa_Initialize();
	if (error != paNoError) {
		throw std::runtime_error(Pa_GetErrorText(error));
	}
	error = Pa_OpenDefaultStream(&_stream, 1, 2, paFloat32, SAMPLE_RATE, 256, callback, nullptr);
	if (error != paNoError) {
		throw std::runtime_error(Pa_GetErrorText(error));
	}
	error = Pa_StartStream(_stream);
	if (error != paNoError) {
		throw std::runtime_error(Pa_GetErrorText(error));
	}
}

Babel::PaInput::~PaInput()
{
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

int	Babel::PaInput::callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	return 0;
}
