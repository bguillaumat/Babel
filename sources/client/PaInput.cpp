#include <stdexcept>
#include <vector>
#include <iostream>
#include "includes/client/SoundDeviceSettings.hpp"
#include "includes/client/PaInput.hpp"

Babel::PaInput::PaInput(Babel::Network::UDPNetwork *udp) : _udp(udp)
{
	_error = Pa_Initialize();
	if (_error != paNoError) {
		throw std::runtime_error("Unable to initialize PortAudio");
	}
	_parameters.device = Pa_GetDefaultInputDevice();
	if (_parameters.device == paNoDevice) {
		throw std::runtime_error("No default input device.");
	}
	_parameters.channelCount              = SoundDeviceSetting::channels;
	_parameters.sampleFormat              = paFloat32;
	_parameters.suggestedLatency          = Pa_GetDeviceInfo(
		_parameters.device)->defaultHighInputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, &_parameters, nullptr,
			       (double)SoundDeviceSetting::sampleRate,
			       SoundDeviceSetting::framePerBuffer, paClipOff,
			       RecordCallback, this);
	if (_error != paNoError) {
		throw std::runtime_error("Unable to open stream.");
	}
}

Babel::PaInput::~PaInput()
{
	stop();
	Pa_CloseStream(_stream);
	Pa_Terminate();
}

//Callback record
int Babel::PaInput::RecordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	auto         input   = reinterpret_cast<const float *>(inputBuffer);
	auto         thisRef = reinterpret_cast<PaInput *>(userData);
	DecodedSound sound   = {};

	(void)outputBuffer;
	(void)timeInfo;
	(void)statusFlags;
	(void)framesPerBuffer;
	if (inputBuffer == nullptr) {
		sound.buffer = std::vector<float>(SoundDeviceSetting::framePerBuffer * SoundDeviceSetting::channels, SoundDeviceSetting::SAMPLE_SILENCE);
	} else {
		for (size_t count = 0; count < framesPerBuffer * SoundDeviceSetting::channels; count++) {
			sound.buffer.push_back(*input++);
		}
	}
	sound.size = (int)sound.buffer.size();
	thisRef->_udp->sendDatagram(sound);
	return paContinue;
}

bool Babel::PaInput::start()
{
	_error = Pa_StartStream(_stream);
	return _error == paNoError;
}

bool Babel::PaInput::stop()
{
	_error = Pa_StopStream(_stream);
	return _error == paNoError;
}

Babel::DecodedSound Babel::PaInput::getSound() const
{
	DecodedSound sound;

	sound.buffer = std::vector<float>(SoundDeviceSetting::framePerBuffer,
					  SoundDeviceSetting::SAMPLE_SILENCE);
	sound.size   = (int)sound.buffer.size();
	return sound;
}

void Babel::PaInput::setSound(const DecodedSound &sound)
{
	(void)sound;
}
