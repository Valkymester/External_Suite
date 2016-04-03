#pragma once
#include "IGEngine.h"

class AimAddon
{
private:
	IGEngine *ng;

public:
	void run();

	AimAddon(IGEngine *engine);
	~AimAddon();
};

