// Abstract class for physic colliders circle and box

#include "Collider.hpp"

Collider::Collider(ColliderType type)
	: mType(type)
{
}

Collider::~Collider() 
{
}

Collider::ColliderType Collider::GetType() {
	return mType;
}

void Collider::Render() {
}