#include "stdafx.h"
#include "IGEngine.h"


IGEngine::IGEngine()
{
	//aiAddonOn = false;
	//trAddonOn = false;

	pm.GetProcess("csgo.exe");
	std::cout << "Process found" << std::endl;

	dwClient = pm.Module("client.dll");
	std::cout << "Client.ddl addr found" << std::endl;

	dwEngine = pm.Module("engine.dll");
	std::cout << "Engine.ddl addr found" << std::endl;

	dwPBase = pm.Read<DWORD>(dwClient + 0x00A804CC);
	dwAngPtr = pm.Read<DWORD>(dwEngine + 0x00610344);
}


IGEngine::~IGEngine()
{
}

void IGEngine::GetInfos()
{
	if (trAddonOn)
	{
		//Read Our Info			
		nfo[0].fPos[0] = pm.Read<float>(dwPBase + 0x134);
		nfo[0].fPos[1] = pm.Read<float>(dwPBase + 0x138);
		nfo[0].fPos[2] = pm.Read<float>(dwPBase + 0x13C);
		W2S_M = pm.Read<WorldToScreenMatrix_t>(dwClient + 0x04A8D074);
	}

	fri_t = pm.Read<int>(dwPBase + 0xF0);

	for (int i = 1; i < 64; i++)
	{
		int offset = i * 0x10;
		dwEntity = pm.Read<DWORD>((dwClient + 0x04A9B4E4) + offset);

		if (!dwEntity)
			return;

		nmy_t = pm.Read<int>(dwEntity + 0xF0);

		if (nmy_t != fri_t && nmy_t > 1)
		{
			if (trAddonOn)
				i_Enemies[i_Count] = pm.Read<int>(dwEntity + 0x64);//Ent ID

			if (aiAddonOn)
			{
				nfo[i_Count].fPos[0] = pm.Read<float>(dwEntity + 0x134);//X			
				nfo[i_Count].fPos[1] = pm.Read<float>(dwEntity + 0x138);//Y			
				nfo[i_Count].fPos[2] = pm.Read<float>(dwEntity + 0x13C);//Z 				
				nfo[i_Count].iHealth = pm.Read<int>(dwEntity + 0xFC);//HP	
				nfo[i_Count].fFlags = pm.Read<int>(dwEntity + 0x100);
			}
			i_Count++;
		}
	}
}
