#include "PauseScreen.hpp"

namespace QuickSDL {

	PauseScreen::PauseScreen() {

		mTimer = Timer::Instance();
		mInput = InputManager::Instance();

		// Top Bar Entities
		mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));



		mTopBar->Parent(this);
		mTopBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 25.0f));

		// Logo Entity
		mLogo = new Texture("logo.png");
		mLogo->Parent(this);
		mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.25f));

		// Play Mode Entities
		mPlayModes = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.55f));
		mExitGame = new Texture("Exit Game", "emulogic.ttf", 16, {0, 0, 0});
        mResumeGame = new Texture("Resume Game", "emulogic.ttf", 16, {0, 0, 0});


		mCursor = new Texture("cursor.png");

		mExitGame->Parent(mPlayModes);
		mCursor->Parent(mPlayModes);
        mResumeGame->Parent(mPlayModes);

		mResumeGame->Pos(Vector2(0.0f, -80.0f));
		mExitGame->Pos(Vector2(0.0f,-35.0f));
		mCursor->Pos(Vector2(-70.0f, -38.0f));

		mPlayModes->Parent(this);

		mCursorStartPos = mCursor->Pos(local);
		mCursorOffset = Vector2(0.0f, 45.0f);
		mSelectedMode = 0;
	}

	PauseScreen::~PauseScreen() {
		// Freeing Top Bar Entities
		delete mTopBar;
		mTopBar = NULL;

		// Freeing Logo Entity
		delete mLogo;
		mLogo = NULL;

		// Freeing Play Mode Entities
		delete mPlayModes;
		mPlayModes = NULL;
		delete mResumeGame;
		mResumeGame = NULL;
		delete mCursor;
		mCursor = NULL;
		delete mExitGame;
		mExitGame = NULL;
	}

	int PauseScreen::SelectedMode(){
		
		return mSelectedMode;
	}

	void PauseScreen::ChangeSelectedMode(int change){
		mSelectedMode += change;

		if(mSelectedMode < 0){
			mSelectedMode = 0;
		}
		else if(mSelectedMode > 0){
			mSelectedMode = 1;
		}

		mCursor->Pos(mCursorStartPos + mCursorOffset * mSelectedMode);
	}


	void PauseScreen::Update() {
		if(mInput->KeyPressed(SDL_SCANCODE_DOWN))
			ChangeSelectedMode(1);
		else if(mInput->KeyPressed(SDL_SCANCODE_UP))
			ChangeSelectedMode(-1);
	}

	void PauseScreen::Render() {

		mLogo->Render();

		mResumeGame->Render();
		mCursor->Render();
		mExitGame->Render();
	}
}