#ifndef GRAPHICSETTINGS_H_
#define GRAPHICSETTINGS_H_

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
