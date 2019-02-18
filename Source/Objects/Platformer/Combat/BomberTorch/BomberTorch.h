#pragma once

#include "Objects/Platformer/Combat/Projectile.h"

namespace cocos2d
{
	class Sprite;
}

class HackablePreview;
class SmartAnimationSequenceNode;

class BomberTorch : public Projectile
{
public:
	static BomberTorch* create(PlatformerAttack* associatedAttack);

protected:
	BomberTorch(PlatformerAttack* associatedAttack);
	virtual	~BomberTorch();

	void onEnter() override;
	void initializePositions() override;
	void update(float) override;
	cocos2d::Vec2 getButtonOffset() override;
	HackablePreview* createDefaultPreview() override;
	HackablePreview* createVelocityPreview() override;
	HackablePreview* createAccelerationPreview() override;

private:
	typedef Projectile super;

	cocos2d::Sprite* bomberTorchSprite;
	SmartAnimationSequenceNode* fire;
};
