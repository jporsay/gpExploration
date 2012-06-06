#ifndef HANDLER_H_
#define HANDLER_H_

#include <SFML/Window/Event.hpp>

namespace handler {

class Handler {
public:
	virtual void handleEvent(sf::Event* event);
	virtual ~Handler();
};

}

#endif
