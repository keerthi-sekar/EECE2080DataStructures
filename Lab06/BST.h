#include <string>

class Node
{
public:
	Node();
	Node(int val);
	Node(int val, Node * nextNode);
	virtual ~Node();

	string m_value;
	Node *left;
	Node *right;
}

class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(string value);
	~BinarySearchTree();
	void Insert(string value);
	Node* Find(string value);
	int Size();
	void EmptyTree();
private:
	Node *root;
};









