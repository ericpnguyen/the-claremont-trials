// Main menu

#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include "AnimatedTexture.hpp"
#include "InputManager.hpp"
#include "Player.hpp"

namespace QuickSDL {

	class StartScreen : public GameEntity {

	private:

		Timer* mTimer;
		InputManager* mInput;

		// Logo Entity
		Texture* mLogo;

		// Play Mode Entities
		GameEntity* mPlayModes;
		Texture* mOnePlayerMode;
		Texture* mCursor;
		Texture* mExitGame;
		Vector2 mCursorStartPos;
		Vector2 mCursorOffset;
		int mSelectedMode;

	public:
		StartScreen();
		~StartScreen();

		int SelectedMode();

		void ChangeSelectedMode(int change);

		void Update();

		void Render();
	}; 
}
#endif