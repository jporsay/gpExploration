#include "GenericHandler.h"
#include "../game/State.h"
namespace handler {

GenericHandler::GenericHandler() {
	// TODO Auto-generated constructor stub

}

void GenericHandler::handleEvent(SDL_Event* event) {
	switch (event->type) {
		case SDL_QUIT:
			game::State::inst()->setRunning(false);
			break;
		case SDL_VIDEORESIZE:
			onWindowResize(event->resize);
			break;
		case SDL_ACTIVEEVENT: {
			if ( event->active.state & SDL_APPACTIVE ) {
				game::State::inst()->setHidden(!event->active.gain);
			}
		}
		break;
	}
}


void GenericHandler::onWindowResize(SDL_ResizeEvent event) {
	//int newWidth = event.w;
	//int newHeight = event.h;
}


GenericHandler::~GenericHandler() {
	// TODO Auto-generated destructor stub
}

}
