#include "PlayScreen.hpp"

PlayScreen::PlayScreen() {
	
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	
	mStartLabel = new Texture("START", "emulogic.ttf", 32, { 150, 0, 0 });
	mStartLabel->Parent(this);
	mStartLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.4f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	

	mLevel = NULL;
	mLevelStartDelay = 1.0f;
	mLevelStarted = false;
	
	mPlayer = NULL;
	
	// Enemy::CreatePaths();
	
}

PlayScreen::~PlayScreen() {
	
	mTimer = NULL;
	mInput = NULL;
	
	
	delete mStartLabel;
	mStartLabel = NULL;
	
	delete mLevel;
	mLevel = NULL;
	
	delete mPlayer;
	mPlayer = NULL;
}

void PlayScreen::StartNextLevel() {
	
	mCurrentStage++;
	mLevelStartTimer = 0.0f;
	mLevelStarted = true;
	delete mLevel;
	mLevel = new Level(mCurrentStage, mPlayer);
}


void PlayScreen::StartNewGame() {
	
	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.4f, Graphics::Instance()->SCREEN_HEIGHT * 0.9f));
	mPlayer->Active(false);

	
	
	
	mGameStarted = false;
	mLevelStarted = false;
	mLevelStartTimer = 0.0f;
	mCurrentStage = 0;

}

bool PlayScreen::GameOver() {
	
	if(!mLevelStarted)
		return false;

	return (mLevel->State() == Level::gameover);
}


void PlayScreen::Update() {
	
	if(mGameStarted) {
		
		if(!mLevelStarted) {
			
			mLevelStartTimer += mTimer->DeltaTime();
			if(mLevelStartTimer >= mLevelStartDelay)
				StartNextLevel();
			
		}
		
		
	} else {
		if(!Mix_PlayingMusic()) {
			
			mGameStarted = true;
		}
	}
	
	if(mGameStarted ) {
		
		
		if(mLevelStarted) {
			
			mLevel->Update();
			
			if(mLevel->State() == Level::finished) {
				
				mLevelStarted = false;
			}
		}
		mPlayer->Update();
		}
}

void PlayScreen::Render() {
		
	if(!mGameStarted)
		mStartLabel->Render();
	
	if(mGameStarted) {
		
		if(mLevelStarted)
			mLevel->Render();
		
		mPlayer->Render();
	}
}