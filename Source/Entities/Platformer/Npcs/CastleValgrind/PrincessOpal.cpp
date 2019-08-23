#include "PrincessOpal.h"

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

const std::string PrincessOpal::MapKeyPrincessOpal = "princess-opal";
HexusOpponentData* PrincessOpal::HexusOpponentDataInstance = nullptr;
const std::string PrincessOpal::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_PRINCESS_OPAL";

PrincessOpal* PrincessOpal::deserialize(ValueMap& properties)
{
	PrincessOpal* instance = new PrincessOpal(properties);

	instance->autorelease();

	return instance;
}

PrincessOpal::PrincessOpal(ValueMap& properties) : super(properties,
	PrincessOpal::MapKeyPrincessOpal,
	EntityResources::Npcs_CastleValgrind_PrincessOpal_Animations,
	EntityResources::Npcs_CastleValgrind_PrincessOpal_Emblem,
	Size(112.0f, 160.0f),
	1.05f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = PrincessOpal::getHexusOpponentData();
}

PrincessOpal::~PrincessOpal()
{
}

Vec2 PrincessOpal::getDialogueOffset()
{
	return Vec2(-32.0f, -112.0f);
}

LocalizedString* PrincessOpal::getEntityName()
{
	return nullptr;
}

HexusOpponentData* PrincessOpal::getHexusOpponentData()
{
	if (PrincessOpal::HexusOpponentDataInstance == nullptr)
	{
		PrincessOpal::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_CastleValgrind_PrincessOpal_Animations,
			HexusResources::Menus_HexusFrameCastleValgrind,
			1.05f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			PrincessOpal::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Air,
			0.446f,
			HexusOpponentData::generateDeck(32, 0.446f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),
				CardList::getInstance()->cardListByName.at(CardKeys::Mov),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip2),

			}),
			nullptr
		);
	}

	return PrincessOpal::HexusOpponentDataInstance;
}