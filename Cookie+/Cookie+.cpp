// Cookie+.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




namespace Cookiep {
	using namespace std;

	void pause(bool printmsg) {
		if (printmsg)
			println("Press any key to continue.");
		getchar();
	}

	string getInput() {
		string input;
		cin >> input;
		return input;
	}

	void println(string line) {
		cout << line;
		prinln();
	}

	void prinln() {
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
}



using namespace Cookiep;

int main(int argc, char*args)
{
	CommandManager manager;
	Command hi = Command([&]() { println("Hello"); });
	hi.addName("Hello");
	hi.addName("Hi");

	manager.addCommand(hi);

	bool run = true;
	while (run) {
		manager.run(getInput());
	}


	pause(false);
	return 0;
}