#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Handler.h"
#include "../app/State.h"
#include <SFML/Window/Event.hpp>
#include <vector>

namespace event {

class Manager {
private:
	std::vector<handler::Handler*>* handlers;
public:
	Manager();
	void handleEvents();
	void registerHandler(handler::Handler* handler);
	virtual ~Manager();
};

}
#endif
