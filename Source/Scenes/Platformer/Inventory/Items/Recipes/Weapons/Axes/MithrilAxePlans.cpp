#include "MithrilAxePlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string MithrilAxePlans::SaveKeyMithrilAxePlans = "mithril-axe-plans";

MithrilAxePlans* MithrilAxePlans::create()
{
	MithrilAxePlans* instance = new MithrilAxePlans();

	instance->autorelease();

	return instance;
}

MithrilAxePlans::MithrilAxePlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

MithrilAxePlans::~MithrilAxePlans()
{
}

Item* MithrilAxePlans::craft()
{
	return MithrilAxe::create();
}

std::map<Item*, int> MithrilAxePlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 2 },
		{ Iron::create(), 4 },
	};
}

Item* MithrilAxePlans::clone()
{
	return MithrilAxePlans::create();
}

std::string MithrilAxePlans::getItemName()
{
	return MithrilAxePlans::SaveKeyMithrilAxePlans;
}

LocalizedString* MithrilAxePlans::getString()
{
	return Strings::Items_Equipment_Weapons_Axes_MithrilAxe::create();
}

std::string MithrilAxePlans::getIconResource()
{
	return ObjectResources::Items_Crafting_SCROLL_1;
}

std::string MithrilAxePlans::getCraftedItemIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Axes_MithrilAxe;
}

std::string MithrilAxePlans::getSerializationKey()
{
	return MithrilAxePlans::SaveKeyMithrilAxePlans;
}
