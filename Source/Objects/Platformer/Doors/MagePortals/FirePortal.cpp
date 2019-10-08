#include "FirePortal.h"

#include "cocos/2d/CCDrawNode.h"
#include "cocos/2d/CCParticleSystemQuad.h"

#include "Resources/ParticleResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string FirePortal::MapKeyFirePortal = "fire-portal";

FirePortal* FirePortal::create(ValueMap& properties)
{
	FirePortal* instance = new FirePortal(properties);

	instance->autorelease();

	return instance;
}

FirePortal::FirePortal(ValueMap& properties) : super(properties)
{
	this->background = DrawNode::create();
	this->portalParticles = ParticleSystemQuad::create(ParticleResources::Portals_PortalFire);
	this->edge = DrawNode::create();

	this->background->drawSolidCircle(Vec2::ZERO, 96.0f, 0.0f, 32, Color4F::RED);
	this->drawEdge(Color4F::BLACK, this->edge, 96.0f, 6);

	this->contentNode->addChild(this->background);
	this->contentNode->addChild(this->portalParticles);
	this->contentNode->addChild(this->edge);
}

FirePortal::~FirePortal()
{
}

void FirePortal::onEnter()
{
	super::onEnter();
}

void FirePortal::initializePositions()
{
	super::initializePositions();
}

void FirePortal::initializeListeners()
{
	super::initializeListeners();
}