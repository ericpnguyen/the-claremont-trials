// Used to keep track of score and high score

#include "Scoreboard.hpp"

Scoreboard::Scoreboard() {

	Score(0);
}

Scoreboard::~Scoreboard() {

	ClearBoard();
}

void Scoreboard::ClearBoard() {

	for (int i = 0; i < mScore.size(); i++) {
		delete mScore[i];
		mScore[i] = NULL;
	}
	mScore.clear();
}

void Scoreboard::Score(int score) {

	ClearBoard();

	// Case where score is 0
	if(score == 0) {
		for (int i = 0; i < 2; i++) {
			mScore.push_back(new Texture("0", "emulogic.ttf", 32, {230, 230, 230}));
			mScore[i]->Parent(this);
			mScore[i]->Pos(Vector2(-32.0f*i, 0.0f));
		}
	}
	// If score isn't 0
	else {
		std::string str = std::to_string(score);
		int lastIndex = str.length() - 1;

		for (int i = 0; i <= lastIndex; i++) {
			mScore.push_back(new Texture(str.substr(i, 1), "emulogic.ttf", 32, {230, 230, 230}));
			mScore[i]->Parent(this);
			mScore[i]->Pos(Vector2(-32.0f*(lastIndex-i), 0.0f));
		}
	}
}

void Scoreboard::Render() {
	for(int i = 0; i < mScore.size(); i++) {
		mScore[i]->Render();
	}
}