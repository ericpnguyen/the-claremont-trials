#ifndef PlayScreen_hpp
#define PlayScreen_hpp
#include "Level.hpp"

class PlayScreen : public GameEntity {
	
private:
	
	
	Timer* mTimer;
	InputManager* mInput;
	
    Texture* mStartLabel;
	
	float mLevelStartTimer;
	float mLevelStartDelay;
	
	bool mGameStarted;
	
	Level* mLevel;	
	bool mLevelStarted;
	int mCurrentStage;

	// Ground strip
	Texture* mGroundStrip;

	// Background
	Texture* mBackground;

	// Ready label
	Texture* mReadyLabel;
	
	Player* mPlayer;
	
private:
	
	void StartNextLevel();
	
public:
	
	PlayScreen();
	~PlayScreen();
	
	void StartNewGame();
	
	bool GameOver();
	
	void Update();
	
	void Render();
	
	
};





#endif