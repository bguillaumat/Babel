#ifndef BABEL_PAOUTPUT_H
#define BABEL_PAOUTPUT_H

#include <portaudio.h>
#include "IAudio.hpp"

namespace Babel {

//This class play sound on the device
class PaOutput : public IAudio {
	public:
		PaOutput();
		~PaOutput() override;
		//Callback record
		int	PlayCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, PaStreamCallbackTimeInfo timeInfo, PaStreamCallbackFlags statusFlags, void * userData);
		bool	start() override;
		bool	stop() override;

	private:
		PaStream	*_stream = nullptr;
		PaError		error;
		PaStreamParameters	_paParams;
};

} // namespace Babel
#endif
