#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "util/Logger.h"
#include "event/Manager.h"
#include "event/GenericHandler.h"
#include "app/State.h"
#include "app/Settings.h"
#include "manager/Shader.h"
#include "gl/util/Helper.h"

#include "parser/ThreeDS.h"
#include "model/Model.h"

SDL_Surface* screen;
event::Manager* eventManager;
bool running = true;

model::Model* o;

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

bool initGlew() {
	GLenum glew_init;
	glew_init = glewInit();
	if (glew_init != GLEW_OK) {
		std::cout << "Error initializing GLEW" << std::endl;
		return false;
	}
	if (!GLEW_VERSION_3_3) {
		std::cout << "OpenGL 3.3 not supported" << std::endl;
		return false;
	}
	return true;
}

bool initOpenGL() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	return true;
}

bool initEverything() {
	if (!initSDL() || !initGlew() || !initOpenGL()) {
		return false;
	}
	app::Settings::inst()->setResourcePath("resources/");
	app::Settings::inst()->setShaderPath("resources/shaders/");
	app::Settings::inst()->setModelPath("resources/models/");
	Logger::inst()->setFileName("log.txt");
	eventManager = new event::EventManager();
	eventManager->registerHandler(new handler::GenericHandler());
	return true;
}

bool loadEverything() {
	parser::ThreeDS* parser = new parser::ThreeDS();
	parser->setFile("Cube.3ds");
	o = parser->parse();
	o->upload();
	manager::Shader::inst()->setPath(app::Settings::inst()->getShaderPath());
	if (!manager::Shader::inst()->loadShaders()) {
		return false;
	}
	if(!manager::Shader::inst()->compile("simple")) {
		return false;
	}
	gl::ShaderProgram* simpleShader = manager::Shader::inst()->getProgram("simple");
	simpleShader->bindAttribLocation("vert", gl::util::GL_ATTRIB_VERTEX);
	simpleShader->link();
	return true;
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.827, 0.827, 0.827, 1.0);
	o->draw();
	SDL_GL_SwapBuffers();
}

void run() {
	app::State::inst()->setRunning(true);
	while (app::State::inst()->isRunning()) {
		if (!app::State::inst()->isHidden()) {
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
	LOG_INFO("Starting demo");
	if (!loadEverything()) {
		return 1;
	}
	run();
	clean();
	return 0;
}
