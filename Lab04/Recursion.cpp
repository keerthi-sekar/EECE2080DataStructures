#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1
string Palidrome::GetWord() const { return word; }

string Palidrome::FormatLetters()
{
	string newWord = "";

	newWord = boost::algorithm::to_lower_copy(word);

	return newWord;
}

bool Palidrome::CheckPalidromeRecursion(int startIndex, int endIndex)
{
	string formatWord = FormatLetters();

	//Assuming empty string is not a palidrome
	if (formatWord.length() == 0)
	{
		return false;
	}

	if (startIndex >= endIndex)
	{
		return true;
	}
	if (formatWord[startIndex] != formatWord[endIndex])
	{
		return false;
	}

	return CheckPalidromeRecursion(++startIndex, --endIndex);
}

bool Palidrome::CheckPalidromeStack()
{
	//referenced stackoverflow for logic help
	//Source: https://stackoverflow.com/questions/29500782/stack-and-queue-palindrome-program

	string formatWord = FormatLetters();
	int cutLength = formatWord.length() / 2;
	bool isPalidrome = false;

	if (formatWord.length() > 0)
	{
		for (int i = cutLength - 1; i >= 0; i--)
		{
			wordCheck.push(formatWord[i]);
		}

		for (int i = 1; i <= cutLength && !wordCheck.empty(); ++i)
		{
			if (wordCheck.top() == formatWord[formatWord.length() - i])
			{
				isPalidrome = true;
			}
			else
			{
				isPalidrome = false;
			}
			wordCheck.pop();
		}
	}
	else
	{
		isPalidrome = false;
	}

	return isPalidrome;
}

int FactorialByRecursion::CalculateFactorial(int num)
{

	if (num <= 1)
	{
		return 1;
	}

	else
	{
		return num * CalculateFactorial(num - 1);
	}
}

int FactorialByStack::CalculateFactorial(int num)
{

	int answer = 1;

	if (num <= 1)
	{
		return 1;
	}

	while (num > 1)
	{
		s.push(num);
		num--;
	}
	while (!s.empty())
	{
		answer = answer * s.top();
		s.pop();
	}
	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col)
{

	if (col >= 8)
	{
		string answer = "";
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				int temp = chessBoard.m_board[i][j];
				stringstream ss;
				ss << temp;
				string str = ss.str();
				answer = answer + str;
			}
			answer = answer + "\n";
		}
		cout << answer << endl;
		return true;
	}

	for (int i = 0; i < 8; i++)
	{
		if (CheckSafeQueens(chessBoard, i, col))
		{

			if (i != 0 && chessBoard.col_stack.back() == 8)
			{
				return true;
			}
			else
			{
				chessBoard.col_stack.push_back(col);
				chessBoard.m_board[i][col] = 1;
				col++;
			}
		}

		else if (!(CheckSafeQueens(chessBoard, i, col)) && (chessBoard.m_board[i][col + 1] != 1))
		{
			chessBoard.col_stack.push_back(col + 1);
			chessBoard.m_board[i][col + 1] = 1;
		}

		else if (!(CheckSafeQueens(chessBoard, i, col + 1)))
		{
			chessBoard.col_stack.pop_back();
			chessBoard.m_board[i][col] = 0;
			col--;
			i--;
		}
	}

	return false;
}

bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		if (chessBoard.m_board[row][i] != 0 && i != chessBoard.col_stack.back())
		{
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (chessBoard.m_board[i][j] != 0)
		{
			return false;
		}
	}

	for (int i = row, j = col; j >= 0 && i < 8; i++, j--)
	{
		if (chessBoard.m_board[i][j] != 0)
		{
			return false;
		}
	}

	return true;
}

string ChessBoard::ToString()
{

	string answer = "";
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{
	// TODO:
	// Note this is starter code that is not safe.
	// As Simple exceptin method will throw an exception
	// which will not be handled, and we will also leak resources.
	// Make this method safer and handle all possible exceptions
	// And also return a string of the exception recieved
	// The tests will tell you what to string to return.

	std::string retVal;
	MyFakeClass *resourceThatNeedsToBeCleanedup = nullptr;
	resourceThatNeedsToBeCleanedup = new MyFakeClass();

	try
	{
		SimpleExceptionMethod(i);
	}
	catch (MyException1 &e)
	{
		retVal = "I got Exception 1";
		return retVal;
	}
	catch (MyException2 &e)
	{
		retVal = "I got Exception 2";
		return retVal;
	}
	catch (MyException3 &e)
	{
		retVal = "I got Exception 3";
		return retVal;
	}

	retVal = "I did not get an Exception";

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();
	}
	else if (i == 3)
	{
		// TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;
}

char const *MyBaseException::what() const throw()
{
	return "MyBaseException";
}
char const *MyException1::what() const throw()
{
	return "MyException1";
}
char const *MyException2::what() const throw()
{
	return "MyException2";
}
char const *MyException3::what() const throw()
{
	return "MyException3";
}