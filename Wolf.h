#pragma once
#include "Animal.h"
#include "World.h"
#include "Organism.h"
#include <string>
#define LETTER_OF_WOLF 'W'
#define STRENGTH_OF_WOLF 9
#define INITIATIVE_OF_WOLF 5
#define NAME_OF_WOLF "wolf"

class Wolf : public Animal
{
public:
	Wolf(World* world);
	Wolf(int coordinateX, int coordinateY, World* world);
	~Wolf();
	void draw();
};
