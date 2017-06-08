#include "ConfigurableParameters.h"




ConfigurableParameters::ConfigurableParameters()
{
	PlayerAgent_Radius = 3;
	PlayerAgent_HealthPoints = 10;
	PlayerAgent_MovementaPoints = 30;
	PlayerAgent_Weapon = WeaponIndentifier::None;
	PlayerAgent_MovementPointsGathered = 15;

	Missile_Radius = 1;
	Missile_Speed = 20;

	OrbitalMissile_Radius = 5;
	OrbitalMissile_TurnsToTarget = 3;

	World_Radius = 100;
	World_RadiusDecrease = 5;
	World_TurnsTillDecrease = 20;

	World_PlayerSpawn_MinDistanceToCenter = static_cast<unsigned int> (World_Radius * 0.2);
	World_PlayerSpawn_MaxDistanceToCenter = static_cast<unsigned int> (World_Radius * 0.8);

	World_GenerateResourcesAtStart = 1000;
	World_MaxResourceGeneratedPerTurn = 20;

	World_GasSpawnChance = 55;
	World_MissileSpawnChance = 30;
	World_OrbitalMissileSpawnChance = 15;

	using namespace std::chrono_literals;
	Algorithm_ResponseTime = 1500ms;
}


ConfigurableParameters::~ConfigurableParameters()
{
}
