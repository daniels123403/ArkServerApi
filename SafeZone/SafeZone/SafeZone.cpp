#include "SafeZone.h"
#include "SafeZoneHooks.h"
#include "SafeZoneConfig.h"
#include "SafeZoneCommands.h"
#pragma comment(lib, "ArkApi.lib")

void Init()
{
	Log::Get().Init("SafeZone");
	InitConfig();
	InitHooks();
	InitCommands();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		RemoveHooks();
		RemoveCommands();
		break;
	}
	return TRUE;
}