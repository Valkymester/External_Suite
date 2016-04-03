#include "stdafx.h"
#include "TriggerAddon.h"

DWORD localPlayer = NULL;
DWORD entityPlayer = NULL;

int localTeam = NULL;
int entityTeam = NULL;

bool fireNeeded = false;

int inCrossId = NULL;

void TriggerAddon::run()
{
	//if (ng->trAddonOn && ng->pm.Locate(ng->i_Enemies, ng->i_Count, ng->pm.Read<int>(ng->dwPBase + 0xA954)))
	//{
	//	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	//	Sleep(1); //Response Time     				
	//	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	//}


	localPlayer = ng->pm.Read<int>(ng->dwClient + 0xA804CC);
	inCrossId = ng->pm.Read<int>(localPlayer + 0xA954);

	entityPlayer = ng->pm.Read<int>(ng->dwClient + 0x4A9B4E4 + ((inCrossId - 1) * 0x10));

	localTeam = ng->pm.Read<int>(localPlayer + 0xF0);
	entityTeam = ng->pm.Read<int>(entityPlayer + 0xF0);

	if (inCrossId > 0 && inCrossId <= 64)
	{
		if (localTeam != entityTeam) // Team check
		{
			if (GetAsyncKeyState(86))
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(5);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(5);
			}
		}
	}

	return;
}

TriggerAddon::TriggerAddon(IGEngine * engine)
{
	this->ng = engine;
}

TriggerAddon::~TriggerAddon()
{
}

