#include <iostream>
#include <vector> 
#include "Organism.h"
#include "World.h"
#define N 25
#define M 25

using namespace std;

int main()
{
	World w(N, M);
	char sign = ' ';

	while (sign != 'q' && sign != 'Q')
	{
		if (sign == ' ')
		{
			w.drawMenu();
			w.drawWorld();
		}
		else if (sign != ' ' && sign != 'Z' && sign != 'L')
		{
			w.drawMenu();
			w.makeTurn(sign);
			w.drawWorld();
		}
		else if (sign == 'Z')
		{
			w.saveState();
			w.drawMenu();
			w.drawWorld();
		}
		else if (sign == 'L')
		{
			system("cls");
			w.loadState();
			w.drawMenu();
			w.drawWorld();
			w.makeTurn(sign);
			
		}
		cin >> sign;
		system("cls");
	}
	return 0;
}


