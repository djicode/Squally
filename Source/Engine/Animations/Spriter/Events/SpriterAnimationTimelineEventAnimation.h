#pragma once
#include "cocos/base/CCValue.h"

#include "Engine/Animations/Spriter/Events/SpriterAnimationTimelineEventBase.h"

class SpriterAnimationTimeline;

class SpriterAnimationTimelineEventAnimation : public SpriterAnimationTimelineEventBase
{
public:
	static SpriterAnimationTimelineEventAnimation* create(
		SpriterAnimationTimeline* timeline,
		float endTime,
		const SpriterTimeline& keyParent,
		const SpriterTimelineKey& animationKey
	);

	SpriterAnimationTimelineEventAnimation* getNext();
	void setNext(SpriterAnimationTimelineEventAnimation* next);
	void advance(SpriterAnimationNode* animation) override;

protected:
	SpriterAnimationTimelineEventAnimation(SpriterAnimationTimeline* timeline,
		float endTime,
		const SpriterTimeline& keyParent,
		const SpriterTimelineKey& animationKey
	);
	
	void onFire(SpriterAnimationNode* animation) override;

	SpriterAnimationTimelineEventAnimation* next;

private:
	typedef SpriterAnimationTimelineEventBase super;
	
	std::string partName;
	cocos2d::Vec2 position;
	cocos2d::Vec2 scale;
	float rotation;
	float alpha;
	
	float speed;
};
