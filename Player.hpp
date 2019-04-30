#ifndef _Player_HPP
#define _Player_HPP
#include "AnimatedTexture.hpp"
#include "InputManager.hpp"

using namespace QuickSDL;

class Player : public GameEntity {

private:

    Timer* mTimer;
    InputManager* mInput;

    bool mVisible;
    bool mAnimating;

    int mGPA;
    int mLives;

    Texture* mPlayer;

    float mMoveSpeed;
    Vector2 mMoveBounds;

private:

    void HandleMovement();

public:

    Player();
    ~Player();

    void Visible(bool visitive);
    bool IsAnimating();

    int GPA();
    int Lives();

    void AddGPA(int change);

    void Update();

    void Render();
};






#endif