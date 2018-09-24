#ifndef BABEL_PAOUTPUT_H
#define BABEL_PAOUTPUT_H


#include "IAudio.hpp"

namespace Babel {

//This class play sound on the device
class PaOutput : public IAudio {
	private:
    PaStream * _stream = nullptr;


	public:
    PaOutput();

    ~PaOutput();

    //Callback record 
    int PlayCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo timeInfo, const PaStreamCallbackFlags statusFlags, void * userData);

    virtual bool start() override;

    virtual bool stop() override;


	private:
	PaError error;
	PaStreamParameters _paParams;
};

} // namespace Babel
#endif
