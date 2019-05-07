#ifndef _Player_HPP
#define _Player_HPP
#include "AnimatedTexture.hpp"
#include "InputManager.hpp"
#include "Bullet.hpp"
#include "AudioManager.hpp"

using namespace QuickSDL;

class Player : public PhysEntity {

private:

    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;

    bool mVisible;
    bool mAnimating;
    bool mWasHit;

    int mGPA;
    int mLives;

    Texture* mPlayer;

    float mMoveSpeed;
    Vector2 mMoveBounds;

    // Bullet array
    static const int MAX_BULLETS = 5;
    Bullet* mBullets[MAX_BULLETS];

private:

    void HandleMovement();
    void HandleFiring();

public:

    Player();
    ~Player();

    void Visible(bool visitive);

    void Hit(PhysEntity* other) override;
    bool WasHit();

    bool IsAnimating();

    int GPA();
    int Lives();

    void AddGPA(int change);

    void Update() override;

    void Render() override;
};






#endif