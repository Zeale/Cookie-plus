#pragma once

namespace Cookiep {
	class Command
	{ 
	public:
		Command(function<void ()> func);
		~Command();
		void addName(string name);
		vector<string>names;
		void execute();

	private:
		function<void()> func;
	};

	class CommandManager
	{
	public:
		CommandManager();
		~CommandManager();
		void run(string cmd);
		void exec(string cmd);
		void addCommand(Command cmd);

	private:
		string prevCmd;
		int sameCmdCount = 0;
		Command parsecmd(string cmd);
		vector<Command>commands;
	};

	class InvalidCmdException : exception
	{
	public:

	private:

	};
}