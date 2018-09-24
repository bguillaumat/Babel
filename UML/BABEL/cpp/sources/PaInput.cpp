
#include "PaInput.hpp"

namespace Babel {

PaInput::PaInput() {
	error = Pa_Initialize();
	if (error != paNoError) {
		thrown std::runtime_error("Unable to initialize PortAudio")
	}
}

PaInput::~PaInput() {
}

//Callback record 
int PaInput::RecordCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, PaStreamCallbackTimeInfo timeInfo, PaStreamCallbackFlags statusFlags, void * userData) {
}

bool PaInput::start() {
}

bool PaInput::stop() {
}


} // namespace Babel
