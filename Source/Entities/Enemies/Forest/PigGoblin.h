#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class PigGoblin : public Enemy
{
public:
	static PigGoblin * create();

private:
	PigGoblin();
	~PigGoblin();
};
