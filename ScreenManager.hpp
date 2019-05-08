// Used to decide switching between main menu and play screen

#ifndef ScreenManager_h
#define ScreenManager_h
#include "StartScreen.hpp"
#include "PlayScreen.hpp"
#include "AudioManager.hpp"
#include "PauseScreen.hpp"

class ScreenManager {
	
private:
	
	enum SCREENS { start, play, pause};
	
	static ScreenManager* sInstance;
	
	InputManager* mInput;
	AudioManager* mAudio;
	
	StartScreen* mStartScreen;
	PlayScreen* mPlayScreen;
	PauseScreen* mPauseScreen;

	SCREENS mCurrentScreen;
	
public:
	
	static ScreenManager* Instance();
	static void Release();
	
	void Update();
	void Render();
	
private:
	
	ScreenManager();
	~ScreenManager();
};
#endif 