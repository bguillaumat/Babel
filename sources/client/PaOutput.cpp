
#include <stdexcept>
#include <SoundDeviceSettings.hpp>
#include <iostream>
#include "PaOutput.hpp"

namespace Babel {

PaOutput::PaOutput() {
	_error = Pa_Initialize();
	if (_error != paNoError) {
		throw std::runtime_error("Unable to initialize PortAudio");
	}
	_parameters.device = Pa_GetDefaultOutputDevice();
	if (_parameters.device == paNoDevice) {
		throw std::runtime_error("No default output device.");
	}
	_parameters.channelCount = SoundDeviceSetting::channels;
	_parameters.sampleFormat = paFloat32;
	_parameters.suggestedLatency = Pa_GetDeviceInfo(_parameters.device)->defaultLowInputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, nullptr, &_parameters, (double)SoundDeviceSetting::sampleRate, SoundDeviceSetting::framePerBuffer, paClipOff, PlayCallback, nullptr);
	if (_error != paNoError) {
		throw std::runtime_error("Unable to open stream.");
	}

}

PaOutput::~PaOutput()
{
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

//Callback record
int PaOutput::PlayCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	(void)userData;
	(void)timeInfo;
	(void)statusFlags;
	(void)inputBuffer;
	float	*output = (float*)outputBuffer;

	for (size_t i = 0; i < framesPerBuffer ; i++) {
		*output++ = 0.0f;
		if (SoundDeviceSetting::channels == 2) {
			*output++ = 0.0f;
		}
	}
	return paContinue;
}

bool PaOutput::start()
{
	_error = Pa_StartStream(_stream);
	return _error == paNoError;
}

bool PaOutput::stop()
{
	_error = Pa_StopStream(_stream);
	return _error == paNoError;
}


} // namespace Babel
