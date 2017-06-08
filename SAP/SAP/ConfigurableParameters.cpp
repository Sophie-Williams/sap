#include "ConfigurableParameters.h"




ConfigurableParameters::ConfigurableParameters()
{
	PlayerAgent_Radius = 3;
	PlayerAgent_Speed = 3;
	PlayerAgent_HealthPoints = 3;
	PlayerAgent_MovementaPoints = 30;
	PlayerAgent_Weapon = WeaponIndentifier::None;
	PlayerAgent_MovementPointsGathered = 15;

	Missile_Radius = 1;
	Missile_Speed = 20;

	OrbitalMissile_Radius = 5;
	OrbitalMissile_TurnsToTarget = 3;

	World_Radius = 100;
	World_RadiusDecrease = 10;
	World_TurnsTillDecrease = 10;

	World_PlayerSpawn_MinDistanceToCenter = static_cast<unsigned int> (World_Radius * 0.4);
	World_PlayerSpawn_MaxDistanceToCenter = static_cast<unsigned int> (World_Radius * 0.9);

	World_GenerateResourcesAtStart = 10;
	World_MaxResourceGeneratedPerTurn = 2;

	World_GasSpawnChance = 55;
	World_MissileSpawnChance = 30;
	World_OrbitalMissileSpawnChance = 15;

	using namespace std::chrono_literals;
	Algorithm_ResponseTime = 1500ms;
}


ConfigurableParameters::~ConfigurableParameters()
{
}
