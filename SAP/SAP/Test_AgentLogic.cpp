#include "Test_AgentLogic.h"



Test_AgentLogic::Test_AgentLogic()
{
}


Test_AgentLogic::~Test_AgentLogic()
{
}


Action* Test_AgentLogic::getAction()
{	
	// return new Move(AllowedMovement::Forward_By1);
	return new Move(AllowedMovement::Forward_By3);	
}
