#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class RockGolem : public Enemy
{
public:
	static RockGolem * create();

private:
	RockGolem();
	~RockGolem();
};
