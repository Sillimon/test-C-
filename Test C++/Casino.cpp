#include "Casino.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

Casino::Casino()
{
}


Casino::Casino(std::vector<Jeu> &gameList)
{
	this->m_gameList = gameList;
}



Casino::~Casino()
{
	delete m_player;
	m_player = NULL;
}


//Set the player of the casino object
void Casino::setPlayer(Joueur &newPlayer)
{
	this->m_player = new Joueur(newPlayer.getName(), newPlayer.getTokens());
}


//Display games and ask the user to choose one
void Casino::chooseGame()
{
	int cptr = 0;
	for (auto &g : m_gameList)
	{
		std::cout << "[" << cptr << "] Play " << g.getName() << " (" << g.getWinRate() << "% winrate)" << std::endl 
			<< "Description : " << g.getLabel() << std::endl;
		cptr++;
	}

	system("pause");
	system("cls");

	do
	{
		std::cout << "Choose a game : ";
		std::cin >> m_choice;
		system("cls");
	} while (m_choice < 0 || m_choice > m_gameList.size() - 1);
}

//Play the choosen game
void Casino::play()
{
	//Player bet
	int bet;
	
	do
	{
		//Tell the user what he's playing right now and the chances he has to win
		std::cout << "You're currently playing : " << m_gameList.at(m_choice).getName() << std::endl
		<< "Win rate : " << m_gameList.at(m_choice).getWinRate() << "%" << std::endl << std::endl;

	
		std::cout << m_player->getName() << " tokens : " << m_player->getTokens() << std::endl
			<< "Choose a bet value : ";

		std::cin >> bet;
		system("cls");
	} while (m_player->getTokens() < bet || bet <= 0);

	//Win or lose (roll a dice out of 100)
	srand(time(NULL));
	int result = rand() % 101;

	if (result > m_gameList.at(m_choice).getWinRate())
	{
		//Lose (dice roll > winrate)
		std::cout << m_player->getName() << " loses " << bet << " tokens." << std::endl;
		
		//Decrease amount of tokens own by the player
		m_player->decrementTokens(bet);
	}
	else
	{
		//Win (dice roll < winrate)
		std::cout << m_player->getName() << " earns " << bet << " tokens." << std::endl;

		//Increase amount of tokens own by the player
		m_player->incrementTokens(bet);
	}

	system("pause");
	system("cls");
}


//Load a player
bool Casino::loadGame()
{
	bool opened;

	//Search a saved player thanks to his name
	std::string playerName;

	std::cout << "Enter the player name to load the corresponding game : ";
	std::cin >> playerName;

	//Open the corresponding save
	std::ifstream loadedGame(playerName + ".txt");

	
	std::string line;

	//If the save is found
	if (loadedGame.is_open())
	{
		//Insert in variable line, a string of each line in the .txt (in this case, only keep the last line)
		while (std::getline(loadedGame, line))
		{
			std::cout << std::endl << line;
			//Erase the ninth first elements of the lines so we only keep the tokens number
			line.erase(0, 9);

		}
		//Close the file
		loadedGame.close();

		//player contained in Casino now points to a new Joueur object containing the data inside the save file
		m_player = new Joueur(playerName, std::stoi(line, nullptr, 0));

		opened = true;
	}
	//If the save isn't found
	else
	{
		std::cout << "Unable to find the save..." << std::endl << std::endl;
		opened = false;
	}
	
	std::cout << std::endl << std::endl;

	system("pause");
	system("cls");

	return opened;
}

//Save a player
void Casino::saveGame()
{
	//Create a file and open it
	std::ofstream newSave;
	newSave.open(m_player->getName() + ".txt");

	//Write player data inside the file
	newSave << "Player : " << m_player->getName() << std::endl 
		<< "Tokens : " << m_player->getTokens();

	//Close the file
	newSave.close();

	std::cout << "Game Saved" << std::endl << std::endl;

	system("pause");
	system("cls");
}