#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class Gargoyle : public PlatformerEnemy
{
public:
	static Gargoyle* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyGargoyle;

private:
	typedef PlatformerEnemy super;
	Gargoyle(cocos2d::ValueMap& properties);
	~Gargoyle();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
