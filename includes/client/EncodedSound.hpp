#ifndef BABEL_ENCODEDSOUND_H
#define BABEL_ENCODEDSOUND_H

namespace Babel {
	typedef struct EncodedSound {
		std::vector<unsigned char>	buffer;
		int							size = 0;
	}			   EncodedSound;
} // namespace Babel
#endif
