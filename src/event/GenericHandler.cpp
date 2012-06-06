#include "GenericHandler.h"
#include "../app/State.h"
namespace handler {

GenericHandler::GenericHandler() {
	// TODO Auto-generated constructor stub

}

void GenericHandler::handleEvent(sf::Event* event) {
	switch (event->type) {
		case sf::Event::Resized:
			onWindowResize(event);
			break;
		case sf::Event::Closed:
			app::State::mainWindow->close();
			break;
		default:
			break;

	}
}


void GenericHandler::onWindowResize(sf::Event* event) {
	//int newWidth = event.w;
	//int newHeight = event.h;
}


GenericHandler::~GenericHandler() {
	// TODO Auto-generated destructor stub
}

}
