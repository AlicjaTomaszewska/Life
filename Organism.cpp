#include <iostream>
#include "Organism.h"
using namespace std;

Organism::Organism(int coordinateX, int coordinateY, World* world, int strength, int initiative, char letter, string name) :
	Organism(world, strength, initiative, letter, name)
{
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
}

Organism::Organism(World* world, int strength, int initiative, char letter, string name)
{
	this->letter = letter;
	this->name = name;
	this->strength = strength;
	this->initiative = initiative;
	this->world = world;
	this->alive = true;
	this->age = 1;
	DrawingCoordinates(this->coordinateX, this->coordinateY);
}

Organism::~Organism()
{
}

int Organism::GetX() const
{
	return coordinateX;
}

int Organism::GetY() const
{
	return coordinateY;
}

int Organism::GetStrength()
{
	return strength;
}

int Organism::GetInitiative()
{
	return initiative;
}

int Organism::GetLetter()
{
	return letter;
}

int Organism::GetAge()
{
	return age;
}

string Organism::GetName()
{
	return name;
}

bool Organism::GetAlive()
{
	return alive;
}

void Organism::SetX(int coordinateX)
{
	this->coordinateX = coordinateX;
}

void Organism::SetY(int coordinateY)
{
	this->coordinateY = coordinateY;
}

void Organism::SetStrength(int strength)
{
	this->strength = strength;
}

void Organism::SetInitiative(int initiative)
{
	this->initiative = initiative;
}

void Organism::SetAlive(bool alive)
{
	this->alive = alive;
}

void Organism::SetAge(int age)
{
	this->age = age;
}

void Organism::DrawingCoordinates(int& x, int& y)
{
	bool isPlaceFree = false;
	while (!isPlaceFree) {
		isPlaceFree = true;
		x = rand() % this->world->GetN();
		y = rand() % this->world->GetM();
		if (this->world->GetOrganism(x, y) != NULL)
		{
			isPlaceFree = false;
			break;
		}
	}
}

void Organism ::NewDirection(Organism* secondOrg)
{
	int newDir = rand() % HOW_MANY_DIRECTIONS;
	int posX = this->GetX();
	int posY = this->GetY();
	if (this->world->GetOrganism(posX, posY - 1) == NULL || this->world->GetOrganism(posX, posY + 1) == NULL || this->world->GetOrganism(posX - 1, posY) == NULL || this->world->GetOrganism(posX + 1, posY) == NULL || this->world->GetOrganism(posX + 1, posY + 1) == NULL || this->world->GetOrganism(posX - 1, posY - 1) == NULL || this->world->GetOrganism(posX + 1, posY - 1) == NULL || this->world->GetOrganism(posX - 1, posY + 1) == NULL)
	{
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
			this->NewDirection(secondOrg);
		}
	}
	else
	{
		cout << "Antelope was killed because it was no place for escape" << endl;
		secondOrg->alive = false;
	}
}

void Organism::collision(Organism* secondOrg)
{
	if (this->letter == secondOrg->letter)
	{
		int childX = secondOrg->coordinateX;
		int childY = secondOrg->coordinateY;
		int dir = rand() % HOW_MANY_DIRECTIONS;

		if (dir == 0 && childY > 0)
		{
			childY--;
		}
		if (dir == 1 && childY < 24)
		{
			childY++;
		}
		if (dir == 2 && childX > 0)
		{
			childX--;
		}
		if (dir == 3 && childX < 24)
		{
			childX++;
		}
		if (dir == 4 && childX > 0 && childY < 24)
		{
			childY++;
			childX--;
		}
		if (dir == 5 && childX < 24 && childY > 0)
		{
			childY--;
			childX++;
		}
		if (dir == 6 && childX > 0 && childY > 0)
		{
			childY--;
			childX--;
		}
		if (dir == 7 && childX < 24 && childY < 24)
		{
			childY++;
			childX++;
		}

		Organism* orgOnPos = this->world->GetOrganism(childX, childY);

		if (orgOnPos != NULL)
		{
			cout << this->name << " was killed just after birth because of lack of place in the flock" << endl;
		}
		else
		{
			this->world->CreateOrganism(childX, childY, this->letter);
		}
	}
	else if (this->strength >= secondOrg->strength)
	{
		if (secondOrg->letter != 'T' || (secondOrg->letter == 'T' && this->strength >= 5))
		{
			int antelopeRand = rand() % 2;
			if (secondOrg->letter != 'A' || (secondOrg->letter == 'A' && antelopeRand == 0))
			{
				secondOrg->alive = false;
				this->coordinateX = secondOrg->coordinateX;
				this->coordinateY = secondOrg->coordinateY;
				if (secondOrg->letter == 'u')
				{
					this->strength = this->strength + 3;
				}
				cout << secondOrg->name << " was killed by " << this->name << endl;
				if (secondOrg->letter == 'b' || secondOrg->letter == 'h')
				{
					this->alive = false;
					cout << this->name << " was killed by " << secondOrg->name << endl;
				}
			}
			else
			{
				NewDirection(secondOrg);
			}
		}
	}
	else
	{
		this->alive = false;
		cout << this->name << " was killed by " << secondOrg->name << endl;
	}
}

string Organism::save() {
	string organism;
	organism += GetLetter();
	organism += " " + to_string(GetX());
	organism += " " + to_string(GetY());
	organism += " " + to_string(GetAge());
	organism += " " + to_string(GetStrength()) + "\n";
	return organism;
}



