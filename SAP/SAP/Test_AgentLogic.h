#pragma once
#include "AgentController.h"
class Test_AgentLogic :
	public AgentController
{
	unsigned int number = 0;
	unsigned int getNumber();
public:
	Test_AgentLogic();
	~Test_AgentLogic();

	Action* getAction() override;
};

