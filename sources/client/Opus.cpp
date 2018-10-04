#include <stdexcept>
#include <iostream>
#include "Opus.hpp"

Babel::Opus::Opus()
{
	int error = OPUS_OK;

	_encoder = opus_encoder_create(SoundDeviceSetting::sampleRate,
				       SoundDeviceSetting::channels,
				       OPUS_APPLICATION_VOIP, &error);
	if (error != OPUS_OK) {
		throw std::runtime_error(
			"OpusEncoder: " + std::string(opus_strerror(error)));
	}
	_decoder = opus_decoder_create(SoundDeviceSetting::sampleRate,
				       SoundDeviceSetting::channels, &error);
	if (error != OPUS_OK) {
		throw std::runtime_error(
			"OpusDecoder: " + std::string(opus_strerror(error)));
	}
}

Babel::Opus::~Opus()
{
	opus_encoder_destroy(_encoder);
	opus_decoder_destroy(_decoder);
}

#include <iterator>

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T, std::allocator<T>> &v)
{
	if (!v.empty()) {
		out << '[';
		std::copy(v.begin(), v.end(),
			  std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}

Babel::EncodedSound Babel::Opus::encodeSound(const DecodedSound &decodedSound)
{
	EncodedSound  encodeSound = {
		std::vector<unsigned char>(SoundDeviceSetting::framePerBuffer),
		0};
	const float   *in         = decodedSound.buffer.data();
	unsigned char *out        = encodeSound.buffer.data();
	int           size        = (int)decodedSound.buffer.size();

	encodeSound.size = opus_encode_float(_encoder, in,
					     SoundDeviceSetting::framePerBuffer,
					     out, size);
	if (encodeSound.size < 0) {
		throw std::runtime_error("Encoder failed: " + std::string(
			opus_strerror(encodeSound.size)));
	}
	std::cout << "first: " << decodedSound.buffer
		<< decodedSound.buffer.size() << std::endl;
	std::cout << "to: " << encodeSound.buffer << encodeSound.buffer.size()
		<< std::endl;
	return encodeSound;
}

Babel::DecodedSound Babel::Opus::decodeSound(const EncodedSound &soundEncode)
{
	DecodedSound        decodeSound = {
		std::vector<float>(SoundDeviceSetting::framePerBuffer * 2), 0};
	const unsigned char *in         = soundEncode.buffer.data();
	float               *out        = decodeSound.buffer.data();
	int                 size        = (int)soundEncode.buffer.size();

	decodeSound.size = opus_decode_float(_decoder, in,
					     sizeof(std::vector<unsigned char>) +
						     (sizeof(unsigned char) *
							     size), out,
					     SoundDeviceSetting::framePerBuffer,
					     0);
	if (decodeSound.size < 0) {
		throw std::runtime_error("Decoder failed: " + std::string(
			opus_strerror(decodeSound.size)));
	}
	std::cout << "second: " << decodeSound.buffer
		<< decodeSound.buffer.size() << std::endl;
	return decodeSound;
}
