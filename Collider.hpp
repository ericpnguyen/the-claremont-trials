// Abstract class for physic colliders circle and box

#ifndef _COLLIDER_H
#define _COLLIDER_H
#include "Texture.hpp"

using namespace QuickSDL;

class Collider : public GameEntity {

public:
	enum class ColliderType {
		Box,
		Circle
	};

protected:
	ColliderType mType;

public:
	Collider(ColliderType type);
	virtual ~Collider();

	virtual Vector2 GetFurthestPoint() = 0;

	ColliderType GetType();

	virtual void Render();
};

#endif // _COLLIDER_H