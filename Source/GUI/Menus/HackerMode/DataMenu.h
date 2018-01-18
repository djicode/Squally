#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Shaders/PostProcess.h"
#include "GUI/Components/MenuSprite.h"
#include "Objects/Hackables/HackableObject.h"

using namespace cocos2d;

class DataMenu : public Node
{
public:
	static DataMenu * create();

private:
	DataMenu();
	~DataMenu();

	void initializePositions();
	void initializeListeners();

	Sprite* dataMenuBackground;
	MenuSprite* closeButton;
};

