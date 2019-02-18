#pragma once
#include <functional>

#include "Engine/SmartNode.h"

// forward declarations
namespace cocos2d
{
	class Animate;
	class Sprite;
}

class SmartAnimationSequenceNode : public SmartNode
{
public:
	static SmartAnimationSequenceNode* create(std::string defaultSprite);
	static SmartAnimationSequenceNode* create();

	static void primeCache(std::string initialSequenceResourceFile);
	void playAnimation(std::string initialSequenceResourceFile, float animationSpeed, bool insertBlankFrame = false, std::function<void()> onAnimationComplete = nullptr);
	void playAnimationRepeat(std::string initialSequenceResourceFile, float animationSpeed, float repeatDelay = 0.0f, bool insertBlankFrame = false);
	void playAnimationAndReverse(std::string initialSequenceResourceFile, float animationSpeedIn, float reverseDelay, float animationSpeedOut, bool insertBlankFrame = false, std::function<void()> onAnimationComplete = nullptr);
	void playAnimationAndReverseRepeat(std::string initialSequenceResourceFile, float animationSpeedIn, float reverseDelay, float animationSpeedOut, float repeatDelay = 0.0f, bool insertBlankFrame = false, bool startReversed = false);

	void setFlippedX(bool isFlipped);
	void setFlippedY(bool isFlipped);

	cocos2d::Animate* getForwardsAnimation();
	cocos2d::Animate* getBackwardsAnimation();

protected:
	cocos2d::Sprite* sprite;

private:
	typedef SmartNode super;
	SmartAnimationSequenceNode();
	SmartAnimationSequenceNode(std::string defaultSprite);
	virtual ~SmartAnimationSequenceNode();

	cocos2d::Animate* forwardsAnimation;
	cocos2d::Animate* backwardsAnimation;

	static std::map<std::string, std::vector<std::string>> AnimationFileCache;
	static std::vector<std::string> getAllAnimationFiles(std::string firstFrameResource);
};
