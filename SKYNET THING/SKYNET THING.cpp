// SKYNET THING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int smallBound = 1; // initializes and stores the small bound
int largeBound = 64; //  initializes and stores the large bound
int targetLocation; // stores the location of the enemy
int checkNumber = 1; // keeps track of how many guesses have taken place
int guess = 0; // keeps track of the current guess value
bool found = false; // stores the victory state

int main()
{
	srand(time(0)); // seeds the time for a more random number generation
	targetLocation = rand() % 64 + 1; // generates a random value between 1 and 64
	cout << "Enemy is located at position #" << targetLocation << " of 64.\n";
	while (!found) // runs until the found boolean is true
	{
		cout << "Ping #" << checkNumber << ".\n";
		guess = ((largeBound - smallBound) / 2) + smallBound; // sets the guess variable to the difference of the large bound and the small bound divided by two plus the small bound
		if (guess > targetLocation) // check for high guess
		{
			cout << "Prediction of position #" << guess << " was higher than actual position of #" << targetLocation << ".\n";
			largeBound = guess; // resets the large bound to the guessed location
			checkNumber += 1; // increments the check number variable
		}
		if (guess < targetLocation) // check for low guess
		{
			cout << "Prediction of position #" << guess << " was lower than actual position of #" << targetLocation << ".\n";
			smallBound = guess; // resets the small bound to the guessed location
			checkNumber += 1; // increments the check number variable
		}
		if (guess == targetLocation) //  check for correct guess
		{
			cout << "Enemy Spotted!\n";
			cout << "Enemy was located at position #" << guess << " after " << checkNumber << " attempts.\n";
			found = true; // changes victory condition boolean to true
		}
	}	 
}