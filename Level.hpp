// Used to set up our only level

#ifndef Level_h
#define Level_h
#include "InputManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

class Level : public GameEntity {
		
private:

	Timer* mTimer;
	
	// Stage variables
	int mStage;
	bool mStageStarted;
	
	float mLabelTimer;
	
	// Texture* mStageLabel;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;
	
	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;
	
	Player* mPlayer;
	
	Texture* mGameOverLabel;
	bool mGameOver;
	
	// Background
	Texture* mBackground;

	// Enemies
	int mEnemyCount;
	std::vector<Enemy*> mEnemies;
	
	XMLDocument mSpawningPatterns;
	int mCurrentPriority;
	int mCurrentIndex;	

	bool mSpawningFinished;
	float mSpawnDelay;
	float mSpawnTimer;

private:
	
	void StartStage();
	
	void HandleEnemySpawning();
	
public:
	
	Level(int stage, Player* player);
	~Level();
		
	void Update();
	
	void Render();
};
#endif