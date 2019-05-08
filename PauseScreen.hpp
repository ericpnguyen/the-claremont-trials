#ifndef _PAUSESCREEN_HPP
#define _PAUSESCREEN_HPP

#include "AnimatedTexture.hpp"
#include "InputManager.hpp"
#include "Player.hpp"

namespace QuickSDL {

	class PauseScreen : public GameEntity {

	private:

		Timer* mTimer;
		InputManager* mInput;

		// Top Bar Entities
		GameEntity* mTopBar;

		// Logo Entity
		Texture* mLogo;

		// Play Mode Entities
		GameEntity* mPlayModes;

		Texture* mResumeGame;
		Texture* mCursor;
		Texture* mExitGame;
		Texture* mPauseHelp;
		Vector2 mCursorStartPos;
		Vector2 mCursorOffset;

		int mSelectedMode;

	public:
		PauseScreen();
		~PauseScreen();


		int SelectedMode();

		void ChangeSelectedMode(int change);

		void Update();

		void Render();
	}; 
}
#endif