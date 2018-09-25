
#include <stdexcept>
#include "PaInput.hpp"

namespace Babel {

PaInput::PaInput() {
	error = Pa_Initialize();
	if (error != paNoError) {
		throw std::runtime_error("Unable to initialize PortAudio");
	}
}

PaInput::~PaInput() {
}

//Callback record 
int PaInput::RecordCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, PaStreamCallbackTimeInfo timeInfo, PaStreamCallbackFlags statusFlags, void * userData) {
	return true;
}

bool PaInput::start() {
	return true;
}

bool PaInput::stop() {
	return true;
}


} // namespace Babel
