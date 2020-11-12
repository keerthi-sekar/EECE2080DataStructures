#include "PriorityQueue.h"
#include <gtest/gtest.h>

    TEST(ArrayBasedQueue, Insert1)
    {
        ArrayBasedQueue data(10);

        ASSERT_TRUE(data.Insert(10, 1));
        ASSERT_TRUE(data.Insert(8, 2));
        ASSERT_TRUE(data.Insert(5, 3));
    }

    TEST(ArrayBasedQueue, Insert2)
    {
        ArrayBasedQueue data(10);

        ASSERT_TRUE(data.Insert(10, 1));
        ASSERT_TRUE(data.Insert(8, 2));
        ASSERT_TRUE(data.Insert(5, 3));
        ASSERT_TRUE(data.Insert(5, 4));
    }

    TEST(ArrayBasedQueue, Remove1)
    {
        ArrayBasedQueue data(10);

        ASSERT_TRUE(data.Insert(10, 1));
        ASSERT_TRUE(data.Insert(8, 2));
        ASSERT_TRUE(data.Insert(5, 3));
        ASSERT_TRUE(data.Remove());
    }

    TEST(ArrayBasedQueue, Remove2)
    {
        ArrayBasedQueue data(10);

        ASSERT_FALSE(data.Remove());
    }

    TEST(ArrayBasedQueue, Print1)
    {
        ArrayBasedQueue data(10);

        ASSERT_TRUE(data.Insert(10, 1));
        ASSERT_TRUE(data.Insert(8, 2));
        ASSERT_TRUE(data.Insert(5, 3));
        ASSERT_TRUE(data.Remove());
        data.Print();
    }

    TEST(ArrayBasedQueue, Print2)
    {
        ArrayBasedQueue data(10);

        ASSERT_FALSE(data.Remove());
        data.Print();
    }

    TEST(Heap, Insert1)
    {
        Heap heap;

        ASSERT_TRUE(heap.Insert(45));
        ASSERT_TRUE(heap.Insert(31));
        ASSERT_TRUE(heap.Insert(14));
        ASSERT_TRUE(heap.Insert(4));
    }

    TEST(Heap, Insert2)
    {
        Heap heap;

        ASSERT_TRUE(heap.Insert(25));
        ASSERT_TRUE(heap.Insert(50));
        ASSERT_TRUE(heap.Insert(21));
    }
        
    TEST(Heap, Remove1)
    {
        Heap heap;

        heap.Insert(22);
        heap.Insert(79);
        heap.Insert(10);
        heap.Insert(50);
        heap.Insert(2);
        heap.Remove(1);

        ASSERT_EQ(79, heap.RemoveMax());
    }

    TEST(Heap, Remove2)
    {
        Heap heap;

        heap.Insert(22);
        heap.Insert(79);
        heap.Insert(10);
        heap.Insert(20);
        heap.Insert(2);

        ASSERT_EQ(79, heap.RemoveMax());

        heap.Remove(0);
        heap.Remove(3);

        heap.Print();
    }

    TEST(Heap, Print1)
    {
        Heap heap;

        heap.Insert(22);
        heap.Insert(79);
        heap.Insert(10);
        heap.Insert(50);
        heap.Insert(43);
        heap.Remove(3);

        heap.Print();

        ASSERT_EQ(79, heap.RemoveMax());

    }

    TEST(Heap, Print2)
    {
        Heap heap;

        heap.Print();

        ASSERT_EQ(-1, heap.getMSize());

    }
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
