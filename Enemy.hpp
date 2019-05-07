#ifndef _ENEMY_H
#define _ENEMY_H
#include "AnimatedTexture.hpp"
#include "BezierPath.hpp"
#include "Graphics.hpp"
#include "PhysEntity.hpp"


class Enemy: public PhysEntity {

private:
	static std::vector<std::vector<Vector2>> sPaths;

	enum STATES {flyIn};


	bool alive(); 
	bool hasCollided(int x);
	void kill(); 
	void changeSpeed(float x);

	Timer* mTimer; 

	Texture* mTexture; 

	STATES mCurrentState;

	int mCurrentPath;

	int mCurrentWaypoint;

	const float EPSILON = 5.0f;

	float mSpeed; 
	Vector2 mMoveBounds; 
	bool mAlive;

public:

	static void CreatePaths();

	Enemy(int path);

	virtual ~Enemy();

	virtual void HandleFlyInState();

	void HandleStates();


	// void Visible(bool visible);


	void Update();

	void Render();
}; 
#endif