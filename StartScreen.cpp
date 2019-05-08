// Main menu

#include "StartScreen.hpp"

namespace QuickSDL {

	StartScreen::StartScreen() {

		mTimer = Timer::Instance();
		mInput = InputManager::Instance();

		// Logo Entity
		mLogo = new Texture("logo.png");
		mLogo->Parent(this);
		mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.25f));

		// Play Mode Entities
		mPlayModes = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.55f));
		mOnePlayerMode = new Texture("Play Game", "emulogic.ttf", 16, {0, 0, 0});
		mExitGame = new Texture("Exit Game", "emulogic.ttf", 16, {0, 0, 0});

		mCursor = new Texture("cursor.png");

		mOnePlayerMode->Parent(mPlayModes);
		mExitGame->Parent(mPlayModes);
		mCursor->Parent(mPlayModes);

		mOnePlayerMode->Pos(Vector2(0.0f, -80.0f));
		mExitGame->Pos(Vector2(0.0f,-35.0f));
		mCursor->Pos(Vector2(-50.0f, -38.0f));

		mPlayModes->Parent(this);

		mCursorStartPos = mCursor->Pos(local);
		mCursorOffset = Vector2(0.0f, 45.0f);
		mSelectedMode = 0;
	}

	StartScreen::~StartScreen() {

		// Freeing Logo Entity
		delete mLogo;
		mLogo = NULL;

		// Freeing Play Mode Entities
		delete mPlayModes;
		mPlayModes = NULL;
		delete mOnePlayerMode;
		mOnePlayerMode = NULL;
		delete mCursor;
		mCursor = NULL;
		delete mExitGame;
		mExitGame = NULL;
	}

	int StartScreen::SelectedMode(){
		
		return mSelectedMode;
	}

	void StartScreen::ChangeSelectedMode(int change){

		mSelectedMode += change;

		if(mSelectedMode < 0){
			mSelectedMode = 0;
		}
		else if(mSelectedMode >  1){
			mSelectedMode = 1;
		}

		mCursor->Pos(mCursorStartPos + mCursorOffset * mSelectedMode);
	}


	void StartScreen::Update() {

		if(mInput->KeyPressed(SDL_SCANCODE_DOWN))
			ChangeSelectedMode(1);
		else if(mInput->KeyPressed(SDL_SCANCODE_UP))
			ChangeSelectedMode(-1);
	}

	void StartScreen::Render() {
		
		mLogo->Render();

		mOnePlayerMode->Render();
		mCursor->Render();
		mExitGame->Render();
	}
}