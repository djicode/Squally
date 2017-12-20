#include "TutorialScreen.h"

TutorialScreen * TutorialScreen::create()
{
	TutorialScreen* tutorialScreen = new TutorialScreen();

	tutorialScreen->autorelease();

	return tutorialScreen;
}

TutorialScreen::TutorialScreen()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->background = Sprite::create(Resources::Menus_TutorialMenu_Background);
	this->tutorialWindow = Sprite::create(Resources::Menus_TutorialMenu_TutorialSelect);

	this->floatingBox1 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectBox1, Vec2(-32.0f, -32.0f), Vec2(8.0f, 5.0f));
	this->floatingBox2 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectBox2, Vec2(32.0f, 32.0f), Vec2(8.0f, 8.0f));
	this->floatingMisc1 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectSci1, Vec2(64.0f, 32.0f), Vec2(7.0f, 8.0f));
	this->floatingMisc2 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectSci2, Vec2(32.0f, 32.0f), Vec2(8.0f, 8.0f));
	this->floatingMisc3 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectSci3, Vec2(-32.0f, 32.0f), Vec2(8.0f, 8.0f));
	this->floatingObelisk1 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectObelisk1, Vec2(-64.0f, -64.0f), Vec2(8.0f, 8.0f));
	this->floatingObeliskParent = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectObeliskChildren, Vec2(-8.0f, 8.0f), Vec2(8.0f, 8.0f));
	this->floatingObeliskChild1 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectObeliskChildren_01, Vec2(-16.0f, 16.0f), Vec2(8.0f, 8.0f));
	this->floatingObeliskChild2 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectObeliskChildren_02, Vec2(16.0f, -16.0f), Vec2(8.0f, 8.0f));
	this->floatingObeliskChild3 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectObeliskChildren_03, Vec2(16.0f, -16.0f), Vec2(8.0f, 8.0f));
	this->floatingObeliskChild4 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectObeliskChildren_04, Vec2(-24.0f, 24.0f), Vec2(8.0f, 8.0f));
	this->floatingRocks2 = FloatingSprite::create(Resources::Menus_TutorialMenu_ObjectRocks2, Vec2(-32.0f, 32.0f), Vec2(8.0f, 8.0f));

	this->nether = ParticleSystemQuad::create(Resources::Particles_BlueNether);
	this->swirl = ParticleSystemQuad::create(Resources::Particles_BlueStarCircle);
	this->mouse = Mouse::create();

	this->background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	this->nether->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->swirl->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	this->floatingBox1->setPosition(Vec2(origin.x + visibleSize.width / 2 + 640.0f, origin.y + visibleSize.height / 2 + 420.0f));
	this->floatingBox2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 500.0f, origin.y + visibleSize.height / 2 + 64.0f));
	this->floatingMisc1->setPosition(Vec2(origin.x + visibleSize.width / 2 + 224.0f, origin.y + visibleSize.height / 2 + 320.0f));
	this->floatingMisc2->setPosition(Vec2(origin.x + visibleSize.width / 2 + 540.0f, origin.y + visibleSize.height / 2));
	this->floatingMisc3->setPosition(Vec2(origin.x + visibleSize.width / 2 - 640.0f, origin.y + visibleSize.height / 2 + 420.0f));
	this->floatingObelisk1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 196.0f, origin.y + visibleSize.height / 2 - 320.0f));
	this->floatingObeliskParent->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240.0f, origin.y + visibleSize.height / 2 + 352.0f));
	this->floatingObeliskChild1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240.0f, origin.y + visibleSize.height / 2 + 352.0f));
	this->floatingObeliskChild2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240.0f, origin.y + visibleSize.height / 2 + 352.0f));
	this->floatingObeliskChild3->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240.0f, origin.y + visibleSize.height / 2 + 352.0f));
	this->floatingObeliskChild4->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240.0f, origin.y + visibleSize.height / 2 + 352.0f));
	this->floatingRocks2->setPosition(Vec2(origin.x + visibleSize.width / 2 + 240.0f, origin.y + visibleSize.height / 2 - 272.0f));

	this->tutorialWindow->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	//this->addChild(this->background);
	this->addChild(this->nether);
	this->addChild(this->swirl);

	this->addChild(this->floatingBox1);
	this->addChild(this->floatingBox2);
	this->addChild(this->floatingMisc1);
	this->addChild(this->floatingMisc2);
	this->addChild(this->floatingMisc3);
	this->addChild(this->floatingObelisk1);
	this->addChild(this->floatingObeliskChild1);
	this->addChild(this->floatingObeliskChild3);
	this->addChild(this->floatingObeliskParent);
	this->addChild(this->floatingObeliskChild2);
	this->addChild(this->floatingObeliskChild4);
	this->addChild(this->floatingRocks2);

	this->addChild(this->tutorialWindow);

	this->LoadNodes();

	this->addChild(this->mouse);
}

TutorialScreen::~TutorialScreen()
{
}

void TutorialScreen::LoadNodes()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	float screenCenterX = origin.x + visibleSize.width / 2;
	float screenCenterY = origin.y + visibleSize.height / 2;

	this->tutorialButtons = new std::vector<MenuSprite*>();

	this->addChild(TutorialItem::create(
		"Exact Value Scan I",
		Resources::Levels_Debug,
		Vec2(screenCenterX, screenCenterY + 168.0f - 12.0f)
	));

	this->addChild(TutorialItem::create(
		"Exact Value Scan II",
		Resources::Levels_Debug,
		Vec2(screenCenterX, screenCenterY + 72.0f - 12.0f * 2)
	));

	this->addChild(TutorialItem::create(
		"Unknown Value Scan",
		Resources::Levels_Debug,
		Vec2(screenCenterX, screenCenterY - 24.0f - 12.0f * 3)
	));

	this->addChild(TutorialItem::create(
		"Data Types - Float",
		Resources::Levels_Debug,
		Vec2(screenCenterX, screenCenterY - 120.0f - 12.0f * 4)
	));
}

void TutorialScreen::onEnter()
{
	Scene::onEnter();

	this->InitializeListeners();
}

void TutorialScreen::InitializeListeners()
{
	EventListenerKeyboard* listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(TutorialScreen::OnKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void TutorialScreen::OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		Director::getInstance()->replaceScene(TitleScreen::create());
		break;
	}
}
