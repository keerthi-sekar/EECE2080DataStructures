#include "BST.h"

Node::Node() : m_value(-1), m_next(nullptr)
{

}

Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}

Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
}

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::BinarySearchTree(string value)
{
	root = nullptr;
	left = nullptr;
	right = nullptr;
}

void BinarySearchTree::Insert(string value)
{
	Node *nextNode = new Node();
	nextNode->m_value = value;

	Node *temp = new Node();
	temp = root;

	Node *parent;

	if(root == nullptr)
	{
		root = nextNode;
	}
	else
	{

		Node *current;
		current = root;

		while(current)
		{
			parent = current;
			if(nextNode->m_value > current->m_value)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}

		if(nextNode->m_value > parent->m_value)
		{
			parent->right = nextNode;
		}
		else
		{
			parent->left = nextNode;
		}
	}
	
}

Node* BinarySearchTree::Find(string value)
{
	if(root == nullptr)
	{
		return nullptr;
	}
	else
	{
		while(root)
		{
			if(value > root->m_value)
			{
				root = root->right;
			}
			else if(value < root->m_value)
			{
				root = root->left;
			}
			else if(value == root->m_value)
			{
				return root;
			}
		}

		return nullptr;
	}
}

//used geeksforgeeks recursive method
int BinarySearchTree::Size()
{
	if(root == nullptr)
	{
		return 0;
	}
	return(root->m_value + Size(root->left) + Size(root->right));
}