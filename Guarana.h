#pragma once
#include "Plant.h"
#define LETTER_OF_GUARANA 'u'
#define NAME_OF_GUARANA "guarana"
#define STRENGTH_OF_GUARANA 0
#define INITIATIVE_OF_GUARANA 0

class Guarana : public Plant
{
public:
	Guarana(World* world);
	Guarana(int coordinateX, int coordinateY, World* world);
	~Guarana();
	void draw();
};
