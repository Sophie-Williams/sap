#include "GameSimulator.h"
#include "Test_AgentLogic.h"

int main(void)
{
	Test_AgentLogic p1;
	Test_AgentLogic p2;
	ConfigurableParameters configuration;
	GameSimulator simulator(configuration, &p1, &p2);
	simulator.play();

	system("pause");
	return 0;
}