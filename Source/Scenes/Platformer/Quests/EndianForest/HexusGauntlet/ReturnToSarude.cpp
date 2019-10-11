#include "ReturnToSarude.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/DialogueOption.h"
#include "Engine/Dialogue/DialogueSet.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/QuestEvents.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Sarude.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/DialogueEvents.h"
#include "Events/PlatformerEvents.h"
#include "Objects/Platformer/Doors/MagePortals/MagePortal.h"
#include "Scenes/Platformer/AttachedBehavior/Npcs/Dialogue/NpcDialogueBehavior.h"

#include "Strings/Hexus/Hexus.h"
#include "Strings/Platformer/Quests/EndianForest/HexusGauntlet/Sarude/FirstChallenge.h"
#include "Strings/Platformer/Quests/EndianForest/HexusGauntlet/Sarude/HaveYouHeardOfHexus.h"
#include "Strings/Platformer/Quests/EndianForest/HexusGauntlet/Sarude/HexusIsAGameWhere.h"
#include "Strings/Platformer/Quests/EndianForest/HexusGauntlet/Sarude/ReadyToStart.h"
#include "Strings/Platformer/Quests/EndianForest/HexusGauntlet/Sarude/WelcomeToMagesGuild.h"
#include "Strings/Platformer/Quests/EndianForest/HexusGauntlet/Sarude/WishToLearn.h"

using namespace cocos2d;

const std::string ReturnToSarude::MapKeyQuest = "return-to-sarude";
const std::string ReturnToSarude::QuestPortalTag = "quest-portal";

ReturnToSarude* ReturnToSarude::create(GameObject* owner, QuestLine* questLine,  std::string questTag)
{
	ReturnToSarude* instance = new ReturnToSarude(owner, questLine, questTag);

	instance->autorelease();

	return instance;
}

ReturnToSarude::ReturnToSarude(GameObject* owner, QuestLine* questLine, std::string questTag) : super(owner, questLine, ReturnToSarude::MapKeyQuest, questTag, false)
{
	this->sarude = nullptr;
	this->squally = nullptr;
	this->portal = nullptr;
}

ReturnToSarude::~ReturnToSarude()
{
}

void ReturnToSarude::onLoad(QuestState questState)
{
	ObjectEvents::watchForObject<Sarude>(this, [=](Sarude* sarude)
	{
		this->sarude = sarude;
	});

	ObjectEvents::watchForObject<Squally>(this, [=](Squally* squally)
	{
		this->squally = squally;
	});

	ObjectEvents::watchForObject<MagePortal>(this, [=](MagePortal* portal)
	{
		this->portal = portal;
		
		if (questState == QuestState::Complete)
		{
			this->portal->openPortal(true);
		}
		else
		{
			this->portal->closePortal(true);
		}
	}, ReturnToSarude::QuestPortalTag);
}

void ReturnToSarude::onActivate(bool isActiveThroughSkippable)
{
	this->registerDialogue();
}

void ReturnToSarude::onComplete()
{
	if (this->portal != nullptr)
	{
		this->portal->openPortal(true);
	}
}

void ReturnToSarude::onSkipped()
{
	this->removeAllListeners();
}

void ReturnToSarude::registerDialogue()
{
	this->sarude->watchForAttachedBehavior<NpcDialogueBehavior>([=](NpcDialogueBehavior* interactionBehavior)
	{
		// Pre-text chain
		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_HexusGauntlet_Sarude_WelcomeToMagesGuild::create(),
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Left,
			[=]()
			{
			},
			DialogueEvents::BuildPreviewNode(this->sarude, false),
			DialogueEvents::BuildPreviewNode(this->squally, true)
		));
		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_HexusGauntlet_Sarude_HaveYouHeardOfHexus::create()->setStringReplacementVariables(Strings::Hexus_Hexus::create()),
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Left,
			[=]()
			{
			},
			DialogueEvents::BuildPreviewNode(this->sarude, false),
			DialogueEvents::BuildPreviewNode(this->squally, true)
		));
		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_HexusGauntlet_Sarude_HexusIsAGameWhere::create()->setStringReplacementVariables(Strings::Hexus_Hexus::create()),
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Left,
			[=]()
			{
			},
			DialogueEvents::BuildPreviewNode(this->sarude, false),
			DialogueEvents::BuildPreviewNode(this->squally, true)
		));
		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_HexusGauntlet_Sarude_WishToLearn::create(),
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Left,
			[=]()
			{
			},
			DialogueEvents::BuildPreviewNode(this->sarude, false),
			DialogueEvents::BuildPreviewNode(this->squally, true)
		));

		interactionBehavior->getMainDialogueSet()->addDialogueOption(DialogueOption::create(
			Strings::Platformer_Quests_EndianForest_HexusGauntlet_Sarude_ReadyToStart::create(),
			[=]()
			{
				DialogueEvents::TriggerDialogueOpen(DialogueEvents::DialogueOpenArgs(
					Strings::Platformer_Quests_EndianForest_HexusGauntlet_Sarude_FirstChallenge::create(),
					DialogueBox::DialogueDock::Bottom,
					DialogueBox::DialogueAlignment::Left,
					[=]()
					{
						this->complete();
					},
					DialogueEvents::BuildPreviewNode(this->sarude, false),
					DialogueEvents::BuildPreviewNode(this->squally, true)
				));
			}),
			1.0f
		);
	});
}
