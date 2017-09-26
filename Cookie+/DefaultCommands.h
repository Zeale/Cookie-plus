#pragma once
#include <stdlib.h>

namespace Cookiep {
	namespace Commands {
		void _help();
		CommandManager buildGlobalManager();
		extern CommandManager GLOBAL_MANAGER;
		void _clrscrn();
		void _setSystemTime();
		void printSystemTime(SYSTEMTIME time);
	}
}


