#include "Player.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Player::Player(){

    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    // Player variables
    mVisible = false;
    mAnimating = false;
    mGPA = 200;

    // Player texture
    mPlayer = new Texture("player.png");
    mPlayer->Parent(this);
    mPlayer->Pos(VEC2_ZERO);

    // Movement of player
    mMoveSpeed = 1500.0f;
    mMoveBounds = Vector2(20.0f, 1000.0f);

    // Creating bullets
    for(int i = 0; i < MAX_BULLETS; i++) {
        mBullets[i] = new Bullet(true);
    }
}

Player::~Player(){
    
    mTimer = NULL;
    mInput = NULL;
    mAudio = NULL;

    // Player 
    delete mPlayer;
    mPlayer = NULL;

    // Bullets
    for (int i = 0; i < MAX_BULLETS; i++) {
        delete mBullets[i];
        mBullets[i] = NULL;
    }
}

// Keys to move player
void Player::HandleMovement() {

    if(mInput->KeyDown(SDL_SCANCODE_RIGHT)){
        Translate(VEC2_RIGHT*mMoveSpeed*mTimer->DeltaTime(), world);
    }
    else if(mInput->KeyDown(SDL_SCANCODE_LEFT)){
        Translate(-VEC2_RIGHT*mMoveSpeed*mTimer->DeltaTime(), world);
    }

    Vector2 pos = Pos(local);

    if(pos.x < mMoveBounds.x)
        pos.x = mMoveBounds.x;
        
    else if(pos.x > mMoveBounds.y){
        pos.x = mMoveBounds.y;
    }

    Pos(pos);
}

// Press space to fire
void Player::HandleFiring() {

    if(mInput->KeyPressed(SDL_SCANCODE_SPACE)) {

        for(int i = 0; i < MAX_BULLETS; i++) {

            if(!mBullets[i]->Active()) {

                mBullets[i]->Fire(Pos());
                mAudio->PlaySFX("shotgun.wav");
                break;
            }
        }
    }
}

void Player::Visible(bool visible) {

    mVisible = visible;
}

bool Player::IsAnimating() {

    return mAnimating;
}

int Player::GPA(){

    return mGPA;
}

void Player::AddGPA(int change) {

    mGPA += change;
}

void Player::Update() {

    if(Active()) {

        HandleMovement();
        HandleFiring();
    }

    // Update bullets
    for (int i = 0; i < MAX_BULLETS; i++) {
        mBullets[i]->Update();
    }
}

// Render bullets and player
void Player::Render() {

    if (mVisible) {

        if(mAnimating) {

        }
        else {
            mPlayer->Render();
        }
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        mBullets[i]->Render();
    }
}