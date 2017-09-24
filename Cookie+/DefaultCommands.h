#pragma once

namespace Cookiep {
	namespace Commands {
		void addDefaultCommands(Cookiep::CommandManager manager);
		void _help();
		CommandManager buildGlobalManager();
		extern CommandManager GLOBAL_MANAGER;
	}
}


