// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
			for (int i = 0; i < m_stack3.size(); i++)
			{
				if (m_stack3[i] > m_stack3[i + 1])
				{
					m_GameEnded = false;
				}
				else
				{
					m_GameEnded = true;
				}
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
		cout << "Pole 1: ";
		for (int i = 0; i < m_stack1.size(); i++)
		{
			cout << m_stack1[i] << " ";
		}
		cout << endl;

		cout << "Pole 2: ";
		for (int i = 0; i < m_stack2.size(); i++)
		{
			cout << m_stack2[i] << " ";
		}
		cout << endl;

		cout << "Pole 3: ";
		for (int i = 0; i < m_stack3.size(); i++)
		{
			cout << m_stack3[i] << " ";
		}
		cout << endl;
	}

	bool makeMove(int disk, int colFrom, int colTo)
	{
		if (disk >= 1 && (colFrom != colTo))
		{
			if (colFrom == 1 && m_stack1.back() == disk)
			{
				if(m_stack2.empty() && colTo == 2)
				{
					m_stack2.push_back(m_stack1.back());
					m_stack1.pop_back();
				}
				else if (colTo == 2 && m_stack2.back() > disk)
				{
					m_stack2.push_back(m_stack1.back());
					m_stack1.pop_back();
				}
				else if(m_stack3.empty() && colTo == 3)
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
					cout << "Larger disks cannot be placed on smaller disks. 1 is the smallest disk and 4 is the largest." << endl;
					return false;
				}
			}
			else if (colFrom == 2 && m_stack2.back() == disk)
			{
				if(m_stack1.empty() && colTo == 1)
				{
					m_stack1.push_back(m_stack2.back());
					m_stack2.pop_back();
				}
				else if (colTo == 1 && m_stack1.back() > disk)
				{
					m_stack1.push_back(m_stack2.back());
					m_stack2.pop_back();
				}
				else if(m_stack3.empty() && colTo == 3)
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
					cout << "Larger disks cannot be placed on smaller disks. 1 is the smallest disk and 4 is the largest." << endl;
					return false;
				}
			}
			else if (colFrom == 3 && m_stack3.back() == disk)
			{
				if(m_stack1.empty() && colTo == 1)
				{
					m_stack1.push_back(m_stack3.back());
					m_stack3.pop_back();
				}
				else if (colTo == 1 && m_stack1.back() > disk)
				{
					m_stack1.push_back(m_stack3.back());
					m_stack3.pop_back();
				}
				else if(m_stack2.empty() && colTo == 2)
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
					cout << "Larger disks cannot be placed on smaller disks. 1 is the smallest disk and 4 is the largest." << endl;
					return false;
				}
			}
			else
			{
				cout << "Invalid column to move disk from or move disk to was chosen OR";
				cout << "column to move from did not contain the selected disk." << endl;
				cout << "Please check the state of the game." << endl;
				return false;
			}
			IsGameEnded();
		}
		else
		{
			cout << "Invalid move. Select disks from 1 to 4 and columns from 1 to 3." << endl;
			return false;
		}
	}

private:
	bool m_GameEnded;
	ArrayBasedQueue m_moves;
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
	cout << "To Begin: Type 1 to interactively play or Type 0 to insert a file for your moves." << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;
	string manualInput = "0";

	cout << "Would you like to play manually or input a file?" << endl;
	getline(cin, manualInput);

	if (manualInput == "0")
	{
		ifstream file;
		file.open("moves.txt", ios::in);
		if(file.is_open())
		{
			cout << "opened file" << endl;
		}
		string inputLine;
		while (getline(file, inputLine) || game.IsGameEnded() || !receivedEndToken)
		{
			cout << inputLine << endl;
			game.PrintTowers();

			if (inputLine == "-1")
			{
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
					cout << "(1) Invalid input recieved = " + inputLine << endl;
				}
				else
				{
					std::string disk = output[0];
					std::string from = output[1];
					std::string to = output[2];

					if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
					{
						receivedEndToken = true;
						cout << "(2) Invalid input recieved = " + inputLine << endl;
					}

					int diskId = atoi(disk.c_str());
					int fromId = atoi(from.c_str());
					int toId = atoi(to.c_str());
					//if any number is zero we didn't have a integer
					if (diskId == 0 || fromId == 0 || toId == 0)
					{
						receivedEndToken = true;
						cout << "(3) Invalid input recieved = " + inputLine << endl;
					}
					cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
					game.makeMove(diskId, fromId, toId);
				}
			}
		}
	}
	else if (manualInput == "1")
	{
		while (!receivedEndToken || game.IsGameEnded())
		{
			string inputLine;
			cout << "Enter Move " << endl;

			if(game.IsGameEnded())
			{
				inputLine == "-1";
			}
			else
			{
				getline(cin, inputLine);
			}

			game.PrintTowers();

			if (inputLine == "-1")
			{
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
				}
			}
		}
	}

	return 0;
}
