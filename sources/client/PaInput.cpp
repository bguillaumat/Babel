#include <stdexcept>
#include <vector>
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
	_parameters.suggestedLatency          = Pa_GetDeviceInfo(_parameters.device)->defaultLowInputLatency;
	_parameters.hostApiSpecificStreamInfo = nullptr;
	_error = Pa_OpenStream(&_stream, &_parameters, nullptr, (double)SoundDeviceSetting::sampleRate, SoundDeviceSetting::framePerBuffer, paClipOff, RecordCallback, this);
	if (_error != paNoError) {
		throw std::runtime_error("Unable to open stream.");
	}
}

Babel::PaInput::~PaInput()
{
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
	for (size_t count = 0; count < framesPerBuffer; count++) {
		if (inputBuffer == nullptr) {
			sound.buffer.push_back(SoundDeviceSetting::SAMPLE_SILENCE);
			if (SoundDeviceSetting::channels == 2) {
				sound.buffer.push_back(
					SoundDeviceSetting::SAMPLE_SILENCE);
			}
		} else {
			sound.buffer.push_back(*input++);
			if (SoundDeviceSetting::channels == 2) {
				sound.buffer.push_back(*input++);
			}

		}
	}
	thisRef->_udp->sendDatagram(sound);
	//thisRef->addSound(sound);
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

	if (!_sounds.empty()) {
		_lock.lock();
		sound = std::move(_sounds.front());
		_sounds.erase(_sounds.begin());
		_lock.unlock();
	} else {
		sound.buffer = std::vector<float>(
			SoundDeviceSetting::framePerBuffer,
			SoundDeviceSetting::SAMPLE_SILENCE);
		sound.size   = SoundDeviceSetting::framePerBuffer;
	}

	return sound;
}

void Babel::PaInput::addSound(DecodedSound &sound)
{
	_lock.lock();
	_sounds.emplace_back(sound);
	_lock.unlock();
}

void Babel::PaInput::setSound(const DecodedSound &sound)
{
	(void)sound;
}
