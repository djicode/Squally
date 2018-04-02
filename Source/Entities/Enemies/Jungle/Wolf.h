#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class Wolf : public Enemy
{
public:
	static Wolf * create();

private:
	Wolf();
	~Wolf();
};
