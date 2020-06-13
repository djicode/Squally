#pragma once

#include "Engine/GlobalNode.h"

namespace cocos2d
{
	class EventCustom;
}

class PlatformerCollisionMapping : public GlobalNode
{
public:
	static void registerGlobalNode();

	void onMapKeyMappingRequest(cocos2d::EventCustom* eventCustom);

	static const std::string MapKeyCollisionTypePhysics;
	static const std::string MapKeyCollisionTypeSolid;
	static const std::string MapKeyCollisionTypePassThrough;
	static const std::string MapKeyCollisionTypePlayer;
	static const std::string MapKeyCollisionTypePlayerHover;
	static const std::string MapKeyCollisionTypeNpc;
	static const std::string MapKeyCollisionTypeEnemy;
	static const std::string MapKeyCollisionTypeForce;
	static const std::string MapKeyCollisionTypeSolidNpc;
	static const std::string MapKeyCollisionTypeWater;
	static const std::string MapKeyCollisionTypeDamage;
	static const std::string MapKeyCollisionTypeKill;

protected:
	PlatformerCollisionMapping();
	virtual ~PlatformerCollisionMapping();

	void initializeListeners() override;

private:
	typedef GlobalNode super;
	
	static PlatformerCollisionMapping* instance;
};
