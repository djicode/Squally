#include "MeetFlyBot.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/QuestEvents.h"
#include "Engine/Events/SceneEvents.h"
#include "Engine/Sound/Sound.h"
#include "Entities/Platformer/Helpers/EndianForest/FlyBot.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/HelperEvents.h"
#include "Events/PlatformerEvents.h"
#include "Objects/Platformer/Cinematic/CinematicMarker.h"

#include "Strings/Dialogue/Story/Intro/GetYouPatched.h"
#include "Strings/Dialogue/Story/Intro/DistressBeacon.h"
#include "Strings/Dialogue/Story/Intro/YoureAlive.h"

using namespace cocos2d;

const std::string MeetFlyBot::MapKeyQuest = "meet-flybot";

MeetFlyBot* MeetFlyBot::create(GameObject* owner, QuestLine* questLine, std::string questTag)
{
	MeetFlyBot* instance = new MeetFlyBot(owner, questLine, questTag);

	instance->autorelease();

	return instance;
}

MeetFlyBot::MeetFlyBot(GameObject* owner, QuestLine* questLine, std::string questTag) : super(owner, questLine, MeetFlyBot::MapKeyQuest, questTag, true)
{
	this->hasRunEvent = false;
	this->flyBot = dynamic_cast<FlyBot*>(owner);
}

MeetFlyBot::~MeetFlyBot()
{
}

void MeetFlyBot::onLoad(QuestState questState)
{
	if (this->flyBot != nullptr)
	{
		this->flyBot->getAnimations()->setFlippedX(true);

		if (questState == QuestState::Complete)
		{
			this->flyBot->setVisible(false);
		}
	}
}

void MeetFlyBot::onActivate(bool isActiveThroughSkippable)
{
	this->listenForMapEvent(MeetFlyBot::MapKeyQuest, [=](ValueMap args)
	{
		this->runCinematicSequence();
	});

	this->addEventListenerIgnorePause(EventListenerCustom::create(SceneEvents::EventBeforeSceneChange, [=](EventCustom* eventCustom)
	{
		this->complete();
	}));
}

void MeetFlyBot::onComplete()
{
}

void MeetFlyBot::onSkipped()
{
	this->removeAllListeners();
}

void MeetFlyBot::runCinematicSequence()
{
	if (this->hasRunEvent)
	{
		return;
	}
	
	this->hasRunEvent = true;
	Vec2 positionA = Vec2::ZERO;

	ObjectEvents::QueryObjects(QueryObjectsArgs<CinematicMarker>([&](CinematicMarker* cinematicMarker)
	{
		switch(cinematicMarker->getId())
		{
			case 0:
			{
				positionA = cinematicMarker->getPosition();
				break;
			}
			default:
			{
				break;
			}
		}
	}));

	if (this->flyBot != nullptr)
	{
		PlatformerEvents::TriggerCinematicHijack();

		this->flyBot->runAction(Sequence::create(
			CallFunc::create([=]()
			{
				this->flyBot->droidAlarmedSound->play();
			}),
			EaseSineInOut::create(MoveTo::create(2.0f, positionA)),
			CallFunc::create([=]()
			{
				this->flyBot->speechBubble->runDialogue(Strings::Dialogue_Story_Intro_YoureAlive::create());
			}),
			DelayTime::create(2.0f),
			CallFunc::create([=]()
			{
				this->flyBot->droidBrief1Sound->play();
				this->flyBot->speechBubble->runDialogue(Strings::Dialogue_Story_Intro_DistressBeacon::create());
			}),
			DelayTime::create(4.0f),
			CallFunc::create([=]()
			{
				this->flyBot->droidBrief1Sound->play();
				this->flyBot->speechBubble->runDialogue(Strings::Dialogue_Story_Intro_GetYouPatched::create());
			}),
			DelayTime::create(4.0f),
			CallFunc::create([=]()
			{
				this->flyBot->speechBubble->hideDialogue();
			}),
			DelayTime::create(1.0f),
			CallFunc::create([=]()
			{
				Vec2 positionB = Vec2::ZERO;

				ObjectEvents::QueryObjects(QueryObjectsArgs<Squally>([&](Squally* squally)
				{
					positionB = squally->getPosition();
				}));

				this->flyBot->runAction(EaseSineInOut::create(MoveTo::create(1.0f, positionB)));
			}),
			DelayTime::create(1.0f),
			CallFunc::create([=]()
			{
				this->flyBot->setVisible(false);

				HelperEvents::TriggerFindFlyBot();
				PlatformerEvents::TriggerCinematicRestore();

				this->complete();
			}),
			nullptr
		));
	}
}