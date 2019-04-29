#ifndef _STARTSCREEN_HPP
#define _STARTSCREEN_HPP
#include "AnimatedTexture.hpp"
#include "InputManager.hpp"



using namespace QuickSDL;

class StartScreen : public GameEntity {

private:

    GameEntity* mTopBar;
    Texture* mPlayerOne;
    Texture* mHiScore;
    Texture* mPlayerTwo;


public:

    StartScreen();
    ~StartScreen();

    void Update();

    void Render();
};

#endif