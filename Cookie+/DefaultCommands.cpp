#include "stdafx.h"


namespace Cookiep {
	namespace Commands {
		using namespace Cookiep;

		//v0.1
		Command HELLO = Command([&]() { println("Hello"); }), HELP = Command(Commands::_help);
		//v0.2c1
		Command EXIT = Command([&]() { run = false; println("Exiting now..."); pause(true); });
		//v0.2c2
		Command CLRSCRN = Command(_clrscrn);


		CommandManager GLOBAL_MANAGER = buildGlobalManager();

		void Commands::addDefaultCommands(CommandManager manager)
		{
			manager.addCommand(HELLO);
			manager.addCommand(HELP);
		}

		//v0.1
		void _help() {
			using namespace Cookiep;
			println("Showing help:");
			println();
			println("help ~ Shows help.");
			println("hello|hi|greetings ~ Greets you.");
			println("exit|close|quit ~ Exits Cookie+.");
			println("clrscrn|clear-screen|cls|clr|cs|clear ~ Clears the console.");
		}

		//v0.2c2
		void _clrscrn() {
			system("cls");
			println("Please enter a command or \"help\" to continue. (Don't use quotes.)");
		}



		CommandManager buildGlobalManager() {

			using namespace Cookiep;

			//0.1
			HELLO.addName("hello");
			HELLO.addName("hi");
			HELLO.addName("greetings");
			HELLO.addName("-show-greeting");
			HELP.addName("help");
			HELP.addName("-show-help");
			//v0.2c2
			EXIT.addName("exit");
			EXIT.addName("close");
			EXIT.addName("quit");
			//v0.2c2
			CLRSCRN.addName("clrscrn");
			CLRSCRN.addName("clear-screen");
			CLRSCRN.addName("cls");
			CLRSCRN.addName("clr");
			CLRSCRN.addName("cs");
			CLRSCRN.addName("clear");



			CommandManager manager;

			manager.addCommand(HELLO);
			manager.addCommand(HELP);
			manager.addCommand(EXIT);
			manager.addCommand(CLRSCRN);

			return manager;
		}

	}
}