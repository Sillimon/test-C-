#include "Joueur.h"



Joueur::Joueur()
{
}


Joueur::Joueur(std::string name)
{
	m_name = name;
}

Joueur::Joueur(std::string name, int tokens)
{
	this->m_name = name;
	this->m_tokens = tokens;
}


Joueur::~Joueur()
{
}


//Get name of the player
std::string Joueur::getName()
{
	return m_name;
}

//Set name of the player
void Joueur::setName(std::string newName)
{
	m_name = newName;
}



//Get tokens of the player
int Joueur::getTokens()
{
	return m_tokens;
}

//Set tokens of the player
void Joueur::setTokens(int newTokens)
{
	m_tokens = newTokens;
}

//Increment tokens of the player
void Joueur::incrementTokens(int tokensToAdd)
{
	m_tokens += tokensToAdd;
}

//Decrement tokens of the player
void Joueur::decrementTokens(int tokensToRemove)
{
	m_tokens -= tokensToRemove;
}