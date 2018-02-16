#include "Jeu.h"


Jeu::Jeu()
{
}

Jeu::Jeu(std::string name, std::string label, int winRate)
{
	this->m_name = name;
	this->m_label = label;
	this->m_winRate = winRate;
}

Jeu::~Jeu()
{
}


//Get name of the game
std::string Jeu::getName()
{
	return m_name;
}

//Set name of the game
void Jeu::setName(std::string newName)
{
	m_name = newName;
}


//Get label of the game
std::string Jeu::getLabel()
{
	return m_label;
}

//Set label of the game
void Jeu::setLabel(std::string newLabel)
{
	m_label = newLabel;
}


//Get winrate of the game
int Jeu::getWinRate()
{
	return m_winRate;
}

//Set winrate of the game
void Jeu::setWinRate(int newWinRate)
{
	m_winRate = newWinRate;
}