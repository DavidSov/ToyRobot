#include "pch.h"
#include "CppUnitTest.h"
#include "..\ToyRobotLib\TableTop.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ToyRobot;

namespace ToyRobotUnitTest
{

	TEST_CLASS(TableTopClass)
	{
	public:
		int ExpectX = 5;
		int ExpectY = 5;

		TEST_METHOD(GetXUnits_Valid)
		{
			TableTop TabTop(ExpectX, ExpectY);
			int TestX = TabTop.GetXUnits();
			Assert::AreEqual(ExpectX, TestX);
		}

		TEST_METHOD(GetYUnits_Valid)
		{
			TableTop TabTop(ExpectX, ExpectY);
			int TestY = TabTop.GetYUnits();
			Assert::AreEqual(ExpectY, TestY);
		}

		TEST_METHOD(InsideArea_Inside)
		{
			TableTop TabTop(ExpectX, ExpectY);
			bool TestVal = TabTop.InsideArea(1, 1);
			Assert::AreEqual(TestVal, true);
		}

		TEST_METHOD(InsideArea_OutsideBottomLeft)
		{
			TableTop TabTop(ExpectX, ExpectY);
			bool TestVal = TabTop.InsideArea(-1, -1);
			Assert::AreEqual(TestVal, false);
		}

		TEST_METHOD(InsideArea_OutsideBottomRight)
		{
			TableTop TabTop(ExpectX, ExpectY);
			bool TestVal = TabTop.InsideArea(6, 0);
			Assert::AreEqual(TestVal, false);
		}

		TEST_METHOD(InsideArea_OutsideTopRight)
		{
			TableTop TabTop(ExpectX, ExpectY);
			bool TestVal = TabTop.InsideArea(6, 6);
			Assert::AreEqual(TestVal, false);
		}

		TEST_METHOD(InsideArea_OutsideTopLeft)
		{
			TableTop TabTop(ExpectX, ExpectY);
			bool TestVal = TabTop.InsideArea(0, 6);
			Assert::AreEqual(TestVal, false);
		}

	};

}
