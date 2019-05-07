#ifndef _Player_HPP
#define _Player_HPP
#include "AnimatedTexture.hpp"
#include "InputManager.hpp"
#include "Bullet.hpp"
#include "AudioManager.hpp"

using namespace QuickSDL;

class Player : public GameEntity {

private:

    // Regular instances
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;

    // Player variables
    bool mVisible;
    bool mAnimating;
    int mGPA;

    Texture* mPlayer;

    float mMoveSpeed;
    Vector2 mMoveBounds;

    // Bullet array meaning only two bullets on screen at once
    static const int MAX_BULLETS = 2;
    Bullet* mBullets[MAX_BULLETS];

private:

    void HandleMovement();
    void HandleFiring();

public:

    Player();
    ~Player();

    void Visible(bool visible);

    bool IsAnimating();

    int GPA();

    void AddGPA(int change);

    void Update() override;

    void Render() override;
};
#endif