#include "LionMan.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string LionMan::MapKeyLionMan = "lion-man";
HexusOpponentData* LionMan::HexusOpponentDataInstance = nullptr;
const std::string LionMan::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_LION_MAN";

LionMan* LionMan::deserialize(ValueMap& initProperties)
{
	LionMan* instance = new LionMan(initProperties);

	instance->autorelease();

	return instance;
}

LionMan::LionMan(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_UnderflowRuins_LionMan_Animations,
	EntityResources::Enemies_UnderflowRuins_LionMan_Emblem,
	PlatformerCollisionType::Enemy,
	Size(256.0f, 326.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = LionMan::getHexusOpponentData();
}

LionMan::~LionMan()
{
}

Vec2 LionMan::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -196.0f);
}

HexusOpponentData* LionMan::getHexusOpponentData()
{
	if (LionMan::HexusOpponentDataInstance == nullptr)
	{
		LionMan::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_UnderflowRuins_LionMan_Animations,
			HexusResources::Menus_HexusFrameUnderflowRuins,
			1.0f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -196.0f),
			Vec2(-32.0f, -196.0f),
			LionMan::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Light,
			0.500f,
			HexusOpponentData::generateDeck(32, 0.500f,
			{

			}),
			StateOverride::create(
				// Player losses
				1,
				// Enemy losses
				1,
				// Player's turn
				true,
				// Player passed
				true,
				// Enemy passed
				true,
				// Player deck
				std::vector<CardData*>
				{
					
				},
				// Enemy deck
				std::vector<CardData*>
				{
					
				},
				// Player hand
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Flip3),
CardList::getInstance()->cardListByName.at(CardKeys::Flip2),
CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary9),
CardList::getInstance()->cardListByName.at(CardKeys::Binary9),
CardList::getInstance()->cardListByName.at(CardKeys::Binary1),
				},
				// Player decimal cards
				std::vector<CardData*>
				{
					
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary6),
CardList::getInstance()->cardListByName.at(CardKeys::Binary6),
CardList::getInstance()->cardListByName.at(CardKeys::Binary6),
CardList::getInstance()->cardListByName.at(CardKeys::Binary12),
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal4),
CardList::getInstance()->cardListByName.at(CardKeys::Decimal12),
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Hex0),
CardList::getInstance()->cardListByName.at(CardKeys::Hex3),
CardList::getInstance()->cardListByName.at(CardKeys::Hex12),
				},
				StateOverride::TutorialMode::NoTutorial
			)
		);
	}

	return LionMan::HexusOpponentDataInstance;
}