#ifndef BABEL_OPUS_H
#define BABEL_OPUS_H


#include "ICompressor.hpp"

namespace Babel { struct EncodedSound; } 
namespace Babel { struct DecodedSound; } 

namespace Babel {

class Opus : public ICompressor {
	public:
    Opus();

    ~Opus();


	private:
    //This is use for encode sound to opus codec
    OpusEncoder * _encoder;

    //This is use for decode a sound with opus codec
    OpusDecoder * _decoder;


	public:
    EncodedSound encodeSound(const DecodedSound & decodedSound);

    DecodedSound decodeSound(const EncodedSound & soundEncode);

};

} // namespace Babel
#endif
