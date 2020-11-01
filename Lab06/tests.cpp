// tests.cpp
#include "BST.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

    TEST(BinarySearchTree, InsertTest1)
    {
        BinarySearchTree BSTObject;
        BSTObject.Insert("Star Wars");
        BSTObject.Insert("Star Trek");
        BSTObject.Insert("Space Balls");
        BSTObject.Insert("Galaxy Quest");

        Node *checkInsert1;
        checkInsert1 = BSTObject.Find("Star Trek");

        Node *checkInsert2;
        checkInsert2 = BSTObject.Find("Galaxy Quest");

        ASSERT_EQ("Star Trek", checkInsert1->m_value);
        ASSERT_EQ("Galaxy Quest", checkInsert2->m_value);
    }

    TEST(BinarySearchTree, InsertTest2)
    {
        BinarySearchTree BSTObject;
        BSTObject.Insert("Star Wars");
        BSTObject.Insert("Star Trek");
        BSTObject.Insert("Space Balls");
        BSTObject.Insert("Galaxy Quest");

        Node *checkInsert3;
        checkInsert3 = BSTObject.Find("Nutella");

        ASSERT_EQ(nullptr, checkInsert3);
    }

    TEST(BinarySearchTree, FindTest1)
    {
        BinarySearchTree BSTObject;
        BSTObject.Insert("Cars");
        BSTObject.Insert("Monsters Inc");
        BSTObject.Insert("The Incredibles");
        BSTObject.Insert("WallE");

        Node *findElement;
        findElement = BSTObject.Find("The Incredibles");

        ASSERT_EQ("The Incredibles", findElement->m_value);

    }

    TEST(BinarySearchTree, FindTest2)
    {
        BinarySearchTree BSTObject;
        BSTObject.Insert("Cars");
        BSTObject.Insert("Monsters Inc");
        BSTObject.Insert("The Incredibles");
        BSTObject.Insert("WallE");

        Node *findElement;
        findElement = BSTObject.Find("Moana");

        ASSERT_EQ(nullptr, findElement);
    }

    TEST(BinarySearchTree, SizeTest1)
    {
        BinarySearchTree BSTObject;
        BSTObject.Insert("Cars");
        BSTObject.Insert("Monsters Inc");
        BSTObject.Insert("The Incredibles");
        BSTObject.Insert("WallE");

        ASSERT_EQ(4, BSTObject.Size(BSTObject.GetRoot()));
    }

    TEST(BinarySearchTree, SizeTest2)
    {
        BinarySearchTree BSTObject;
        BSTObject.Insert("Halloween");
        BSTObject.Insert("A Nightmare On Elm Street");
        BSTObject.Insert("Hocus Pocus");
        BSTObject.Insert("Beetlejuice");
        BSTObject.Insert("The Grinch");

        ASSERT_EQ(5, BSTObject.Size(BSTObject.GetRoot()));
    }

    TEST(BinarySearchTree, SizeTest3)
    {
        BinarySearchTree BSTObject;

        ASSERT_EQ(0, BSTObject.Size(BSTObject.GetRoot()));
    }

    TEST(BinarySearchTree, GetAllAscendingTest1)
    {
        BinarySearchTree BSTObject;
        vector<string> BSTstrings;
        vector<string> staticCheck = {"Galaxy Quest", "Space Balls", "Star Trek", "Star Wars"};

        BSTObject.Insert("Star Wars");
        BSTObject.Insert("Star Trek");
        BSTObject.Insert("Space Balls");
        BSTObject.Insert("Galaxy Quest");

        BSTObject.GetTreeNodes(BSTObject.GetRoot());
        BSTstrings = BSTObject.GetAllAscending();

        for(int i = 0; i < staticCheck.size(); i++)
        {
            ASSERT_EQ(staticCheck[i], BSTstrings[i]);
        }
    }

    TEST(BinarySearchTree, GetAllAscendingTest2)
    {
        BinarySearchTree BSTObject;
        vector<string> BSTstrings;
        vector<string> staticCheck = {"Cars", "Monsters Inc", "The Incredibles", "WallE"};

        BSTObject.Insert("Monsters Inc");
        BSTObject.Insert("Cars");
        BSTObject.Insert("The Incredibles");
        BSTObject.Insert("WallE");

        BSTObject.GetTreeNodes(BSTObject.GetRoot());
        BSTstrings = BSTObject.GetAllAscending();

        for(int i = 0; i < staticCheck.size(); i++)
        {
            ASSERT_EQ(staticCheck[i], BSTstrings[i]);
        }
    }

    TEST(BinarySearchTree, GetAllAscendingTest3)
    {
        BinarySearchTree BSTObject;
        vector<string> BSTstrings;
        vector<string> staticCheck = {"A Nightmare on Elm Street", "Beetlejuice", "Halloween", "Hocus Pocus"};

        BSTObject.Insert("Beetlejuice");
        BSTObject.Insert("Halloween");
        BSTObject.Insert("A Nightmare on Elm Street");
        BSTObject.Insert("Hocus Pocus");

        BSTObject.GetTreeNodes(BSTObject.GetRoot());
        BSTstrings = BSTObject.GetAllAscending();

        for(int i = 0; i < staticCheck.size(); i++)
        {
            ASSERT_EQ(staticCheck[i], BSTstrings[i]);
        }
    }

    TEST(BinarySearchTree, GetAllDescendingTest1)
    {
        BinarySearchTree BSTObject;
        vector<string> BSTstrings;
        vector<string> staticCheck = {"Hocus Pocus", "Halloween", "Beetlejuice", "A Nightmare on Elm Street"};

        BSTObject.Insert("Beetlejuice");
        BSTObject.Insert("Halloween");
        BSTObject.Insert("A Nightmare on Elm Street");
        BSTObject.Insert("Hocus Pocus");

        BSTObject.GetTreeNodes(BSTObject.GetRoot());
        BSTstrings = BSTObject.GetAllDescending();

        for(int i = 0; i < staticCheck.size(); i++)
        {
            ASSERT_EQ(staticCheck[i], BSTstrings[i]);
        }
    }

    TEST(BinarySearchTree, GetAllDescendingTest2)
    {
        BinarySearchTree BSTObject;
        vector<string> BSTstrings;
        vector<string> staticCheck = {"WallE", "The Incredibles", "Monsters Inc", "Cars"};

        BSTObject.Insert("Monsters Inc");
        BSTObject.Insert("Cars");
        BSTObject.Insert("The Incredibles");
        BSTObject.Insert("WallE");

        BSTObject.GetTreeNodes(BSTObject.GetRoot());
        BSTstrings = BSTObject.GetAllDescending();

        for(int i = 0; i < staticCheck.size(); i++)
        {
            ASSERT_EQ(staticCheck[i], BSTstrings[i]);
        }
    }

    TEST(BinarySearchTree, GetAllDescendingTest3)
    {
        BinarySearchTree BSTObject;
        vector<string> BSTstrings;
        vector<string> staticCheck = {"Star Wars", "Star Trek", "Space Balls", "Galaxy Quest"};

        BSTObject.Insert("Star Wars");
        BSTObject.Insert("Star Trek");
        BSTObject.Insert("Space Balls");
        BSTObject.Insert("Galaxy Quest");

        BSTObject.GetTreeNodes(BSTObject.GetRoot());
        BSTstrings = BSTObject.GetAllDescending();

        for(int i = 0; i < staticCheck.size(); i++)
        {
            ASSERT_EQ(staticCheck[i], BSTstrings[i]);
        }
    }

    TEST(BinarySearchTree, EmptyTest1)
    {
        BinarySearchTree BSTObject;

        BSTObject.Insert("Star Wars");
        BSTObject.Insert("Star Trek");
        BSTObject.Insert("Space Balls");
        BSTObject.Insert("Galaxy Quest");

        ASSERT_TRUE(BSTObject.EmptyTree(BSTObject.GetRoot()));
    }

    TEST(BinarySearchTree, EmptyTest2)
    {
        BinarySearchTree BSTObject;

        ASSERT_FALSE(BSTObject.EmptyTree(BSTObject.GetRoot()));
    }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
