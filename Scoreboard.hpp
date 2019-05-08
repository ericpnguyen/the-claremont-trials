// Used to keep track of score and high score

#ifndef _SCOREBOARD_H
#define _SCOREBOARD_H
#include "Texture.hpp"
#include <vector>

using namespace QuickSDL;

class Scoreboard : public GameEntity{

private:

	std::vector<Texture*> mScore;

public:

	Scoreboard();
	~Scoreboard();

	void Score(int score);

	void Render();

private:
	
	void ClearBoard();
};
#endif