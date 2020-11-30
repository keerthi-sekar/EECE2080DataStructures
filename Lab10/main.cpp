#include "Hashes.h"
#include <iostream>

using namespace std;

void Menu()
{
	cout << "Press 1 to return the next index for the key you are looking for. (Hash())" << endl;
	cout << "Press 2 to add an item to the list. (AddItem())" << endl;
	cout << "Press 3 to find the value of a specific key. (GetItem())" << endl;
	cout << "Press 4 to get the number of items in the table. (GetItemsInDicitionary())" << endl;
	cout << "Press 5 to quit." << endl;
}

int main()
{
	Hash<int, int> *h = new Hash<int, int>;
	int move = 0;

	cout << "Yo yo. Test out the Hash class: " << endl;

	while(move != 5)
	{
		Menu();
		cin >> move;
		switch (move)
		{
			case 1:
				int keyValue;
				cout << "Enter key: ";
				cin >> keyValue;
				cout << "Index: " << h->GetItem(keyValue);
				break;
			case 2:
				int addValue, addKey;
				cout << "Enter key and value: " << endl;
				cout << "Key: ";
				cin >> addKey;
				cout << "Value: ";
				cin >> addValue;
				h->AddItem(addKey, addValue);
				break;
			case 3:
				int findKey;
				cout << "Enter Key for value to find: ";
				cin >> findKey;
				cout << "Value Found: " << h->GetItem(findKey);
				break;
			case 4:
				int tableSize;
				cout << "Total items in table: " << h->getItems() << endl;
				h->PrintMap();
				break;
			case 5:
				cout << "GoodBye ╮ (. ❛ ᴗ ❛.) ╭" << endl;
				break;
			default:
				cout << "You pressed the wrong number type a move again. Current map: " << endl;
				h->PrintMap();
				break;
		}

	}

    /*h->AddItem(1,1); 
    h->AddItem(2,2); 
    h->AddItem(2,3); 
    cout << h->getItems() << endl;
	h->PrintMap();*/
	
	return 0;
}
