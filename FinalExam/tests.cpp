// tests.cpp
#include "Skyrim.h"
#include <gtest/gtest.h>

//My Assumption: tests.cpp needs to build but since no implementation, test cases don't need to pass/run properly

TEST(Skyrim, ChairAbleToSit1)
{
    //Test checks true since no other interaction is being called, the bool for sitting must match True
    Chair chair;
    ASSERT_TRUE(chair.AbleToSit());
}

TEST(Skyrim, ChairAbleToSit2)
{
    //Test to check after destroying the object that the player cannot sit in the chair

    Chair chair;
    chair.AbleToDestroy();
    chair.Destroy();
    //would assert false and cout the error statement
    ASSERT_FALSE(chair.AbleToSit());
}

TEST(Skyrim, ChairAbleToDestroy1)
{
    //Test checks true since no other interaction is being called, the bool for destroying must match True
    Chair chair;

    ASSERT_TRUE(chair.AbleToDestroy());
}

TEST(Skyrim, ChairAbleToDestroy2)
{
    //Test to check after destroying the object that the player cannot destroy the object again
    Chair chair;

    chair.AbleToDestroy();
    chair.Destroy();
    //would assert false and cout the error statement/exception
    ASSERT_FALSE(chair.AbleToDestroy());
}

TEST(Skyrim, StatueAbleToSit1)
{
    //Test checks that even that sit is set to false - since hardcoded into the constructor then it should always be false
    Statue statue;
    ASSERT_FALSE(statue.AbleToSit());
}

TEST(Skyrim, StatueAbleToSit2)
{
    //Tests the bool for sit is false
    Statue statue;
    ASSERT_FALSE(statue.AbleToSit());
    //even if you called sit the false condition would make it output a error statement (handle the error/mistake of calling sit)
    statue.Sit();
}

TEST(Skyrim, StatueAbleToDestroy1)
{
    //Test checks that even that destroy is set to false - since hardcoded into the constructor then it should always be false
    Statue statue;

    ASSERT_FALSE(statue.AbleToDestroy());
    //even if you called destroy the false condition would make it output a error statement (handle the error/mistake of calling destroy)
    statue.Destroy();
}

TEST(Skyrim, StatueAbleToDestroy2)
{
    //Tests the bool for destroy is false
    Statue statue;

    ASSERT_FALSE(statue.AbleToDestroy());
    statue.Destroy();
    //even if you called destroy the false condition would make it output a error statement (handle the error/mistake of calling destroy)
    ASSERT_FALSE(statue.AbleToDestroy());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
