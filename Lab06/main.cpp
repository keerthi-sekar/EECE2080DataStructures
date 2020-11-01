#include "BST.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    BinarySearchTree BSTObject;
    BinarySearchTree BSTObject2;
    BinarySearchTree BSTObject3;

    BinarySearchTree BSTObject11;
    BinarySearchTree BSTObject22;
    BinarySearchTree BSTObject33;

    vector<string> ascending1;
    vector<string> ascending2;
    vector<string> ascending3;

    vector<string> descending;
    vector<string> descending2;
    vector<string> descending3;

    BSTObject.Insert("Star Wars");
    BSTObject.Insert("Star Trek");
    BSTObject.Insert("Space Balls");
    BSTObject.Insert("Galaxy Quest");
    
    BSTObject.GetTreeNodes(BSTObject.GetRoot());
    ascending1 = BSTObject.GetAllAscending();
    
    for(int i=0; i < ascending1.size(); i++)
    {
        cout << ascending1[i] << endl;
    }

    cout << endl;

    BSTObject2.Insert("Cars");
    BSTObject2.Insert("Monsters Inc");
    BSTObject2.Insert("The Incredibles");
    BSTObject2.Insert("WallE");
    
    BSTObject2.GetTreeNodes(BSTObject2.GetRoot());
    ascending2 = BSTObject2.GetAllAscending();
    
    for(int i=0; i < ascending2.size(); i++)
    {
        cout << ascending2[i] << endl;
    }

    cout << endl;

    BSTObject3.Insert("Halloween");
    BSTObject3.Insert("A Nightmare On Elm Street");
    BSTObject3.Insert("Hocus Pocus");
    BSTObject3.Insert("Beetlejuice");
    
    BSTObject3.GetTreeNodes(BSTObject3.GetRoot());
    ascending3 = BSTObject3.GetAllAscending();
    
    for(int i=0; i < ascending3.size(); i++)
    {
        cout << ascending3[i] << endl;
    }

    cout << endl;

    BSTObject11.Insert("Star Wars");
    BSTObject11.Insert("Star Trek");
    BSTObject11.Insert("Space Balls");
    BSTObject11.Insert("Galaxy Quest");

    BSTObject11.GetTreeNodes(BSTObject11.GetRoot());
    descending = BSTObject11.GetAllDescending();

    for(int i = 0; i < descending.size(); i++)
    {
        cout << descending[i] << endl;
    }

    cout << endl;

    BSTObject22.Insert("Halloween");
    BSTObject22.Insert("A Nightmare On Elm Street");
    BSTObject22.Insert("Hocus Pocus");
    BSTObject22.Insert("Beetlejuice");

    BSTObject22.GetTreeNodes(BSTObject22.GetRoot());
    descending2 = BSTObject22.GetAllDescending();

    for(int i = 0; i < descending2.size(); i++)
    {
        cout << descending2[i] << endl;
    }

    cout << endl;

    BSTObject33.Insert("Cars");
    BSTObject33.Insert("Monsters Inc");
    BSTObject33.Insert("The Incredibles");
    BSTObject33.Insert("Wall E");

    BSTObject33.GetTreeNodes(BSTObject33.GetRoot());
    descending3 = BSTObject33.GetAllDescending();

    for(int i = 0; i < descending3.size(); i++)
    {
        cout << descending3[i] << endl;
    }


    return 0;
}
