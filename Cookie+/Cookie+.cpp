// Cookie+.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstdio>

namespace Cookiep {
	using namespace std;

	void parsecmd(string input);
	void pause(bool printmsg);
	void println(string line);
	void prinln();

	string getInput();



	void parsecmd(string input) {
		if (input == "hello")println("hi.");
		else
			println("That command isn't registered...");

	}

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
}



using namespace Cookiep;

int main(int argc, char*args)
{

	bool run = true;
	while (run) {
		parsecmd(getInput());
	}


	pause(false);
	return 0;
}