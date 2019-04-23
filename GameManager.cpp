#include "GameManager.hpp"

GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {

	if(sInstance == NULL) {
		sInstance = new GameManager();
	}

	return sInstance;
}

void GameManager::Release() {

	delete sInstance;
	sInstance = NULL;
}

GameManager::GameManager() {

	mQuit = false;
	mGraphics = Graphics::Instance();

	if(!Graphics::Initialized()) {
		mQuit = true;
	}

	std::string path = SDL_GetBasePath();
	path.append("Start_screen.png");
	mTex = new Texture(path);
}

GameManager::~GameManager() {

	Graphics::Release();
	mGraphics = NULL;

	delete mTex;
	mTex = NULL;
}

void GameManager::Run() {

	while(!mQuit) {
		while(SDL_PollEvent(&mEvents) != 0) {
			if(mEvents.type == SDL_QUIT) {
				mQuit = true;
			}
			mGraphics->ClearBackBuffer();
			mTex->Render();
			mGraphics->Render();

			if(mEvents.type==SDL_KEYDOWN){
					if(mEvents.key.keysym.sym == SDLK_0){
						std::string path = SDL_GetBasePath();
						path.append("Play_screen.png");
						mTex = new Texture(path);
					}
					if(mEvents.key.keysym.sym == SDLK_1){
						std::string path = SDL_GetBasePath();
						path.append("End_screen.png");
						mTex = new Texture(path);
					}
			}

		}
	}
}