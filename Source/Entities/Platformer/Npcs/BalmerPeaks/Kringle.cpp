#include "Kringle.h"

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

const std::string Kringle::MapKeyKringle = "kringle";
HexusOpponentData* Kringle::HexusOpponentDataInstance = nullptr;
const std::string Kringle::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_KRINGLE";

Kringle* Kringle::deserialize(ValueMap& properties)
{
	Kringle* instance = new Kringle(properties);

	instance->autorelease();

	return instance;
}

Kringle::Kringle(ValueMap& properties) : super(properties,
	Kringle::MapKeyKringle,
	EntityResources::Npcs_BalmerPeaks_Kringle_Animations,
	EntityResources::Npcs_BalmerPeaks_Kringle_Emblem,
	Size(112.0f, 160.0f),
	0.85f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Kringle::getHexusOpponentData();
}

Kringle::~Kringle()
{
}

Vec2 Kringle::getDialogueOffset()
{
	return Vec2(-32.0f, -112.0f);
}

LocalizedString* Kringle::getEntityName()
{
	return nullptr;
}

HexusOpponentData* Kringle::getHexusOpponentData()
{
	if (Kringle::HexusOpponentDataInstance == nullptr)
	{
		Kringle::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_BalmerPeaks_Kringle_Animations,
			HexusResources::Menus_HexusFrameBalmerPeaks,
			0.85f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Kringle::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Water,
			0.580f,
			HexusOpponentData::generateDeck(32, 0.580f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip3),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),

			}),
			nullptr
		);
	}

	return Kringle::HexusOpponentDataInstance;
}