#include "SteelHelm.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string SteelHelm::SaveKey = "steel-helm";

SteelHelm* SteelHelm::create()
{
	SteelHelm* instance = new SteelHelm();

	instance->autorelease();

	return instance;
}

SteelHelm::SteelHelm() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Magic Attack
	0,
	// Armor
	0,
	// Speed
	0.05f
))
{
}

SteelHelm::~SteelHelm()
{
}

Item* SteelHelm::clone()
{
	return SteelHelm::create();
}

std::string SteelHelm::getItemName()
{
	return SteelHelm::SaveKey;
}

LocalizedString* SteelHelm::getString()
{
	return Strings::Items_Equipment_Gear_Hats_SteelHelm::create();
}

std::string SteelHelm::getIconResource()
{
	return ItemResources::Equipment_Gear_Hats_SteelHelm;
}

std::string SteelHelm::getSerializationKey()
{
	return SteelHelm::SaveKey;
}

Vec2 SteelHelm::getDisplayOffset()
{
	return Vec2(4.0f, -22.0f);
}
