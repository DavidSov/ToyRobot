#pragma once
#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <vector>

using namespace std;

namespace ToyRobot
{

	class Direction
	{
	public:
		Direction() {};
		~Direction() {};

		bool ValidDirection(const string Direction);
		string Rotate90DegreeClockwise(const string Facing);
		string Rotate90DegreeAntiClockwise(const string Facing);

	private:
		vector<string> DirectionList = { "NORTH", "EAST", "SOUTH", "WEST" };

	};

}
#endif // DIRECTION_H