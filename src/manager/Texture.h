#ifndef MANAGER_TEXTURE_H
#define MANAGER_TEXTURE_H

#include <map>
#include <string>
#include <SFML/Graphics/Image.hpp>
#include "../model/Texture.h"
#include "../util/string.h"

namespace manager {

class Texture {
private:
	std::map<std::string, model::Texture*> textures;
	Texture();
	static Texture* instance;
public:
	virtual ~Texture();
	static Texture* inst();
	model::Texture* get(std::string fileName);
	model::Texture* addTexture(std::string fileName);
};

}
#endif
