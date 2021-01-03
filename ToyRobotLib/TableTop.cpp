#include "pch.h"
#include "TableTop.h"

namespace ToyRobot
{

    TableTop::TableTop(int X, int Y)
    {
        XUnits = X;
        YUnits = Y;
    }

    bool TableTop::InsideArea(const int X, const int Y) const
    {
        return ((X >= 0) && (X <= XUnits) && (Y >= 0) && (Y <= YUnits));
    }

}