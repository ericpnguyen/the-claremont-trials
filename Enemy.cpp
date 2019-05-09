#include "Enemy.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

using namespace QuickSDL;

std::vector<std::vector<Vector2>> Enemy::sPaths;
Player* Enemy::sPlayer = nullptr;

void Enemy::CreatePaths() {

    // Creating paths for enemy homework assignments
    int currentPath = 0;
    BezierPath* path = new BezierPath();
    path->AddCurve( {Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f), Vector2(0.0f, 896.0f), Vector2(0.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 1;
    path = new BezierPath();
    path->AddCurve( {Vector2(51.0f, 0.0f), Vector2(51.0f, 0.0f), Vector2(51.0f, 896.0f), Vector2(51.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 2;
    path = new BezierPath();
    path->AddCurve( {Vector2(102.0f, 0.0f), Vector2(102.0f, 0.0f), Vector2(102.0f, 896.0f), Vector2(102.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 3;
    path = new BezierPath();
    path->AddCurve( {Vector2(153.0f, 0.0f), Vector2(153.0f, 0.0f), Vector2(153.0f, 896.0f), Vector2(153.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 4;
    path = new BezierPath();
    path->AddCurve( {Vector2(204.0f, 0.0f), Vector2(204.0f, 0.0f), Vector2(204.0f, 896.0f), Vector2(204.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 5;
    path = new BezierPath();
    path->AddCurve( {Vector2(255.0f, 0.0f), Vector2(255.0f, 0.0f), Vector2(255.0f, 896.0f), Vector2(255.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 6;
    path = new BezierPath();
    path->AddCurve( {Vector2(306.0f, 0.0f), Vector2(306.0f, 0.0f), Vector2(306.0f, 896.0f), Vector2(306.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 7;
    path = new BezierPath();
    path->AddCurve( {Vector2(357.0f, 0.0f), Vector2(357.0f, 0.0f), Vector2(357.0f, 896.0f), Vector2(357.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 8;
    path = new BezierPath();
    path->AddCurve( {Vector2(408.0f, 0.0f), Vector2(408.0f, 0.0f), Vector2(408.0f, 896.0f), Vector2(408.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 9;
    path = new BezierPath();
    path->AddCurve( {Vector2(459.0f, 0.0f), Vector2(459.0f, 0.0f), Vector2(459.0f, 896.0f), Vector2(459.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 10;
    path = new BezierPath();
    path->AddCurve( {Vector2(510.0f, 0.0f), Vector2(510.0f, 0.0f), Vector2(510.0f, 896.0f), Vector2(510.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 11;
    path = new BezierPath();
    path->AddCurve( {Vector2(561.0f, 0.0f), Vector2(561.0f, 0.0f), Vector2(561.0f, 896.0f), Vector2(561.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 12;
    path = new BezierPath();
    path->AddCurve( {Vector2(612.0f, 0.0f), Vector2(612.0f, 0.0f), Vector2(612.0f, 896.0f), Vector2(612.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 13;
    path = new BezierPath();
    path->AddCurve( {Vector2(663.0f, 0.0f), Vector2(663.0f, 0.0f), Vector2(663.0f, 896.0f), Vector2(663.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 14;
    path = new BezierPath();
    path->AddCurve( {Vector2(714.0f, 0.0f), Vector2(714.0f, 0.0f), Vector2(714.0f, 896.0f), Vector2(714.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 15;
    path = new BezierPath();
    path->AddCurve( {Vector2(765.0f, 0.0f), Vector2(765.0f, 0.0f), Vector2(765.0f, 896.0f), Vector2(765.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 16;
    path = new BezierPath();
    path->AddCurve( {Vector2(816.0f, 0.0f), Vector2(816.0f, 0.0f), Vector2(816.0f, 896.0f), Vector2(816.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 17;
    path = new BezierPath();
    path->AddCurve( {Vector2(867.0f, 0.0f), Vector2(867.0f, 0.0f), Vector2(867.0f, 896.0f), Vector2(867.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 18;
    path = new BezierPath();
    path->AddCurve( {Vector2(918.0f, 0.0f), Vector2(918.0f, 0.0f), Vector2(918.0f, 896.0f), Vector2(918.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 19;
    path = new BezierPath();
    path->AddCurve( {Vector2(969.0f, 0.0f), Vector2(969.0f, 0.0f), Vector2(969.0f, 896.0f), Vector2(969.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;

    currentPath = 20;
    path = new BezierPath();
    path->AddCurve( {Vector2(1020.0f, 0.0f), Vector2(1020.0f, 0.0f), Vector2(1020.0f, 896.0f), Vector2(1020.0f, 896.0f) }, 1);

    sPaths.push_back(std::vector<Vector2>());
    path->Sample(&sPaths[currentPath]);
    delete path;
}

Enemy::Enemy(int path)
{
    // Hw assignment moves
    mSpeed = 600.0f; 
    mMoveBounds = Vector2(0.0f, 800.0f);

    mTimer = Timer::Instance();

    // Paths
    mCurrentPath = path;
    mCurrentState = flyIn;
    mCurrentWaypoint = 0;
    Pos(sPaths[mCurrentPath][mCurrentWaypoint]);

    // Hw texture
    mTexture = new Texture("A.png");
    mTexture->Parent(this);
    mTexture->Pos(VEC2_ZERO);
    mAlive = true; 
    mWasHit = false;

    // Collider 
    AddCollider(new BoxCollider(mTexture->ScaledDimensions()));
    mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);
}

// Deconstructor
Enemy::~Enemy()
{
    mTimer = NULL;

    // Texture
    delete mTexture;
    mTexture = NULL;
}

// Grab current player
void Enemy::CurrentPlayer(Player* player) {
    sPlayer = player;
}

// When homeworks first come in how to translate
void Enemy::HandleFlyInState() {
    if((sPaths[mCurrentPath][mCurrentWaypoint] - Pos()).MagnitudeSqr() < EPSILON) {
        mCurrentWaypoint++;
    }
    if(mCurrentWaypoint < sPaths[mCurrentPath].size()) {
        Vector2 dist = sPaths[mCurrentPath][mCurrentWaypoint] - Pos();
        Translate(dist.Normalized() * mTimer->DeltaTime() * mSpeed);
    }
}

bool Enemy::IgnoreCollisions() {
    return !alive();
}

bool Enemy::alive()
{
	return mAlive;
}

void Enemy::Hit(PhysEntity* other) {
    sPlayer->AddGPA(4);
    mAlive = false;
    this->Active(false);
}

bool Enemy::WasHit() {
    return mWasHit;
}

void Enemy::Update()
{
    if(Active()) {
        HandleFlyInState();
    }
}

void Enemy::Render()
{
    if (Active()) {
        mTexture->Render();
        PhysEntity::Render();
    }
}