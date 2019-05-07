#include "Enemy.hpp"
#include "BoxCollider.hpp"

using namespace QuickSDL;

std::vector<std::vector<Vector2>> Enemy::sPaths;

void Enemy::CreatePaths() {

    int currentPath = 0;
    BezierPath* path = new BezierPath();
    path->AddCurve( {Vector2(512.0f, 0.0f), Vector2(512.0f, 0.0f), Vector2(512.0f, 896.0f), Vector2(512.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 1;
    path = new BezierPath();
    path->AddCurve( {Vector2(256.0f, 0.0f), Vector2(256.0f, 0.0f), Vector2(256.0f, 896.0f), Vector2(256.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 2;
    path = new BezierPath();
    path->AddCurve( {Vector2(768.0f, 0.0f), Vector2(768.0f, 0.0f), Vector2(768.0f, 896.0f), Vector2(768.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;
}

Enemy::Enemy(int path)
{
    mSpeed = 400.0f; 
    mMoveBounds = Vector2(0.0f, 800.0f);

    mTimer = Timer::Instance();
    mCurrentPath = path;

    mCurrentState = flyIn;

    mCurrentWaypoint = 0;
    Pos(sPaths[mCurrentPath][mCurrentWaypoint]);
    //mCurrentState = incoming;

    mTexture = new Texture("A.png");
    mTexture->Parent(this);
    mTexture->Pos(VEC2_ZERO);
    mAlive = true; 

    AddCollider(new BoxCollider(mTexture->ScaledDimensions()));
}

//deconstructor
Enemy::~Enemy()
{
    mTimer = NULL;

    delete mTexture;
    mTexture = NULL;
}

void Enemy::HandleFlyInState() {
    if((sPaths[mCurrentPath][mCurrentWaypoint] - Pos()).MagnitudeSqr() < EPSILON) {
        mCurrentWaypoint++;
    }
    if(mCurrentWaypoint < sPaths[mCurrentPath].size()) {
        Vector2 dist = sPaths[mCurrentPath][mCurrentWaypoint] - Pos();
        Translate(dist.Normalized() * mTimer->DeltaTime() * mSpeed);
    }
}

void Enemy::HandleStates() {
    switch(mCurrentState) {
        case flyIn:
            HandleFlyInState();
            break;
    }
}

bool Enemy::alive()
{
	return mAlive;
}

bool Enemy::hasCollided(int pos)
{
    return false;
}

void Enemy::kill()
{   
}    

void Enemy::changeSpeed(float x)
{
    mSpeed = x; 
}

void Enemy::Update()
{
    if(Active())
        HandleStates();
}

// void Enemy:: HandleIncomingState(){}

void Enemy::Render()
{
    if (Active()) {
        mTexture->Render();
        PhysEntity::Render();
        // for (int i = 0; i < sPaths[mCurrentPath].size() - 1; i++)
        // {
        //     Graphics::Instance()->DrawLine(sPaths[mCurrentPath][i].x, sPaths[mCurrentPath][i].y, sPaths[mCurrentPath][i+1].x, sPaths[mCurrentPath][i+1].y);
        // }
    }
}

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
// }