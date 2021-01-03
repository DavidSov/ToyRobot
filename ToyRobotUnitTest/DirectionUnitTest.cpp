#include "pch.h"
#include "CppUnitTest.h"
#include "..\ToyRobotLib\Direction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ToyRobot;

namespace ToyRobotUnitTest
{

	TEST_CLASS(DirectionClass)
	{
	public:
		Direction Direct;

		TEST_METHOD(ValidDirection_Valid)
		{
			bool RetVal = Direct.ValidDirection("NORTH");
			Assert::AreEqual(RetVal, true);
		}

		TEST_METHOD(ValidDirection_Invalid)
		{
			bool RetVal = Direct.ValidDirection("BADNORTH");
			Assert::AreEqual(RetVal, false);
		}

		TEST_METHOD(Rotate90DegreeClockwise_Valid)
		{
			string ExpectDirect = "NORTH";
			string TestDirect = Direct.Rotate90DegreeClockwise("WEST");
			Assert::AreEqual(TestDirect, ExpectDirect);
		}

		TEST_METHOD(Rotate90DegreeClockwise_Invalid)
		{
			string ExpectDirect = "";
			string TestDirect = Direct.Rotate90DegreeClockwise("BADNORTH");
			Assert::AreEqual(TestDirect, ExpectDirect);
		}

		TEST_METHOD(Rotate90DegreeAntiClockwise_Valid)
		{
			string ExpectDirect = "WEST";
			string TestDirect = Direct.Rotate90DegreeAntiClockwise("NORTH");
			Assert::AreEqual(TestDirect, ExpectDirect);
		}

		TEST_METHOD(Rotate90DegreeAntiClockwise_Invalid)
		{
			string ExpectDirect = "";
			string TestDirect = Direct.Rotate90DegreeAntiClockwise("BADNORTH");
			Assert::AreEqual(TestDirect, ExpectDirect);
		}

	};

}
