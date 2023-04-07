#include <iostream>
#include "Human.h"

using namespace std;

Human::Human(int coordinateX, int coordinateY, World* world) : Animal(coordinateX, coordinateY, world, STRENGTH_OF_HUMAN, INITIATIVE_OF_HUMAN, LETTER_OF_HUMAN, NAME_OF_HUMAN)
{
}
Human::Human(World* world) : Animal(world, STRENGTH_OF_HUMAN, INITIATIVE_OF_HUMAN, LETTER_OF_HUMAN, NAME_OF_HUMAN)
{

}

Human::~Human()
{
}

void Human::AntylopesSpeed(char whichDirection)
{
	char newDir = ' ';
	int posX = this->GetX();
	int posY = this->GetY();

	if (whichDirection == 'N' || whichDirection == 'n')
	{
		if (this->GetY() > 1)
		{
			posX = this->GetX();
			posY = this->GetY() - 2;
		}
	}
	else if (whichDirection == 'S' || whichDirection == 's')
	{
		if (this->GetY() < 23)
		{
			posX = this->GetX();
			posY = this->GetY() + 2;
		}
	}
	else if (whichDirection == 'E' || whichDirection == 'e')
	{
		if (this->GetX() < 23)
		{
			posX = this->GetX() + 2;
			posY = this->GetY();
		}
	}
	else if (whichDirection == 'W' || whichDirection == 'w')
	{
		if (this->GetX() > 1)
		{
			posX = this->GetX() - 2;
			posY = this->GetY();
		}
	}

	Organism* orgOnPos = this->world->GetOrganism(posX, posY);

	if (orgOnPos == NULL || orgOnPos->GetLetter() == 'H')
	{
		this->SetX(posX);
		this->SetY(posY);
	}
	else
	{
		this->collision(orgOnPos);
	}
}

void Human::action(char whichDirection)
{
	int antylopeSpeedChances = rand() % 2;
	int posX = this->GetX();;
	int posY = this->GetY();

	if (whichDirection == '2')
	{
		if (roundForAntylopesSpeed == -5)
		{
			roundForAntylopesSpeed = 6;
			antylopeSpeedActivated = 1;
			cout << "Human special ability is activated" << endl;
		}
	}
	if (antylopeSpeedActivated == 1 && (roundForAntylopesSpeed > 2 || antylopeSpeedChances == 1))
	{
		AntylopesSpeed(whichDirection);
	}
	else
	{
		if (whichDirection == 'N' || whichDirection == 'n')
		{
			if (this->GetY() > 0)
			{
				posX = this->GetX();
				posY = this->GetY() - 1;
			}
		}
		else if (whichDirection == 'S' || whichDirection == 's')
		{
			if (this->GetY() < 24)
			{
				posX = this->GetX();
				posY = this->GetY() + 1;
			}
		}
		else if (whichDirection == 'E' || whichDirection == 'e')
		{
			if (this->GetX() < 24 )
			{
				posX = this->GetX() + 1;
				posY = this->GetY();
			}
		}
		else if (whichDirection == 'W' || whichDirection == 'w')
		{
			if (this->GetX() > 0)
			{
				posX = this->GetX() - 1;
				posY = this->GetY();
			}
		}
		Organism* orgOnPos = this->world->GetOrganism(posX, posY);

		if (orgOnPos == NULL || orgOnPos->GetLetter() == 'H')
		{
			this->SetX(posX);
			this->SetY(posY);
		}
		else
		{
			this->collision(orgOnPos);
		}
	}
	if (roundForAntylopesSpeed > -5)
	{
		roundForAntylopesSpeed--;
	}
	if (roundForAntylopesSpeed == 0)
	{
		antylopeSpeedActivated = 0;
		cout << "Human special ability is disactivated" << endl;
	}
	this->SetAge(this->GetAge() + 1);
}

void Human::draw()
{
	cout << LETTER_OF_HUMAN;
}