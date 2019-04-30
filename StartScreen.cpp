#include "StartScreen.hpp"

namespace QuickSDL {

	StartScreen::StartScreen() {
		// Top Bar Entities
		mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));
		mHiScore = new Texture("HIGH SCORE", "Lobster.otf", 32, {0, 0, 0});

		mHiScore->Parent(mTopBar);

		mHiScore->Pos(VEC2_ZERO);

		mTopBar->Parent(this);
		mTopBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 25.0f));

		// Play Mode Entities
		mPlayModes = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.55f));
		mOnePlayerMode = new Texture("1 Student", "Lobster.otf", 32, {0, 0, 0});
		mCursor = new Texture("cursor.png");

		mOnePlayerMode->Parent(mPlayModes);
		mCursor->Parent(mPlayModes);

		mOnePlayerMode->Pos(Vector2(-18.0f, -35.0f));
		mCursor->Pos(Vector2(-170.0f, -35.0f));

		mPlayModes->Parent(this);
	}

	StartScreen::~StartScreen() {
		// Freeing Top Bar Entities
		delete mTopBar;
		mTopBar = NULL;
		delete mHiScore;
		mHiScore = NULL;

		// Freeing Play Mode Entities
		delete mPlayModes;
		mPlayModes = NULL;
		delete mOnePlayerMode;
		mOnePlayerMode = NULL;
		delete mCursor;
		mCursor = NULL;
	}

	void StartScreen::Update() {

	}

	void StartScreen::Render() {
		mHiScore->Render();

		mOnePlayerMode->Render();
		mCursor->Render();
	}
}