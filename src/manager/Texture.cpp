#include "Texture.h"
#include "../app/Settings.h"

namespace manager {

Texture* Texture::instance = 0;

Texture::Texture() {
}

Texture* Texture::inst() {
	if (Texture::instance == 0) {
		Texture::instance = new Texture();
	}
	return Texture::instance;
}

model::Texture* Texture::get(std::string fileName) {
	std::map<std::string, model::Texture*>::iterator it = this->textures.find(fileName);
	if (it != this->textures.end()) {
		return (*it).second;
	}
	return this->addTexture(fileName);
}

model::Texture* Texture::addTexture(std::string fileName) {
	sf::Image* img = new sf::Image();
	model::Texture* t = new model::Texture();
	img->loadFromFile(app::Settings::inst()->getTexturePath() + utilities::toLower(fileName));
	t->setFileName(fileName);
	t->setSFImage(img);
	this->textures.insert(std::pair<std::string, model::Texture*>(fileName, t));
	return t;
}

Texture::~Texture() {
}

}
