
#include <stdexcept>
#include <SoundDeviceSettings.hpp>
#include <iostream>
#include <vector>
#include "PaInput.hpp"

namespace Babel {

PaInput::PaInput() {
	_error = Pa_Initialize();
	if (_error != paNoError) {
		throw std::runtime_error("Unable to initialize PortAudio");
	}
	_parameters.device = Pa_GetDefaultInputDevice();
	if (_parameters.device == paNoDevice) {
		throw std::runtime_error("No default input device.");
	}
	_parameters.channelCount = SoundDeviceSetting::channels;
	_parameters.sampleFormat = paFloat32;
	_parameters.suggestedLatency = Pa_GetDeviceInfo(_parameters.device)->defaultLowInputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, &_parameters, nullptr, (double)SoundDeviceSetting::sampleRate, SoundDeviceSetting::framePerBuffer, paClipOff, RecordCallback, nullptr);
	if (_error != paNoError) {
		throw std::runtime_error("Unable to open stream.");
	}
}

PaInput::~PaInput() {
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

//Callback record
int PaInput::RecordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void * userData)
{
	(void)outputBuffer;
	(void)userData;
	(void)timeInfo;
	(void)statusFlags;
	(void)framesPerBuffer;
	auto	input = static_cast<const float *>(inputBuffer);

	if (inputBuffer == nullptr) {

	}
	return paContinue;
}

bool PaInput::start() {
	_error = Pa_StartStream(_stream);
	return _error == paNoError;
}

bool PaInput::stop() {
	_error = Pa_StopStream(_stream);
	return _error == paNoError;
}


} // namespace Babel
