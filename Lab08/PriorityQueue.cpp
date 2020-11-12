//Got help from GeeksforGeeks and PrepInsta to understand how to implement these functions for Priority Queues
#include "PriorityQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;

//int MVALUES_SIZE = 10;

ArrayBasedQueue::ArrayBasedQueue(int size)
{
    for (int i = 0; i < size; i++)
    {
        m_values[i] = -1;
    }

    m_front = -1;
    m_back = -1;
    m_size = size;
}

bool ArrayBasedQueue::Insert(int value, int pn)
{
    int i;
    if ((m_front == 0) && (m_back == 5000))
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        if (m_front == -1)
        {
            m_front = m_back = 0;
            m_values[m_back] = value;
            m_priority[m_back] = pn;
        }
        else if (m_back == m_size - 1)
        {
            for (i = m_front; i <= m_back; i++)
            {
                m_values[i - m_front] = m_values[i];
                m_priority[i - m_front] = m_priority[i];
                m_back = m_back - m_front;
                m_front = 0;
                for (i = m_back; i > m_front; i--)
                {
                    if (pn > m_priority[i])
                    {
                        m_values[i + 1] = m_values[i];
                        m_priority[i + 1] = m_priority[i];
                    }
                    else
                    {
                        break;
                    }
                    m_values[i + 1] = value;
                    m_priority[i + 1] = pn;
                    m_back++;
                }
            }
        }
        else
        {
            for (i = m_back; i >= m_front; i--)
            {
                if (pn > m_priority[i])
                {
                    m_values[i + 1] = m_values[i];
                    m_priority[i + 1] = m_priority[i];
                }
                else
                {
                    break;
                }
            }
            m_values[i + 1] = value;
            m_priority[i + 1] = pn;
            m_back++;
        }
    }
}

bool ArrayBasedQueue::Remove()
{
    if(m_front == -1)
    {
        cout << "Queue is empty!" << endl;
        return false;
    }
    else
    {
        if(m_front == m_back)
        {
            m_front = m_back = -1;
        }
        else
        {
            m_front++;
        }
        
    }
    
}

void ArrayBasedQueue::Print()
{
    for(int i = m_front; i < m_back; i++)
    {
        cout << "Value: " << m_values[i] <<"With priority: " << m_priority[i] << endl;
    }
}

ArrayBasedQueue::~ArrayBasedQueue()
{
}

Heap::Heap()
{
    for (int i = 0; i < m_size; i++)
    {
        m_elements[i] = -1;
    }

    m_size = -1;
}

Heap::~Heap()
{
}

int Heap::getParent(int value)
{
    return (value - 1) / 2;
}

int Heap::getLeft(int value)
{
    return ((2 * value) + 1);
}

int Heap::getRight(int value)
{
    return ((2 * value) + 2);
}

void Heap::Ascend(int value)
{
    while (value > 0 && m_elements[getParent(value)] < m_elements[value])
    {
        swap(m_elements[getParent(value)], m_elements[value]);

        value = getParent(value);
    }
}

void Heap::Descend(int value)
{
    int idx = value;

    int left = getLeft(value);

    if (left <= m_size && m_elements[left] > m_elements[idx])
    {
        idx = left;
    }

    int right = getRight(value);

    if (right <= m_size && m_elements[right] > m_elements[idx])
    {
        idx = right;
    }

    if (value != idx)
    {
        swap(m_elements[value], m_elements[idx]);
        Descend(idx);
    }
}

int Heap::RemoveMax()
{
    int max = m_elements[0];

    m_elements[0] = m_elements[m_size];
    m_size = m_size - 1;

    Descend(0);

    return max;
}

bool Heap::Insert(int value)
{
    m_size = m_size + 1;
    m_elements[m_size] = value;
    int temp = m_size;

    Ascend(m_size);
    return true; //Change later for testing purposes.
}

bool Heap::Remove(int index)
{
    m_elements[index] = m_elements[0];

    Ascend(index);

    RemoveMax();
}

void Heap::Print()
{
    int i = 0;
    while (i < m_size)
    {
        cout << m_elements[i] << " ";
        i++;
    }

    cout << endl;
}