#include <iostream>
#include "Antelope.h"

using namespace std;

Antelope::Antelope(int coordinateX, int coordinateY, World* world) : Animal(coordinateX, coordinateY, world, STRENGTH_OF_ANTELOPE, INITIATIVE_OF_ANTELOPE, LETTER_OF_ANTELOPE, NAME_OF_ANTELOPE)
{
}

Antelope::Antelope(World* world) : Animal(world, STRENGTH_OF_ANTELOPE, INITIATIVE_OF_ANTELOPE, LETTER_OF_ANTELOPE, NAME_OF_ANTELOPE)
{
}

Antelope::~Antelope()
{
}

void Antelope::action(char whichDirection)
{
	int newDir = rand() % HOW_MANY_DIRECTIONS;
	int posX = this->GetX();
	int posY = this->GetY();

	if (newDir == 0 && posY > MIN_GRID_FIELD_FOR_ANTELOPE)
	{
		posY = posY - 2;
	}
	if (newDir == 1 && posY < MAX_GRID_FIELD_FOR_ANTELOPE)
	{
		posY = posY + 2;
	}
	if (newDir == 2 && posX > MIN_GRID_FIELD_FOR_ANTELOPE)
	{
		posX = posX - 2;
	}
	if (newDir == 3 && posX < MAX_GRID_FIELD_FOR_ANTELOPE)
	{
		posX = posX + 2;
	}
	if (newDir == 4 && posX > MIN_GRID_FIELD_FOR_ANTELOPE && posY < MAX_GRID_FIELD_FOR_ANTELOPE)
	{
		posY = posY + 2;
		posX = posX - 2;
	}
	if (newDir == 5 && posX < MAX_GRID_FIELD_FOR_ANTELOPE && posY > MIN_GRID_FIELD_FOR_ANTELOPE)
	{
		posY = posY - 2;
		posX = posX + 2;
	}
	if (newDir == 6 && posX > MIN_GRID_FIELD_FOR_ANTELOPE && posY > MIN_GRID_FIELD_FOR_ANTELOPE)
	{
		posY = posY - 2;
		posX = posX - 2;
	}
	if (newDir == 7 && posX < MAX_GRID_FIELD_FOR_ANTELOPE && posY < MAX_GRID_FIELD_FOR_ANTELOPE)
	{
		posY = posY + 2;
		posX = posX + 2;
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

void Antelope::draw()
{
	cout << LETTER_OF_ANTELOPE;
}
