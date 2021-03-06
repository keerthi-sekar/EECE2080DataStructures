// TowerHannoiGame.cpp : Defines the entry point for the console application.
// main.cpp: Gives the user 2 choices via manual or file input. This script runs the game with in mind various user errors that could go wrong. 
//           The file merely identifies the error and exits the program so the user can fix there mistakes. Cute emojis in the terminal identify that the user has won.
// StackQueue.h: Has the basic stack and queue functinality to pass the test cases, as well as, make the main.cpp functional in the "backend".

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		m_stack1.push_back(4);
		m_stack1.push_back(3);
		m_stack1.push_back(2);
		m_stack1.push_back(1);
	}

	bool IsGameEnded()
	{
		if (m_stack3.size() == 4)
		{
			if (m_stack3.at(0) == 4 && m_stack3.at(1) == 3 && m_stack3.at(2) == 2 && m_stack3.at(3) == 1)
			{
				m_GameEnded = true;
			}
			else
			{
				m_GameEnded = false;
			}
		}
		else
		{
			m_GameEnded = false;
		}
		return m_GameEnded;
	}

	void PrintTowers()
	{
		cout << "Column 1: ";
		for (int i = 0; i < m_stack1.size(); i++)
		{
			cout << m_stack1[i] << " ";
		}
		cout << endl;

		cout << "Column 2: ";
		for (int i = 0; i < m_stack2.size(); i++)
		{
			cout << m_stack2[i] << " ";
		}
		cout << endl;

		cout << "Column 3: ";
		for (int i = 0; i < m_stack3.size(); i++)
		{
			cout << m_stack3[i] << " ";
		}
		cout << endl;
	}

	bool makeMove(int disk, int colFrom, int colTo)
	{
		checkValidMove = true;
		if (disk >= 1 && (colFrom != colTo))
		{
			if (colFrom == 1 && m_stack1.back() == disk)
			{
				if (m_stack2.empty() && colTo == 2)
				{
					m_stack2.push_back(m_stack1.back());
					m_stack1.pop_back();
				}
				else if (colTo == 2 && m_stack2.back() > disk)
				{
					m_stack2.push_back(m_stack1.back());
					m_stack1.pop_back();
				}
				else if (m_stack3.empty() && colTo == 3)
				{
					m_stack3.push_back(m_stack1.back());
					m_stack1.pop_back();
				}
				else if (colTo == 3 && m_stack3.back() > disk)
				{
					m_stack3.push_back(m_stack1.back());
					m_stack1.pop_back();
				}
				else
				{
					checkValidMove = false;
					cout << "Larger disks cannot be placed on smaller disks. 1 is the smallest disk and 4 is the largest." << endl;
					return false;
				}
			}
			else if (colFrom == 2 && m_stack2.back() == disk)
			{
				if (m_stack1.empty() && colTo == 1)
				{
					m_stack1.push_back(m_stack2.back());
					m_stack2.pop_back();
				}
				else if (colTo == 1 && m_stack1.back() > disk)
				{
					m_stack1.push_back(m_stack2.back());
					m_stack2.pop_back();
				}
				else if (m_stack3.empty() && colTo == 3)
				{
					m_stack3.push_back(m_stack2.back());
					m_stack2.pop_back();
				}
				else if (colTo == 3 && m_stack3.back() > disk)
				{
					m_stack3.push_back(m_stack2.back());
					m_stack2.pop_back();
				}
				else
				{
					checkValidMove = false;
					cout << "Larger disks cannot be placed on smaller disks. 1 is the smallest disk and 4 is the largest." << endl;
					return false;
				}
			}
			else if (colFrom == 3 && m_stack3.back() == disk)
			{
				if (m_stack1.empty() && colTo == 1)
				{
					m_stack1.push_back(m_stack3.back());
					m_stack3.pop_back();
				}
				if (colTo == 1 && m_stack1.back() > disk)
				{
					m_stack1.push_back(m_stack3.back());
					m_stack3.pop_back();
				}
				else if (m_stack2.empty() && colTo == 2)
				{
					m_stack2.push_back(m_stack3.back());
					m_stack3.pop_back();
				}
				else if (colTo == 2 && m_stack2.back() > disk)
				{
					m_stack2.push_back(m_stack3.back());
					m_stack3.pop_back();
				}
				else
				{
					checkValidMove = false;
					cout << "Larger disks cannot be placed on smaller disks. 1 is the smallest disk and 4 is the largest." << endl;
					return false;
				}
			}
			else
			{
				checkValidMove = false;
				cout << "Invalid column to move disk from or move disk to was chosen OR ";
				cout << "column to move from did not contain the selected disk." << endl;
				cout << "Please check the state of the game." << endl;
				return false;
			}
		}
		else
		{
			checkValidMove = false;
			cout << "Invalid move. Select disks from 1 to 4 and columns from 1 to 3." << endl;
			return false;
		}
		TrackMoves(disk, colFrom, colTo);
	}

	void TrackMoves(int disk, int colFrom, int colTo)
	{
		string moves;
		if(checkValidMove)
		{
			moves = "VALID: " + to_string(disk) + "," + to_string(colFrom) + "," + to_string(colTo);
		}
		else
		{
			moves = "INVALID: " + to_string(disk) + "," + to_string(colFrom) + "," + to_string(colTo);
		}
		m_moves.push_back(moves);
	}

	void PrintMoves()
	{
		ofstream outputFile;
		outputFile.open("movesTranscript.txt");
		for(int i=0; i < m_moves.size(); i++)
		{
			outputFile << m_moves[i] << endl;
		}
		cout << "Printing to File is complete." << endl;
	}

private:
	bool m_GameEnded;
	bool checkValidMove;
	vector<string> m_moves;
	vector<int> m_stack1;
	vector<int> m_stack2;
	vector<int> m_stack3;
};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;
	string gameType = "0";
	ifstream movesFile;
	string inputLine;

	movesFile.open("moves.txt");

	if(movesFile.fail())
	{
		cout << "Error: Couldn't open file. Please make sure it's in the Lab02 build folder!" << endl;
		cout << "ENTERING MANUAL MODE." << endl;
		gameType = "1"; //failsafe just in case file fails to open
	}
	else
	{
		cout << "Reading File... We are assuming you entered the moves right, double check the file if it doesn't work!" << endl;
		gameType = "0";
	}

	if (gameType == "0")
	{		
		while ((getline(movesFile, inputLine, '\n') || !game.IsGameEnded()) && !receivedEndToken)
		{
			game.PrintTowers();
			if (inputLine == "-1")
			{
				game.PrintMoves();
				receivedEndToken = true;
			}
			else
			{
				std::vector<std::string> output;
				std::string::size_type prev_pos = 0, pos = 0;
				// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
				// tokenizing a string
				while ((pos = inputLine.find(",", pos)) != std::string::npos)
				{
					std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
					output.push_back(substring);
					prev_pos = ++pos;
				}
				//Need to get last token
				output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

				if (output.size() != 3)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}
				else
				{
					std::string disk = output[0];
					std::string from = output[1];
					std::string to = output[2];

					if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
					{
						receivedEndToken = true;
						cout << "Invalid input recieved = " + inputLine << endl;
					}

					int diskId = atoi(disk.c_str());
					int fromId = atoi(from.c_str());
					int toId = atoi(to.c_str());
					//if any number is zero we didn't have a integer
					if (diskId == 0 || fromId == 0 || toId == 0)
					{
						receivedEndToken = true;
						cout << "Invalid input recieved = " + inputLine << endl;
					}
					
					cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
					game.makeMove(diskId, fromId, toId);
					if (game.IsGameEnded() == true)
					{
						game.PrintMoves();
						cout << "(ღ˘⌣˘ღ) ´͈ ᵕ `͈  Congrats! You Won!!! ´͈ ᵕ `͈  (ღ˘⌣˘ღ)" << endl;
						receivedEndToken = true;
					}
				}
			}
		}
	}
	else if (gameType == "1")
	{
		while (!receivedEndToken)
		{
			std::string inputLine;
			game.PrintTowers();
			cout << "Enter Move " << endl;
			getline(cin, inputLine);
			if (inputLine == "-1")
			{
				receivedEndToken = true;
			}
			else
			{
				//need to repeat code so it doesn't get into segmentation fault (when in function)
				std::vector<std::string> output;
				std::string::size_type prev_pos = 0, pos = 0;
				// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
				// tokenizing a string
				while ((pos = inputLine.find(",", pos)) != std::string::npos)
				{
					std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
					output.push_back(substring);
					prev_pos = ++pos;
				}
				//Need to get last token
				output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

				if (output.size() != 3)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}
				else
				{
					std::string disk = output[0];
					std::string from = output[1];
					std::string to = output[2];

					if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
					{
						receivedEndToken = true;
						cout << "Invalid input recieved = " + inputLine << endl;
					}

					int diskId = atoi(disk.c_str());
					int fromId = atoi(from.c_str());
					int toId = atoi(to.c_str());
					//if any number is zero we didn't have a integer
					if (diskId == 0 || fromId == 0 || toId == 0)
					{
						receivedEndToken = true;
						cout << "Invalid input recieved = " + inputLine << endl;
					}

					cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
					game.makeMove(diskId, fromId, toId);
					if (game.IsGameEnded() == true)
					{
						cout << "(ღ˘⌣˘ღ) ´͈ ᵕ `͈  Congrats! You Won!!! ´͈ ᵕ `͈  (ღ˘⌣˘ღ)" << endl;
						receivedEndToken = true;
					}
				}
			}
		}
	}
	return 0;
}
