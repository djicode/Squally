#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Axes/AxeRecipe.h"

class IronAxePlans : public AxeRecipe
{
public:
	static IronAxePlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeyIronAxePlans;

protected:
	IronAxePlans();
	virtual ~IronAxePlans();
	
	std::map<Item*, int> getReagentsInternal() override;

private:
	typedef AxeRecipe super;
};
