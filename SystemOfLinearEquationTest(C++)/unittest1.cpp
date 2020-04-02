#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Task2(C++)/LinearEquation.h"
#include"../Task2(C++)/LinearEquation.cpp"
#include"../Task2(C++)/SystemOfLinearEquation.h"
#include"../Task2(C++)/SystemOfLinearEquation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SystemOfLinearEquationTestC
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CorrectIndex)
		{
			SystemOfLinearEquation s(3);
			s.add(LinearEquation("2,-4,9,28"));
			s.add(LinearEquation("7,3,-6,-1"));
			s.add(LinearEquation("7,9,-9,5"));
			Assert::AreEqual(9.0, s[0][2]);
		}

		TEST_METHOD(CorrectAnswer)
		{
			int n = 3;
			SystemOfLinearEquation s(n);
			LinearEquation a1("3.0, 2.0,-4.0, 3.0");
			LinearEquation a2("2.0, 3.0, 3.0, 15.0");
			LinearEquation a3("5.0, -3, 1.0, 14.0");
			s.add(a1);
			s.add(a2);
			s.add(a3);
			s.steppingUp();
			std::vector<double> solve1 = s.solveSystem();
			bool check = true;
			std::vector<double>solve2{ 3,1,2 };
			for (int i = 0; i < solve1.size(); i++)
				if (abs(solve1[i] - solve2[i]) > 1e-9) check = false;
			Assert::AreEqual(true, check);
		}

		TEST_METHOD(CheckNoSolutions)
		{
			auto func = []()
			{
				int n = 3;
				SystemOfLinearEquation s(n);
				LinearEquation a1("2.0, 6.0,-5.0, 5.0");
				LinearEquation a2("4.0, 12.0, -10.0, 20.0");
				LinearEquation a3("4.0, 12.0, -10.0, 20.0");
				s.add(a1);
				s.add(a2);
				s.add(a3);
				s.steppingUp();
				std::vector<double> solve1 = s.solveSystem();
			};
			Assert::ExpectException< std::invalid_argument>(func);
		}

		TEST_METHOD(InfinitelyManySolutions)
		{
			auto func = []()
			{
				int n = 3;
				SystemOfLinearEquation s(n);
				LinearEquation a1("2.0, 6.0,-5.0, 10.0");
				LinearEquation a2("4.0, 12.0, -10.0, 20.0");
				LinearEquation a3("4.0, 12.0, -10.0, 20.0");
				s.add(a1);
				s.add(a2);
				s.add(a3);
				s.steppingUp();
				std::vector<double> solve1 = s.solveSystem();
			};
			Assert::ExpectException< std::invalid_argument>(func);
		}

		TEST_METHOD(FailWithIndexing1)
		{
			auto func = []() 
			{
				SystemOfLinearEquation s(3);
				s.add(LinearEquation("2,-4,9,28"));
				s.add(LinearEquation("7,3,-6,-1"));
				s.add(LinearEquation("7,9,-9,5"));
				LinearEquation tmp = s[-1]; 
			};
			Assert::ExpectException<std::out_of_range>(func);
		}

		TEST_METHOD(FailWithIndexing2)
		{
			auto func = []() 
			{
				SystemOfLinearEquation s(3);
				s.add(LinearEquation("2,-4,9,28"));
				s.add(LinearEquation("7,3,-6,-1"));
				s.add(LinearEquation("7,9,-9,5"));
				LinearEquation tmp = s[15]; 
			};
			Assert::ExpectException<std::out_of_range>(func);
		}

		TEST_METHOD(FailWithAddEquation)
		{
			auto func = []()
			{
				SystemOfLinearEquation s(3);
				s.add(LinearEquation("1,2,3,3,4,6,7,8,5"));
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}		
	};
}