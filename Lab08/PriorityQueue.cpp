#include "PriorityQueue.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int MVALUES_SIZE = 10;

ArrayBasedQueue::ArrayBasedQueue()
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        m_values[i].value = -1;
        m_values[i].priorityNumber = 0;
    }
}

bool ArrayBasedQueue::Insert(int value, int pn)
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        if(m_values[i].value == -1)
        {
            m_values[i].value = value;
            m_values[i].priorityNumber = pn;
            return true;
        }
    }

    return false;
}

bool ArrayBasedQueue::Remove(int value)
{
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        if(m_values[i].value == value)
        {
            m_values[i].value = -1;
            m_values[i].priorityNumber = 0;
            return true;
        }
    }

    return false;
}

void:: ArrayBasedQueue::Print()
{
    //i think it needs to be sorted by priority
    //https://stackoverflow.com/questions/61499825/k-sorted-array-using-priority-queue-c
    for(int i = 0; i < MVALUES_SIZE; i++)
    {
        cout << "value: " + m_values[i].value << " || priority: " + m_values[i].priorityNumber << endl;
    }
}

ArrayBasedQueue::~ArrayBasedQueue()
{
    
}

Heap::Heap()
{
    Element element;
    element.value = -1;
    element.priorityNumber = 0;
    
    for(int i = 0; i < 10; i++)
    {
        m_values.push_back(element);
    }
}

Heap::~Heap()
{

}