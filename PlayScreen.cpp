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

	// Ground strip
	mGroundStrip = new Texture("groundstrip.png");
	mGroundStrip->Parent(this);
	mGroundStrip->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.83f));

	// Ready label
	mReadyLabel = new Texture("READY?", "emulogic.ttf", 32, { 150, 0, 0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mPlayer = NULL;
	
	Enemy::CreatePaths();
}

PlayScreen::~PlayScreen() {
	
	mTimer = NULL;
	mInput = NULL;
	
	
	delete mStartLabel;
	mStartLabel = NULL;
	
	delete mLevel;
	mLevel = NULL;

	// Ground strip
	delete mGroundStrip;
	mGroundStrip = NULL;

	// Ready Label
	delete mReadyLabel;
	mReadyLabel = NULL;
	
	// Player
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
	mPlayer->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.1f, Graphics::Instance()->SCREEN_HEIGHT * 0.68f));
	mPlayer->Active(false);

	
	
	
	mGameStarted = true;
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
		
	if(mGameStarted) {
		
		if(mLevelStarted)
			mLevel->Render();

			mGroundStrip->Render();
			if(mLevelStartTimer > 0.0f && mLevelStartTimer < 1.5f) {
				mReadyLabel->Render();
			}
			mPlayer->Render();
	}
}