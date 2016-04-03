#pragma once
#include "ProcMem.h"

typedef struct s_players_infos {
	bool trAddonOn;
	bool aiAddonOn;
	int i_team, e_team, iHealth, i_Count, fFlags;
	float fPos[3], Angle[3];
}t_info;

class IGEngine
{
public:
	ProcMem pm;
	t_info  nfo[32];
	DWORD dwClient;
	DWORD dwEngine;
	DWORD dwPBase;
	DWORD dwEntity;
	DWORD dwBase;
	DWORD dwAngPtr;
	int i_Enemies[32];

	bool aiAddonOn;
	bool trAddonOn;

	int  nmy_t;
	int	 fri_t;
	int	 i_Count;

	//World To Screen Info
	typedef struct {
		float flMatrix[4][4];
	} WorldToScreenMatrix_t;
	WorldToScreenMatrix_t W2S_M;

public:
	IGEngine();
	~IGEngine();

	void GetInfos();
};

