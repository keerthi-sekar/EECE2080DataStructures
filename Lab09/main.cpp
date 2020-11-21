#include "Graphs.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void Menu()
{
	cout << "Press 1 to add an edge to graph." << endl;
	cout << "Press 2 remove an edge from graph." << endl;
	cout << "Press 3 Find an edge in the graph." << endl;
	cout << "Press 4 Find the out edges of a vertices." << endl;
	cout << "Press 5 Find the in edges of a vertices." << endl;
	cout << "Press 6 To Print out Adjacency Matrix." << endl;
	cout << "Press 7 to quit." << endl;
}

int main()
{
	bool fileOption = false;
	char decision;
	int move = 0;
	int n, m;

	cout << "Welcome! Set a size for your graph. N = rows, M = columns." << endl;
	cout << "N: " << endl;
	cin >> n;
	cout << "M: " << endl;
	cin >> m;

	Graphs graph(n, m);

	cout << "Do you have a file for the moves you would like to place? Y or N" << endl;
	cin >> decision;
	if(decision == 'Y' || decision == 'y')
	{
		fileOption = true;
	}
	else if(decision == 'N' || decision == 'n')
	{
		fileOption = false;
	}
	else
	{
		fileOption = false;
	}
	
	if(fileOption)
	{
		std::string line;
		std::ifstream infile("moves.txt");
		vector<vector<int>> temp;

		while (std::getline(infile, line))
		{
			vector<int> row;
			for (char &c : line)
			{
				if (c != ',')
				{
					int num = c - '0';
					row.push_back(num);
				}
			}

			temp.push_back(row);
		}

		for(int i = 0; i < temp.size(); i++)
		{
			for(int j = 0; j < temp[i].size(); j++)
			{
				graph.m_values[i][j] = temp[i][j];
			}
		}
	}

	cout << "Now that you have set the graph, the following controls are available to you: " << endl;

	while(move != 7)
	{
		Menu();
		cin >> move;
		switch(move)
		{
			int i, j;
			case 1: 
				cout << "input coordinate to add edge. i = row, j = column" << endl;
				cin >> i;
				cin >> j;
				graph.AddEdge(i, j);
				break;
			case 2:
				cout << "input coordinate to remove edge. i = row, j = column" << endl;
				cin >> i;
				cin >> j;
				graph.RemoveEdge(i, j);
				break;
			case 3:
				cout << "input coordinate to find edge. i = row, j = column" << endl;
				cin >> i;
				cin >> j;
				if(graph.HasEdge(i, j))
				{
					cout << "Found Edge" << endl;
				}
				else
				{
					cout << "Could not find edge." << endl;
				}
				break;
			case 4: {
				int x;
				cout << "input the row to find all out edges. i:" << endl;
				cin >> x;
				vector<int> outie;
				outie = graph.OutEdges(x);
				cout << "Location of OutEdges: ";
				for(int l = 0; l < outie.size(); l++)
				{
					cout << outie[l] << " ";
				}
				cout << endl;
				break;
			}
			case 5: {
				int y;
				cout << "input the column to find all in edges. j:" << endl;
				cin >> y;
				vector<int> innie;
				innie = graph.InEdges(y);
				cout << "Location of InEdges: ";
				for(int l = 0; l < innie.size(); l++)
				{
					cout << innie[l] << " ";
				}
				cout << endl;
				break;
			}
			case 6:
				graph.PrintOutAdjacencyMatrix();
				break;
			case 7:
				cout << "Okay. Quitting..." << endl;
				break;
			default:
				cout << "Command not found. Re-enter move." << endl;
				break;
		}
	}

	cout << "You have left the graphing capabilities. Goodbye ƪ(˘⌣˘)┐~" << endl;
	

	return 0;
}
