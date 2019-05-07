#include "CircleCollider.hpp"

CircleCollider::CircleCollider(float radius, bool broadPhase)
	: Collider(ColliderType::Circle)
{
	mRadius = radius;
}

CircleCollider::~CircleCollider() {

}

Vector2 CircleCollider::GetFurthestPoint() {
	return VEC2_RIGHT * (mRadius + Pos(GameEntity::local).Magnitude());
}

float CircleCollider::GetRadius() {
	return mRadius;
}