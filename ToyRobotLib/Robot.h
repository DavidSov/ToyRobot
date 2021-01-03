#pragma once

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream> 
#include <fstream>
#include<sstream>
//#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include "TableTop.h"
#include "Direction.h"
#include "CommandProcessor.h"
#include "Position.h"

using namespace std;

namespace ToyRobot
{

	class Robot
	{
	public:
		Robot(const TableTop& ATableTop, const Direction& ADirection);
		bool ProcessCommandLine(const string CmdLine);
		bool GetCurrentPosition(int &X, int &Y, string &Facing);
	private:
		string CommandLine;
		string Command;
		vector<string> ParameterList;
		Position CurrentPosition;
		Position NextPosition;
		TableTop RobotTableTop;
		Direction RobotDirection;
		bool FirstPLACEExecuted;

		bool ExecuteCommand();
		bool GetParameters();
		bool PlaceAtNextPostion();
		bool TurnLeft();
		bool TurnRight();
		bool Move();
		bool Report();
		void GetCurrentPosition(Position& Pos);
		void GetNextPosition();
		bool isInteger(string str);
	};

}
#endif // ROBOT_H