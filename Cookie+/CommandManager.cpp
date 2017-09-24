#include "stdafx.h"

namespace Cookiep {

	using namespace std;


	void Command::addName(string name) {
		names.push_back(name);
	}

	void Command::execute()
	{
		func();
	}

	Command::Command(function<void()> f)
	{
		func = f;
	}

	Command::~Command()
	{
	}

	CommandManager::CommandManager()
	{
	}

	CommandManager::~CommandManager()
	{
		prevCmd.~basic_string();
		sameCmdCount = 0;
		commands.~vector();
	}
	void CommandManager::run(string cmd)
	{


		try { parsecmd(cmd).execute(); }
		catch (InvalidCmdException e) {
			Cookiep::println("Invalid command.");
		}

	}
	Command CommandManager::parsecmd(string cmd) {
		for (Command c : commands) {
			for (string s : c.names) {

				if (Cookiep::toLowerCase(s) == Cookiep::toLowerCase(cmd))
					return c;
			}
		}
		throw InvalidCmdException();
	}
	void CommandManager::exec(string cmd)
	{
	}

	void CommandManager::addCommand(Command cmd) {
		commands.push_back(cmd);
	}
}