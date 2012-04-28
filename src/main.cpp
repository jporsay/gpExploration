#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "util/Logger.h"
#include "event/Manager.h"
#include "event/GenericHandler.h"
#include "game/State.h"
#include "game/Settings.h"

#include "parser/ThreeDS.h"
#include "object/Object.h"

SDL_Surface* screen;
event::Manager* eventManager;
bool running = true;

bool initSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Couldn't initialize SDL" << std::endl;
		return false;
	}
	screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	if (screen == NULL) {
		std::cout << "Error creating OpenGL Surface." << std::endl;
		return false;
	}
	return true;
}

bool initEverything() {
	if (!initSDL()) {
		return false;
	}

	GLenum glew_init;
	glew_init = glewInit();
	if (glew_init != GLEW_OK) {
		std::cout << "Error initializing GLEW" << std::endl;
		return false;
	}
	if (!GLEW_VERSION_2_1) {
		std::cout << "OpenGL 2.1 not supported" << std::endl;
		return false;
	}
	game::Settings::inst()->setResourcePath("resources/");
	game::Settings::inst()->setShaderPath("resources/shaders/");
	game::Settings::inst()->setModelPath("resources/models/");
	Logger::inst()->setFileName("log.txt");
	eventManager = new event::Manager();
	eventManager->registerHandler(new handler::GenericHandler());
	return true;
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	SDL_GL_SwapBuffers();
}

void run() {
	game::State::inst()->setRunning(true);
	while (game::State::inst()->isRunning()) {
		if (!game::State::inst()->isHidden()) {
			eventManager->handleEvents();
			render();
		}
	}
}

void clean() {

}

int main(int argc, char* argv[]) {
	if (!initEverything()) {
		return 1;
	}
	parser::ThreeDS* parser = new parser::ThreeDS();
	parser->setFile("Box.3DS");
	object::Object* o = parser->parse();
	run();
	clean();
	return 0;
}
