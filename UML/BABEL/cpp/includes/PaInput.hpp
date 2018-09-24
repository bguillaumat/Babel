#ifndef BABEL_PAINPUT_H
#define BABEL_PAINPUT_H


#include "IAudio.hpp"

namespace Babel {

//This class take sound from the first micro on the device
class PaInput : public IAudio {
	private:
    //Contain current input stream
    PaStream * _stream = nullptr;


	public:
    PaInput();

    ~PaInput();

    //Callback record 
    int RecordCallback(void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo timeInfo, const PaStreamCallbackFlags statusFlags, void * userData);

    virtual bool start() override;

    virtual bool stop() override;


	private:
	PaError error;
	PaStreamParameters _paParams;
};

} // namespace Babel
#endif
