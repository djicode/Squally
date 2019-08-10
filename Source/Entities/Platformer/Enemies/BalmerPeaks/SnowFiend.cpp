#include "SnowFiend.h"

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

const std::string SnowFiend::MapKeySnowFiend = "snow-fiend";
HexusOpponentData* SnowFiend::HexusOpponentDataInstance = nullptr;
const std::string SnowFiend::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SNOW_FIEND";

SnowFiend* SnowFiend::deserialize(ValueMap& initProperties)
{
	SnowFiend* instance = new SnowFiend(initProperties);

	instance->autorelease();

	return instance;
}

SnowFiend::SnowFiend(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_BalmerPeaks_SnowFiend_Animations,
	EntityResources::Enemies_BalmerPeaks_SnowFiend_Emblem,
	PlatformerCollisionType::Enemy,
	Size(420.0f, 420.0f),
	0.85f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = SnowFiend::getHexusOpponentData();
}

SnowFiend::~SnowFiend()
{
}

Vec2 SnowFiend::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -248.0f);
}

HexusOpponentData* SnowFiend::getHexusOpponentData()
{
	if (SnowFiend::HexusOpponentDataInstance == nullptr)
	{
		SnowFiend::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_BalmerPeaks_SnowFiend_Animations,
			HexusResources::Menus_HexusFrameBalmerPeaks,
			0.85f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -248.0f),
			SnowFiend::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Water,
			0.833f,
			HexusOpponentData::generateDeck(32, 0.833f,
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
					CardList::getInstance()->cardListByName.at(CardKeys::Steal),
CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
CardList::getInstance()->cardListByName.at(CardKeys::Flip4),
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					
				},
				// Player decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal10),
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary4),
CardList::getInstance()->cardListByName.at(CardKeys::Binary2),
CardList::getInstance()->cardListByName.at(CardKeys::Binary3),
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal2),
CardList::getInstance()->cardListByName.at(CardKeys::Decimal4),
CardList::getInstance()->cardListByName.at(CardKeys::Decimal3),
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Hex13),
CardList::getInstance()->cardListByName.at(CardKeys::Hex5),
				},
				StateOverride::TutorialMode::NoTutorial
			)
		);
	}

	return SnowFiend::HexusOpponentDataInstance;
}