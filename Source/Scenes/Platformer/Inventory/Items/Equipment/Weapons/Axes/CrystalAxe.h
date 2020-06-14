#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Axes/Axe.h"

class CrystalAxe : public Axe
{
public:
	static CrystalAxe* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;
	cocos2d::Size getWeaponCollisionSize() override;
	cocos2d::Vec2 getWeaponCollisionOffset() override;
	cocos2d::Vec2 getDisplayOffset() override;

	static const std::string SaveKey;

protected:
	CrystalAxe();
	virtual ~CrystalAxe();

private:
	typedef Axe super;
};
