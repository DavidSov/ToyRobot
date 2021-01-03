#include "pch.h"
#include "CppUnitTest.h"
#include "..\ToyRobotLib\CommandProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace ToyRobot;

namespace ToyRobotUnitTest
{

	TEST_CLASS(CommandProcessorClass)
	{
	public:
		CommandProcessor CmdProcessor;

		TEST_METHOD(GetCommand_Valid)
		{
			string ExpectCmd = "EXIT";
			bool RetVal = CmdProcessor.ParseCommandLine(ExpectCmd);
			string TestCmd = CmdProcessor.GetCommand();
			Assert::AreEqual(ExpectCmd, TestCmd);
		}

		TEST_METHOD(GetCommand_Invalid)
		{
			string ExpectCmd = "PLACEX";
			bool RetVal = CmdProcessor.ParseCommandLine(ExpectCmd);
			string TestCmd = CmdProcessor.GetCommand();
			Assert::AreEqual(ExpectCmd, TestCmd);
		}

		TEST_METHOD(GetParameters_Valid)
		{
			string ActualCmdLine = "PLACE 1,2,NORTH";
			int ExpectX = 1;
			int ExpectY = 2;
			string ExpectFacing = "NORTH";
			bool RetVal = CmdProcessor.ParseCommandLine(ActualCmdLine);
			vector<string> Parameters = CmdProcessor.GetParameters();
			Assert::AreEqual(ExpectX, stoi(Parameters[0]));
			Assert::AreEqual(ExpectY, stoi(Parameters[1]));
			Assert::AreEqual(ExpectFacing, Parameters[2]);
		}

		TEST_METHOD(GetParameters_Invalid)
		{
			string ActualCmdLine = "PLACE 1,2,NORTHX";
			int ExpectX = 1;
			int ExpectY = 2;
			string ExpectFacing = "NORTH";
			bool RetVal = CmdProcessor.ParseCommandLine(ActualCmdLine);
			vector<string> Parameters = CmdProcessor.GetParameters();
			Assert::AreEqual(ExpectX, stoi(Parameters[0]));
			Assert::AreEqual(ExpectY, stoi(Parameters[1]));
			Assert::AreNotEqual(ExpectFacing, Parameters[2]);
		}

	};

}
