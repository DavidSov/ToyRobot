#pragma once
#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <vector>

using namespace std;

namespace ToyRobot
{

	class Position
	{
	public:
		Position();
		~Position() {};

		Position& operator= (const Position& rhs);

		void SetPosition(const int X, const int Y, const string Facing);
		bool GetPositon(int& X, int& Y, string& Facing);
		int GetPositionX() const { return PositionX; };
		int GetPositionY() const { return PositionY; };
		string GetPositionFacing() const { return PositionFacing; };
		void SetPositionX(const int X) { PositionX = X; };
		void SetPositionY(const int Y) { PositionY = Y; };
		void SetPositionFacing(const string Facing) { PositionFacing = Facing; };
	private:
		int PositionX;
		int PositionY;
		string PositionFacing;
	};

}
#endif // POSITION_H