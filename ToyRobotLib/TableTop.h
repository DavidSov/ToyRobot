#pragma once

#ifndef TABLETOP_H
#define TABLETOP_H

namespace ToyRobot
{

	class TableTop
	{
	public:
		TableTop(int X, int Y);
		~TableTop() {};

		int GetXUnits() const { return XUnits; };
		int GetYUnits() const { return YUnits; };
		bool InsideArea(const int X, const int Y) const;

	private:
		int XUnits;
		int YUnits;
	};

}
#endif // TABLETOP_H