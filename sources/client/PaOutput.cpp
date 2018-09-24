/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <stdexcept>
#include <PaOutput.hpp>

Babel::PaOutput::PaOutput()
{
	PaError	error;

	error = Pa_Initialize();
	if (error != paNoError)
	{
		throw std::runtime_error(Pa_GetErrorText(error));
	}
	error = Pa_OpenDefaultStream(&_stream, 1, 2, paFloat32, 44100, 256, callback, nullptr);
	if (error != paNoError)
	{
		throw std::runtime_error(Pa_GetErrorText(error));
	}
	error = Pa_StartStream(_stream);
	if (error != paNoError)
	{
		throw std::runtime_error(Pa_GetErrorText(error));
	}
}

Babel::PaOutput::~PaOutput()
{
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

int	Babel::PaOutput::callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	return 0;
}
