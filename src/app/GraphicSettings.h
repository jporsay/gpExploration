#ifndef APP_GRAPHICSETTINGS_H
#define APP_GRAPHICSETTINGS_H

namespace app {

class GraphicSettings {
private:
	GraphicSettings();
	static GraphicSettings* instance;
public:
	static unsigned int screenWidth;
	static unsigned int screenHeight;
	static GraphicSettings* inst();
	virtual ~GraphicSettings();
};

}
#endif
