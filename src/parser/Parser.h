#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <string>
#include "../model/Model.h"
namespace parser {

class Parser {
protected:
	Parser();
	std::string file;
public:
	virtual model::Model* parse() = 0;
	virtual void setFile(std::string file);
	virtual ~Parser();
};

}
#endif
