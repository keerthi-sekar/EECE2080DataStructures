// tests.cpp
#include "StackQueue.h"
#include <gtest/gtest.h>


		
 		TEST(StackTests,isEmpty1)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
		}

		TEST(StackTests,IsEmpty2)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
			ASSERT_TRUE(stack.push(4));

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(3));

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(2));

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(1));

			ASSERT_FALSE(stack.isEmpty());

		}

		TEST(StackTests,IsEmpty3)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
			ASSERT_TRUE(stack.push(4));

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(3));

			ASSERT_FALSE(stack.isEmpty());

			ASSERT_TRUE(stack.pop());
			ASSERT_FALSE(stack.isEmpty());

			ASSERT_TRUE(stack.pop());
			ASSERT_TRUE(stack.isEmpty());

		}

		TEST(StackTests,PushAndPeek1)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
			try
			{
				int val = stack.peek();
				ASSERT_TRUE(false); // force test failure if this line executes
			}
			catch (...)
			{
				//Assuming right exception was thrown
			}

		}

		TEST(StackTests,PushAndPeek2)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
			ASSERT_TRUE(stack.push(4));
			ASSERT_EQ(4, stack.peek());

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(3));
			ASSERT_EQ(3, stack.peek());

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(2));
			ASSERT_EQ(2, stack.peek());

			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(1));
			ASSERT_EQ(1, stack.peek());

		}
		
		TEST(StackTests,Pop)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
			ASSERT_TRUE(stack.push(4));
			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(3));
			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(2));
			ASSERT_FALSE(stack.isEmpty());
			ASSERT_TRUE(stack.push(1));
			ASSERT_FALSE(stack.isEmpty());

			ASSERT_EQ(1, stack.peek());
			ASSERT_TRUE(stack.pop());
			ASSERT_FALSE(stack.isEmpty());
			ASSERT_EQ(2, stack.peek());
			ASSERT_TRUE(stack.pop());
			ASSERT_FALSE(stack.isEmpty());
			ASSERT_EQ(3, stack.peek());
			ASSERT_TRUE(stack.pop());
			ASSERT_FALSE(stack.isEmpty());
			ASSERT_EQ(4, stack.peek());
			ASSERT_TRUE(stack.pop());

			ASSERT_TRUE(stack.isEmpty());

			ASSERT_FALSE(stack.pop());
		}

		TEST(StackTests,Pop2)
		{
			ArrayBasedStack stack;
			ASSERT_TRUE(stack.isEmpty());
			ASSERT_FALSE(stack.pop());

		}

		TEST(QueueTests,IsEmpty1)
		{
			ArrayBasedQueue queue;
			ASSERT_TRUE(queue.isEmpty());
		}

		TEST(QueueTests,IsEmpty2)
		{
			ArrayBasedQueue queue;
			ASSERT_TRUE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("1,1,2"));
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("2,1,3"));
			ASSERT_FALSE(queue.isEmpty());
		}

		TEST(QueueTests,IsEmpty3)
		{
			ArrayBasedQueue queue;
			ASSERT_TRUE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("1,1,2"));
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("2,1,3"));
			ASSERT_FALSE(queue.isEmpty());

			ASSERT_EQ(std::string("1,1,2"), queue.peekFront());
			ASSERT_TRUE(queue.deQueue());
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_EQ(std::string("2,1,3"), queue.peekFront());
			ASSERT_TRUE(queue.deQueue());
			ASSERT_TRUE(queue.isEmpty());

		}



		TEST(QueueTests,EnQueue_PeekFront1)
		{
			ArrayBasedQueue queue;
			ASSERT_TRUE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("1,1,2"));
			ASSERT_EQ(std::string("1,1,2"), queue.peekFront());
			ASSERT_FALSE(queue.isEmpty());

			ASSERT_TRUE(queue.enQueue("2,1,3"));
			ASSERT_EQ(std::string("1,1,2"), queue.peekFront());
			ASSERT_FALSE(queue.isEmpty());

			ASSERT_TRUE(queue.enQueue("1,2,3"));
			ASSERT_EQ(std::string("1,1,2"), queue.peekFront());
			ASSERT_FALSE(queue.isEmpty());

			ASSERT_TRUE(queue.enQueue("3,1,2"));
			ASSERT_EQ(std::string("1,1,2"), queue.peekFront());
			ASSERT_FALSE(queue.isEmpty());

		}


		TEST(QueueTests,PeekFront2)
		{
			ArrayBasedQueue queue;
			ASSERT_TRUE(queue.isEmpty());
			try
			{
				std::string val = queue.peekFront();
				ASSERT_TRUE(false); // force test failure if this line executes
			}
			catch (...)
			{
				//Assuming right exception was thrown
			}

		}

		TEST(QueueTests,DeQueue1)
		{
			ArrayBasedQueue queue;
			ASSERT_TRUE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("1,1,2"));
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("2,1,3"));
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("1,2,3"));
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_TRUE(queue.enQueue("3,1,2"));
			ASSERT_FALSE(queue.isEmpty());

			ASSERT_EQ(std::string("1,1,2"), queue.peekFront());
			ASSERT_TRUE(queue.deQueue());
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_EQ(std::string("2,1,3"), queue.peekFront());
			ASSERT_TRUE(queue.deQueue());
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_EQ(std::string("1,2,3"), queue.peekFront());
			ASSERT_TRUE(queue.deQueue());
			ASSERT_FALSE(queue.isEmpty());
			ASSERT_EQ(std::string("3,1,2"), queue.peekFront());
			ASSERT_TRUE(queue.deQueue());

			ASSERT_TRUE(queue.isEmpty());

			ASSERT_FALSE(queue.deQueue());

		}







 

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
