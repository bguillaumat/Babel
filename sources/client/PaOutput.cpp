#include <stdexcept>
#include "SoundDeviceSettings.hpp"
#include "PaOutput.hpp"

Babel::PaOutput::PaOutput()
{
	_error = Pa_Initialize();
	if (_error != paNoError) {
		throw std::runtime_error("Unable to initialize PortAudio");
	}
	_parameters.device = Pa_GetDefaultOutputDevice();
	if (_parameters.device == paNoDevice) {
		throw std::runtime_error("No default output device.");
	}
	_parameters.channelCount              = SoundDeviceSetting::channels;
	_parameters.sampleFormat              = paFloat32;
	_parameters.suggestedLatency          = Pa_GetDeviceInfo(_parameters.device)->defaultLowInputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, nullptr, &_parameters, (double)SoundDeviceSetting::sampleRate, SoundDeviceSetting::framePerBuffer, paClipOff, PlayCallback, nullptr);
	if (_error != paNoError) {
		throw std::runtime_error("Unable to open stream.");
	}
}

Babel::PaOutput::~PaOutput()
{
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

//Callback record
int Babel::PaOutput::PlayCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	(void)userData;
	(void)timeInfo;
	(void)statusFlags;
	(void)inputBuffer;
	float *output = (float *)outputBuffer;

	for (size_t i = 0; i < framesPerBuffer; i++) {
		*output++ = SoundDeviceSetting::SAMPLE_SILENCE;
		if (SoundDeviceSetting::channels == 2) {
			*output++ = SoundDeviceSetting::SAMPLE_SILENCE;
		}
	}
	return paContinue;
}

bool Babel::PaOutput::start()
{
	_error = Pa_StartStream(_stream);
	return _error == paNoError;
}

bool Babel::PaOutput::stop()
{
	_error = Pa_StopStream(_stream);
	return _error == paNoError;
}

Babel::DecodedSound Babel::PaOutput::getSound() const
{
	return _sound;
}
