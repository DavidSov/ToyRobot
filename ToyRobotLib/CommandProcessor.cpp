#include "pch.h"
#include "CommandProcessor.h"

namespace ToyRobot
{

	bool CommandProcessor::ParseCommandLine(const string CommandLine)
	{
		bool Found = false;
		bool Valid = true;
		int FirstPosition = 0;

		CmdLine = CommandLine;

		// Covert CommandLine to UPPER
		for_each(CmdLine.begin(), CmdLine.end(), [](char& c) { c = ::toupper(c); });

		int LastPosition = CmdLine.find_first_of(" ");

		if (LastPosition == -1)
		{
			LastPosition = CmdLine.length();
		}

		// Extract the command
		Cmd = CmdLine.substr(FirstPosition, LastPosition);

		for (vector<string>::iterator it = CommandList.begin(); it != CommandList.end(); it++)
		{
			string ValidCmd = *it;

			if (Cmd == ValidCmd)
			{
				Found = true;

				if (Cmd == "PLACE")
				{
					if (LastPosition == CmdLine.length())
					{
						Valid = false;
						break;
					}

					string CmdLineParms = CmdLine.substr(LastPosition + 1, CmdLine.length());
					// STRIP SPACE
					CmdLineParms.erase(std::remove_if(CmdLineParms.begin(), CmdLineParms.end(), ::isspace), CmdLineParms.end());
					ParameterList.clear();

					// Extract the parameters
					stringstream s_stream(CmdLineParms);
					while (s_stream.good())
					{
						string Parameter;
						getline(s_stream, Parameter, ',');
						ParameterList.push_back(Parameter);
					}
				}
				break;
			}
		}

		if (!Found)
		{
			cout << "ERROR - Invalid command" << endl;
			return false;
		}

		if (!Valid)
		{
			cout << "ERROR - PLACE Command must be in the form: PLACE X,Y,F" << endl;
			return false;
		}

		return true;
	}

}