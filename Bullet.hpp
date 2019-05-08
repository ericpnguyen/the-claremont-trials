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
	Bullet(bool friendly);
	~Bullet();

	void Fire(Vector2 pos);
	void Reload();

	void Hit(PhysEntity* other) override;

	void Update() override;

	void Render() override;

private:
	bool IgnoreCollisions() override;
};

#endif 