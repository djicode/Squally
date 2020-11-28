#pragma once
#include "cocos/base/CCValue.h"

#include "Engine/SmartNode.h"

#include "Engine/Animations/Spriter/SpriterStructs.h"

namespace cocos2d
{
	class Sprite;
}

class SpriterAnimationTimeline;

class SpriterAnimationNode : public SmartNode
{
public:
	static SpriterAnimationNode* create(const std::string& animationResource);

protected:
	SpriterAnimationNode(const std::string& animationResource);
	virtual ~SpriterAnimationNode();

	void setFlippedX(bool isFlippedX);

private:
	typedef SmartNode super;

	SpriterAnimationTimeline* timeline;

	std::map<int, cocos2d::Node*> bones;
	std::map<int, cocos2d::Sprite*> animationParts;

	void buildBones(const SpriterData& spriterData);
	void buildSprites(const SpriterData& spriterData, const std::string& animationResource);
	
	cocos2d::Node* animationPartContainer;
};
