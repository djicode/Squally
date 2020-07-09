#pragma once

#include "Engine/Maps/GameObject.h"

namespace cocos2d
{
	class Sprite;
}

class CollisionObject;

class LiftBase : public GameObject
{
public:

protected:
	LiftBase(cocos2d::ValueMap& properties, cocos2d::Size collisionSize, std::string railArt);
	virtual ~LiftBase();

	enum class MovementDirection
	{
		UpDown,
		LeftRight
	};

	void onEnter() override;
	virtual float getPadding();

	float width;
	float height;
	MovementDirection movementDirection;
	cocos2d::Node* railingNode;
	cocos2d::Node* liftNode;
	CollisionObject* liftCollision;

private:
	typedef GameObject super;

	float speedPer256px;

	cocos2d::Sprite* railing;

	static const std::string PropertySpeed;
};