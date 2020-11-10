#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int MVALUES_SIZE = 10;

ArrayBasedQueue::ArrayBasedQueue()
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        m_values[i].value = -1;
    }
}

bool ArrayBasedQueue::Insert(int value, int priorityNumber)
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        if(m_values[i].value == -1)
        {
            m_values[i].value = value;
            return true;
        }
    }

    return false;
}

bool ArrayBasedQueue::Remove(int value, int priorityNumber)
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        if(m_values[i].value == value)
        {
            m_values[i].value = -1;
            return true;
        }
    }

    return false;
}

void:: ArrayBasedQueue::Print()
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        cout << m_values[i].value << endl;
    }
}

ArrayBasedQueue::~ArrayBasedQueue()
{
    
}