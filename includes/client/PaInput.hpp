#ifndef BABEL_PAINPUT_H
#define BABEL_PAINPUT_H

#include <portaudio.h>
#include "DecodedSound.hpp"
#include "IAudio.hpp"

namespace Babel {

	//This class take sound from the first micro on the device
	class PaInput : public IAudio {
	public:
		PaInput();
		~PaInput() override;
		//Callback record
		static int RecordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
		bool start() override;
		bool stop() override;
		DecodedSound getSound() const override;
	private:
		void addSound(DecodedSound &);

	private:
		//Contain current input stream
		PaStream                          *_stream = nullptr;
		PaStreamParameters                _parameters;
		PaError                           _error;
		mutable std::vector<DecodedSound> _sounds;
	};
} // namespace Babel
#endif
