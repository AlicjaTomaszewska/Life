#include <iostream>
#include "SowThistle.h"

using namespace std;

SowThistle::SowThistle(int coordinateX, int coordinateY, World* world) : Plant(coordinateX, coordinateY, world, STRENGTH_OF_SOW_THISTLE, INITIATIVE_OF_SOW_THISTLE, LETTER_OF_SOW_THISTLE, NAME_OF_SOW_THISTLE)
{
}

SowThistle::SowThistle(World* world) : Plant(world, STRENGTH_OF_SOW_THISTLE, INITIATIVE_OF_SOW_THISTLE, LETTER_OF_SOW_THISTLE, NAME_OF_SOW_THISTLE)
{
}

SowThistle::~SowThistle()
{
}

void SowThistle::action(char whichDirection)
{
	int counter = 0;
	while (counter < HOW_MANY_SEEDS)
	{
		int dirOfNewPlant = rand() % HOW_MANY_DIRECTIONS;
		int posX = this->GetX();
		int posY = this->GetY();
		int probability = rand() % 100;

		if (probability <= PROBABILITY_TO_SIEVE)
		{
			if (dirOfNewPlant == 0 && posY > MIN_GRID_FIELD)
			{
				posY--;
			}
			if (dirOfNewPlant == 1 && posY < MAX_GRID_FIELD)
			{
				posY++;
			}
			if (dirOfNewPlant == 2 && posX > MIN_GRID_FIELD)
			{
				posX--;
			}
			if (dirOfNewPlant == 3 && posX < MAX_GRID_FIELD)
			{
				posX++;
			}
			if (dirOfNewPlant == 4 && posX > MIN_GRID_FIELD && posY < MAX_GRID_FIELD)
			{
				posY++;
				posX--;
			}
			if (dirOfNewPlant == 5 && posX < MAX_GRID_FIELD && posY > MIN_GRID_FIELD)
			{
				posY--;
				posX++;
			}
			if (dirOfNewPlant == 6 && posX > MIN_GRID_FIELD && posY > MIN_GRID_FIELD)
			{
				posY--;
				posX--;
			}
			if (dirOfNewPlant == 7 && posX < MAX_GRID_FIELD && posY < MAX_GRID_FIELD)
			{
				posY++;
				posX++;
			}

			Organism* orgOnPos = this->world->GetOrganism(posX, posY);

			if (orgOnPos == NULL)
			{
				this->world->CreateOrganism(posX, posY, GetLetter());
			}
			else
			{
				cout << "Place for new " << GetName() << " was taken" << endl;
			}
		}
		counter++;
	}
	this->SetAge(this->GetAge() + 1);
}

void SowThistle::draw()
{
	cout << LETTER_OF_SOW_THISTLE;
}