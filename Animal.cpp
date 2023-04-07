#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(int coordinateX, int coordinateY, World* world, int strength, int initiative, char letter, string name) : Organism(coordinateX, coordinateY, world, strength, initiative, letter, name)
{
}

Animal::Animal(World* world, int strength, int initiative, char letter, string name) : Organism(world, strength, initiative, letter, name)
{
}

Animal::~Animal()
{
}

void Animal::action(char whichDirection)
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
	else
	{
		this->collision(orgOnPos);
	}
	this->SetAge(this->GetAge() + 1);		
}