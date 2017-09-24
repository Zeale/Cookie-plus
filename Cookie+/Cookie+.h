#pragma once
#include "stdafx.h"

using namespace std;

namespace Cookiep {

	void pause(bool printmsg);
	void println(std::string line);
	void prinln();
	string toLowerCase(string input);
	bool strcasecmp(string s1, string s2);

	string getInput();
}