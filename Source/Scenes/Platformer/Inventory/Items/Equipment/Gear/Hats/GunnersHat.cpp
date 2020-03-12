#include "GunnersHat.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string GunnersHat::SaveKeyGunnersHat = "gunners-hat";

GunnersHat* GunnersHat::create()
{
	GunnersHat* instance = new GunnersHat();

	instance->autorelease();

	return instance;
}

GunnersHat::GunnersHat() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Armor
	0,
	// Speed
	0.05f
))
{
}

GunnersHat::~GunnersHat()
{
}

Item* GunnersHat::clone()
{
	return GunnersHat::create();
}

std::string GunnersHat::getItemName()
{
	return GunnersHat::SaveKeyGunnersHat;
}

LocalizedString* GunnersHat::getString()
{
	return Strings::Items_Equipment_Gear_Hats_GunnersHat::create();
}

std::string GunnersHat::getIconResource()
{
	return ObjectResources::Items_Equipment_Gear_Hats_GunnersHat;
}

std::string GunnersHat::getSerializationKey()
{
	return GunnersHat::SaveKeyGunnersHat;
}

Vec2 GunnersHat::getDisplayOffset()
{
	return Vec2(0.0f, -26.0f);
}