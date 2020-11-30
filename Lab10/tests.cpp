// tests.cpp
#include "Hashes.h"
#include <gtest/gtest.h>

TEST(Hashes, Hash1)
{
    Hash<int, int> *h = new Hash<int, int>;

    h->AddItem(1, 2);
    ASSERT_EQ(1, h->getIndex(1));

}

TEST(Hashes, Hash2)
{
    Hash<int, int> *h = new Hash<int, int>;

    ASSERT_EQ(0, h->getIndex(0)); 
}

TEST(Hashes, AddItem1)
{
    Hash<int, int> *h = new Hash<int, int>;

    h->AddItem(1,1); 
    h->AddItem(2,2); 
    h->AddItem(3,3); 
    ASSERT_EQ(3, h->getItems());
}

TEST(Hashes, AddItem2)
{
    Hash<int, int> *h = new Hash<int, int>;

    ASSERT_EQ(0, h->getItems());
}

TEST(Hashes, GetItem1)
{
    Hash<int, int> *h = new Hash<int, int>;

    h->AddItem(1,1); 
    h->AddItem(2,5); 
    h->AddItem(3,7); 
    ASSERT_EQ(5, h->GetItem(2));
}

TEST(Hashes, GetItem2)
{
    Hash<int, int> *h = new Hash<int, int>;

    h->AddItem(1,1); 
    h->AddItem(3,7); 
    ASSERT_EQ(NULL, h->GetItem(2));
}

TEST(Hashes, GetItemsInDictionary1)
{
    Hash<int, int> *h = new Hash<int, int>;

    ASSERT_EQ(0, h->getItems());
}

TEST(Hashes, GetItemsInDictionary2)
{
    Hash<int, int> *h = new Hash<int, int>;
    h->AddItem(1,1); 
    h->AddItem(2,5); 
    h->AddItem(3,7);
    h->AddItem(4,8); 
    h->AddItem(5,14); 
    h->AddItem(6,2);
    ASSERT_EQ(6, h->getItems());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
