#pragma once
#include "Animal.h"
#define LETTER_OF_TURTLE 'T'
#define NAME_OF_TURTLE "turtle"
#define STRENGTH_OF_TURTLE 2
#define INITIATIVE_OF_TURTLE 1

class Turtle : public Animal
{
public:
	Turtle(World* world);
	Turtle(int coordinateX, int coordinateY, World* world);
	~Turtle();
	void action(char whichDirection) override;
	void draw();
};
