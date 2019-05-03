#ifndef Level_h
#define Level_h
#include "InputManager.hpp"
#include "Player.hpp"


class Level : public GameEntity {
	
public:
	
	
	
	enum LEVEL_STATES { running, finished, gameover };
	
private:
	Timer* mTimer;
	
	int mStage;
	bool mStageStarted;
	
	float mLabelTimer;
	
	Texture* mStageLabel;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;
	
	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;
	
	
	Player* mPlayer;
	bool mPlayerHit;
	float mPlayerRespawnDelay;
	float mPlayerRespawnTimer;
	float mPlayerRespawnLabelOnScreen;
	
	Texture* mGameOverLabel;
	bool mGameOver;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;
	
	LEVEL_STATES mCurrentState;
	
	
	
	// std::vector<Enemy*> mEnemies;
	
private:
	
	void StartStage();
	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();
	
	
	void HandleEnemySpawning();
	void HandleEnemyFormation();
	void HandleEnemyDiving();
	
	
public:
	
	Level(int stage, Player* player);
	~Level();
	
	LEVEL_STATES State();
	
	void Update();
	
	void Render();
};

#endif