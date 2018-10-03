#ifndef BABEL_IAUDIO_H
#define BABEL_IAUDIO_H

#include "DecodedSound.hpp"

namespace Babel {

class IAudio {
	public:
		virtual ~IAudio() = default;
		virtual bool start() = 0;
		virtual bool stop() = 0;
		virtual Babel::DecodedSound	getSound() const = 0;
};

} // namespace Babel
#endif
