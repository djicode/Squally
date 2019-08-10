#include "ReanimatedFighter.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string ReanimatedFighter::MapKeyReanimatedFighter = "reanimated-fighter";
HexusOpponentData* ReanimatedFighter::HexusOpponentDataInstance = nullptr;
const std::string ReanimatedFighter::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_REANIMATED_FIGHTER";

ReanimatedFighter* ReanimatedFighter::deserialize(ValueMap& initProperties)
{
	ReanimatedFighter* instance = new ReanimatedFighter(initProperties);

	instance->autorelease();

	return instance;
}

ReanimatedFighter::ReanimatedFighter(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_LambdaCrypts_ReanimatedFighter_Animations,
	EntityResources::Enemies_LambdaCrypts_ReanimatedFighter_Emblem,
	PlatformerCollisionType::Enemy,
	Size(256.0f, 248.0f),
	0.9f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = ReanimatedFighter::getHexusOpponentData();
}

ReanimatedFighter::~ReanimatedFighter()
{
}

Vec2 ReanimatedFighter::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -112.0f);
}

HexusOpponentData* ReanimatedFighter::getHexusOpponentData()
{
	if (ReanimatedFighter::HexusOpponentDataInstance == nullptr)
	{
		ReanimatedFighter::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_LambdaCrypts_ReanimatedFighter_Animations,
			HexusResources::Menus_HexusFrameLambdaCrypts,
			0.9f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			ReanimatedFighter::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			0.250f,
			HexusOpponentData::generateDeck(32, 0.250f,
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
					
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					
				},
				StateOverride::TutorialMode::NoTutorial
			)
		);
	}

	return ReanimatedFighter::HexusOpponentDataInstance;
}