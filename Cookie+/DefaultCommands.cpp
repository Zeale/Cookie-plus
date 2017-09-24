#include "stdafx.h"


namespace Cookiep {
	namespace Commands {
		using namespace Cookiep;

		Command HELLO = Command([&]() { println("Hello"); }), HELP = Command(Commands::_help);
		CommandManager GLOBAL_MANAGER = buildGlobalManager();

		void Commands::addDefaultCommands(CommandManager manager)
		{
			manager.addCommand(HELLO);
			manager.addCommand(HELP);
		}

		void _help() {
			using namespace Cookiep;
			println("Showing help:");
			println();
			println("help ~ Shows help.");
			println("hello|hi|greetings ~ Greets you.");
		}

		CommandManager buildGlobalManager() {

			using namespace Cookiep;

			HELLO.addName("hello");
			HELLO.addName("hi");
			HELLO.addName("greetings");
			HELLO.addName("-show-greeting");
			HELP.addName("help");
			HELP.addName("-show-help");



			CommandManager manager;

			manager.addCommand(HELLO);
			manager.addCommand(HELP);
			return manager;
		}

	}
}