#include "Parser.h"
#include "../app/Settings.h"

namespace parser {

Parser::Parser() {
	// TODO Auto-generated constructor stub

}

void Parser::setFile(std::string file) {
	this->file = app::Settings::inst()->getModelPath() + file;
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

}
