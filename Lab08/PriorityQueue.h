#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class ArrayBasedQueue
{
    public:
        ArrayBasedQueue(int size);
        bool Insert(int value, int pn);
        bool Remove();
        void Print();
        ~ArrayBasedQueue();
    private:
        int m_size;
        int m_values[5000];
        int m_priority[5000];
        int m_front;
        int m_back;
        
};

class Heap
{
    public:
        Heap();
        bool Insert(int value);
        bool Remove(int value);
        int RemoveMax();
        void Ascend(int value);
        void Descend(int value);
        void Print();
        int getParent(int value);
        int getLeft(int value);
        int getRight(int value);
        int getMSize() { return m_size; }
        ~Heap();
    private:
        int m_elements[5000]; 
        int m_size;
};