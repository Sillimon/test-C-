#pragma once

#include <string>

class Jeu
{
public:
	Jeu();
	Jeu(std::string name, std::string label, int winRate);
	~Jeu();

	std::string getName();
	void setName(std::string newName);

	std::string getLabel();
	void setLabel(std::string newLabel);

	int getWinRate();
	void setWinRate(int newWinRate);

protected:

private:
	std::string m_name;
	std::string m_label;
	int m_winRate;
};

