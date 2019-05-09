// Screen where playing happens

#ifndef PlayScreen_hpp
#define PlayScreen_hpp
#include "Level.hpp"
#include "Scoreboard.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

class PlayScreen : public GameEntity {
	
private:
	
	Timer* mTimer;
	InputManager* mInput;
		
	// Level variables
	float mLevelStartTimer;
	float mLevelStartDelay;
	bool mGameStarted;
	Level* mLevel;	
	bool mLevelStarted;
	int mCurrentStage;

	// mTopScoreLabel
	Texture* mTopScoreLabel;

	// mTopBar
	GameEntity* mTopBar;

	// Ground strip
	// Texture* mGroundStrip;

	// Ready label
	Texture* mReadyLabel;

	
	Player* mPlayer;

	// Scoreboards
	Scoreboard* mPlayerOneScore;
	Scoreboard* mTopScore;

	XMLDocument mHighScore;
	
private:
	
	void StartNextLevel();
	
public:
	
	PlayScreen();
	~PlayScreen();
	
	void StartNewGame();
	
	bool GameOver();

	void SaveScore();

	void LoadScore();
	
	void Update();
	
	void Render();
};
#endif