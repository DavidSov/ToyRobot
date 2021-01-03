#include "pch.h"
#include "CppUnitTest.h"
#include "..\ToyRobotLib\TableTop.h"
#include"..\ToyRobotLib\\Direction.h"
#include "..\ToyRobotLib\Robot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ToyRobot;

namespace ToyRobotUnitTest
{
	TEST_CLASS(RobotClass)
	{
	public:
		int XUnits = 5;
		int YUnits = 5;
		Direction RobotDirection;

		TEST_METHOD(ProcessCommandLine_Valid_EXIT)
		{
			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine = "EXIT";
			bool RetVal = ToyRobot.ProcessCommandLine(CommandLine);
			Assert::AreEqual(true, RetVal);
		}

		TEST_METHOD(ProcessCommandLine_Invalid_EXIT)
		{
			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine = "EXITS";
			bool RetVal = ToyRobot.ProcessCommandLine(CommandLine);
			Assert::AreEqual(false, RetVal);
		}

		TEST_METHOD(ProcessCommandLine_Valid_REPORT)
		{
			int ExpectX = 3;
			int ExpectY = 2;
			string ExpectFacing = "SOUTH";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine1 = "PLACE 3,2,SOUTH";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine1);
			bool RetVal2 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate Report current position
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

		TEST_METHOD(ProcessCommandLine_Valid_PLACE)
		{
			int ExpectX = 1;
			int ExpectY = 1;
			string ExpectFacing = "NORTH";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine = "PLACE 1,1,NORTH";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine);
			bool RetVal2 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate position the same as placed
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

		TEST_METHOD(ProcessCommandLine_Invalid_PLACE)
		{
			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine = "PLACE 1,1";
			bool RetVal = ToyRobot.ProcessCommandLine(CommandLine);
			Assert::AreEqual(false, RetVal);
		}

		TEST_METHOD(ProcessCommandLine_Valid_MOVE)
		{
			int ExpectX = 1;
			int ExpectY = 2;
			string ExpectFacing = "NORTH";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine1 = "PLACE 1,1,NORTH";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine1);
			string CommandLine2 = "MOVE";
			bool RetVal2 = ToyRobot.ProcessCommandLine(CommandLine2);
			bool RetVal3 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate position moved
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

		TEST_METHOD(ProcessCommandLine_Invalid_MOVE)
		{
			int ExpectX = 0;
			int ExpectY = 1;
			string ExpectFacing = "WEST";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine1 = "PLACE 0,1,WEST";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine1);
			string CommandLine2 = "MOVE";
			bool RetVal2 = ToyRobot.ProcessCommandLine(CommandLine2);
			bool RetVal3 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate position stays the same
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

		TEST_METHOD(ProcessCommandLine_Valid_LEFT)
		{
			int ExpectX = 1;
			int ExpectY = 1;
			string ExpectFacing = "WEST";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine1 = "PLACE 1,1,NORTH";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine1);
			string CommandLine2 = "LEFT";
			bool RetVal2 = ToyRobot.ProcessCommandLine(CommandLine2);
			bool RetVal3 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate position X, Y stays the same but direction changed
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

		TEST_METHOD(ProcessCommandLine_Valid_RIGHT)
		{
			int ExpectX = 0;
			int ExpectY = 1;
			string ExpectFacing = "NORTH";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine1 = "PLACE 0,1,WEST";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine1);
			string CommandLine2 = "RIGHT";
			bool RetVal2 = ToyRobot.ProcessCommandLine(CommandLine2);
			bool RetVal3 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate position X, Y stays the same but direction changed
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

		TEST_METHOD(ProcessCommandLine_Valid_Commands)
		{
			int ExpectX = 3;
			int ExpectY = 2;
			string ExpectFacing = "NORTH";
			int TestX = 0;
			int TestY = 0;
			string TestFacing = "";

			TableTop RobotTableTop(XUnits, YUnits);
			Robot ToyRobot(RobotTableTop, RobotDirection);
			string CommandLine1 = "PLACE 2,2,NORTH";
			bool RetVal1 = ToyRobot.ProcessCommandLine(CommandLine1);
			string CommandLine2 = "RIGHT";
			bool RetVal2 = ToyRobot.ProcessCommandLine(CommandLine2);
			string CommandLine3 = "MOVE";
			bool RetVal3 = ToyRobot.ProcessCommandLine(CommandLine3);
			string CommandLine4 = "LEFT";
			bool RetVal4 = ToyRobot.ProcessCommandLine(CommandLine4);
			// Report
			bool RetVal5 = ToyRobot.GetCurrentPosition(TestX, TestY, TestFacing);
			// Validate current position
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectFacing, TestFacing);
		}

	};

}
