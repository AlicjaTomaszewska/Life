#pragma once
#include <iostream>
#include <vector> 
#include <fstream>
#include "Organism.h"
using namespace std;

class Organism;

class World
{
	int N;
	int M;
	vector<Organism*> organisms;
	vector<Organism*> newBornOrganisms;

public:
	World(int N, int M);
	~World();
	int GetM();
	int GetN();
	int GetOrganismsSize();
	bool GetAlive(int x, int y);
	void SetM(int M);
	void SetN(int N);
	void makeTurn(char whichDirection);
	void drawMenu();
	void drawWorld(); 
	void saveState();
	void loadState();
	void CreateOrganism(int posX, int posY, char letter);
	Organism* GetOrganism(int x, int y);
};
