#include "GraphicSettings.h"

namespace app {

unsigned int GraphicSettings::screenHeight = 0;
unsigned int GraphicSettings::screenWidth = 0;
GraphicSettings* GraphicSettings::instance = 0;

GraphicSettings* GraphicSettings::inst() {
	if (instance == 0) {
		instance = new GraphicSettings();
	}
	return instance;
}

GraphicSettings::GraphicSettings() {
	// TODO Auto-generated constructor stub

}

GraphicSettings::~GraphicSettings() {
	// TODO Auto-generated destructor stub
}

}
