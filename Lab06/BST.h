#include <string>
#include <iostream>

using namespace std;
class Node
{
public:
	Node();
	Node(string val);
	virtual ~Node();

	string m_value;
	Node *left;
	Node *right;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(string value);
	~BinarySearchTree();
	void Insert(string value);
	Node* Find(string value);
	int Size(Node * currentNode);
	bool EmptyTree(Node * currentNode);
	//vector<string> GetAllAscending();
	//vector<string> GetAllDescending();

private:
	Node *root;
};









