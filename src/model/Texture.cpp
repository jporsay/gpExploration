#include "Texture.h"

namespace model {

Texture::Texture() {
}
void Texture::setFileName(std::string fileName) {
	this->fileName = fileName;
}
void Texture::setSFImage(sf::Image* image) {
	sf::Vector2u size = image->getSize();
	this->height = size.y;
	this->width = size.x;
	image->flipVertically();
	this->image = image;
}
unsigned int Texture::getWidth() {
	return this->width;
}
unsigned int Texture::getHeight() {
	return this->height;
}
const uint8_t* Texture::getPixelPtr() {
	return this->image->getPixelsPtr();
}
std::string Texture::getFileName() {
	return this->fileName;
}

Texture::~Texture() {
}

}
