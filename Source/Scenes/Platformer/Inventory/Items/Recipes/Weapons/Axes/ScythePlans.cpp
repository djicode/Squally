#include "ScythePlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string ScythePlans::SaveKeyScythePlans = "scythe-plans";

ScythePlans* ScythePlans::create()
{
	ScythePlans* instance = new ScythePlans();

	instance->autorelease();

	return instance;
}

ScythePlans::ScythePlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

ScythePlans::~ScythePlans()
{
}

Item* ScythePlans::craft()
{
	return Scythe::create();
}

std::map<Item*, int> ScythePlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 2 },
		{ Iron::create(), 4 },
	};
}

Item* ScythePlans::clone()
{
	return ScythePlans::create();
}

std::string ScythePlans::getItemName()
{
	return ScythePlans::SaveKeyScythePlans;
}

LocalizedString* ScythePlans::getString()
{
	return Strings::Items_Equipment_Weapons_Axes_Scythe::create();
}

std::string ScythePlans::getIconResource()
{
	return ObjectResources::Items_Crafting_SCROLL_1;
}

std::string ScythePlans::getCraftedItemIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Axes_Scythe;
}

std::string ScythePlans::getSerializationKey()
{
	return ScythePlans::SaveKeyScythePlans;
}
