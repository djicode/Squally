#include "Penguin1.h"

Penguin1* Penguin1::create()
{
	Penguin1* instance = new Penguin1();

	instance->autorelease();

	return instance;
}

Penguin1::Penguin1() : Enemy::Enemy(
	Resources::Entities_Environment_Volcano_BossDemonKing_Animations,
	false)
{
}

Penguin1::~Penguin1()
{
}
