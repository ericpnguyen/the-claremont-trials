// Used to set up our only level

#include "Level.hpp"

Level::Level(int stage, Player* player) {
	
	mTimer = Timer::Instance();

	// Set stage variables
	mStage = stage;
	mStageStarted = false;
	mLabelTimer = 0.0f;
	mStageLabelOnScreen = 0.0f;
	mStageLabelOffScreen = 1.5f;

	// Ready label
	mReadyLabel = new Texture("READY?", "emulogic.ttf", 32, { 150, 0, 0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mReadyLabelOnScreen = mStageLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 1.0f;
	
	// Player
	mPlayer = player;

	// Game over label
	mGameOverLabel = new Texture("GAME OVER", "emulogic.ttf", 32, {150, 0, 0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	// Cloud background
	mBackground = new Texture("background.png");
	mBackground->Parent(this);	
	mBackground->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	// Enemy
	mEnemyCount = 0;

	// XML enemy spawning

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Enemy.xml");
	mSpawningPatterns.LoadFile(fullPath.c_str());

	mCurrentPriority = 0;
	mCurrentIndex = 0;
	mSpawningFinished = false;
	mSpawnDelay = 0.3f;
	mSpawnTimer = 0.0f;

	Enemy::CurrentPlayer(mPlayer);
}

Level::~Level(){
	
	mTimer = NULL;
	mPlayer = NULL;
	
	// Ready label
	delete mReadyLabel;
	mReadyLabel = NULL;
		
	// GameOverLabel
	delete mGameOverLabel;
	mGameOverLabel = NULL;

	// Background
	delete mBackground;
	mBackground = NULL;

	// Enemies
	for(int i = 0; i < mEnemies.size(); i++) {
		
		delete mEnemies[i];
		mEnemies[i] = NULL;
	}
}


void Level::StartStage() {

	mStageStarted = true;
	mPlayer->Active(true);
	mPlayer->Visible(true);
}

// Use XML file to spawn enemies one at a time
// Search for children and spawn based on priority attribute 
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

// Initialize level and spawn enemies when necessary
void Level::Update() {
	
	if(!mStageStarted) {
		
		StartStage();	
	} 
	else {
		
		if(!mSpawningFinished)
			HandleEnemySpawning();

		// Enemy updates
		for (int i = 0; i < mEnemies.size(); i++)
			mEnemies[i]->Update();
	}
}

void Level::Render() {

	// Show ready label

	if(!mStageStarted) {

		if(mLabelTimer > mStageLabelOnScreen && mLabelTimer < mStageLabelOffScreen) {			
			mReadyLabel->Render();
		}
	} 
	else {

		// Background, enemy, and game over label
		mBackground->Render();
		for (int i = 0; i < mEnemies.size(); i++)
			mEnemies[i]->Render();
		
		if(mEnemies.size() == 50) {
			mGameOverLabel->Render();
		}
	}
}