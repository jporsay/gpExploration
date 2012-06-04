#include "State.h"

namespace app {

State* State::instance = 0;

State::State() {
	this->running = false;
	this->hidden = false;
}

State* State::inst() {
	if (instance == 0) {
		instance = new State();
	}
	return instance;
}

bool State::isRunning() {
	return this->running;
}

void State::setRunning(bool value) {
	this->running = value;
}

bool State::isHidden() {
	return this->hidden;
}

void State::setHidden(bool value) {
	this->hidden = value;
}

State::~State() {
	// TODO Auto-generated destructor stub
}

}
