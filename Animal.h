#pragma once
#include <iostream>
#include <string>
#include "Organism.h"
using namespace std;

class Animal : public Organism
{
public:
	Animal(int coordinateX, int coordinateY, World* world, int strength, int initiative, char letter, string name);
	Animal(World* world, int strength, int initiative, char letter, string name);
	virtual ~Animal();
	void action(char whichDirection) override;
	virtual void draw() = 0;
};