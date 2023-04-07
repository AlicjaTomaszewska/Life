#include <iostream>
#include "Turtle.h"

using namespace std;

Turtle::Turtle(int coordinateX, int coordinateY, World* world) : Animal(coordinateX, coordinateY, world, STRENGTH_OF_TURTLE, INITIATIVE_OF_TURTLE, LETTER_OF_TURTLE, NAME_OF_TURTLE)
{
}

Turtle::Turtle(World* world) : Animal(world, STRENGTH_OF_TURTLE, INITIATIVE_OF_TURTLE, LETTER_OF_TURTLE, NAME_OF_TURTLE)
{
}

Turtle::~Turtle()
{
}

void Turtle::action(char whichDirection)
{
	int newDir = rand() % HOW_MANY_DIRECTIONS;
	int chancesToStayInTheSamePlace = rand() % 4;
	int posX = this->GetX();
	int posY = this->GetY();
	int changeOfPlace = 0;
	if (chancesToStayInTheSamePlace == 3)
	{
		if (newDir == 0 && posY > MIN_GRID_FIELD)
		{
			posY--;
			changeOfPlace++;
		}
		else if (newDir == 1 && posY < MAX_GRID_FIELD)
		{
			posY++;
			changeOfPlace++;
		}
		else if (newDir == 2 && posX > MIN_GRID_FIELD)
		{
			posX--;
			changeOfPlace++;
		}
		else if (newDir == 3 && posX < MAX_GRID_FIELD)
		{
			posX++;
			changeOfPlace++;
		}
		else if (newDir == 4 && posX > 0 && posY < MAX_GRID_FIELD)
		{
			posY++;
			posX--;
			changeOfPlace++;
		}
		else if (newDir == 5 && posX < MAX_GRID_FIELD && posY > MIN_GRID_FIELD)
		{
			posY--;
			posX++;
			changeOfPlace++;
		}
		else if (newDir == 6 && posX > MIN_GRID_FIELD && posY > MIN_GRID_FIELD)
		{
			posY--;
			posX--;
			changeOfPlace++;
		}
		else if (newDir == 7 && posX < MAX_GRID_FIELD && posY < MAX_GRID_FIELD)
		{
			posY++;
			posX++;
			changeOfPlace++;
		}
		Organism* orgOnPos = this->world->GetOrganism(posX, posY);

		if (orgOnPos == NULL || changeOfPlace == 0)
		{
			this->SetX(posX);
			this->SetY(posY);
		}
		else
		{
			this->collision(orgOnPos);
		}
	}
	this->SetAge(this->GetAge() + 1);
}

void Turtle::draw()
{
	cout << LETTER_OF_TURTLE;
}