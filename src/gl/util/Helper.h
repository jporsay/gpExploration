#ifndef HELPER_H_
#define HELPER_H_

#include <gl/glew.h>
#include "../../util/string.h"
#include "../../util/Logger.h"

namespace gl {
namespace util {

enum {
	GL_ATTRIB_MVP = 0,
	GL_ATTRIB_VERTEX,
	GL_ATTRIB_NORMAL,
	GL_ATTRIB_TEXTURE
};

void printShaderOrProgramLog(GLuint object);

}
}


#endif
