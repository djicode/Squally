#include "CshlBlock.h"

#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Input/ClickableNode.h"
#include "Scenes/Cipher/Config.h"

#include "Resources/CipherResources.h"

#include "Strings/Cipher/Operations/CSHL.h"

using namespace cocos2d;

CshlBlock* CshlBlock::create()
{
	CshlBlock* instance = new CshlBlock();

	instance->autorelease();

	return instance;
}

CshlBlock::CshlBlock() : super(ClickableNode::create(CipherResources::BlockBin, CipherResources::BlockBin), CipherResources::Icons_CircularShiftLeft, Strings::Cipher_Operations_CSHL::create())
{
}

CshlBlock::~CshlBlock()
{
}

void CshlBlock::onEnter()
{
	super::onEnter();
}

void CshlBlock::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();
}