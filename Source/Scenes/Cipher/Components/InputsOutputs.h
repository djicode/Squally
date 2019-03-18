#pragma once

#include "Scenes/Cipher/Components/CipherComponentBase.h"

namespace cocos2d
{
	class Sprite;
}

class LocalizedLabel;

class InputsOutputs : public CipherComponentBase
{
public:
	static InputsOutputs* create();

protected:
	void onBeforeStateChange(CipherState* cipherState) override;
	void onAnyStateChange(CipherState* cipherState) override;

private:
	typedef CipherComponentBase super;
	InputsOutputs();
	~InputsOutputs();

	void onEnter() override;
	void initializePositions() override;
	void updateDisplayedLosses(CipherState* cipherState);

	LocalizedLabel* inputsLabel;
	LocalizedLabel* outputsLabel;

	std::vector<std::tuple<std::string, std::string>> inputs;
};
