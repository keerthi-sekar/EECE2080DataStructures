// tests.cpp
#include "SomeThing.h"
#include <gtest/gtest.h>
		
    TEST(Card,ValueTest)
    {
        Card testCard1(1,0);

        ASSERT_EQ(1, testCard1.GetValue());

    }

    TEST(Card,SuitTest)
    {
        Card testCard1(1,0);

        ASSERT_EQ(0, testCard1.GetSuit());

    }

    TEST(Deck,DeckTest)
    {
        Deck communityDeck;

        ASSERT_EQ(52, communityDeck.GetDeck().size());
    }

    TEST(Deck,DrawTest)
    {
        Deck deck1;
        Person player1("Keerthi");

        ASSERT_TRUE(deck1.Draw(player1));
    }

    TEST(Deck, DealTest)
    {
        Deck deck1;
        Person player2("Grayson");

        deck1.Deal(player2);
        ASSERT_EQ(5, player2.GetCardsInHand().size());
    }

    TEST(Person, PlayerName)
    {
        Person player3("Patrick");

        ASSERT_EQ("Patrick", player3.GetName());
    }    
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}