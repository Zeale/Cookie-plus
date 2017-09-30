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
		Command SETSYSTIME = Command(_setSystemTime), GETSYSTIME = Command([]() {SYSTEMTIME st; LPSYSTEMTIME lpst = &st; GetSystemTime(lpst); printSystemTime(st); });
		//v0.3c1
		Command GETNAME = Command([&]() {
			TCHAR username[UNLEN + 1];
			DWORD namesize = UNLEN + 1;
			if (GetUserName((TCHAR*)username, &namesize))
				std::wcout << "Your username is: " << username << L".\n";
			else
				println("An error occurred while retrieving your username.");
		});
		//v0.3c2
		Command OPEN_WEBSITE = Command([&]() {ShellExecute(NULL, "open", "http://dusttoash.org/", NULL, NULL, SW_SHOWNORMAL); });



		CommandManager GLOBAL_MANAGER = buildGlobalManager();

		//v0.1
		void _help() {
			using namespace Cookiep;
			println("Showing help:");
			println();
			println();
			println();
			println("help ~ Shows help.");
			println();
			println("hello|hi|greetings ~ Greets you.");
			println();
			println("exit|close|quit ~ Exits Cookie+.");
			println();
			println("clrscrn|clear-screen|cls|clr|cs|clear ~ Clears the console.");
			println();
			println("settime|set-system-time|set-time|setsystime ~ Sets the time for your computer. If the time value is invalid, then this will do nothing.");
			println();
			println("gettime|get-system-time|get-time|getsystime ~ Gets the time for your system. This should be the same as looking in the bottom right of your computer, apart from the fact that this will show you milliseconds.");
			println();
			println("website ~ Opens Cookie+'s website in your default browser.");
			println();
		}

		//v0.2c2
		void _clrscrn() {
			clearScreen();
			println("Please enter a command or \"help\" to continue. (Don't use quotes.)");
		}

		//v0.2c3
		void _setSystemTime() {
			clearScreen();
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
			println("Please input a day of the month. (From 0-31");
			cin >> in;
			systime.wDay = in;
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
			if (!SetSystemTime(&systime))
				if (GetLastError() == 87)
					println("The time value was invalid. (Perhaps it was too far in the future or past...)");
				else;
			else println("The time was successfully set.");


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
			//v0.3c1
			GETNAME.addName("get-name");
			GETNAME.addName("getname");
			//0.2c2
			OPEN_WEBSITE.addName("open-website");
			OPEN_WEBSITE.addName("website");



			CommandManager manager;

			manager.addCommand(HELLO);
			manager.addCommand(HELP);
			manager.addCommand(EXIT);
			manager.addCommand(CLRSCRN);
			manager.addCommand(SETSYSTIME);
			manager.addCommand(GETSYSTIME);
			manager.addCommand(GETNAME);
			manager.addCommand(OPEN_WEBSITE);

			return manager;
		}

	}
}