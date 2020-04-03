#include "CastFortitude.h"

#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Sound/WorldSound.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityBuffBehavior.h"
#include "Scenes/Platformer/Level/Combat/Attacks/Buffs/Fortitude/Fortitude.h"

#include "Resources/FXResources.h"
#include "Resources/SoundResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

CastFortitude* CastFortitude::create(float attackDuration, float recoverDuration, Priority priority)
{
	CastFortitude* instance = new CastFortitude(attackDuration, recoverDuration, priority);

	instance->autorelease();

	return instance;
}

CastFortitude::CastFortitude(float attackDuration, float recoverDuration, Priority priority) : super(AttackType::Buff, UIResources::Menus_Icons_Shield, priority, 0, 0, 4, attackDuration, recoverDuration)
{
	this->spellAura = Sprite::create(FXResources::Auras_ChantAura2);
	this->castSound = WorldSound::create(SoundResources::Platformer_Combat_Attacks_Spells_Heal5);

	this->spellAura->setColor(Color3B::YELLOW);
	this->spellAura->setOpacity(0);

	this->addChild(this->spellAura);
	this->addChild(this->castSound);
}

CastFortitude::~CastFortitude()
{
}

void CastFortitude::initializePositions()
{
	super::initializePositions();

	this->setPosition(Vec2(0.0f, 118.0f));
}

PlatformerAttack* CastFortitude::cloneInternal()
{
	return CastFortitude::create(this->getAttackDuration(), this->getRecoverDuration(), this->priority);
}

LocalizedString* CastFortitude::getString()
{
	return Strings::Menus_Hacking_Abilities_Buffs_Fortitude_Fortitude::create();
}

std::string CastFortitude::getAttackAnimation()
{
	return "AttackCast";
}

void CastFortitude::performAttack(PlatformerEntity* owner, PlatformerEntity* target)
{
	super::performAttack(owner, target);

	this->castSound->play();
	owner->getAnimations()->clearAnimationPriority();
	owner->getAnimations()->playAnimation("AttackCast");

	owner->getAttachedBehavior<EntityBuffBehavior>([=](EntityBuffBehavior* entityBuffBehavior)
	{
		entityBuffBehavior->applyBuff(Fortitude::create(owner, target));
	});

	this->spellAura->runAction(Sequence::create(
		FadeTo::create(0.25f, 255),
		DelayTime::create(0.5f),
		FadeTo::create(0.25f, 0),
		nullptr
	));
}

void CastFortitude::onCleanup()
{
}

bool CastFortitude::isWorthUsing(PlatformerEntity* caster, const std::vector<PlatformerEntity*>& sameTeam, const std::vector<PlatformerEntity*>& otherTeam)
{
	bool hasBuff = false;

	caster->getAttachedBehavior<EntityBuffBehavior>([&](EntityBuffBehavior* entityBuffBehavior)
	{
		entityBuffBehavior->getBuff<Fortitude>([&](Fortitude* haste)
		{
			hasBuff = true;
		});
	});

	return !hasBuff;
}