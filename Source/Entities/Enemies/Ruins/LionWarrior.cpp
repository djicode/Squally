#include "LionWarrior.h"

LionWarrior* LionWarrior::create()
{
	LionWarrior* instance = new LionWarrior();

	instance->autorelease();

	return instance;
}

LionWarrior::LionWarrior() : Enemy::Enemy(
	Resources::Entities_Environment_Volcano_BossDemonKing_Animations,
	false)
{
}

LionWarrior::~LionWarrior()
{
}
