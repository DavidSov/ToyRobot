#include "pch.h"
#include "Robot.h"

namespace ToyRobot
{

	Robot::Robot(const TableTop& ATableTop, const Direction& ADirection) : RobotTableTop(ATableTop), RobotDirection(ADirection)
	{
		CommandLine = "";
		Command = "";
		ParameterList.clear();
		CurrentPosition.SetPosition(-1, -1, "");
		NextPosition.SetPosition(-1, -1, "");
		FirstPLACEExecuted = false;
	}


	bool Robot::ProcessCommandLine(const string CmdLine)
	{
		CommandProcessor RobotCommandProcessor;

		if (!RobotCommandProcessor.ParseCommandLine(CmdLine))
		{
			return false;
		}

		Command = RobotCommandProcessor.GetCommand();

		if (Command == "PLACE")
		{
			ParameterList = RobotCommandProcessor.GetParameters();

			if (!GetParameters())
			{
				return false;
			}
		}

		if (!FirstPLACEExecuted && Command != "EXIT")
		{
			if (Command != "PLACE")
			{
				cout << "Initial command must be a valid PLACE or an EXIT command" << endl;
				return false;
			}
			FirstPLACEExecuted = true;
		}

		return ExecuteCommand();
	}

	bool Robot::GetCurrentPosition(int& X, int& Y, string& Facing)
	{
		X = CurrentPosition.GetPositionX();
		Y = CurrentPosition.GetPositionY();
		Facing = CurrentPosition.GetPositionFacing();
		return true;
	}

	bool Robot::ExecuteCommand()
	{
		if (Command == "PLACE")
		{
			return PlaceAtNextPostion();
		}
		else if (Command == "LEFT")
		{
			return TurnLeft();
		}
		else if (Command == "RIGHT")
		{
			return TurnRight();
		}
		else if (Command == "MOVE")
		{
			return Move();
		}
		else if (Command == "REPORT")
		{
			return Report();
		}
		else if (Command == "EXIT")
		{
			return true;
		}
	}


	bool Robot::GetParameters()
	{

		if (ParameterList.size() != 3)
		{
			cout << "ERROR - Invalid Number of PLACE Command Parameters" << endl;
			return false;
		}
		else
		{
			// Check that X, Y are numbers
			if (!isInteger(ParameterList[0]) || !isInteger(ParameterList[1]))
			{
				cout << "ERROR - Invalid PLACE Command Parameter X or Y" << endl;
				return false;
			}

			// Check that Facing is a direction
			if (!RobotDirection.ValidDirection(ParameterList[2]))
			{
				cout << "ERROR - Invalid PLACE Command Parameter F" << endl;
				return false;
			}

			int ParameterX = stoi(ParameterList[0]);
			int ParameterY = stoi(ParameterList[1]);
			string ParameterFacing = ParameterList[2];
			NextPosition.SetPosition(ParameterX, ParameterY, ParameterFacing);

			if (!RobotTableTop.InsideArea(ParameterX, ParameterY))
			{
				cout << "ERROR - PLACE position is outside the table top area. " << endl;
				return false;
			}

		}

		return true;
	}

	bool Robot::PlaceAtNextPostion()
	{
		CurrentPosition = NextPosition;
		return true;
	}

	bool Robot::Move()
	{
		GetNextPosition();
		if (RobotTableTop.InsideArea(NextPosition.GetPositionX(), NextPosition.GetPositionY()))
		{
			CurrentPosition = NextPosition;
			return true;
		}
		else
		{
			cout << "ERROR - Outside table top area. I am not moving because I don't want to fall off the table top." << endl;
			return false;
		}
	}

	bool Robot::TurnLeft()
	{
		CurrentPosition.SetPositionFacing(RobotDirection.Rotate90DegreeAntiClockwise(CurrentPosition.GetPositionFacing()));
		return true;
	}

	bool Robot::TurnRight()
	{
		CurrentPosition.SetPositionFacing(RobotDirection.Rotate90DegreeClockwise(CurrentPosition.GetPositionFacing()));
		return true;
	}

	bool Robot::Report()
	{
		cout << "Output: " << CurrentPosition.GetPositionX() << "," << CurrentPosition.GetPositionY() << "," << CurrentPosition.GetPositionFacing() << endl;
		return true;
	}

	void Robot::GetNextPosition()
	{
		// Work out Next position
		NextPosition = CurrentPosition;

		if (CurrentPosition.GetPositionFacing() == "NORTH")
		{
			NextPosition.SetPositionY(CurrentPosition.GetPositionY() + 1);
		}
		else if (CurrentPosition.GetPositionFacing() == "EAST")
		{
			NextPosition.SetPositionX(CurrentPosition.GetPositionX() + 1);
		}
		else if (CurrentPosition.GetPositionFacing() == "SOUTH")
		{
			NextPosition.SetPositionY(CurrentPosition.GetPositionY() - 1);
		}
		else if (CurrentPosition.GetPositionFacing() == "WEST")
		{
			NextPosition.SetPositionX(CurrentPosition.GetPositionX() - 1);
		}
	}

	void Robot::GetCurrentPosition(Position& Pos)
	{
		Pos = CurrentPosition;
	}

	bool Robot::isInteger(string str)
	{
		if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+') && (str[0] != ' ')))
			return false;

		char* p;
		long int RetVal;
		RetVal = strtol(str.c_str(), &p, 10);

		return (*p == 0);
	}

}