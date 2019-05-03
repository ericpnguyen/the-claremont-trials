#include "StartScreen.hpp"

namespace QuickSDL {

	StartScreen::StartScreen() {

		mTimer = Timer::Instance();
		mInput = InputManager::Instance();

		// Top Bar Entities
		mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));
		mHiScore = new Texture("HIGH SCORE - 4.00 GPA", "emulogic.ttf", 16, {0, 0, 0});

		mHiScore->Parent(mTopBar);

		mHiScore->Pos(VEC2_ZERO);

		mTopBar->Parent(this);
		mTopBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 25.0f));

		// Logo Entity
		mLogo = new Texture("logo.png");
		mLogo->Parent(this);
		mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.25f));

		// Play Mode Entities
		mPlayModes = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.55f));
		mOnePlayerMode = new Texture("Play Game", "emulogic.ttf", 16, {0, 0, 0});
		mLoadGame = new Texture("Load Game", "emulogic.ttf", 16, {0, 0, 0});
		mExitGame = new Texture("Exit Game", "emulogic.ttf", 16, {0, 0, 0});

		mCursor = new Texture("cursor.png");

		mOnePlayerMode->Parent(mPlayModes);
		mLoadGame->Parent(mPlayModes);
		mExitGame->Parent(mPlayModes);
		mCursor->Parent(mPlayModes);

		mOnePlayerMode->Pos(Vector2(0.0f, -125.0f));
		mLoadGame->Pos(Vector2(0.0f,-80.0f));
		mExitGame->Pos(Vector2(0.0f,-35.0f));
		mCursor->Pos(Vector2(-50.0f, -83.0f));

		mPlayModes->Parent(this);

		mCursorStartPos = mCursor->Pos(local);
		mCursorOffset = Vector2(0.0f, 45.0f);
		mSelectedMode = 0;
	}

	StartScreen::~StartScreen() {
		// Freeing Top Bar Entities
		delete mTopBar;
		mTopBar = NULL;
		delete mHiScore;
		mHiScore = NULL;

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
		delete mLoadGame;
		mLoadGame = NULL;
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
			mSelectedMode = 2;
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
		mHiScore->Render();

		mLogo->Render();

		mOnePlayerMode->Render();
		mCursor->Render();
		mLoadGame->Render();
		mExitGame->Render();
	}
}