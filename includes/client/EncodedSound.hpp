#ifndef BABEL_ENCODEDSOUND_H
#define BABEL_ENCODEDSOUND_H

#include <vector>

namespace Babel {
	typedef struct EncodedSound {
		std::vector<unsigned char>	buffer;
		unsigned long			size = 0;
	}			   EncodedSound;
} // namespace Babel
#endif
