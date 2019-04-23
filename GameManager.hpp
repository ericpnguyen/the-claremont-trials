#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Texture.hpp"

class GameManager {

private:
	static GameManager* sInstance;

	bool mQuit;
	Graphics* mGraphics;

	SDL_Event mEvents;

	Texture* mTex;

public:
	static GameManager* Instance();
	static void Release();

	void Run();

private:
	GameManager();
	~GameManager();
};

#endif