#ifndef STATE_H_
#define STATE_H_

#include <string>

namespace game {

class State {
private:
	static State* instance;

	bool running;
	bool hidden;
	State();
public:
	static State* inst();
	bool isRunning();
	void setRunning(bool value);
	bool isHidden();
	void setHidden(bool value);
	virtual ~State();
};

}

#endif
