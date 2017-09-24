#include "stdafx.h"


namespace Cookiep {
	namespace Commands {
		using namespace Cookiep;

		//v0.1
		Command HELLO = Command([&]() { println("Hello"); }), HELP = Command(Commands::_help);
		//v0.2
		Command EXIT = Command([&]() { run = false; println("Exiting now..."); pause(true); });


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
			println("exit|close|quit ~ Exits Cookie+.");
		}

		CommandManager buildGlobalManager() {

			using namespace Cookiep;

			HELLO.addName("hello");
			HELLO.addName("hi");
			HELLO.addName("greetings");
			HELLO.addName("-show-greeting");
			HELP.addName("help");
			HELP.addName("-show-help");
			EXIT.addName("exit");
			EXIT.addName("close");
			EXIT.addName("quit");



			CommandManager manager;

			manager.addCommand(HELLO);
			manager.addCommand(HELP);
			manager.addCommand(EXIT);

			return manager;
		}

	}
}