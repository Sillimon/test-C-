#pragma once

#include "Jeu.h"
#include "Joueur.h"

#include <vector>
#include <fstream>

class Casino
{
public:
	Casino();
	Casino(std::vector<Jeu> &gameList);
	virtual ~Casino();

	void setPlayer(Joueur &newPlayer);

	void chooseGame();
	void play();

	bool loadGame();
	void saveGame();

protected:

private:
	std::vector<Jeu> m_gameList;
	Joueur * m_player = nullptr;

	int m_choice;
};

