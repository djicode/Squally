#include "IvyBow.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string IvyBow::SaveKey = "ivy-bow";

IvyBow* IvyBow::create()
{
	IvyBow* instance = new IvyBow();

	instance->autorelease();

	return instance;
}

IvyBow::IvyBow() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), 24, 32, ItemStats(
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
	0.25f
))
{
}

IvyBow::~IvyBow()
{
}

Item* IvyBow::clone()
{
	return IvyBow::create();
}

std::string IvyBow::getItemName()
{
	return IvyBow::SaveKey;
}

LocalizedString* IvyBow::getString()
{
	return Strings::Items_Equipment_Weapons_Bows_IvyBow::create();
}

std::string IvyBow::getIconResource()
{
	return ItemResources::Equipment_Weapons_Bows_IvyBow;
}

std::string IvyBow::getSerializationKey()
{
	return IvyBow::SaveKey;
}

Vec2 IvyBow::getDisplayOffset()
{
	return Vec2(0.0f, -24.0f);
}
