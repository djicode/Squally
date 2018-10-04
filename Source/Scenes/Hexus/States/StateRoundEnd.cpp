#include "StateRoundEnd.h"

StateRoundEnd* StateRoundEnd::create()
{
	StateRoundEnd* instance = new StateRoundEnd();

	instance->autorelease();

	return instance;
}

StateRoundEnd::StateRoundEnd() : StateBase(GameState::StateType::RoundEnd)
{
}

StateRoundEnd::~StateRoundEnd()
{
}

void StateRoundEnd::onBeforeStateEnter(GameState* gameState)
{
	StateBase::onBeforeStateEnter(gameState);
}

void StateRoundEnd::onStateEnter(GameState* gameState)
{
	StateBase::onStateEnter(gameState);

	GameState::StateType nextState = GameState::StateType::RoundStart;

	if (gameState->playerLosses >= 2)
	{
		nextState = GameState::StateType::GameEnd;
		SoundManager::playSoundResource(Resources::Sounds_Hexus_UI_CCG_card_downgrade);
	}
	else if (gameState->enemyLosses >= 2)
	{
		nextState = GameState::StateType::GameEnd;
		SoundManager::playSoundResource(Resources::Sounds_Hexus_UI_CCG_card_upgrade);
	}
	else if (gameState->playerHand->getCardCount() == 0)
	{
		// Player cannot enter the last round with zero cards
		gameState->playerLosses++;
		SoundManager::playSoundResource(Resources::Sounds_Hexus_UI_CCG_card_downgrade);
	}

	const float fadeSpeed = 0.5f;

	this->runAction(Sequence::create(
		CallFunc::create([=]()
		{
			std::vector<CardRow*> rows = gameState->getAllRows();

			for (auto it = rows.begin(); it != rows.end(); it++)
			{
				for (auto cardIt = (*it)->rowCards->begin(); cardIt != (*it)->rowCards->end(); cardIt++)
				{
					(*cardIt)->runAction(FadeTo::create(fadeSpeed, 0));
				}
			}
		}),
		DelayTime::create(fadeSpeed),
		CallFunc::create([=]()
		{
			gameState->endRound();
		}),
		CallFunc::create([=]()
		{
			GameState::updateState(gameState, nextState);
		}),
		nullptr
	));
}

void StateRoundEnd::onStateReload(GameState* gameState)
{
	StateBase::onStateReload(gameState);
}

void StateRoundEnd::onStateExit(GameState* gameState)
{
	StateBase::onStateExit(gameState);
}