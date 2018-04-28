#include "BlueGoblin.h"

BlueGoblin* BlueGoblin::create()
{
	BlueGoblin* instance = new BlueGoblin();

	instance->autorelease();

	return instance;
}

BlueGoblin::BlueGoblin() : Enemy::Enemy(
	Resources::Entities_Environment_Volcano_BossDemonKing_Animations,
	false)
{
}

BlueGoblin::~BlueGoblin()
{
}
