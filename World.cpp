#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector> 
#include <algorithm>
#include "World.h"
#include "Organism.h"
#include "Wolf.h"
#include "Human.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskysHogweed.h"

using namespace std;

World::World(int N, int M)
{
	srand(time(NULL));
	this->N = N;
	this->M = M;
	organisms.push_back(new Human(this));
	organisms.push_back(new Wolf(this));
	organisms.push_back(new Wolf(this));
	organisms.push_back(new Guarana(this));
	organisms.push_back(new Guarana(this));
	organisms.push_back(new Belladonna(this));
	organisms.push_back(new Belladonna(this));
	organisms.push_back(new SosnowskysHogweed(this));
	organisms.push_back(new SosnowskysHogweed(this));
	organisms.push_back(new Sheep(this));
	organisms.push_back(new Sheep(this));
	organisms.push_back(new Fox(this));
	organisms.push_back(new Fox(this));
	organisms.push_back(new SowThistle(this));
	organisms.push_back(new SowThistle(this));
	organisms.push_back(new Turtle(this));
	organisms.push_back(new Turtle(this));
	organisms.push_back(new Antelope(this));
	organisms.push_back(new Antelope(this));
	organisms.push_back(new Grass(this));
	organisms.push_back(new Grass(this));
}

	

World::~World()
{
}

int World::GetM()
{
	return M;
}

int World::GetN()
{
	return N;
}

int World::GetOrganismsSize()
{
	return organisms.size();
}

bool World::GetAlive(int x, int y)
{
	for (int z = 0; z < organisms.size(); z++)
	{
		if (organisms[z]->GetAlive())
		{
			return true;
		}
	}
	for (int z = 0; z < newBornOrganisms.size(); z++)
	{
		if (newBornOrganisms[z]->GetAlive())
		{
			return true;
		}
	}
	return false;
}

void World::SetM(int M)
{
	this->M = M;
}

void World::SetN(int N)
{
	this->N = N;
}

void World::makeTurn(char whichDirection)
{
	sort(organisms.begin(), organisms.end(), [](Organism* i, Organism* j)
		{
			if (i->GetInitiative() == j->GetInitiative())
			{
				return i->GetAge() > j->GetAge();
			}
			return i->GetInitiative() > j->GetInitiative();
		});

	for (int z = 0; z < organisms.size(); z++)
	{
		if (organisms[z]->GetAlive())
			organisms[z]->action(whichDirection);
	}

	vector<int> deadOrganisms;

	for (int i = 0; i < organisms.size(); i++)
	{
		if (!organisms[i]->GetAlive())
			deadOrganisms.push_back(i);
	}

	for (int i = deadOrganisms.size() - 1; i >= 0; i--)
	{
		organisms.erase(organisms.begin() + deadOrganisms[i]);
	}

	for (int i = 0; i < newBornOrganisms.size(); i++)
	{
		if (newBornOrganisms[i]->GetAlive())
			organisms.push_back(newBornOrganisms[i]);
	}

	newBornOrganisms.clear();
}

void World::drawMenu() {
	cout << "Alicja Tomaszewska 191678:" << endl;
	cout << "----------------------------------------" << endl;
	cout << "| Z - SAVE | L - LOAD STATE | Q - EXIT |" << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void World::drawWorld()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Organism* organismOnPosition = GetOrganism(j, i);
			if (organismOnPosition != NULL)
				organismOnPosition->draw();
			else
				cout << ".";
		}
		cout << endl;
	}
}

void World:: saveState() {
	fstream file;
	file.open("./save.txt", ios::out);
	if (file.good())
	{
		file << to_string(N) + " " + to_string(M) + "\n";
		file << to_string(organisms.size()) + "\n";
		for (int i = 0; i < organisms.size(); i++)
		{
			file << organisms[i]->save();
		}

		file.close();
	}
	else
	{
		cout << "Not able to open a file!" << endl;
	}
}

void World::loadState() {

	organisms.clear();
	newBornOrganisms.clear();
	fstream file;
	file.open("./save.txt", ios::in);
	if (file.good())
	{
		int N;
		int M;
		int organismSize;
		file >> N >> M;
		file >> organismSize;
		this->N = N;
		this->M = M;

		for (int i = 0; i < organismSize; i++)
		{
			char letter;
			int x;
			int y;
			int strength;
			int age;
			file >> letter >> x >> y >> age >> strength;
			CreateOrganism(x, y, letter);
			newBornOrganisms[i]->SetAge(age);
			newBornOrganisms[i]->SetStrength(strength);
		}
		file.close();
	}
	else {
		cout << "Not able to open a file!" << endl;
	}
}


void World::CreateOrganism(int posX, int posY, char letter)
{
	if (letter == 'W')
	{
		newBornOrganisms.push_back(new Wolf(posX, posY, this));
		cout << "New wolf is born!" << endl;
	}
	if (letter == 'S')
	{
		newBornOrganisms.push_back(new Sheep(posX, posY, this));
		cout << "New sheep is born!" << endl;
	}
	if (letter == 'F')
	{
		newBornOrganisms.push_back(new Fox(posX, posY, this));
		cout << "New fox is born!" << endl;
	}
	if (letter == 'T')
	{
		newBornOrganisms.push_back(new Turtle(posX, posY, this));
		cout << "New turtle is born!" << endl;
	}
	if (letter == 'A')
	{
		newBornOrganisms.push_back(new Antelope(posX, posY, this));
		cout << "New antelope is born!" << endl;
	}
	if (letter == 'g')
	{
		newBornOrganisms.push_back(new Grass(posX, posY, this));
		cout << "New grass is sown!" << endl;
	}
	if (letter == 's')
	{
		newBornOrganisms.push_back(new SowThistle(posX, posY, this));
		cout << "New sow thistle is sown!" << endl;
	}
	if (letter == 'u')
	{
		newBornOrganisms.push_back(new Guarana(posX, posY, this));
		cout << "New guarana is sown!" << endl;
	}
	if (letter == 'b')
	{
		newBornOrganisms.push_back(new Belladonna(posX, posY, this));
		cout << "New belladonna is sown!" << endl;
	}
	if (letter == 'h')
	{
		newBornOrganisms.push_back(new SosnowskysHogweed(posX, posY, this));
		cout << "New sosnowsyky's hogweed is sown!" << endl;
	}
	if (letter == 'H')
	{
		newBornOrganisms.push_back(new Human(posX, posY, this));
	}
}

Organism* World::GetOrganism(int x, int y)
{
	for (int z = 0; z < organisms.size(); z++)
	{
		if (organisms[z]->GetAlive() && organisms[z]->GetX() == x && organisms[z]->GetY() == y)
		{
			return organisms[z];
		}
	}
	for (int z = 0; z < newBornOrganisms.size(); z++)
	{
		if (newBornOrganisms[z]->GetAlive() && newBornOrganisms[z]->GetX() == x && newBornOrganisms[z]->GetY() == y)
		{
			return newBornOrganisms[z];
		}
	}
	return NULL;
}






