#include "stdafx.h"
#include "TriggerAddon.h"

void TriggerAddon::run()
{
	if (ng->trAddonOn && ng->pm.Locate(ng->i_Enemies, ng->i_Count, ng->pm.Read<int>(ng->dwPBase + 0xA954)))
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(1); //Response Time     				
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
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
