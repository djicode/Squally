#include "RestorePotionTutorial.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/HackableEvents.h"
#include "Engine/Inventory/Inventory.h"
#include "Engine/Inventory/Item.h"
#include "Engine/Sound/Sound.h"
#include "Entities/Platformer/Helpers/EndianForest/FlyBot.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion.h"
#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"
#include "Scenes/Platformer/Level/Combat/Buffs/RestoreHealth/RestoreHealth.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Strings/Dialogue/Story/Intro/HackerModeCombat.h"

using namespace cocos2d;

const std::string RestorePotionTutorial::MapKeyAttachedBehavior = "restore-potion-tutorial";

RestorePotionTutorial* RestorePotionTutorial::create(GameObject* owner)
{
	RestorePotionTutorial* instance = new RestorePotionTutorial(owner);

	instance->autorelease();

	return instance;
}

RestorePotionTutorial::RestorePotionTutorial(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}

	this->hasTutorialRun = false;
	this->flyBot = nullptr;
}

RestorePotionTutorial::~RestorePotionTutorial()
{
}

void RestorePotionTutorial::onLoad()
{
	RestorePotion* restorePotion = this->entity->getInventory()->getItemOfType<RestorePotion>();

	if (restorePotion != nullptr)
	{
		restorePotion->getAssociatedAttack()->registerAttackCompleteCallback([=]()
		{
			this->runTutorial();
		});
	}

	ObjectEvents::watchForObject<FlyBot>(this, &this->flyBot);
	HackableEvents::TriggerDisallowHackerMode();
}

void RestorePotionTutorial::runTutorial()
{
	if (this->hasTutorialRun || this->flyBot == nullptr)
	{
		return;
	}

	this->hasTutorialRun = true;

	static const float TutorialDelay = 1.5f;

	this->runAction(Sequence::create(
		DelayTime::create(TutorialDelay),
		CallFunc::create([=]()
		{
			HackableEvents::TriggerAllowHackerMode();
			HackableEvents::TriggerForceHackerModeEnable();

			this->runAction(Sequence::create(
				CallFunc::create([=]()
				{
					this->flyBot->droidChatterSound->play();
				}),
				CallFunc::create([=]()
				{
					this->flyBot->speechBubble->runDialogue(Strings::Dialogue_Story_Intro_HackerModeCombat::create());
				}),
				DelayTime::create(4.0f),
				CallFunc::create([=]()
				{
					this->flyBot->speechBubble->hideDialogue();
				}),
				nullptr
			));
		}),
		nullptr
	));
}