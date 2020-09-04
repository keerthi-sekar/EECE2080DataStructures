// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	//TODO - hint, you can recursively handle this
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}
/** Returns true  if list is empty, otherwise true(false?) */
bool PointerBasedLinkedList::isEmpty() const
{
	//Check if the head node is empty
	if(m_head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	Node *nextNode = new Node();
	nextNode->m_value = val;
	nextNode->m_next = nullptr;

	if(m_head->getNext() == nullptr)
	{
		m_head->setNext(nextNode);
		nextNode->getNext();
		//return true;
	}
	else
	{
		//return false;
	}
	
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	//TODO
	return false;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	m_head = NULL; 
    //TODO
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";


    //TODO
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
	for (int i = 0; i < 10; ++i) {
		m_values[i] = -1;
	}
	//TODO
}

bool ArrayBasedLinkedList::isEmpty() const
{
	for(int i=0; i < 10; i++)
	{   
		//in our logic, we are saying all -1 in the array means the array is empty
		if(m_values[i] != -1)
		{
			return false;
		}
	}
	return true;
}
bool ArrayBasedLinkedList::add(int val)
{
	for(int i=0; i < 10; ++i)
	{
		if(m_values[i] == -1)
		{
			m_values[i] = val;
			return true;
		}
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	for(int i=0; i < 10; i++)
	{
		if(m_values[i] == val)
		{
			m_values[i] = -1;
			return true;
		}
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	for(int i=0; i < 10; i++)
	{
		m_values[i] = -1;
	}
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str;
	int count = 0;
	for(int i=0; i < 10; i++)
	{
		string currentString = "";
		if(m_values[i] == -1)
		{
			currentString = "";
		}
		else
		{
			currentString = to_string(m_values[i]);
		}

		if(count >= 1 && m_values[i] != -1)
		{
			str += " " + currentString;
		}
		else
		{
			str += currentString;
		}
		count++;

	}
	
	//clean up string (delete leading spaces if remove is called)
	if(str[0] == ' ')
	{
		str.erase(0, 1);
	}

	return str;
}
