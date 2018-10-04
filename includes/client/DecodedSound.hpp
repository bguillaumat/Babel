#ifndef BABEL_DECODEDSOUND_H
#define BABEL_DECODEDSOUND_H

#include <vector>

namespace Babel {
	typedef struct DecodedSound {
		std::vector<float> buffer;
		int                size = 0;
	} DecodedSound;
} // namespace Babel
#endif
