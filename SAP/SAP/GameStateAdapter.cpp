#include "GameStateAdapter.h"
#include <algorithm>


GameStateAdapter::GameStateAdapter()
{
	
}


GameStateAdapter::~GameStateAdapter()
{
}


void GameStateAdapter::bind(GameState game, bool player2)
{
	_config_ptr = game.config_ptr;
	_radius = &game.Radius;
	_turn = &game.Turn;

	_resourceMap = &game.ResourceMap;
	_missileList = &game.MissileList;
	_orbitalMissileList = &game.OrbitalMissileList;

	if (player2) {
		_player1 = &game.Player2;
		_player2 = &game.Player1;
	}
	else {
		_player1 = &game.Player1;
		_player2 = &game.Player2;
	}
}


GameState GameStateAdapter::getGameState() const
{
	GameState newGameState;

	newGameState.Radius = *_radius;
	newGameState.Turn = *_turn;
	newGameState.Player1 = *_player1;
	newGameState.Player2 = *_player2;
	newGameState.MissileList = *_missileList;
	newGameState.OrbitalMissileList = *_orbitalMissileList;
	newGameState.ResourceMap = *_resourceMap;
	newGameState.config_ptr = _config_ptr;

	return newGameState;
}


PlayerAgent GameStateAdapter::getPlayer1() const
{
	PlayerAgent newPlayerAgent;
	newPlayerAgent = *_player1;
	return newPlayerAgent;
}


PlayerAgent GameStateAdapter::getPlayer2() const
{
	PlayerAgent newPlayerAgent;
	newPlayerAgent = *_player2;
	return newPlayerAgent;
}


std::map<Point2D, ResourceIndentifier> GameStateAdapter::getResourceMap() const
{
	std::map<Point2D, ResourceIndentifier> newMap = *_resourceMap;
	return newMap;
}


std::list<MovableObject> GameStateAdapter::getMissileList() const
{
	std::list<MovableObject> newList = *_missileList;
	return newList;
}


std::list<OrbitalMissile> GameStateAdapter::getOrbitalMissileList() const
{
	std::list<OrbitalMissile> newList = *_orbitalMissileList;
	return newList;
}


