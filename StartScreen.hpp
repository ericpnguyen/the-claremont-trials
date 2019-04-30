#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include "AnimatedTexture.hpp"
#include "InputManager.hpp"

namespace QuickSDL {

	class StartScreen : public GameEntity {

	private:
		// Top Bar Entities
		GameEntity* mTopBar;
		Texture* mHiScore;

		// Play Mode Entities
		GameEntity* mPlayModes;
		Texture* mOnePlayerMode;
		Texture* mCursor;


	public:
		StartScreen();
		~StartScreen();

		void Update();

		void Render();
	}; 
}
#endif