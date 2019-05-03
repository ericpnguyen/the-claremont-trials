#ifndef PlayScreen_h
#define PlayScreen_h
#include "InputManager.hpp"
#include "Player.hpp"


class PlayScreen : public GameEntity {
	
private:
	
	
	Timer* mTimer;
	InputManager* mInput;
	
	Texture* mStartLabel;
	
	float mLevelStartTimer;
	float mLevelStartDelay;
	
	bool mGameStarted;
	
	bool mLevelStarted;
	int mCurrentStage;
	
	
	Player* mPlayer;
	
private:
	
	void StartNextLevel();
	
public:
	
	PlayScreen();
	~PlayScreen();
	
	void StartNewGame();
	
	
	void Update();
	
	void Render();
	
	
};





#endif