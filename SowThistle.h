#pragma once
#include "Plant.h"
#define LETTER_OF_SOW_THISTLE 's'
#define NAME_OF_SOW_THISTLE "sow thistle"
#define STRENGTH_OF_SOW_THISTLE 0
#define INITIATIVE_OF_SOW_THISTLE 0
#define HOW_MANY_SEEDS 3

class SowThistle : public Plant
{
public:
	SowThistle(World* world);
	SowThistle(int coordinateX, int coordinateY, World* world);
	~SowThistle();
	void action(char whichDirection) override;
	void draw();
};