#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Task2(C++)/LinearEquation.h"
#include"../Task2(C++)/LinearEquation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearEquationTestC
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CorrectIndex1)
		{
			std::vector<double>_a{ 1,3,5,7.9,9 };
			LinearEquation a(_a);
			Assert::AreEqual(3.0, a[1]);
		}

		TEST_METHOD(CorrectIndex2)
		{
			std::string s = "1,3,5,7.9,9";
			LinearEquation a(s);
			Assert::AreEqual(7.9, a[3]);
		}

		TEST_METHOD(CorrectIndex3)
		{
			LinearEquation a(11);
			Assert::AreEqual(0.0, a[5]);
		}

		TEST_METHOD(CorrectMult1)
		{
			std::string s = "1,3.5,5,7.9,9";
			LinearEquation a(s);
			a = a * 3.0;
			Assert::AreEqual(10.5, a[1]);
		}

		TEST_METHOD(CorrectMult2)
		{
			std::string s = "1,3.5,5,7.9,9";
			LinearEquation a(s);
			a = 4.0 * a;
			Assert::AreEqual(20.0, a[2]);
		}

		TEST_METHOD(CorrectSum)
		{
			std::string s1 = "2,4,6,8,10,12.5,14.9";
			std::string s2 = "3,5,7,9,11,-13.7,15.9";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("5,9,13,17,21,-1.2,30.8");
			Assert::AreEqual(true, res == (a + b));
		}

		TEST_METHOD(CorrectSub)
		{
			std::string s1 = "1,3,5,7.9,9";
			std::string s2 = "2.2,4,6,8,10";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("-1.2,-1,-1,-0.1,-1");
			Assert::AreEqual(true, res == (a - b));
		}

		TEST_METHOD(SameInit)
		{
			LinearEquation a(10);
			a.same_initialization(10.543);
			Assert::AreEqual(10.543, a[5]);
		}

		TEST_METHOD(CorrectUnaryMinus)
		{
			LinearEquation a("1,3,5,7.9,9");
			a = -a;
			Assert::AreEqual(-1.0, a[0]);
		}

		TEST_METHOD(CheckContradictoryEquation)
		{
			LinearEquation a("0,0,0,15.2");
			bool check = (a) ? true : false;
			Assert::AreEqual(false, check);
		}


		TEST_METHOD(CheckSolvableEquation)
		{
			LinearEquation a("0,2,0,15.2");
			bool check = (a) ? true : false;
			Assert::AreEqual(true, check);
		}

		TEST_METHOD(CopyToList)
		{
			LinearEquation a("0,2,0,-4");
			std::list<double> tmp = a;
			Assert::AreEqual(0.0, tmp.front());
		}

		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto func = []() {

				LinearEquation a("1,3,5,7.9,9");
				double tmp = a[-1];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}

		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto func = []() 
			{
				LinearEquation a("1,3,5,7.9,9");
				double tmp = a[15];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}