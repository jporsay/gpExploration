#ifndef MODEL_TEXTURE_H
#define MODEL_TEXTURE_H

#include <string>
#include <SFML/Graphics/Image.hpp>
namespace model {

class Texture {
private:
	std::string fileName;
	sf::Image* image;
	unsigned int width;
	unsigned int height;
public:
	Texture();
	void setFileName(std::string fileName);
	void setSFImage(sf::Image* image);
	unsigned int getWidth();
	unsigned int getHeight();
	const uint8_t* getPixelPtr();
	std::string getFileName();
	virtual ~Texture();
};

}
#endif
