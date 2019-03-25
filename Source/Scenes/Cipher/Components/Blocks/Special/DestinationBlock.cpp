#include "DestinationBlock.h"

#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Input/ClickableNode.h"
#include "Engine/Localization/ConstantString.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Utils/HackUtils.h"
#include "Events/CipherEvents.h"
#include "Scenes/Cipher/Config.h"

#include "Resources/CipherResources.h"
#include "Resources/UIResources.h"

#include "Strings/Cipher/Operations/Immediate.h"

using namespace cocos2d;

DestinationBlock* DestinationBlock::create(int cipherIndex)
{
	DestinationBlock* instance = new DestinationBlock(cipherIndex);

	instance->autorelease();

	return instance;
}

DestinationBlock::DestinationBlock(int cipherIndex) : super(BlockType::Static, ConnectionType::Single, ConnectionType::None, ClickableNode::create(CipherResources::Blocks_BlockDecHuge, CipherResources::Blocks_BlockDecHuge), UIResources::EmptyImage, Strings::Cipher_Operations_Immediate::create())
{
	this->cipherIndex = cipherIndex;
	this->receivedValue = char(0);
	this->charValue = char(0);
	this->displayDataType = CipherEvents::DisplayDataType::Ascii;
	this->displayValue = ConstantString::create();
	this->displayLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::H2, this->displayValue);
	this->receivedDisplayValue = ConstantString::create();
	this->receivedDisplayLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::H2, this->receivedDisplayValue);
	this->spriteAscii = Sprite::create(CipherResources::Blocks_BlockAsciiHuge);
	this->spriteBin = Sprite::create(CipherResources::Blocks_BlockBinHuge);
	this->spriteDec = Sprite::create(CipherResources::Blocks_BlockDecHuge);
	this->spriteHex = Sprite::create(CipherResources::Blocks_BlockHexHuge);

	this->spriteAscii->setAnchorPoint(Vec2::ZERO);
	this->spriteBin->setAnchorPoint(Vec2::ZERO);
	this->spriteDec->setAnchorPoint(Vec2::ZERO);
	this->spriteHex->setAnchorPoint(Vec2::ZERO);

	this->displayLabel->setTextColor(Color4B::WHITE);
	this->displayLabel->enableOutline(Color4B::BLACK, 2);
	this->receivedDisplayLabel->setTextColor(Color4B::WHITE);
	this->receivedDisplayLabel->enableOutline(Color4B::BLACK, 2);
	this->block->getSprite()->setOpacity(1);
	this->block->getSprite()->setCascadeOpacityEnabled(false);
	this->block->getSpriteSelected()->setOpacity(1);
	this->block->getSpriteSelected()->setCascadeOpacityEnabled(false);

	this->block->getSprite()->addChild(this->spriteAscii);
	this->block->getSprite()->addChild(this->spriteBin);
	this->block->getSprite()->addChild(this->spriteDec);
	this->block->getSprite()->addChild(this->spriteHex);
	this->addChild(this->displayLabel);
	this->addChild(this->receivedDisplayLabel);
}

DestinationBlock::~DestinationBlock()
{
}

void DestinationBlock::onEnter()
{
	super::onEnter();

	this->spriteAscii->setVisible(true);
	this->spriteBin->setVisible(false);
	this->spriteDec->setVisible(false);
	this->spriteHex->setVisible(false);
}

void DestinationBlock::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->displayLabel->setPositionY(4.0f - 16.0f);
	this->receivedDisplayLabel->setPositionY(4.0f + 16.0f);
}

void DestinationBlock::initializeListeners()
{
	super::initializeListeners();

	this->addEventListenerIgnorePause(EventListenerCustom::create(CipherEvents::EventChangeActiveCipher, [&](EventCustom* eventCustom)
	{
		CipherEvents::CipherChangeActiveCipherArgs* args = static_cast<CipherEvents::CipherChangeActiveCipherArgs*>(eventCustom->getUserData());

		if (args != nullptr)
		{
			this->charValue = this->cipherIndex < args->output.size() ? args->output[this->cipherIndex] : char(0);
			
			this->loadDisplayValue();
		}
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(CipherEvents::EventChangeDisplayDataType, [&](EventCustom* eventCustom)
	{
		CipherEvents::CipherChangeDisplayDataTypeArgs* args = static_cast<CipherEvents::CipherChangeDisplayDataTypeArgs*>(eventCustom->getUserData());

		if (args != nullptr)
		{
			this->displayDataType = args->displayDataType;

			this->loadDisplayValue();
		}
	}));
}

void DestinationBlock::loadDisplayValue()
{
	this->spriteAscii->setVisible(false);
	this->spriteBin->setVisible(false);
	this->spriteDec->setVisible(false);
	this->spriteHex->setVisible(false);
	
	switch(this->displayDataType)
	{
		default:
		case CipherEvents::DisplayDataType::Ascii:
		{
			this->displayValue->setString(std::string(1, this->charValue));
			this->receivedDisplayValue->setString(std::string(1, this->receivedValue));
			this->spriteAscii->setVisible(true);
			break;
		}
		case CipherEvents::DisplayDataType::Bin:
		{
			this->displayValue->setString(HackUtils::toBinary8(int(this->charValue)));
			this->receivedDisplayValue->setString(HackUtils::toBinary8(int(this->receivedValue)));
			this->spriteBin->setVisible(true);
			break;
		}
		case CipherEvents::DisplayDataType::Dec:
		{
			this->displayValue->setString(std::to_string(int(this->charValue)));
			this->receivedDisplayValue->setString(std::to_string(int(this->receivedValue)));
			this->spriteDec->setVisible(true);
			break;
		}
		case CipherEvents::DisplayDataType::Hex:
		{
			this->displayValue->setString(HackUtils::toHex(int(this->charValue)));
			this->receivedDisplayValue->setString(HackUtils::toHex(int(this->receivedValue)));
			this->spriteHex->setVisible(true);
			break;
		}
	}

	std::string displayString = this->displayValue->getString();
	std::string receivedString = this->receivedDisplayValue->getString();

	for (int index = 0; index < displayString.size() && index < receivedString.size(); index++)
	{
		Sprite* next = this->receivedDisplayLabel->getLetter(index);

		if (next == nullptr)
		{
			continue;
		}

		if (displayString[index] != receivedString[index])
		{
			next->setColor(Color3B::RED);
		}
		else
		{
			next->setColor(Color3B::GREEN);
		}
		
	}
}

float DestinationBlock::getBoltOffsetY()
{
	return 48.0f;
}

void DestinationBlock::execute(std::function<void()> onExecuteComplete)
{
	super::execute(onExecuteComplete);

	this->loadDisplayValue();
}

unsigned char DestinationBlock::compute()
{
	if (this->currentInputs.size() < 1)
	{
		return (unsigned char)(0);
	}

	return this->currentInputs[0];
}

BlockBase* DestinationBlock::spawn()
{
	return DestinationBlock::create(this->cipherIndex);
}