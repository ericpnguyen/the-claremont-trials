#ifndef ScreenManager_h
#define ScreenManager_h
#include "StartScreen.hpp"
#include "PlayScreen.hpp"

class ScreenManager {
	
	
private:
	
	enum SCREENS { start, play };
	
	static ScreenManager* sInstance;
	
	InputManager* mInput;
	
	StartScreen* mStartScreen;
	PlayScreen* mPlayScreen;
	
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