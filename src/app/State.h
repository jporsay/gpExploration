#ifndef STATE_H_
#define STATE_H_

#include <string>
#include <SFML/Graphics.hpp>
namespace app {

class State {
private:
	static State* instance;

	bool running;
	bool hidden;
	State();
public:
	static State* inst();
	static sf::RenderWindow* mainWindow;
	bool isRunning();
	void setRunning(bool value);
	bool isHidden();
	void setHidden(bool value);
	virtual ~State();
};

}

#endif
