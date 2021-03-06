// Test C++.cpp : définit le point d'entrée pour l'application console.
//

#include <iostream>
#include <vector>

#include "Jeu.h"
#include "Joueur.h"
#include "Casino.h"

int main()
{
	//Instantiate the 3 objects 'Jeu'
	Jeu roulette("Roulette", "Roulette is a casino game named after the French word meaning little wheel."
		"\nIn the game, players may choose to place bets on either a single number, various groupings of numbers, the colors red or black, whether the number is odd or even, or if the numbers are high (19 to 36) or low (1 to 18)."
		"\nInterestingly, the sum of all the numbers on the roulette wheel (from 0 to 36) is 666, which is the Number of the Beast. One legend says that François Blanc made a deal with the devil to obtain the secrets of roulette.\n", 30);

	Jeu craps("Craps", "Craps is a dice game in which the players make wagers on the outcome of the roll, or a series of rolls, of a pair of dice\n", 20);

	Jeu blackJack("Black Jack", "Blackjack, also known as twenty-one, is a comparing card game between usually several players and a dealer, where each player in turn competes against the dealer, but players do not play against each other.\n", 60);

	//Add the previous objects in a vector
	std::vector<Jeu> gameList;
	gameList.push_back(roulette);
	gameList.push_back(craps);
	gameList.push_back(blackJack);

	//Instantiate an object 'Casino' using the vector
	Casino myCasino(gameList);

	bool hasOpen;
	do
	{
		//Load a saved game or make a new one
		int menu;
		do
		{
			std::cout << "[0] New game - [1] Load previous game" << std::endl;
			std::cin >> menu;
			system("cls");
		} while (menu != 0 && menu != 1);

		//Load game
		if (menu == 1)
		{
			hasOpen = myCasino.loadGame();
		}
		//New game
		else
		{
			//Ask for a player name
			std::string playerName;

			std::cout << "Enter Player Name : ";
			std::cin >> playerName;

			system("cls");

			//Instantiate a new player with the user entry
			//thenadd it to the casino object
			Joueur player(playerName);
			myCasino.setPlayer(player);

			hasOpen = true;
		}
	} while (!hasOpen);

	//Choose game then play
	myCasino.chooseGame();
	myCasino.play();


	//play again, save, load or quit
	int endGameChoice;

	do
	{
		std::cout << "[0] Play again - [1] Save - [2] Load - [3] Quit" << std::endl
			<< "What will you do ?  ";
		std::cin >> endGameChoice;

		system("cls");

		switch (endGameChoice)
		{
		case 0:
			//Keep playing
			myCasino.chooseGame();
			myCasino.play();
			break;

		case 1:
			//Save current player
			myCasino.saveGame();
			break;

		case 2:
			//Load another player
			myCasino.loadGame();
			break;

		case 3:
			//Exit the program
			return 0;

		default:
			//Invalid entries
			std::cout << "WARNING : Wrong entry ! Please evacuate ! Please evacuate ! pets and women before !" << std::endl << std::endl;
			system("pause");
			system("cls");
			break;
		}
	} while (endGameChoice != 0 || endGameChoice != 1 || endGameChoice != 2 || endGameChoice != 3);

	//Call Casino's destructor and make the pointer m_player poiting on Null
	myCasino.~Casino();

    return 0;
}

