#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "util/Logger.h"
#include "event/Manager.h"
#include "event/GenericHandler.h"
#include "app/State.h"
#include "app/Settings.h"
#include "app/GraphicSettings.h"
#include "manager/Shader.h"
#include "manager/CameraManager.h"
#include "gl/util/Helper.h"

#include "parser/ThreeDS.h"
#include "model/Model.h"
#include "world/Camera.h"

event::Manager* eventManager;
manager::Camera* cameraManager;
bool running = true;

model::Model* o;

bool initSFML() {
	app::State::mainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Graphics Programming Exploration!");
	return true;
}

bool initGlew() {
	GLenum glew_init;
	glew_init = glewInit();
	if (glew_init != GLEW_OK) {
		std::cout << "Error initializing GLEW" << std::endl;
		LOG_ERROR("Error initializing GLEW");
		return false;
	}
	if (!GLEW_VERSION_3_3) {
		std::cout << "OpenGL 3.3 not supported" << std::endl;
		LOG_ERROR("OpenGL 3.3 not supported");
		return false;
	}
	return true;
}

bool initOpenGL() {
	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CCW);
	return true;
}

bool initEverything() {
	app::Settings::inst()->setResourcePath("resources/");
	app::Settings::inst()->setShaderPath("resources/shaders/");
	app::Settings::inst()->setModelPath("resources/models/");
	Logger::inst()->setFileName("log.txt");
	eventManager = new event::Manager();
	eventManager->registerHandler(new handler::GenericHandler());
	app::GraphicSettings::screenHeight = 600;
	app::GraphicSettings::screenWidth = 800;
	if (!initSFML() || !initGlew() || !initOpenGL()) {
		return false;
	}
	cameraManager = manager::Camera::inst();
	cameraManager->add(new world::Camera(), "world");
	return true;
}

bool loadEverything() {
	parser::ThreeDS* parser = new parser::ThreeDS();
	parser->setFile("Cube.3ds");
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
	o = parser->parse();
	o->upload();
	return true;
}
/*
static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};
GLuint vertexbuffer;
void dummyInit() {
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

}

void dummyRender() {
	glEnableVertexAttribArray(gl::util::GL_ATTRIB_VERTEX);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
	   gl::util::GL_ATTRIB_VERTEX,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	   3,                  // size
	   GL_FLOAT,           // type
	   GL_FALSE,           // normalized?
	   0,                  // stride
	   (void*)0            // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

	glDisableVertexAttribArray(gl::util::GL_ATTRIB_VERTEX);
}
*/
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1.0);
	o->draw();
//	dummyRender();
	app::State::mainWindow->display();
}

void run() {
	app::State::inst()->setRunning(true);
//	dummyInit();
	while (app::State::mainWindow->isOpen()) {
		eventManager->handleEvents();
		render();
	}
}

void clean() {

}

int newMain() {
	run();
	return 1;
}

int main(int argc, char* argv[]) {
	if (!initEverything()) {
		return 1;
	}
	LOG_INFO("Loading resources...")
	if (!loadEverything()) {
		return 1;
	}
	LOG_INFO("Starting demoooo");
	run();
	clean();
	return 0;
}
