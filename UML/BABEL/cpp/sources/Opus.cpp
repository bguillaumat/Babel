
#include "Opus.hpp"
#include "EncodedSound.hpp"
#include "DecodedSound.hpp"

namespace Babel {

Opus::Opus() {
	int	error;

	_encoder = opus_encoder_create(SoundDevice::sampleRate, SoundDevice::channels, OPUS_APPLICATION_VOIP, &error);
	if (error != OPUS_OK) {
		thrown std::runtime_error("Unable to create an encoder");
	}
	_decoder = opus_decoder_create(Sound::sampleRate, Sound::channels, &error);
	if (error != OPUS_OK) {
		thrown std::runtime_error("Unable to create a decoder");
	}
}

Opus::~Opus() {
	opus_encoder_destroy(_encoder);
	opus_decoder_destroy(_decoder);
}

EncodedSound Opus::encodeSound(const DecodedSound & decodedSound) {
	soundEncoded	encodeSound;

	encodeSound.buffer.resize(decodedSound.size);
  	encodeSound.size = opus_encode_float(_encoder, decodedSound.buffer.data(), SoundDevice::frame_size, encodeSound.buffer.data(), decodedSound.size);
  	return encodeSound;
}

DecodedSound Opus::decodeSound(const EncodedSound & soundEncode) {
	soundDecoded	decodeSound;

	decodeSound.buffer.resize(soundEncode.size);
	decodeSound.size = opus_decode_float(_decode, soundEncode.buffer.data(), soundEncode.size(), decodeSound.buffer.data(), soundDecoded::frame_size, 0) * SoundDevice::channels;
	return decodeSound;
}


} // namespace Babel
