// Used to decide switching between main menu and play screen

#include "ScreenManager.hpp"
#include "StartScreen.hpp"

ScreenManager* ScreenManager::sInstance = NULL;

ScreenManager* ScreenManager::Instance() {
	
	if(sInstance == NULL)
		sInstance = new ScreenManager();
	
	return sInstance;
}

void ScreenManager::Release() {
	
	delete sInstance;
	sInstance = NULL;
}

ScreenManager::ScreenManager() {
	
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();
	
	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();
	mPauseScreen = new PauseScreen();
	
	mCurrentScreen = start;
	mAudio->PlayMusic("menu.mp3");
}

ScreenManager::~ScreenManager() {
	
	mInput = NULL;
	
	delete mStartScreen;
	mStartScreen = NULL;
	
	delete mPlayScreen;
	mPlayScreen = NULL;

	delete mPauseScreen;
	mPauseScreen = NULL;
}

void ScreenManager::Update() {
	
	switch(mCurrentScreen) {
			
		case start:
			mStartScreen->Update();

			if(mInput->KeyPressed(SDL_SCANCODE_RETURN) && mStartScreen->SelectedMode() == 0) {
				mCurrentScreen = play;
				mPlayScreen->StartNewGame();
			}

			if(mInput->KeyPressed(SDL_SCANCODE_RETURN) && mStartScreen->SelectedMode() == 1) {
				exit(1);
			}

			break;
		case play:
			mPlayScreen->Update();

			if(mPlayScreen->GameOver()) {
				exit(1);
			}
			else if(mInput->KeyPressed(SDL_SCANCODE_P)){
				mCurrentScreen = pause;
			}
			break;
		
		case pause:
			mPauseScreen->Update();
			if(mInput->KeyPressed(SDL_SCANCODE_RETURN) && mPauseScreen->SelectedMode() == 0) {
				mAudio->PauseMusic();
				mCurrentScreen = play;
			}

			if(mInput->KeyPressed(SDL_SCANCODE_RETURN) && mPauseScreen->SelectedMode() == 1) {
				exit(1);
			}
	}
}

void ScreenManager::Render() {

	switch(mCurrentScreen) {
			
		case start:
			mStartScreen->Render();
			break;
		case play:
			mPlayScreen->Render();			
			break;
		case pause:
			mPauseScreen->Render();
			break;
	}
}