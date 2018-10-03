#ifndef BABEL_ICOMPRESSOR_H
#define BABEL_ICOMPRESSOR_H

#include "DecodedSound.hpp"
#include "EncodedSound.hpp"

namespace Babel {

	class ICompressor {
	public:
		virtual ~ICompressor() = default;
		virtual EncodedSound encodeSound(DecodedSound &decodedSound) = 0;
		virtual DecodedSound decodeSound(EncodedSound &soundEncode) = 0;
	};
} // namespace Babel
#endif
