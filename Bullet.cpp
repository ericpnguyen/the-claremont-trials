#include "Bullet.hpp"
#include "BoxCollider.hpp"
#include "PhysicsManager.hpp"

Bullet::Bullet(bool friendly) {

	mTimer = Timer::Instance();

	mSpeed = 1000.0f;

	// Texture

	mTexture = new Texture("bullet3.png");
	mTexture->Parent(this);
	mTexture->Pos(VEC2_ZERO);

	Reload();

	AddCollider(new BoxCollider(mTexture->ScaledDimensions()));

	if(friendly)
		PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::FriendlyProjectiles);
	else
		PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::HostileProjectiles);
}

Bullet::~Bullet() {

	mTimer = NULL;

	delete mTexture;
	mTexture = NULL;
}

void Bullet::Fire(Vector2 pos) {

	Pos(pos);
	Active(true);
}

void Bullet::Reload() {

	Active(false);
}

void Bullet::Hit(PhysEntity* other) {
	Reload();
}

bool Bullet::IgnoreCollisions() {
	return !Active();
}

void Bullet::Update() {

	// Move bullet up and get rid of it if it's offscreen
	if (Active()) {
		Translate(-VEC2_UP * mSpeed * mTimer->DeltaTime(), local);

		Vector2 pos = Pos();

		if(pos.y < -OFFSCREEN_BUFFER || pos.y > Graphics::Instance()->SCREEN_HEIGHT + OFFSCREEN_BUFFER) {
			Reload();
		}
	}
}

void Bullet::Render() {

	if(Active()) {
		mTexture->Render();
		PhysEntity::Render();
	}
}