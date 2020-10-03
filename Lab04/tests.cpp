// tests.cpp
#include "Recursion.h"
#include <gtest/gtest.h>


	TEST(Palidrome, RecursionCheck1)
	{
		Palidrome coolWord("radar");
		int wordSize = coolWord.GetWord().length();
		ASSERT_TRUE(coolWord.CheckPalidromeRecursion(0, wordSize - 1));
	}

	TEST(Palidrome, RecursionCheck2)
	{
		Palidrome coolWord("keerthi");
		int wordSize = coolWord.GetWord().length();
		ASSERT_FALSE(coolWord.CheckPalidromeRecursion(0, wordSize - 1));
	}

	TEST(Palidrome, RecursionCheck3)
	{
		Palidrome coolWord("Radar");
		int wordSize = coolWord.GetWord().length();
		ASSERT_TRUE(coolWord.CheckPalidromeRecursion(0, wordSize - 1));
	}

	TEST(Palidrome, RecursionEmptyCheck)
	{
		Palidrome coolWord("");
		int wordSize = coolWord.GetWord().length();
		ASSERT_FALSE(coolWord.CheckPalidromeRecursion(0, wordSize - 1));
	}

	/*TEST(Factorial, Recursion1)
	{
		FactorialByRecursion calculator;

		int val = calculator.CalculateFactorial(3);

		ASSERT_EQ(6, val);
	}

	TEST(Factorial, Recursion2)
	{
		FactorialByRecursion calculator;

		int val = calculator.CalculateFactorial(10);

		ASSERT_EQ(3628800, val);

	}
	
	TEST(Factorial, Stack1)
	{
		FactorialByStack calculator;

		int val = calculator.CalculateFactorial(3);

		ASSERT_EQ(6, val);

	}

	TEST(Factorial, Stack2)
	{
		FactorialByStack calculator;

		int val = calculator.CalculateFactorial(10);

		ASSERT_EQ(3628800, val);


	}
	
	TEST(Exception,UserDefinedExceptionTest1)
	{

		std::string status = CallSimpleExceptionMethod(1);
		ASSERT_EQ(std::string("I got Exception 1"), status);
		
	}

	TEST(Exception,UserDefinedExceptionTest2)
	{


			std::string status = CallSimpleExceptionMethod(2);
			ASSERT_EQ(std::string("I got Exception 2"), status);

	}

	TEST(Exception,UserDefinedExceptionTest3)
	{

		std::string status = CallSimpleExceptionMethod(3);
		ASSERT_EQ(std::string("I got Exception 3"), status);

	}

	TEST(Exception,UserDefinedExceptionTest4)
	{

		std::string status = CallSimpleExceptionMethod(4);
		ASSERT_EQ(std::string("I did not get an Exception"), status);

	}*/

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
