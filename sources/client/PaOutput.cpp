
#include <stdexcept>
#include "PaOutput.hpp"

namespace Babel {

PaOutput::PaOutput() {
	error = Pa_Initialize();
	if (error != paNoError) {
		throw std::runtime_error("Unable to initialize PortAudio");
	}
}

PaOutput::~PaOutput() {
}

//Callback record 
int PaOutput::PlayCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, PaStreamCallbackTimeInfo timeInfo, PaStreamCallbackFlags statusFlags, void * userData) {
	return true;
}

bool PaOutput::start() {
	return true;
}

bool PaOutput::stop() {
	return true;
}


} // namespace Babel
