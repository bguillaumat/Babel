
#include "PaOutput.hpp"

namespace Babel {

PaOutput::PaOutput() {
	error = Pa_Initialize();
	if (error != paNoError) {
		thrown std::runtime_error("Unable to initialize PortAudio")
	}
}

PaOutput::~PaOutput() {
}

//Callback record 
int PaOutput::PlayCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, PaStreamCallbackTimeInfo timeInfo, PaStreamCallbackFlags statusFlags, void * userData) {
}

bool PaOutput::start() {
}

bool PaOutput::stop() {
}


} // namespace Babel
