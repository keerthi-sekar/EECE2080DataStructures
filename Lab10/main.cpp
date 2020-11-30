#include "Hashes.h"
#include <iostream>

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
	Hash<int, int> *h = new Hash<int, int>; 
    h->AddItem(1,1); 
    h->AddItem(2,2); 
    h->AddItem(2,3); 
    cout << h->getItems() << endl;
	h->PrintMap();
	
	return 0;
}
