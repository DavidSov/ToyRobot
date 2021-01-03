#include "pch.h"
#include "CppUnitTest.h"
#include "..\ToyRobotLib\Position.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ToyRobot;

namespace ToyRobotUnitTest
{

	TEST_CLASS(PositionClass)
	{
	public:
		int ExpectX = 2;
		int ExpectY = 1;
		string ExpectF = "NORTH";
		Position ExpectPos;

		TEST_METHOD(AssignOperator_Valid)
		{
			int TestX;
			int TestY;
			string TestF;
			ExpectPos.SetPosition(ExpectX, ExpectY, ExpectF);
			Position TestPos = ExpectPos;
			TestPos.GetPositon(TestX, TestY, TestF);
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectF, TestF);
		}

		TEST_METHOD(SetGetPositon_Valid)
		{
			int TestX;
			int TestY;
			string TestF;
			ExpectPos.SetPosition(ExpectX, ExpectY, ExpectF);
			ExpectPos.GetPositon(TestX, TestY, TestF);
			Assert::AreEqual(ExpectX, TestX);
			Assert::AreEqual(ExpectY, TestY);
			Assert::AreEqual(ExpectF, TestF);
		}

		TEST_METHOD(SetGetPositionX_Valid)
		{
			int TestX;
			ExpectPos.SetPositionX(ExpectX);
			TestX = ExpectPos.GetPositionX();
			Assert::AreEqual(ExpectX, TestX);
		}

		TEST_METHOD(SetGetPositionY_Valid)
		{
			int TestY;
			ExpectPos.SetPositionY(ExpectY);
			TestY = ExpectPos.GetPositionY();
			Assert::AreEqual(ExpectY, TestY);
		}

		TEST_METHOD(SetGetPositionFacing_Valid)
		{
			string TestF;
			ExpectPos.SetPositionFacing(ExpectF);
			TestF = ExpectPos.GetPositionFacing();
			Assert::AreEqual(ExpectF, TestF);
		}

	};

}
