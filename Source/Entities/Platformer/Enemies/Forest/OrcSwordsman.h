#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/PlatformerEnemy.h"
#include "Resources.h"

using namespace cocos2d;

class OrcSwordsman : public PlatformerEnemy
{
public:
	static OrcSwordsman * deserialize(ValueMap* initProperties);

	static const std::string MapKeyEnemyOrcSwordsman;

private:
	OrcSwordsman(ValueMap* initProperties);
	~OrcSwordsman();
};