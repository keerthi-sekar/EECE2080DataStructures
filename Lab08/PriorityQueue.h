#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Element
{
    int value;
    int priorityNumber;
};

class ArrayBasedQueue
{
    public:
        ArrayBasedQueue();
        bool Insert(int value, int pn);
        bool Remove(int value);
        void Print();
        ~ArrayBasedQueue();
    private:
        Element m_values[10];
};

class Heap
{
    //sorry grayson :( me too slow so I didnt get to do this before work, got stuck on print for array: Help -> https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
    public:
        Heap();
        bool Insert();
        bool Remove();
        void Print();
        ~Heap();
    private:
        vector<Element> m_values; 
};