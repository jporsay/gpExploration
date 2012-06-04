#ifndef PARSER_H_
#define PARSER_H_

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
