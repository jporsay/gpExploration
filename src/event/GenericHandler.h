#ifndef GENERICHANDLER_H_
#define GENERICHANDLER_H_

#include "Handler.h"

namespace handler {

class GenericHandler: public handler::Handler {
public:
	GenericHandler();
	virtual ~GenericHandler();
	void handleEvent(SDL_Event* event);
	void onWindowResize(SDL_ResizeEvent event);
};

}
#endif
