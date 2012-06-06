#include "Manager.h"

namespace event {

Manager::Manager() {
	this->handlers = new std::vector<handler::Handler*>();
}

void Manager::handleEvents() {
	handler::Handler* h;
	sf::Event e;
	while(app::State::mainWindow->pollEvent(e)) {
		for (int i = 0; i < (int)this->handlers->size(); i++) {
			h = this->handlers->at(i);
			h->handleEvent(&e);
		}
	}
}

void Manager::registerHandler(handler::Handler* handler) {
	this->handlers->push_back(handler);
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

}
