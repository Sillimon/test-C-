#pragma once

#include <string>;

class Joueur
{
public:
	Joueur();
	Joueur(std::string name);
	Joueur(std::string name, int tokens);
	virtual ~Joueur();

	std::string getName();
	void setName(std::string newName);

	int getTokens();
	void setTokens(int newTokens);
	void incrementTokens(int tokensToAdd);
	void decrementTokens(int tokensToRemove);

protected:

private:
	std::string m_name;
	int m_tokens = 100;
};

