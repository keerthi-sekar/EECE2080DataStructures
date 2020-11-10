
class ArrayBasedQueue
{
    public:
        ArrayBasedQueue();
        bool Insert(int value);
        bool Remove(int value);
        void Print();
        ~ArrayBasedQueue();
    private:
        int m_values[10];
};

class Heap
{

};