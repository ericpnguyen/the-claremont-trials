#include "Player.hpp"

Player::Player(){

    mTimer = Timer::Instance();

    mInput = InputManager::Instance();

    mVisible = false;

    mAnimating = false;

    mGPA = 0;
    mLives = 3;

    mPlayer = new Texture("player.png");
    mPlayer->Parent(this);
    mPlayer->Pos(VEC2_ZERO);

    mMoveSpeed = 100.0f;
    mMoveBounds = Vector2(0.0f, 800.0f);

}

Player::~Player(){
    
    mTimer = NULL;
    mInput = NULL;

    delete mPlayer;
    mPlayer = NULL;
}

void Player::HandleMovement(){
    if(mInput->KeyDown(SDL_SCANCODE_RIGHT)){
        Translate(VEC2_RIGHT*mMoveSpeed*mTimer->DeltaTime());
    }
    else if(mInput->KeyDown(SDL_SCANCODE_LEFT)){
        Translate(-VEC2_RIGHT*mMoveSpeed*mTimer->DeltaTime());
    }

    Vector2 pos = Pos(local);

    if(pos.x < mMoveBounds.x)
        pos.x = mMoveBounds.x;
        
    else if(pos.x > mMoveBounds.y){
        pos.x = mMoveBounds.y;
    }

    Pos(pos);
}

void Player::Visible(bool visible){
    mVisible = visible;
}

bool Player::IsAnimating(){
    return mAnimating;
}

int Player::GPA(){
    return mGPA;
}

int Player::Lives(){
    return mLives;
}

void Player::AddGPA(int change){
    mGPA += change;
}

void Player::Update(){
    if (mAnimating){

    }
    else{
        if(Active()){
            HandleMovement();
        }
    }
}

void Player::Render(){
    if (mVisible){
        if(mAnimating){

        }
        else{
            mPlayer->Render();
        }
    }
}