#pragma once
#include "Animal.h"
#define LETTER_OF_HUMAN 'H'
#define NAME_OF_HUMAN "human"
#define STRENGTH_OF_HUMAN 5
#define INITIATIVE_OF_HUMAN 4

class Human : public Animal
{
	int roundForAntylopesSpeed = -5;
	int antylopeSpeedActivated = 0;
public:
	Human(World* world);
	Human(int coordinateX, int coordinateY, World* world);
	~Human();
	void action(char whichDirection) override;
	void draw();
	void AntylopesSpeed(char whichDirection);
};