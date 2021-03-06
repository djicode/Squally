#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class LocalizedString;

class Lazarus : public PlatformerEnemy
{
public:
	static Lazarus* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;
	
protected:
	Lazarus(cocos2d::ValueMap& properties);
	virtual ~Lazarus();

private:
	typedef PlatformerEnemy super;
};
