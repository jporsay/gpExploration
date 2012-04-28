#ifndef HANDLER_H_
#define HANDLER_H_

#include <SDL/SDL.h>

namespace handler {

class Handler {
public:
	virtual void handleEvent(SDL_Event* event);
	virtual ~Handler();
};

}

#endif
