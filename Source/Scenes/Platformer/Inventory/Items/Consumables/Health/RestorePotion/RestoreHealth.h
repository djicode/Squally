#pragma once

#include "Scenes/Platformer/Level/Combat/Buffs/Buff.h"

namespace cocos2d
{
	class Sprite;
}

class HackablePreview;
class PlatformerEntity;
class SmartAnimationSequenceNode;
class WorldSound;

class RestoreHealth : public Buff
{
public:
	static RestoreHealth* create(PlatformerEntity* caster, PlatformerEntity* target, int healAmount);

	static const std::string MapKeyPropertyRestorePotionTutorial;
	static const std::string RestoreHealthIdentifier;

protected:
	RestoreHealth(PlatformerEntity* caster, PlatformerEntity* target, int healAmount);
	~RestoreHealth();

	void onEnter() override;
	void initializePositions() override;
	void registerHackables() override;
	void runRestoreHealth();
	void runRestoreTick();

private:
	typedef Buff super;

	void incrementHeal();
	
	bool showClippy;
	int healAmount;
	SmartAnimationSequenceNode* healEffect;
	WorldSound* impactSound;
	WorldSound* healSound;

	static const float TimeBetweenTicks;
	static const int HackTicks;
};
