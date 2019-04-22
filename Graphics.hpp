#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <stdio.h>

class Graphics {

public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:
	static Graphics* sInstance;
	static bool sInitialized;

	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;

public:
	static Graphics* Instance();
	static void Release();
	static bool Initialized();

	void Render();

private:
	Graphics();
	~Graphics();

	bool Init();
};

#endif 