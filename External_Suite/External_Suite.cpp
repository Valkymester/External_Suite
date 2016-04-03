// External_Suite.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "IGEngine.h"
#include "AimAddon.h"
#include "TriggerAddon.h"

int main()
{
	IGEngine		engine;
	AimAddon		aiAddon(&engine);
	TriggerAddon	trAddon(&engine);

	std::cout << "Running .." << std::endl;
	while (1)
	{
		engine.i_Count = 1;
		if ((GetAsyncKeyState(VK_LBUTTON))) {
			engine.aiAddonOn = true;
		}
		else
			engine.aiAddonOn = false;

		if ((GetAsyncKeyState(VK_XBUTTON1))) {
			engine.trAddonOn = true;
		}
		else
			engine.trAddonOn = false;
		engine.GetInfos();

		trAddon.run();
	}

	system("PAUSE");
    return 0;
}

