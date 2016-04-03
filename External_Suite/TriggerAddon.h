#pragma once
#include "IGEngine.h"

class TriggerAddon
{
private:
	IGEngine *ng;
public:
	void run();

	TriggerAddon(IGEngine *engine);
	~TriggerAddon();
};

