#include "PriorityQueue.h"
#include <iostream>
#include <string>

using namespace std;

int MVALUES_SIZE = 10;

ArrayBasedQueue::ArrayBasedQueue()
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        m_values[i] = -1;
    }
}

bool ArrayBasedQueue::Insert(int value)
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        if(m_values[i] == -1)
        {
            m_values[i] = value;
            return true;
        }
    }

    return false;
}

bool ArrayBasedQueue::Remove(int value)
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        if(m_values[i] == value)
        {
            m_values[i] = -1;
            return true;
        }
    }

    return false;
}

void:: ArrayBasedQueue::Print()
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        cout << m_values[i] << endl;
    }
}