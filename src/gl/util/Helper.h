#ifndef GL_UTIL_HELPER_H
#define GL_UTIL_HELPER_H

#include <gl/glew.h>
#include "../../util/string.h"
#include "../../util/Logger.h"

namespace gl {
namespace util {

enum {
	GL_ATTRIB_VERTEX = 0,
	GL_ATTRIB_NORMAL,
	GL_ATTRIB_TEXTURE
};

void printShaderOrProgramLog(GLuint object);

}
}


#endif
