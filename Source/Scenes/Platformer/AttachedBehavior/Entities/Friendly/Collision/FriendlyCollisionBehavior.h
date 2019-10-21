#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class PlatformerEntity;

class FriendlyCollisionBehavior : public AttachedBehavior
{
public:
	static FriendlyCollisionBehavior* create(GameObject* owner);

	static const std::string MapKeyAttachedBehavior;

protected:
	FriendlyCollisionBehavior(GameObject* owner);
	~FriendlyCollisionBehavior();

	void onLoad() override;

private:
	typedef AttachedBehavior super;

	PlatformerEntity* entity;
};
