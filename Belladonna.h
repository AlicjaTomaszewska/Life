#pragma once
#include "Plant.h"
#define LETTER_OF_BELLADONNA 'b'
#define NAME_OF_BELLADONNA "belladonna"
#define STRENGTH_OF_BELLADONNA 99
#define INITIATIVE_OF_BELLADONNA 0

class Belladonna : public Plant
{
public:
	Belladonna(World* world);
	Belladonna(int coordinateX, int coordinateY, World* world);
	~Belladonna();
	void draw();
};
