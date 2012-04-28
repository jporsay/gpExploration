#include "Parser.h"
#include "../game/Settings.h"

namespace parser {

Parser::Parser() {
	// TODO Auto-generated constructor stub

}

void Parser::setFile(std::string file) {
	this->file = game::Settings::inst()->getModelPath() + file;
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

}
