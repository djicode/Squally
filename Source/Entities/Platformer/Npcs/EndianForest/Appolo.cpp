#include "Appolo.h"

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

const std::string Appolo::MapKeyAppolo = "appolo";
HexusOpponentData* Appolo::HexusOpponentDataInstance = nullptr;
const std::string Appolo::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_APPOLO";

Appolo* Appolo::deserialize(ValueMap& properties)
{
	Appolo* instance = new Appolo(properties);

	instance->autorelease();

	return instance;
}

Appolo::Appolo(ValueMap& properties) : super(properties,
	Appolo::MapKeyAppolo,
	EntityResources::Npcs_EndianForest_Appolo_Animations,
	EntityResources::Npcs_EndianForest_Appolo_Emblem,
	Size(112.0f, 160.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Appolo::getHexusOpponentData();
}

Appolo::~Appolo()
{
}

Vec2 Appolo::getDialogueOffset()
{
	return Vec2(-32.0f, -112.0f);
}

LocalizedString* Appolo::getEntityName()
{
	return nullptr;
}

HexusOpponentData* Appolo::getHexusOpponentData()
{
	if (Appolo::HexusOpponentDataInstance == nullptr)
	{
		Appolo::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Npcs_EndianForest_Appolo_Animations,
			HexusResources::Menus_HexusFrameEndianForest,
			1.0f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Appolo::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Earth,
			0.116f,
			HexusOpponentData::generateDeck(32, 0.116f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),

			}),
			nullptr
		);
	}

	return Appolo::HexusOpponentDataInstance;
}