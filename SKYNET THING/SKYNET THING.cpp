// SKYNET THING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int smallBound = 1;
int largeBound = 64;
int targetLocation;
int checkNumber = 1;
int guess = 0;
bool found = false;

int main()
{
	srand(time(0));
	targetLocation = rand() % 64 + 1;
	cout << "Enemy is located at position #" << targetLocation << " of 64.\n";
	while (!found)
	{
		cout << "Ping #" << checkNumber << ".\n";
		guess = ((largeBound - smallBound) / 2) + smallBound;
		if (guess > targetLocation) // check for high guess
		{
			cout << "Prediction of position #" << guess << " was higher than actual position of #" << targetLocation << ".\n";
			largeBound = guess;
			checkNumber += 1; 
		}
		if (guess < targetLocation) // check for low guess
		{
			cout << "Prediction of position #" << guess << " was lower than actual position of #" << targetLocation << ".\n";
			smallBound = guess;
			checkNumber += 1;
		}
		if (guess == targetLocation) //  check for correct guess
		{
			cout << "Enemy Spotted!\n";
			cout << "Enemy was located at position #" << guess << " after " << checkNumber << " attempts.\n";
			found = true;
		}
	}
		
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
