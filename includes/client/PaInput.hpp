#ifndef BABEL_PAINPUT_H
#define BABEL_PAINPUT_H

#include <portaudio.h>
#include <mutex>
#include "DecodedSound.hpp"
#include "includes/client/Network/UDPNetwork.hpp"
#include "IAudio.hpp"

namespace Babel {

	//This class take sound from the default micro on the device
	class PaInput : public IAudio {
	public:
		explicit PaInput(Babel::Network::UDPNetwork *udp);
		~PaInput() override;
		//Callback record
		static int RecordCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
		bool start() override;
		bool stop() override;
		DecodedSound getSound() const override;
		void setSound(const DecodedSound &sound) override;

	private:
		//Contain current input stream
		PaStream                          *_stream = nullptr;
		PaStreamParameters                _parameters;
		PaError                           _error;
		Babel::Network::UDPNetwork        *_udp;
	};
} // namespace Babel
#endif
