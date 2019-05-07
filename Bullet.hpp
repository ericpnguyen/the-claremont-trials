#ifndef _BULLET_H
#define _BULLET_H

#include "PhysEntity.hpp"
#include "Timer.hpp"

using namespace QuickSDL;

class Bullet : public PhysEntity {

private:
	const int OFFSCREEN_BUFFER = 10;

	Timer* mTimer;

	float mSpeed;

	Texture* mTexture;

public:
	Bullet();
	~Bullet();

	void Fire(Vector2 pos);
	void Reload();

	void Update();

	void Render();
};

#endif 