#include "BST.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    BinarySearchTree BSTObject;
    Node *node1;
    vector<string> descending;
    int size;
    BSTObject.Insert("Star Wars");
    BSTObject.Insert("Star Trek");
    BSTObject.Insert("Space Balls");
    
    //node1 = BSTObject.Find("Star Trek");
    //ascending = BSTObject.GetAllAscending(node1);
    
    /*for(int i=0; i < ascending.size(); i++)
    {
        cout << ascending[i] << endl;
    }*/
    /*cout << BSTObject.GetRoot()->m_value << endl;
    size = BSTObject.Size(BSTObject.GetRoot());
    cout << "BST: " << size << endl;*/

    /*BSTObject.GetTreeNodes(BSTObject.GetRoot());

    descending = BSTObject.GetAllDescending();

    for(int i = 0; i < descending.size(); i++)
    {
        cout << descending[i] << " ";
    }*/

    BSTObject.EmptyTree(BSTObject.GetRoot());

    return 0;
}
