#include "main.h"

DWORD WINAPI MenuThread(LPVOID threadParam)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			bMenuOpen = !bMenuOpen;
			Sleep(300);
		}

		Sleep(1);
	}

	return TRUE;
}

DWORD WINAPI CheatThread(LPVOID threadParam)
{
	offys.dwhActiveWeapon = NetVarManager.GetOffset("DT_BasePlayer", "m_hActiveWeapon");
	hwCSGO = FindWindow(NULL, "Counter-Strike: Global Offensive");
	Interfaces->CaptureInterfaces();
	oPaintTraverse = (PaintTraverseFn)VMTManager.Hook(Interfaces->VPanel, 41, PaintTraverse);
	oCreateMove = (CreateMoveFn)VMTManager.Hook(Interfaces->ClientMode, 24, CreateMove);
	return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason != DLL_PROCESS_ATTACH)
		return TRUE;
	Msg("%s\n", "Creating thread...");
	CreateThread(NULL, NULL, CheatThread, NULL, NULL, NULL);
	CreateThread(NULL, NULL, MenuThread, NULL, NULL, NULL);
	return TRUE;
}