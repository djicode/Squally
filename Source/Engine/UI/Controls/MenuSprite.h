#pragma once
#include <typeinfo>
#include "cocos2d.h"

#include "Engine/Events/MouseEvents.h"
#include "Engine/Sound/SoundManager.h"
#include "Engine/Utils/GameUtils.h"
#include "Resources.h"

using namespace cocos2d;

class MenuSprite : public Node
{
public:
	static MenuSprite * create(std::string spriteNormal, std::string spriteSelectedResource, std::string spriteClickedResource);
	static MenuSprite * create(Node* nodeNormal, Node* nodeSelected, Node* nodeClicked);

	void setContentScale(float scale);
	void setOffsetCorrection(Vec2 newOffsetCorrection);
	void setClickCallback(std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> onMouseClick);
	void setMouseOverCallback(std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> onMouseClick);
	void setMouseDownCallback(std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> onMouseDown);
	void setMouseDragCallback(std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> onDrag);
	void setMouseOverSound(std::string soundResource);
	void setClickSound(std::string soundResource);
	void disableInteraction();
	void enableInteraction();

protected:
	MenuSprite(Node* nodeNormal, Node* nodeSelected, Node* nodeClicked);
	~MenuSprite();

private:
	void initializeListeners();
	void onEnter() override;
	void update(float) override;
	bool intersects(Vec2 mousePos);
	void onMouseMove(EventCustom* event);
	void onMouseDown(EventCustom* event);
	void onMouseUp(EventCustom* event);

	std::string mouseOverSound;
	std::string clickSound;

	Node* sprite;
	Node* spriteClicked;
	Node* spriteSelected;
	Vec2 offsetCorrection;

	bool interactionEnabled;
	bool isClickInit;
	bool isClicked;

	std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> mouseClickEvent;
	std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> mouseDownEvent;
	std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> mouseDragEvent;
	std::function<void(MenuSprite*, MouseEvents::MouseEventArgs* args)> mouseOverEvent;
};
