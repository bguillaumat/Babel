#ifndef BABEL_OPUS_H
#define BABEL_OPUS_H

#include <vector>
#include <opus.h>
#include "SoundDeviceSettings.hpp"
#include "ICompressor.hpp"

namespace Babel {

	class Opus : public ICompressor {
	public:
		Opus();
		~Opus() override;
		EncodedSound encodeSound(const DecodedSound &decodedSound) override;
		DecodedSound decodeSound(const EncodedSound &soundEncode) override;

	private:
		//This is use for encode sound to opus codec
		OpusEncoder *_encoder;
		//This is use for decode a sound with opus codec
		OpusDecoder *_decoder;
	};
} // namespace Babel
#endif
