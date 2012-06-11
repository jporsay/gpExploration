#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SFML/Window/Event.hpp>

namespace handler {

class Handler {
public:
	virtual void handleEvent(sf::Event* event);
	virtual ~Handler();
};

}

#endif
