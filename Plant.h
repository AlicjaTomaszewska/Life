#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Organism.h"
#define PROBABILITY_TO_SIEVE 30
using namespace std;

class Plant : public Organism
{
public:
	Plant(int coordinateX, int coordinateY, World* world, int strength, int initiative, char letter, string name);
	Plant(World* world, int strength, int initiative, char letter, string name);
	virtual ~Plant();
	void action(char whichDirection) override;
	virtual void draw() = 0;
};