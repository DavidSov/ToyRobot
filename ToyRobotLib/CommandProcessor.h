#pragma once
#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace ToyRobot
{

	class CommandProcessor
	{
	public:
		CommandProcessor() {};
		~CommandProcessor() {};

		bool ParseCommandLine(const string CommandLine);
		string GetCommand() const { return Cmd; };
		vector<string> GetParameters() const { return ParameterList; };

	private:
		vector<string> CommandList = { "PLACE", "LEFT", "RIGHT", "MOVE", "REPORT", "EXIT" };
		string CmdLine;
		string Cmd;
		vector<string> ParameterList;

	};

}
#endif // COMMAND_PROCESSOR_H