#ifndef _SCREENMANAGER_HPP
#define _SCREENMANAGER_HPP
#include "StartScreen.hpp"
#include "PlayScreen.hpp"


class ScreenManager {

private:

    enum SCREENS { start, play};

    static ScreenManager* sInstance;

    QuickSDL::InputManager* mInput;

    QuickSDL::StartScreen* mStartScreen;
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