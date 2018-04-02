#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class VampireLord : public Enemy
{
public:
	static VampireLord * create();

private:
	VampireLord();
	~VampireLord();
};
