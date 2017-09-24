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
		//v0.2c3
		Command SETSYSTIME = Command(_setSystemTime), GETSYSTIME = Command([]() {SYSTEMTIME time; GetSystemTime(&time); printSystemTime(time); });


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

		//v0.2c3
		void _setSystemTime() {
			_clrscrn();
			println("Please input a year (From 1601 to 30827.");
			int in;
			cin >> in;
			SYSTEMTIME systime;
			systime.wYear = in;
			println("Please input a month. (From 0-11");
			cin >> in;
			systime.wMonth = in;
			println("Please input a day of the week. (From 0-6)");
			cin >> in;
			systime.wDayOfWeek = in;
			println("Please input an hour. (From 0-23)");
			cin >> in;
			systime.wHour = in;
			println("Please input a minute. (From 0-59)");
			cin >> in;
			systime.wMinute = in;
			println("Please input a second. (From 0-59)");
			cin >> in;
			systime.wSecond = in;
			println("Please input a millisecond. (From 0-999)");
			cin >> in;
			systime.wMilliseconds = in;
			SetSystemTime(&systime);

		}

		void printSystemTime(SYSTEMTIME time) {
			using namespace std;
			cout << "\n\n";
			cout << "Year: " << time.wYear << "\n";
			cout << "Month: " << time.wMonth << "\n";
			cout << "Day of Week: " << time.wDayOfWeek << "\n";
			cout << "Hour: " << time.wHour << "\n";
			cout << "Minute: " << time.wMinute << "\n";
			cout << "Second: " << time.wSecond << "\n";
			cout << "Millisecond: " << time.wMilliseconds << "\n";
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
			//v0.2c3
			SETSYSTIME.addName("set-system-time");
			SETSYSTIME.addName("set-time");
			SETSYSTIME.addName("setsystime");
			SETSYSTIME.addName("settime");
			GETSYSTIME.addName("get-system-time");
			GETSYSTIME.addName("get-time");
			GETSYSTIME.addName("gettime");
			GETSYSTIME.addName("getsystime");



			CommandManager manager;

			manager.addCommand(HELLO);
			manager.addCommand(HELP);
			manager.addCommand(EXIT);
			manager.addCommand(CLRSCRN);
			manager.addCommand(SETSYSTIME);
			manager.addCommand(GETSYSTIME);

			return manager;
		}

	}
}