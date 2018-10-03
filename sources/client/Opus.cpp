#include <stdexcept>
#include <iostream>
#include "Opus.hpp"
#include "EncodedSound.hpp"
#include "DecodedSound.hpp"

namespace Babel {

	Opus::Opus()
	{
		int error = OPUS_OK;

		_encoder = opus_encoder_create(SoundDeviceSetting::sampleRate, SoundDeviceSetting::channels, OPUS_APPLICATION_VOIP, &error);
		if (error != OPUS_OK) {
			throw std::runtime_error("OpusEncoder: " +
				std::string(opus_strerror(error)));
		}
		_decoder = opus_decoder_create(SoundDeviceSetting::sampleRate, SoundDeviceSetting::channels, &error);
		if (error != OPUS_OK) {
			throw std::runtime_error("OpusDecoder: " +
				std::string(opus_strerror(error)));
		}
	}

	Opus::~Opus()
	{
		opus_encoder_destroy(_encoder);
		opus_decoder_destroy(_decoder);
	}

	EncodedSound Opus::encodeSound(DecodedSound &decodedSound)
	{
		EncodedSound encodeSound;

		encodeSound.buffer.resize(decodedSound.size);
		encodeSound.size = opus_encode_float(_encoder, decodedSound.buffer.data(), SoundDeviceSetting::frameSize, encodeSound.buffer.data(), decodedSound.size);
		return encodeSound;
	}

	DecodedSound Opus::decodeSound(EncodedSound &soundEncode)
	{
		DecodedSound decodeSound;

		decodeSound.buffer.resize(soundEncode.size);
		decodeSound.size =
			opus_decode_float(_decoder, soundEncode.buffer.data(), soundEncode.size, decodeSound.buffer.data(), SoundDeviceSetting::sampleRate, 0) *
				SoundDeviceSetting::channels;
		return decodeSound;
	}
} // namespace Babel
