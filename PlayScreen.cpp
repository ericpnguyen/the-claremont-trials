#include "PlayScreen.hpp"
#include "Scoreboard.hpp"
#include <iostream>

PlayScreen::PlayScreen() {
	
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	
	mStartLabel = new Texture("START", "emulogic.ttf", 32, { 150, 0, 0 });
	mStartLabel->Parent(this);
	mStartLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.4f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	//mTopBar
	mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));

	// mTopScoreLabel
	mTopScoreLabel = new Texture("HI-SCORE", "emulogic.ttf", 32, {150, 0, 0});
	mTopScoreLabel->Parent(mTopBar);
	mTopScoreLabel->Pos(Vector2(-30.0f, -50.0f));

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

	mPlayerOneScore = new Scoreboard();
	mTopScore = new Scoreboard();

	mPlayerOneScore->Parent(mTopBar);
	mTopScore->Parent(mTopBar);

	mPlayerOneScore->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.35f, 0.0f));
	mTopScore->Pos(Vector2(-30.0f, 0.0f));

	mTopBar->Parent(this);
	
	Enemy::CreatePaths();

	std::string secondFullPath = SDL_GetBasePath();
	secondFullPath.append("Score.xml");
	mHighScore.LoadFile(secondFullPath.c_str());
}

PlayScreen::~PlayScreen() {
	
	mTimer = NULL;
	mInput = NULL;

	delete mTopScoreLabel;
	mTopScoreLabel = NULL;
	
	delete mStartLabel;
	mStartLabel = NULL;

	delete mTopBar;
	mTopBar = NULL;

	delete mPlayerOneScore;
	mPlayerOneScore = NULL;

	delete mTopScore;
	mTopScore = NULL;
	
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

void PlayScreen::SaveScore() {
	XMLElement* element = mHighScore.FirstChildElement("Level")->FirstChild()->NextSiblingElement();
	int currentHighScore = element->IntAttribute("score");

	if(mPlayer->GPA() > currentHighScore) {
		element->SetAttribute("score", mPlayer->GPA());
	}

	mHighScore.SaveFile("Score.xml");
}

void PlayScreen::LoadScore() {
	XMLElement* element = mHighScore.FirstChildElement("Level")->FirstChild()->NextSiblingElement();
	int currentHighScore = element->IntAttribute("score");

	mTopScore->Score(currentHighScore);
}

bool PlayScreen::GameOver() {
	/*
	if(mTimer->DeltaTime() == 5.0f)
		return true;;

	return false;*/
	if (mLevelStartTimer > 45.0f) {
	mLevelStartTimer = 0.0f;
	return true;
}	

	return false;
}

int counter = 0;

void PlayScreen::Update() {
	while (counter < 1) {
		LoadScore();
		counter++;
	}
	
	if(mGameStarted) {
		
		if(!mLevelStarted) {
			
			if(mLevelStartTimer >= mLevelStartDelay)
				StartNextLevel();
			
		}
		
		
	} else {
		if(!Mix_PlayingMusic()) {
			
			mGameStarted = true;
		}
	}
	
	if(mGameStarted ) {
	mLevelStartTimer += mTimer->DeltaTime();

		
		if(mLevelStarted) {
			mLevel->Update();

			if(mLevel->State() == Level::finished) {
				
				mLevelStarted = false;
			}
		}
		mPlayer->Update();
		mPlayerOneScore->Score(mPlayer->GPA());
		SaveScore();
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
			mPlayerOneScore->Render();
			mTopScoreLabel->Render();
			mTopScore->Render();
	}
}