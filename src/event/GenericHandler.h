#ifndef EVENT_GENERICHANDLER_H
#define EVENT_GENERICHANDLER_H

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
