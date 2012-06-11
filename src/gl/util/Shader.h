#ifndef GL_UTIL_SHADER_H
#define GL_UTIL_SHADER_H

#include <gl/glew.h>
#include "../../util/string.h"
#include "../../util/Logger.h"
#include "Helper.h"

namespace gl {
namespace util {

class Shader {
public:
	Shader();
	virtual ~Shader();
	static GLuint create(GLenum type, std::string fileName);
};

}
}
#endif
