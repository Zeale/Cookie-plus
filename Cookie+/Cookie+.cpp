// Cookie+.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




namespace Cookiep {
	using namespace std;

	void clearScreen() {
		system("cls");
	}

	void pause(bool printmsg) {
		if (printmsg)
			println("Hit enter/return to continue.");
		getchar();
	}

	string getInput() {
		string input;
		cin >> input;
		return input;
	}

	void println(string line) {
		cout << line;
		println();
	}

	void println() {
		cout << "\n";
	}

	string toLowerCase(string input)
	{
		string output;
		transform(input.begin(), input.end(), back_inserter(output), tolower);
		return output;
	}

	bool strcasecmp(string s1, string s2) {
		return toLowerCase(s1) == toLowerCase(s2);
	}

	bool run = true;
}



using namespace Cookiep;

int main(int argc, char*args)
{


	println("Please enter a command or \"help\" to continue. (Don't use quotes.)");

	while (run) {
		Commands::GLOBAL_MANAGER.run(getInput());
		println();
	}


	pause(false);
	return 0;
}