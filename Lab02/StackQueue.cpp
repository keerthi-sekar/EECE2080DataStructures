// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"


int ArrayBasedStack::peek()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		if(m_values[49] != -1)
		{
			return m_values[49];
		}
		for(int i=0; i < 50; i++)
		{
			if(m_values[i+1] == -1 && m_values[i] != -1)
			{
				return m_values[i];
			}
		}
	}
}

std::string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return mq_values[m_head];
	}
}

ArrayBasedStack::ArrayBasedStack()
{
	//Logic is that -1 signifies empty
	for(int i=0; i < 50; i++)
	{
		m_values[i] = -1;
	}
}

ArrayBasedStack::~ArrayBasedStack()
{

}

bool ArrayBasedStack::isEmpty() const
{
	for(int i=0; i < 50; i++)
	{
		if(m_values[i] != -1)
		{
			return false;
		}
	}

	return true;
}

bool ArrayBasedStack::pop()
{
	for(int i=0; i < 50; i++)
	{
		if(i == 0 && m_values[i] == -1)
		{
			return false;
		}
		if(m_values[i] == -1)
		{
			m_values[i-1] = -1;
			return true;
		}
	}

	return false;
}

bool ArrayBasedStack::push(int val)
{
	for(int i=0; i < 50; i++)
	{
		if(m_values[i] == -1)
		{
			m_values[i] = val;
			return true;
		}
	}

	return false;
}

std::string ArrayBasedStack::toString()
{
	return "";
}

ArrayBasedQueue::ArrayBasedQueue()
{
	for(int i=0; i < 50; i++)
	{
		mq_values[i] = "";
	}
}

ArrayBasedQueue::~ArrayBasedQueue()
{

}

bool ArrayBasedQueue::isEmpty() const
{
	for(int i=0; i < 50; i++)
	{
		if(mq_values[i] != "")
		{
			return false;
		}
	}

	return true;
}

bool ArrayBasedQueue::deQueue()
{
	if(mq_values[m_head] == "" && mq_values[m_tail] == "")
	{
		return false;
	}
	if(m_head == 0 && m_tail == 0)
	{
		return false;
	}
	else if(m_head == 49 && m_tail !=0)
	{
		mq_values[m_head] = "";
		m_head = 0;
		return true;
	}
	else if(m_head != (m_tail+1))
	{
		mq_values[m_head] = "";
		m_head++;
		return true;
	}

	return false;
}

bool ArrayBasedQueue::enQueue(std::string val)
{
	if(m_head == 0 && m_tail == 0)
	{
		mq_values[m_head] = val;
		m_tail = m_head + 1;
		return true;
	}
	else if(m_tail == 49 && m_head !=0)
	{
		mq_values[m_tail] = val;
		m_tail = 0;
		return true;
	}
	else if(m_head != (m_tail+1))
	{
		mq_values[m_tail] = val;
		m_tail += 1;
		return true;
	}
	return false;
}

