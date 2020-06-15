#include "SquallyAttackBehavior.h"

#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Input/ClickableNode.h"
#include "Engine/Save/SaveManager.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/CombatEvents.h"
#include "Scenes/Platformer/Inventory/EquipmentInventory.h"
#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Axes/Axe.h"
#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Bows/Bow.h"
#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Maces/Mace.h"
#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Swords/Sword.h"
#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Wands/Wand.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityAttackBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Inventory/EntityInventoryBehavior.h"
#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttacks.h"
#include "Scenes/Platformer/Save/SaveKeys.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/UIResources.h"

using namespace cocos2d;
	
const std::string SquallyAttackBehavior::MapKey = "squally-attacks";

SquallyAttackBehavior* SquallyAttackBehavior::create(GameObject* owner)
{
	SquallyAttackBehavior* instance = new SquallyAttackBehavior(owner);

	instance->autorelease();

	return instance;
}

SquallyAttackBehavior::SquallyAttackBehavior(GameObject* owner) : super(owner)
{
	this->squally = dynamic_cast<Squally*>(owner);

	if (this->squally == nullptr)
	{
		this->invalidate();
	}
}

SquallyAttackBehavior::~SquallyAttackBehavior()
{
}

void SquallyAttackBehavior::initializePositions()
{
}

void SquallyAttackBehavior::onLoad()
{
	this->squally->watchForAttachedBehavior<EntityAttackBehavior>([=](EntityAttackBehavior* attackBehavior)
	{
		this->loadWeaponAttacks(attackBehavior);
	});
}

void SquallyAttackBehavior::onDisable()
{
	super::onDisable();
}

void SquallyAttackBehavior::loadSpellBookAttacks(EntityAttackBehavior* attackBehavior)
{
	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookWater, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookWind, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookLightning, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookHoly, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookNature, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookFrost, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookFire, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookShadow, Value(false)).asBool())
	{
		
	}

	if (SaveManager::getProfileDataOrDefault(SaveKeys::SaveKeySpellBookArcane, Value(false)).asBool())
	{
		
	}
}

void SquallyAttackBehavior::loadWeaponAttacks(EntityAttackBehavior* attackBehavior)
{
	std::tuple<int, int> attackRange = attackBehavior->computeAttackRange();
	int minAttack = std::get<0>(attackRange);
	int maxAttack = std::get<1>(attackRange);

	// attackBehavior->registerAttack(CastHaste::create(0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	
	this->squally->watchForAttachedBehavior<EntityInventoryBehavior>([=](EntityInventoryBehavior* inventoryBehavior)
	{
		Weapon* weapon = inventoryBehavior->getEquipmentInventory()->getWeapon();

		if (dynamic_cast<Axe*>(weapon) != nullptr)
		{
			this->loadAxeAttacks(attackBehavior, minAttack, maxAttack);
		}
		else if (dynamic_cast<Bow*>(weapon) != nullptr)
		{
			this->loadBowAttacks(attackBehavior, minAttack, maxAttack);
		}
		else if (dynamic_cast<Mace*>(weapon) != nullptr)
		{
			this->loadMaceAttacks(attackBehavior, minAttack, maxAttack);
		}
		else if (dynamic_cast<Sword*>(weapon) != nullptr)
		{
			this->loadSwordAttacks(attackBehavior, minAttack, maxAttack);
		}
		else if (dynamic_cast<Wand*>(weapon) != nullptr)
		{
			this->loadWandAttacks(attackBehavior, minAttack, maxAttack);
		}
		else
		{
			this->loadUnarmedAttacks(attackBehavior, minAttack, maxAttack);
		}
	});
}

void SquallyAttackBehavior::loadUnarmedAttacks(EntityAttackBehavior* attackBehavior, int minAttack, int maxAttack)
{
	// Note: ordering here is intentional. Powerful attack first, no-cost attack second. This makes for better UI placement.
	if (this->squally->getRuntimeStateOrDefault(StateKeys::Eq, Value(0)).asInt() >= 2)
	{
		attackBehavior->registerAttack(Pound::create(minAttack, maxAttack, 0.4f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	}

	attackBehavior->registerAttack(Punch::create(minAttack, maxAttack, 0.4f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
}

void SquallyAttackBehavior::loadAxeAttacks(EntityAttackBehavior* attackBehavior, int minAttack, int maxAttack)
{
	attackBehavior->registerAttack(AxeCleave::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	attackBehavior->registerAttack(AxeSwing::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
}

void SquallyAttackBehavior::loadBowAttacks(EntityAttackBehavior* attackBehavior, int minAttack, int maxAttack)
{
	attackBehavior->registerAttack(MultiShot::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	attackBehavior->registerAttack(BowShoot::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
}

void SquallyAttackBehavior::loadMaceAttacks(EntityAttackBehavior* attackBehavior, int minAttack, int maxAttack)
{
	attackBehavior->registerAttack(MaceSmash::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	attackBehavior->registerAttack(MaceSwing::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
}

void SquallyAttackBehavior::loadSwordAttacks(EntityAttackBehavior* attackBehavior, int minAttack, int maxAttack)
{
	attackBehavior->registerAttack(SwordExecute::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	attackBehavior->registerAttack(SwordSlash::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
}

void SquallyAttackBehavior::loadWandAttacks(EntityAttackBehavior* attackBehavior, int minAttack, int maxAttack)
{
	attackBehavior->registerAttack(WandEnergyBolt::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
	attackBehavior->registerAttack(WandSwing::create(minAttack, maxAttack, 0.35f, EntityAttackBehavior::DefaultRecoverSpeed, PlatformerAttack::Priority::Common));
}
