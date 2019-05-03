/*#include "Enemy.hpp"

namespace QuickSDL {
Enemy::Enemy(float x)
{
    
    mMoveSpeed = x; 
    mMoveBounds = Vector2(0.0f, 800.0f);

    mTimer = Timer::Instance();
    //mCurrentState = incoming;
    

    mTexture = new Texture("");
    mTexture->Parent(this);
    mTexture->Pos(VEC2_ZERO);
    mAlive = 1; 
}

//deconstructor
Enemy::~Enemy()
{
    mTimer = NULL;
    delete mTexture;
    mTexture = NULL;
}
bool Enemy::alive()
{
    return mAlive=1; 
}
bool Enemy::hasCollided(int pos)
{
    return false;
}

void Enemy::kill()

{   
}    

void Enemy::changeSpeed(float x){
    mMoveSpeed =x; 
}



void Enemy::Update()
{
    if (alive())
    {
        mTexture->Render();
        for (int i = 0; i < Graphics::Instance()->SCREEN_WIDTH; i++)
        {
            Translate(-VEC2_RIGHT* mMoveSpeed *mTimer->DeltaTime());
        }
        mAlive= false; 
    }
    kill();
} 
}

// void Enemy:: HandleIncomingState(){}

// void Enemy:: Render(){}

// //void Enemy:: HandleDeadState(){}
// //void Enemy:: HandleStates(){

//     switch(mCurrentState){

//         case incoming;
//         HandleIncomingState();
//         break;

//         case dead;
//         HandleDeadState();
//         break;

//     }
// }*/