#include "pch.h"
#include "Direction.h"

namespace ToyRobot
{

	bool Direction::ValidDirection(const string Direction)
	{
		bool Found = false;

		for (vector<string>::iterator it = DirectionList.begin(); it != DirectionList.end(); it++)
		{
			string Direct = *it;
			if (Direct == Direction)
			{
				Found = true;
				break;
			}
		}

		return Found;
	}

	string Direction::Rotate90DegreeClockwise(const string Facing)
	{
		string NewFacing = "";

		for (vector<string>::iterator it = DirectionList.begin(); it != DirectionList.end(); it++)
		{
			string Direction = *it;

			if (Direction == Facing)
			{
				if (it == prev(DirectionList.end()))
				{
					NewFacing = *DirectionList.begin();
				}
				else
				{
					NewFacing = *next(it);
				}
				break;
			}
		}

		return NewFacing;
	}

	string Direction::Rotate90DegreeAntiClockwise(const string Facing)
	{
		string NewFacing = "";

		for (vector<string>::iterator it = DirectionList.begin(); it != DirectionList.end(); it++)
		{
			string Direction = *it;

			if (Direction == Facing)
			{
				if (it == DirectionList.begin())
				{
					NewFacing = *prev(DirectionList.end());
				}
				else
				{
					NewFacing = *prev(it);
				}
				break;
			}
		}

		return NewFacing;
	}

}