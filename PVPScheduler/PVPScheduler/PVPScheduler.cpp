#include "PVPScheduler.h"
#include "PVPSchedulerConfig.h"
#include "PVPSchedulerCommands.h"
#include "PVPSchedulerHooks.h"

#pragma comment(lib, "ArkApi.lib")

void Init()
{
	Log::Get().Init("PVPScheduler");
	InitConfig();
	InitCommands();
	InitHooks();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		RemoveCommands();
		RemoveHooks();
		break;
	}
	return TRUE;
}
