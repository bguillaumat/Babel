#include <stdexcept>
#include <iostream>
#include "PrintVector.hpp"
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
	_error = Pa_OpenStream(&_stream, nullptr, &_parameters,
			       (double)(SoundDeviceSetting::sampleRate),
			       SoundDeviceSetting::framePerBuffer, paClipOff,
			       PlayCallback, this);
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
	auto         output  = reinterpret_cast<float *>(outputBuffer);
	auto         thisRef = reinterpret_cast<PaOutput *>(userData);
	DecodedSound sound;

	(void)timeInfo;
	(void)statusFlags;
	(void)inputBuffer;
	if (thisRef->_sounds.empty()) {
		for (size_t count = 0; count < framesPerBuffer; count++) {
			*output++ = SoundDeviceSetting::SAMPLE_SILENCE;
			if (SoundDeviceSetting::channels == 2) {
				*output++ = SoundDeviceSetting::SAMPLE_SILENCE;
			}
		}
	} else {
		thisRef->_lock.lock();
		sound = thisRef->_sounds.front();
		for (size_t count = 0; count < framesPerBuffer; count++) {
			if (sound.buffer.empty()) {
				break;
			}
			*output++ = sound.buffer.front();
			sound.buffer.erase(sound.buffer.begin());
			if (SoundDeviceSetting::channels == 2) {
				*output++ = sound.buffer.front();
				sound.buffer.erase(sound.buffer.begin());
			}
		}
		// Remove first element
		thisRef->_sounds.erase(thisRef->_sounds.begin());
		thisRef->_lock.unlock();
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
	Babel::DecodedSound sound = {std::vector<float>(0), 0};

	return sound;
}

void Babel::PaOutput::setSound(const DecodedSound &sound)
{
	_sounds.emplace_back(sound);
}
