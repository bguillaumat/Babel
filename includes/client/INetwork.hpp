#ifndef BABEL_INETWORK_H
#define BABEL_INETWORK_H

namespace Babel {

	//This is an interface for Network Plugin
	class INetwork {
	public:
		virtual        ~INetwork();
		virtual bool initConnection() = 0;
		virtual void sendData() = 0;
	};
} // namespace Babel
#endif
