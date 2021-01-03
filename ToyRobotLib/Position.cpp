#include "pch.h"
#include "Position.h"

namespace ToyRobot
{

	Position::Position()
	{
		PositionX = -1;
		PositionY = -1;
		PositionFacing = "";
	}

	Position& Position::operator=(const Position& rhs)
	{
		PositionX = rhs.PositionX;
		PositionY = rhs.PositionY;
		PositionFacing = rhs.PositionFacing;
		return *this;
	}

	void Position::SetPosition(const int X, const int Y, const string Facing)
	{
		PositionX = X;
		PositionY = Y;
		PositionFacing = Facing;
	}

	bool Position::GetPositon(int& X, int& Y, string& Facing)
	{
		X = PositionX;
		Y = PositionY;
		Facing = PositionFacing;
		return true;
	}

}