#include "ScreenManager.hpp"

ScreenManager* ScreenManager::sInstance = NULL;

ScreenManager* ScreenManager::Instance(){
    if(sInstance == NULL)
        sInstance = new ScreenManager();

    return sInstance;
}

void ScreenManager::Release(){
    delete sInstance;
    sInstance = NULL;
}

ScreenManager::ScreenManager(){
    
    mInput = QuickSDL::InputManager::Instance();
    mStartScreen = new QuickSDL::StartScreen();
    mPlayScreen = new PlayScreen();

    mCurrentScreen = start;
}

ScreenManager::~ScreenManager(){
    mInput = NULL;

    delete mStartScreen;
    mStartScreen = NULL;
    
    delete mPlayScreen;
    mPlayScreen = NULL;
}

void ScreenManager::Update(){

    switch(mCurrentScreen){

    case start:
        mStartScreen->Update();

        if(mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
            mCurrentScreen = play;
        }
        break;

    case play:
        // mPlayScreen->Update();

        if(mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            mCurrentScreen = start;
        }
        break;
    }

}


void ScreenManager::Render(){
    switch(mCurrentScreen){

    case start:
        mStartScreen->Render();
        break;

    case play:
        // mPlayScreen->Render();
        break;
    }
}