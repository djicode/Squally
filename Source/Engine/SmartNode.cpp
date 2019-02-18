#include "SmartNode.h"

#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventDispatcher.h"
#include "cocos/base/CCEventListener.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/DeveloperMode/DeveloperModeController.h"
#include "Engine/Events/DeveloperModeEvents.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/SceneEvents.h"

using namespace cocos2d;

SmartNode* SmartNode::create()
{
	SmartNode* instance = new SmartNode();

	instance->autorelease();

	return instance;
}

SmartNode::SmartNode()
{
}

SmartNode::~SmartNode()
{
}

void SmartNode::onEnter()
{
	super::onEnter();

	this->initializePositions();
	this->initializeListeners();

	if (this->isDeveloperModeEnabled())
	{
		this->onDeveloperModeEnable();
	}
}

void SmartNode::onExit()
{
	super::onExit();

	this->removeNonGlobalListeners();
}

void SmartNode::onReenter()
{
	super::onReenter();

	this->initializePositions();
	this->initializeListeners();
}

void SmartNode::initializePositions()
{
}

void SmartNode::initializeListeners()
{
	this->removeAllListeners();

	this->addEventListenerIgnorePause(EventListenerCustom::create(ObjectEvents::EventQueryObject, [=](EventCustom* eventCustom)
	{
		QueryObjectsArgsBase* args = static_cast<QueryObjectsArgsBase*>(eventCustom->getUserData());

		if (args != nullptr)
		{
			args->tryInvoke(this);
		}
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(DeveloperModeEvents::DeveloperModeModeEnableEvent, [=](EventCustom* args)
	{
		this->onDeveloperModeEnable();
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(DeveloperModeEvents::DeveloperModeModeDisableEvent, [=](EventCustom* args)
	{
		this->onDeveloperModeDisable();
	}));
}

void SmartNode::onDeveloperModeEnable()
{
}

void SmartNode::onDeveloperModeDisable()
{
}

bool SmartNode::isDeveloperModeEnabled()
{
	return DeveloperModeController::getInstance()->isDeveloperModeEnabled();
}

void SmartNode::removeAllListeners()
{
	this->getEventDispatcher()->removeEventListenersForTarget(this);
}

void SmartNode::removeNonGlobalListeners()
{
	this->getEventDispatcher()->removeEventListenersForTargetWhere(this, [=](EventListener* listener)
	{
		return !listener->isGlobal();
	});
}

void SmartNode::addEventListener(EventListener* listener)
{
	if (listener == nullptr)
	{
		return;
	}

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void SmartNode::removeEventListener(EventListener* listener)
{
	if (listener == nullptr)
	{
		return;
	}

	this->getEventDispatcher()->removeEventListener(listener);
}

void SmartNode::addEventListenerIgnorePause(EventListener* listener)
{
	if (listener == nullptr)
	{
		return;
	}

	listener->setIgnorePause(true);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void SmartNode::resume()
{
	super::resume();

	this->initializeListeners();
}
