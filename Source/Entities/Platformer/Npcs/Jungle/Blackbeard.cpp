#include "Blackbeard.h"

const std::string Blackbeard::MapKeyNpcBlackbeard = "blackbeard";

Blackbeard* Blackbeard::deserialize(ValueMap* initProperties)
{
	Blackbeard* instance = new Blackbeard(initProperties);

	instance->autorelease();

	return instance;
}

Blackbeard::Blackbeard(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Jungle_Npcs_Blackbeard_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Blackbeard::~Blackbeard()
{
}