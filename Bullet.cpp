#include "Bullet.hpp"
#include "BoxCollider.hpp"

Bullet::Bullet() {

	mTimer = Timer::Instance();

	mSpeed = 500.0f;

	mTexture = new Texture("bullet3.png");
	mTexture->Parent(this);
	mTexture->Pos(VEC2_ZERO);

	Reload();

	AddCollider(new BoxCollider(mTexture->ScaledDimensions()));
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

void Bullet::Update() {

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