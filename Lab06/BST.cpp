#include "BST.h"
#include <iostream>

using namespace std;

Node::Node()
{
	m_value = "0";
}

Node::Node(string val)
{
	m_value = val;
	left = nullptr;
	right = nullptr;
}

Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
}

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::BinarySearchTree(string value)
{
	root->m_value = value;
}

BinarySearchTree::~BinarySearchTree()
{
	std::cout << "Delete binary search tree " << std::endl;
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
/*int BinarySearchTree::Size(Node * currentNode)
{
	if(root == nullptr)
	{
		return 0;
	}
	return(root->m_value + Size(root->left) + Size(root->right));
}*/

bool BinarySearchTree::EmptyTree(Node * currentNode)
{
	if(root == nullptr)
	{
		return true;
	}

	EmptyTree(currentNode->left);
	EmptyTree(currentNode->right);

	cout << "Deleting Node: " << currentNode->m_value << endl;

	delete currentNode;
	
}