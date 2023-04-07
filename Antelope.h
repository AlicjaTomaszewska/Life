#pragma once
#include "Animal.h"
#define LETTER_OF_ANTELOPE 'A'
#define NAME_OF_ANTELOPE "antelope"
#define STRENGTH_OF_ANTELOPE 4
#define INITIATIVE_OF_ANTELOPE 4
#define MAX_GRID_FIELD_FOR_ANTELOPE 23
#define MIN_GRID_FIELD_FOR_ANTELOPE 1

class Antelope : public Animal
{
public:
	Antelope(World* world);
	Antelope(int coordinateX, int coordinateY, World* world);
	~Antelope();
	void action(char whichDirection) override;
	void draw();
};
