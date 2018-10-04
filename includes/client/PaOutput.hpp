#ifndef BABEL_PAOUTPUT_H
#define BABEL_PAOUTPUT_H

#include <portaudio.h>
#include <mutex>
#include "IAudio.hpp"

namespace Babel {

	//This class play sound on the device
	class PaOutput : public IAudio {
	public:
		PaOutput();
		~PaOutput() override;
		//Callback record
		static int PlayCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
		bool start() override;
		bool stop() override;
		DecodedSound getSound() const override;
		void setSound(const DecodedSound &sound) override;

	private:
		PaStream                         *_stream = nullptr;
		PaStreamParameters               _parameters;
		PaError                          _error;
		std::vector<Babel::DecodedSound> _sounds;
		mutable std::mutex               _lock;
	};
} // namespace Babel
#endif
