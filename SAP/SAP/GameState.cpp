#include "GameState.h"



GameState::GameState()
{
}


GameState::~GameState()
{
}


void GameState::advanceOrbitalMissiles()
{
	for (auto it = OrbitalMissileList.begin(); it != OrbitalMissileList.end();)
	{
		if (it->turnEnded()) {
			if (it->didHit(Player1)) {
				Player1.inflictDamage();
			}
			if (it->didHit(Player2)) {
				Player2.inflictDamage();
			}
			it = OrbitalMissileList.erase(it);
		}
		else {
			it++;
		}
	}
}


//	move all missiles step by step, with each step do collsion check
void GameState::moveMissiles()
{
	unsigned int missileSpeed = config_ptr->Missile_Speed;
	for (unsigned int i = 0; i < missileSpeed; i++)
	{
		for (auto missile : MissileList)
		{
			missile.move();
		}

		bool didHit = false;
		auto it = MissileList.begin();

		while (it != MissileList.end())
		{
			didHit = false;

			auto it_collision = next(it);
			while (it_collision != MissileList.end())
			{
				if (it->collision(&(*it_collision)))
				{
					if (it_collision->collision(&Player1)) {
						Player1.inflictDamage();
					}
					if (it_collision->collision(&Player2)) {
						Player2.inflictDamage();
					}

					it_collision = MissileList.erase(it_collision);
				}
				else {
					it_collision++;
				}
			}

			if (it->collision(&Player1)) {
				Player1.inflictDamage();
				didHit = true;
			}
			if (it->collision(&Player2)) {
				Player2.inflictDamage();
				didHit = true;
			}

			if (didHit) {
				it = MissileList.erase(it);
			}
			else {
				it++;
			}
		}
	}
}


void GameState::movePlayer1()
{
	movePlayer(Player1);
}


void GameState::movePlayer2()
{
	movePlayer(Player2);
}


void GameState::movePlayer(PlayerAgent& player)
{
	player.move();
	player.movementPoints--;

	for (auto it = MissileList.begin(); it != MissileList.end();)
	{
		if (player.collision(&(*it))) {
			it = MissileList.erase(it);
			player.inflictDamage();
		}
		else {
			it++;
		}
	}

	if (Player1.collision(&Player2)) {
		Player1.commitedSuicide();
		Player2.commitedSuicide();
	}
}

