#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class Exterminator : public PlatformerEnemy
{
public:
	static Exterminator* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	Exterminator(cocos2d::ValueMap& properties);
	virtual ~Exterminator();

private:
	typedef PlatformerEnemy super;
};
