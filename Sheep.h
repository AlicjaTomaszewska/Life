#pragma once
#include "Animal.h"
#define LETTER_OF_SHEEP 'S'
#define NAME_OF_SHEEP "sheep"
#define STRENGTH_OF_SHEEP 4
#define INITIATIVE_OF_SHEEP 4

class Sheep : public Animal
{
public:
	Sheep(World* world);
	Sheep(int coordinateX, int coordinateY, World* world);
	~Sheep();
	void draw();
};
