/*
** Code by Ather Omar
**
*/

#ifndef _PHYSICSHELPER_H
#define _PHYSICSHELPER_H

#include "CircleCollider.hpp"
#include "BoxCollider.hpp"
#include "MathHelper.hpp"

// Detect if circle circle collision
inline bool CircleCircleCollision(CircleCollider* c1, CircleCollider* c2) {
	return (c1->Pos() - c2->Pos()).Magnitude() < (c1->GetRadius() + c2->GetRadius());
}

// Check what type of collision
inline bool ColliderColliderCheck(Collider* c1, Collider* c2) {
	if(c1->GetType() == Collider::ColliderType::Circle && c2->GetType() == Collider::ColliderType::Circle) {
		return CircleCircleCollision(static_cast<CircleCollider*>(c1), static_cast<CircleCollider*>(c2));
	}
	return false;
}

#endif // _PHYSICSHELPER_H