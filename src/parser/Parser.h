#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include "../object/Object.h"
namespace parser {

class Parser {
protected:
	Parser();
	std::string file;
public:
	virtual object::Object* parse() = 0;
	virtual void setFile(std::string file);
	virtual ~Parser();
};

}
#endif
