#pragma once
#include "Plant.h"
#define LETTER_OF_GRASS 'g'
#define NAME_OF_GRASS "grass"
#define STRENGTH_OF_GRASS 0
#define INITIATIVE_OF_GRASS 0

class Grass : public Plant
{
public:
	Grass(World* world);
	Grass(int coordinateX, int coordinateY, World* world);
	~Grass();
	void draw();
};