#include "Level.hpp"

Level::Level(int stage, Player* player) {
	
	mTimer = Timer::Instance();

	
	mStage = stage;
	
	mStageStarted = false;
	
	mLabelTimer = 0.0f;
	
	// mStageLabel = new Texture("STAGE", "emulogic.ttf", 32, { 75, 75, 200 });
	// mStageLabel->Parent(this);
	// mStageLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.35f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mStageLabelOnScreen = 0.0f;
	mStageLabelOffScreen = 1.5f;
	
	mReadyLabel = new Texture("READY?", "emulogic.ttf", 32, { 150, 0, 0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mReadyLabelOnScreen = mStageLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 1.0f;
	
	mPlayer = player;
	mPlayerHit = false;
	mPlayerRespawnDelay = 3.0f;
	mPlayerRespawnTimer = 0.0f;
	mPlayerRespawnLabelOnScreen = 2.0f;
	
	mGameOverLabel = new Texture("GAME OVER", "emulogic.ttf", 32, {150, 0, 0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mGameOver = false;
	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;
	
	mCurrentState = running;

	// Cloud background
	mBackground = new Texture("background.png");
	mBackground->Parent(this);	
	mBackground->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	// Enemy
	mEnemyCount = 0;

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Enemy.xml");
	mSpawningPatterns.LoadFile(fullPath.c_str());

	mCurrentPriority = 0;
	mCurrentIndex = 0;
	mSpawningFinished = false;
	mSpawnDelay = 2.0f;
	mSpawnTimer = 0.0f;
}

Level::~Level(){
	
	mTimer = NULL;
	
	// delete mStageLabel;
	// mStageLabel = NULL;
	
	delete mReadyLabel;
	mReadyLabel = NULL;
	
	mPlayer = NULL;
	
	delete mGameOverLabel;
	mGameOverLabel = NULL;

	// Background
	delete mBackground;
	mBackground = NULL;
	
	// Enemy
	// delete mEnemy;
	// mEnemy = NULL;
	
	for(int i = 0; i < mEnemies.size(); i++) {
		
		delete mEnemies[i];
		mEnemies[i] = NULL;
	}
}


void Level::StartStage() {

	mStageStarted = true;
}

void Level::HandleStartLabels() {
	
	
	mLabelTimer += mTimer->DeltaTime();
	if(mLabelTimer >= mStageLabelOffScreen) {
				
		if(mStage > 1) {
			
			StartStage();
		} else {
			if(mLabelTimer >= mReadyLabelOffScreen) {
				
				StartStage();
				mPlayer->Active(true);
				mPlayer->Visible(true);
			}
		}
	}

	
	
}


void Level::HandleCollisions() {
	
	if(!mPlayerHit) {
		
		if(InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			
			// mPlayer->WasHit();
			
			mPlayerHit = true;
			mPlayerRespawnTimer = 0.0f;
			mPlayer->Active(false);
		}
	}
}

void Level::HandlePlayerDeath() {
	
	if(!mPlayer->IsAnimating()) {
		
		if(mPlayer->Lives() > 0) {
			
			if(mPlayerRespawnTimer == 0.0f)
				mPlayer->Visible(false);
			
			mPlayerRespawnTimer += mTimer->DeltaTime();
			if(mPlayerRespawnTimer >= mPlayerRespawnDelay) {
				
				mPlayer->Active(true);
				mPlayer->Visible(true);
				mPlayerHit = false;
			}
			
		} else {
			
			if(mGameOverTimer == 0.0f)
				mPlayer->Visible(false);
			
			mGameOverTimer += mTimer->DeltaTime();
			if(mGameOverTimer >= mGameOverDelay) {
				
				mCurrentState = gameover;
			}
		}
	}
}


void Level::HandleEnemySpawning() {

	mSpawnTimer += mTimer->DeltaTime();

	if(mSpawnTimer >= mSpawnDelay) {

		XMLElement* element = mSpawningPatterns.FirstChildElement("Level")->FirstChild()->NextSiblingElement();
		bool spawned = false;
		bool priorityFound = false;

		while(element != NULL) {

			int priority = element->IntAttribute("priority");
			int path = element->IntAttribute("path");
			XMLElement* child = element->FirstChildElement();

			if(mCurrentPriority == priority) {

				priorityFound =true;
				for(int i = 0; i < mCurrentIndex && child != NULL; i++) {
					child = child->NextSiblingElement();
				}

				if(child != NULL) {

					int index = child->IntAttribute("index");

					mEnemies.push_back(new Enemy(path));
					mEnemyCount++;

					spawned = true;
				}
			}
		element = element->NextSiblingElement();
		}

		if(!priorityFound) {
			mSpawningFinished = true;
		}
		else {
			if(!spawned) {
				mCurrentPriority++;
				mCurrentIndex = 0;
			}
			else {
				mCurrentIndex++;
			}
		}
		mSpawnTimer = 0.0f;
	}
}

Level::LEVEL_STATES Level::State() {
	
	return mCurrentState;
}

void Level::Update() {
	
	if(!mStageStarted) {
		
		HandleStartLabels();
		
	} else {
		
		if(!mSpawningFinished)
			HandleEnemySpawning();

		// Enemy
		for (int i = 0; i < mEnemies.size(); i++)
			mEnemies[i]->Update();
		
		HandleCollisions();
		
		if(mPlayerHit) {
			HandlePlayerDeath();
		} else {
			
			if(InputManager::Instance()->KeyPressed(SDL_SCANCODE_N)) {
				
				mCurrentState = finished;
			}
		}
	}
}

void Level::Render() {
	
	
	if(!mStageStarted) {
		
		if(mLabelTimer > mStageLabelOnScreen && mLabelTimer < mStageLabelOffScreen) {
			
			// mStageLabel->Render();
			mReadyLabel->Render();
			
		} else if(mLabelTimer > mReadyLabelOnScreen && mLabelTimer < mReadyLabelOffScreen) {
			
			// mReadyLabel->Render();
			
		}
	} else {

		// Enemy
		mBackground->Render();
		for (int i = 0; i < mEnemies.size(); i++)
			mEnemies[i]->Render();
		
		// for (int i = 0; i < mEnemies.size(); i++ )
		// 	mEnemies[i]->Render();
		
		if(mPlayerHit) {
			
			if(mPlayerRespawnTimer >= mPlayerRespawnLabelOnScreen)
				mReadyLabel->Render();
			
			if(mGameOverTimer >= mGameOverLabelOnScreen)
				mGameOverLabel->Render();
		}
		
	}
}