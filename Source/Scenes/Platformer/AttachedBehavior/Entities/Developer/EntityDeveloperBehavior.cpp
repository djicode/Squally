#include "EntityDeveloperBehavior.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Input/ClickableNode.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/EngineCollisionTypes.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Stats/EntityHealthBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Squally/Stats/SquallyHealthBehavior.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string EntityDeveloperBehavior::MapKeyAttachedBehavior = "entity-debug";

EntityDeveloperBehavior* EntityDeveloperBehavior::create(GameObject* owner)
{
	EntityDeveloperBehavior* instance = new EntityDeveloperBehavior(owner);

	instance->autorelease();

	return instance;
}

EntityDeveloperBehavior::EntityDeveloperBehavior(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);
	this->resurrectButton = ClickableNode::create(UIResources::Menus_Icons_Heart, UIResources::Menus_Icons_Heart);
	this->killButton = ClickableNode::create(UIResources::Menus_Icons_Skull, UIResources::Menus_Icons_Skull);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
	
	this->resurrectButton->setVisible(false);
	this->killButton->setVisible(false);

	this->addChild(this->resurrectButton);
	this->addChild(this->killButton);
}

EntityDeveloperBehavior::~EntityDeveloperBehavior()
{
}

void EntityDeveloperBehavior::initializePositions()
{
	super::initializePositions();
	
	this->killButton->setPosition(Vec2(-64.0f, this->entity->getEntitySize().height + this->entity->getHoverHeight() / 2.0f + 32.0f));
	this->resurrectButton->setPosition(Vec2(64.0f, this->entity->getEntitySize().height + this->entity->getHoverHeight() / 2.0f + 32.0f));
}

void EntityDeveloperBehavior::onDeveloperModeEnable()
{
	super::onDeveloperModeEnable();

	this->resurrectButton->setVisible(true);
	this->killButton->setVisible(true);
}

void EntityDeveloperBehavior::onDeveloperModeDisable()
{
	super::onDeveloperModeDisable();

	this->resurrectButton->setVisible(false);
	this->killButton->setVisible(false);
}

void EntityDeveloperBehavior::onLoad()
{
	this->resurrectButton->setMouseClickCallback([=](InputEvents::MouseEventArgs*)
	{
		this->entity->setState(StateKeys::IsAlive, Value(true));
	});

	this->killButton->setMouseClickCallback([=](InputEvents::MouseEventArgs*)
	{
		this->entity->setState(StateKeys::IsAlive, Value(false));
	});
}