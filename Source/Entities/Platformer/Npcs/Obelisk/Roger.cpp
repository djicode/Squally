#include "Roger.h"

const std::string Roger::MapKeyNpcRoger = "roger";

Roger* Roger::deserialize(ValueMap* initProperties)
{
	Roger* instance = new Roger(initProperties);

	instance->autorelease();

	return instance;
}

Roger::Roger(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Obelisk_Npcs_Roger_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Roger::~Roger()
{
}