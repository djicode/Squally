#pragma once

#include "Scenes/Platformer/Inventory/Items/Collectables/HexusCards/HexusCard.h"

class LocalizedString;

class Hex9 : public HexusCard
{
public:
	static Hex9* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;
	std::string getCardKey() override;

	static const std::string SaveKeyHex9;

protected:
	Hex9();
	~Hex9();

private:
	typedef HexusCard super;
};
