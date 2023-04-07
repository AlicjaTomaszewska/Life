#pragma once
#include <iostream>
#include <string>
#include "World.h"
#define MAX_GRID_FIELD 24
#define MIN_GRID_FIELD 0
#define HOW_MANY_DIRECTIONS 8
using namespace std;

class World;

class Organism
{
	int strength;
	int initiative;
	int coordinateX;
	int coordinateY;
	int age;
	bool alive;
	char letter;
	string name;

public:
	World* world;
	Organism(int coordinateX, int coordinateY, World* world, int strength, int initiative, char letter, string name);
	Organism(World* world, int strength, int initiative, char letter, string name);
	virtual ~Organism();
	int GetX() const;
	int GetY() const;
	int GetStrength();
	int GetInitiative();
	int GetLetter();
	int GetAge();
	string GetName();
	bool GetAlive();
	virtual void SetX(int coordinateX);
	virtual void SetY(int coordinateY);
	void SetStrength(int strength);
	void SetInitiative(int initiative);
	void SetAlive(bool alive);
	void SetAge(int age);
	void DrawingCoordinates(int& x, int& y);
	void NewDirection(Organism* secondOrg);
	virtual void collision(Organism* secondOrg);
	virtual void action(char whichDirection) = 0;
	virtual void draw() = 0;
	string save();
};
