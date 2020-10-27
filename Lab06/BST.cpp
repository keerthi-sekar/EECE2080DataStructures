#include "BST.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Node::Node()
{

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
	delete left;
	delete right;
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
	if(root)
	{
		std::cout << "Destructor BST " << std::endl;
		EmptyTree(root);
	}
}

Node* BinarySearchTree::GetRoot()
{
	return root;
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
		cout << "root null" << endl;
		return nullptr;
	}
	else
	{
		while(root != nullptr)
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
				cout << value + " found" << endl;
				return root;
			}
		}
		return nullptr;
	}
}

//used geeksforgeeks recursive method
int BinarySearchTree::Size(Node* currentNode)
{
	if(currentNode == nullptr)
	{
		return 0;
	}
	
	return 1 + Size(currentNode->left) + Size(currentNode->right);
}

//used geeksforgeeks recursive method
bool BinarySearchTree::EmptyTree(Node *currentNode)
{
	if(currentNode == nullptr)
	{
		return true;
	}
	
	EmptyTree(currentNode->left);
	EmptyTree(currentNode->right);

	cout << "Deleting Node: " << currentNode->m_value << endl;

	if(currentNode->left != nullptr)
	{
		currentNode->left = nullptr;
	}
	if(currentNode->right != nullptr)
	{
		currentNode->right = nullptr;
	}

	delete(currentNode);
}

void BinarySearchTree::GetTreeNodes(Node* currentNode)
{
	if(currentNode == nullptr)
	{
		return;
	}

	GetTreeNodes(currentNode->right);
	items.push_back(currentNode->m_value);
	GetTreeNodes(currentNode->left);
}

vector<string> BinarySearchTree::GetAllAscending()
{
   sort(items.begin(), items.end());
   return items;
}

vector<string> BinarySearchTree::GetAllDescending()
{
	sort(items.rbegin(), items.rend());
	return items;
}