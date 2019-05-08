#ifndef _ENEMY_H
#define _ENEMY_H
#include "AnimatedTexture.hpp"
#include "BezierPath.hpp"
#include "Graphics.hpp"
#include "PhysEntity.hpp"
#include "Player.hpp"


class Enemy: public PhysEntity {

private:
	
	static std::vector<std::vector<Vector2>> sPaths;

private:

	enum STATES {flyIn};

	bool alive(); 

	Timer* mTimer; 
	Texture* mTexture; 

	STATES mCurrentState;
	int mCurrentPath;
	int mCurrentWaypoint;

	const float EPSILON = 5.0f;

	float mSpeed; 
	Vector2 mMoveBounds; 
	bool mAlive;

	bool mWasHit;

protected:

	bool IgnoreCollisions() override;

public:

	static Player* sPlayer;
	static void CurrentPlayer(Player* player);

	static void CreatePaths();

	Enemy(int path);

	virtual ~Enemy();

	virtual void HandleFlyInState();

	// Hit functions
	void Hit(PhysEntity* other) override;
	bool WasHit();

	void Update() override;
	void Render() override;
}; 
#endif