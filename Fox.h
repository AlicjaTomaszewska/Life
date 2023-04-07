#pragma once
#include "Animal.h"
#define LETTER_OF_FOX 'F'
#define NAME_OF_FOX "fox"
#define STRENGTH_OF_FOX 3
#define INITIATIVE_OF_FOX 7  

class Fox : public Animal
{
public:
	Fox(World* world);
	Fox(int coordinateX, int coordinateY, World* world);
	~Fox();
	void action(char whichDirection) override;
	void draw();
};
