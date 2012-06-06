#ifndef GENERICHANDLER_H_
#define GENERICHANDLER_H_

#include "Handler.h"

namespace handler {

class GenericHandler: public handler::Handler {
public:
	GenericHandler();
	virtual ~GenericHandler();
	void handleEvent(sf::Event* event);
	void onWindowResize(sf::Event* event);
};

}
#endif
