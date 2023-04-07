#include <iostream>
#include "Plant.h"
using namespace std;

Plant::Plant(int coordinateX, int coordinateY, World* world, int strength, int initiative, char letter, string name) : Organism(coordinateX, coordinateY, world, strength, initiative, letter, name)
{
	
}

Plant::Plant(World* world, int strength, int initiative, char letter, string name) : Organism(world, strength, initiative, letter, name)
{
	
}


Plant::~Plant()
{

}

void Plant::action(char whichDirection)
{
	int dirOfNewPlant = rand() % HOW_MANY_DIRECTIONS;
	int posX = this->GetX();
	int posY = this->GetY();
	int probability = rand() % 100;

	this->SetAge(this->GetAge() + 1);

	if (probability > PROBABILITY_TO_SIEVE)
		return;
	
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