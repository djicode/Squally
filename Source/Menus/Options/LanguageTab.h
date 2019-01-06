#pragma once

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class Node;
	class Sprite;
	class Label;
}

class LocalizedString;
class ClickableTextNode;

class LanguageTab : public SmartNode
{
public:
	static LanguageTab* create();

protected:
	LanguageTab();
	~LanguageTab();

private:
	typedef SmartNode super;

	void onEnter() override;
	void initializeListeners() override;
	void initializePositions() override;
	ClickableTextNode* constructLanguageButton(LocalizedString* string);

	std::vector<ClickableTextNode*> languageButtons;
};
