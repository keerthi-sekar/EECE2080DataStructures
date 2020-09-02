// tests.cpp
#include "LinkedList.h"
#include <gtest/gtest.h>


		
        TEST(ArrayBasedLinkedList, TestEmpy) 
		{
			ArrayBasedLinkedList linkedList;
            
			ASSERT_TRUE(linkedList.isEmpty());

			ASSERT_EQ(std::string(""), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test1Add)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}
		TEST(ArrayBasedLinkedList, Test2Add)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test3Add)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test11Add)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));
			ASSERT_TRUE(linkedList.add(4));
			ASSERT_TRUE(linkedList.add(5));
			ASSERT_TRUE(linkedList.add(6));
			ASSERT_TRUE(linkedList.add(7));
			ASSERT_TRUE(linkedList.add(8));
			ASSERT_TRUE(linkedList.add(9));
			ASSERT_TRUE(linkedList.add(10));
			ASSERT_FALSE(linkedList.add(11));//Capacity is 11 so won't add

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestRemoveNonExistant)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_FALSE(linkedList.remove(4));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestBeginingRemove)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_TRUE(linkedList.remove(1));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("2 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestMiddleRemove)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_TRUE(linkedList.remove(2));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestEndRemove)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_TRUE(linkedList.remove(3));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestMultipleRemove)
		{
			ArrayBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));
			ASSERT_TRUE(linkedList.add(4));
			ASSERT_TRUE(linkedList.add(5));
			ASSERT_TRUE(linkedList.add(6));
			ASSERT_TRUE(linkedList.add(7));
			ASSERT_TRUE(linkedList.add(8));
			ASSERT_TRUE(linkedList.add(9));
			ASSERT_TRUE(linkedList.add(10));
			ASSERT_FALSE(linkedList.add(11));

			ASSERT_TRUE(linkedList.remove(2));
			ASSERT_TRUE(linkedList.remove(4));
			ASSERT_TRUE(linkedList.remove(6));
			ASSERT_TRUE(linkedList.remove(8));

			ASSERT_FALSE(linkedList.remove(2));
			ASSERT_FALSE(linkedList.remove(4));
			ASSERT_FALSE(linkedList.remove(6));
			ASSERT_FALSE(linkedList.remove(8));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 3 5 7 9 10"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList,TestEmpy)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());

			ASSERT_EQ(std::string(""), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList,Test1Add)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList,Test2Add)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList,Test3Add)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList, ListTest1)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));
			ASSERT_TRUE(linkedList.add(4));
			ASSERT_TRUE(linkedList.add(5));
			ASSERT_TRUE(linkedList.add(6));
			ASSERT_TRUE(linkedList.add(7));
			ASSERT_TRUE(linkedList.add(8));
			ASSERT_TRUE(linkedList.add(9));
			ASSERT_TRUE(linkedList.add(10));
			ASSERT_TRUE(linkedList.add(11));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10 11"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList, TestRemoveNonExistant)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_FALSE(linkedList.remove(4));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList, TestBeginningRemove)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_TRUE(linkedList.remove(1));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("2 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList, TestMiddleRemove)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_TRUE(linkedList.remove(2));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 3"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}

		TEST(PointerBasedLinkedList, TestEndRemove)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));

			ASSERT_TRUE(linkedList.remove(3));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}



		TEST(PointerBasedLinkedList, TestMultipleRemove)
		{
			PointerBasedLinkedList linkedList;
			ASSERT_TRUE(linkedList.isEmpty());
			ASSERT_TRUE(linkedList.add(1));
			ASSERT_TRUE(linkedList.add(2));
			ASSERT_TRUE(linkedList.add(3));
			ASSERT_TRUE(linkedList.add(4));
			ASSERT_TRUE(linkedList.add(5));
			ASSERT_TRUE(linkedList.add(6));
			ASSERT_TRUE(linkedList.add(7));
			ASSERT_TRUE(linkedList.add(8));
			ASSERT_TRUE(linkedList.add(9));
			ASSERT_TRUE(linkedList.add(10));
			ASSERT_TRUE(linkedList.add(11));

			ASSERT_TRUE(linkedList.remove(2));
			ASSERT_TRUE(linkedList.remove(4));
			ASSERT_TRUE(linkedList.remove(6));
			ASSERT_TRUE(linkedList.remove(8));

			ASSERT_FALSE(linkedList.remove(2));
			ASSERT_FALSE(linkedList.remove(4));
			ASSERT_FALSE(linkedList.remove(6));
			ASSERT_FALSE(linkedList.remove(8));

			ASSERT_FALSE(linkedList.isEmpty());

			ASSERT_EQ(std::string("1 3 5 7 9 10 11"), linkedList.toString());

			linkedList.clear();
			ASSERT_TRUE(linkedList.isEmpty());
		}








 

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
