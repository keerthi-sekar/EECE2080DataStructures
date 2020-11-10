#include <iostream>

struct Element
{
    int value;
    int priorityNumber;
};

class ArrayBasedQueue
{
    public:
        ArrayBasedQueue();
        bool Insert(int value, int priorityNumber);
        bool Remove(int value, int priorityNumber);
        void Print();
        ~ArrayBasedQueue();
    private:
        Element m_values[10];
};

class Heap
{

};