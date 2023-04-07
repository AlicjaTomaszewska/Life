#include <iostream>
#include "SosnowskysHogweed.h"

using namespace std;

SosnowskysHogweed::SosnowskysHogweed(int coordinateX, int coordinateY, World* world) : Plant(coordinateX, coordinateY, world, STRENGTH_OF_SOSNOWSKYS_HOGWEED, INITIATIVE_OF_SOSNOWSKYS_HOGWEED, LETTER_OF_SOSNOWSKYS_HOGWEED, NAME_OF_SOSNOWSKYS_HOGWEED)
{
}

SosnowskysHogweed::SosnowskysHogweed(World* world) : Plant(world, STRENGTH_OF_SOSNOWSKYS_HOGWEED, INITIATIVE_OF_SOSNOWSKYS_HOGWEED, LETTER_OF_SOSNOWSKYS_HOGWEED, NAME_OF_SOSNOWSKYS_HOGWEED)
{
}

SosnowskysHogweed::~SosnowskysHogweed()
{
}

void SosnowskysHogweed::draw()
{
	cout << LETTER_OF_SOSNOWSKYS_HOGWEED;
}

void SosnowskysHogweed::basicAction(char whatDirection)
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

void SosnowskysHogweed::actionForSosnowskysHogweed()
{
	int posX = this->GetX();
	int posY = this->GetY();
	Organism* orgOnPos1 = this->world->GetOrganism(posX - 1, posY);
	Organism* orgOnPos2 = this->world->GetOrganism(posX + 1, posY);
	Organism* orgOnPos3 = this->world->GetOrganism(posX, posY - 1);
	Organism* orgOnPos4 = this->world->GetOrganism(posX, posY + 1);
	Organism* orgOnPos5 = this->world->GetOrganism(posX - 1, posY - 1);
	Organism* orgOnPos6 = this->world->GetOrganism(posX + 1, posY + 1);
	Organism* orgOnPos7 = this->world->GetOrganism(posX - 1, posY + 1);
	Organism* orgOnPos8 = this->world->GetOrganism(posX + 1, posY - 1);
	if (orgOnPos1 != NULL && orgOnPos1->GetInitiative() != 0)
	{
		orgOnPos1->SetAlive(false);
		cout << orgOnPos1->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos2 != NULL && orgOnPos2->GetInitiative() != 0)
	{
		orgOnPos2->SetAlive(false);
		cout << orgOnPos2->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos3 != NULL && orgOnPos3->GetInitiative() != 0)
	{
		orgOnPos3->SetAlive(false);
		cout << orgOnPos3->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos4 != NULL && orgOnPos4->GetInitiative() != 0)
	{
		orgOnPos4->SetAlive(false);
		cout << orgOnPos4->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos5 != NULL && orgOnPos5->GetInitiative() != 0)
	{
		orgOnPos5->SetAlive(false);
		cout << orgOnPos5->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos6 != NULL && orgOnPos6->GetInitiative() != 0)
	{
		orgOnPos6->SetAlive(false);
		cout << orgOnPos6->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos7 != NULL && orgOnPos7->GetInitiative() != 0)
	{
		orgOnPos7->SetAlive(false);
		cout << orgOnPos7->GetName() << " was killed by " << this->GetName() << endl;
	}
	else if (orgOnPos8 != NULL && orgOnPos8->GetInitiative() != 0)
	{
		orgOnPos8->SetAlive(false);
		cout << orgOnPos8->GetName() << " was killed by " << this->GetName() << endl;
	}
}

void SosnowskysHogweed::action(char whatDirection)
{
	basicAction(whatDirection);
	actionForSosnowskysHogweed();
}