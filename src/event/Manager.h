#ifndef MANAGER_H_
#define MANAGER_H_

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
