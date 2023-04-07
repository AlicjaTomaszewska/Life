#include <iostream>
#include "Fox.h"

using namespace std;

Fox::Fox(int coordinateX, int coordinateY, World* world) : Animal(coordinateX, coordinateY, world, STRENGTH_OF_FOX, INITIATIVE_OF_FOX, LETTER_OF_FOX, NAME_OF_FOX)
{
}

Fox::Fox(World* world) : Animal(world, STRENGTH_OF_FOX, INITIATIVE_OF_FOX, LETTER_OF_FOX, NAME_OF_FOX)
{
}

Fox::~Fox()
{
}

void Fox::action(char whichDirection)
{
	int newDir = rand() % HOW_MANY_DIRECTIONS;
	int posX = this->GetX();
	int posY = this->GetY();

	if (newDir == 0 && posY > MIN_GRID_FIELD)
	{
		posY--;
	}
	if (newDir == 1 && posY < MAX_GRID_FIELD)
	{
		posY++;
	}
	if (newDir == 2 && posX > MIN_GRID_FIELD)
	{
		posX--;
	}
	if (newDir == 3 && posX < MAX_GRID_FIELD)
	{
		posX++;
	}
	if (newDir == 4 && posX > MIN_GRID_FIELD && posY < MAX_GRID_FIELD)
	{
		posY++;
		posX--;
	}
	if (newDir == 5 && posX < MAX_GRID_FIELD && posY > MIN_GRID_FIELD)
	{
		posY--;
		posX++;
	}
	if (newDir == 6 && posX > MIN_GRID_FIELD && posY > MIN_GRID_FIELD)
	{
		posY--;
		posX--;
	}
	if (newDir == 7 && posX < MAX_GRID_FIELD && posY < MAX_GRID_FIELD)
	{
		posY++;
		posX++;
	}

	Organism* orgOnPos = this->world->GetOrganism(posX, posY);

	if (orgOnPos == NULL)
	{
		this->SetX(posX);
		this->SetY(posY);
	}
	else if(orgOnPos->GetLetter() == LETTER_OF_FOX || orgOnPos->GetStrength() <= STRENGTH_OF_FOX)
	{
		this->collision(orgOnPos);
	}

	this->SetAge(this->GetAge() + 1);
}

void Fox::draw()
{
	cout << LETTER_OF_FOX;
}
