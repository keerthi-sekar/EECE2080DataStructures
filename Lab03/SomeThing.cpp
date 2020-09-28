
#include "SomeThing.h"

// TODO standard classes to be tested should be defined
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <random>

static int guid = 1;


	//0 for hearts, 1 for diamonds, 2 for clubs, 3 for spades

	Card::Card(int value, int suit) : m_value(value), m_suit(suit)
	{
		m_guid = guid;
		guid++;
	}
     Card::~Card() {}

	Card::Card(const Card &c)
	{
		std::cout << "    BAD!!!! Copy Constructor being called.  I shouldn't really be callled!!!" << std::endl;
		m_value = c.m_value;
		m_suit = c.m_suit;
		m_guid = guid;
		guid++;
	}

	int Card::GetValue() const { return m_value; }
	int Card::GetSuit() const { return m_suit; }

	Card::Card(Card &&obj)
	{
		std::cout << "    Calling Move Constructor" << std::endl;
		this->m_value = obj.m_value;
		this->m_suit = obj.m_suit;
		m_guid = obj.m_guid;
	}



	Deck::Deck()
	{
		int count = 1;
		for (int i = 0; i < 4; i++)
		{
			while (i == 0 && count != 14)
			{
				Card card(count, i);
				m_deck.push_back(card);
				count++;
			}

			count = 1;

			while (i == 1 && count != 14)
			{
				Card card(count, i);
				m_deck.push_back(card);
				count++;
			}

			count = 1;

			while (i == 2 && count != 14)
			{
				Card card(count, i);
				m_deck.push_back(card);
				count++;
			}

			count = 1;

			while (i == 3 && count != 14)
			{
				Card card(count, i);
				m_deck.push_back(card);
				count++;
			}
		}
		/*for(int i = 0; i < m_deck.size() - 1; i++)
			{
				int j = i + rand() % (m_deck.size() - i);
				Card temp1(m_deck[i]);
				Card temp2(m_deck[j]);
				m_deck.insert(m_deck.begin() + j, temp1);
				m_deck.insert(m_deck.begin() + i, temp2);
				m_deck.erase(m_deck.begin()+i);
				m_deck.erase(m_deck.begin()+j);
			}*/
	}

	Deck::~Deck()
	{
		//Do nothing for now
	}

	bool Deck::Deal(Person player)
	{
		for (int i = 0; i < 5; i++)
		{
			player.m_handOfCards.push_back(m_deck.back());
			m_deck.pop_back();
		}
		return true; //For testing purposes, change later
	}

	bool Deck::Draw(Person player)
	{
		if (player.m_handOfCards.size() < 7)
		{
			player.m_handOfCards.push_back(m_deck.back());
			m_deck.pop_back();
		}
		else
		{
			std::cout << "You have too many cards in your hand!" << std::endl;
			return false;
		}

		return true; //For testing purposes, change later
    }


	Person::Person(std::string name) : m_name(name)
	{
	}

	std::string const Person::GetName()
	{
		return m_name;
	}

     Person::~Person()
	{
		std::cout << "Deleting " << m_name << std::endl;
	}

	/*void AddCardToHandObject4(Card  &c)
	{
		std::cout<<"   AddCardToHandObject4 :"<<c.GetValue()<<" "<<c.GetSuit()<<std::endl;
		//m_listOfCardsObject.push_front(std::move(c));
	}*/

	bool Person::AddCardToStack(int x)
	{
		if (m_handOfCards.at(x).GetValue() == m_stackOfCards.back().GetValue() + 1)
		{
			m_stackOfCards.push_back(std::move(m_handOfCards.at(x)));
			std::move(m_handOfCards.erase(m_handOfCards.begin() + (x - 1)));
			return true;
		}
		else
		{
			std::cout << "Invalid move: Incorrect order in player stack." << std::endl;
			return false;
		}
	}

	void Person::Discard(Deck deck, int x)
	{
		//deck.m_deck.insert(deck.m_deck.begin(), std::move(m_handOfCards.at(x)));
		//m_handOfCards.erase(m_handOfCards.begin() + (x - 1));
	}

	void Person::Mulligan(Deck deck)
	{
		for (int i = 0; i < m_handOfCards.size() - 1; i++)
		{
			//deck.m_deck.insert(deck.m_deck.begin(), std::move(m_handOfCards.at(i)));
			//m_handOfCards.erase(m_handOfCards.begin() + i);
		}
	}



	Game::Game()
	{
		//Deck deck1;
		// For create the Cards in the masterCardList, and then seed the
		// community deck
		// See - http://www.cplusplus.com/reference/cstdlib/rand/ for ideas of how to pick random
		// numbers
	}

	Game::~Game()
	{
		//Do nothing for now
		//do a for each on masterCard list and delete the Cards
	}

	void Game::playGame()
	{
		Deck deck1;
		Person player1("Player1");
		Person player2("Player2");

		deck1.Deal(player1);
		deck1.Deal(player2);

		int playChoice;

		bool gameEnded;
		while (!gameEnded)
		{
			std::cout << "Would you like to get a new hand and end your turn? Enter 0 for yes and 1 for no." << std::endl;
			std::cin >> playChoice;
			if (playChoice == 0)
			{
				player1.Mulligan(deck1);
				deck1.Deal(player1);
			}
			else if (playChoice == 1)
			{
				std::cout << "Player 1 chooses to keep their hand." << std::endl;
			}
			std::cout << "Player 1 begins and draws a card." << std::endl;
			deck1.Draw(player1);
			bool turnEnd = false;
			while (!turnEnd)
			{
				std::cout << "These are the cards in your hand: " << std::endl;
				for (int i = 0; i < player1.m_handOfCards.size() - 1; i++)
				{
					std::cout << player1.m_handOfCards.at(i).GetValue() << ", ";
				}
				std::cout << "The top card in your stack is: " << player1.m_stackOfCards.back().GetValue() << std::endl;
				std::cout << "Enter 0 to draw a card and enter 1 to play a card to the stack." << std::endl;
				std::cin >> playChoice;
				if (playChoice == 0 && player1.m_handOfCards.size() < 7)
				{
					deck1.Draw(player1);
				}
				else if (playChoice == 1)
				{
					for (int i = 0; i < player1.m_handOfCards.size() - 1; i++)
					{
						std::cout << player1.m_handOfCards.at(i).GetValue() << ", ";
					}
					std::cout << "Enter the position of the card you want to play to the stack with ";
					std::cout << "the first position starting on the left with 1" << std::endl;
					std::cin >> playChoice;
					player1.AddCardToStack(playChoice);
				}
				if (player1.m_stackOfCards.back().GetValue() == 13)
				{
					gameEnded = true;
				}
				else
				{
					bool noPlays = true;
					for (int i = 0; i < player1.m_handOfCards.size() - 1; i++)
					{
						int temp = player1.m_handOfCards.at(i).GetValue();
						for (int i = 0; i < player1.m_handOfCards.size() - 1; i++)
						{
							if (temp == player1.m_stackOfCards.at(i).GetValue() + 1)
							{
								noPlays = false;
							}
						}
					}
					if (noPlays == true && player1.m_handOfCards.size() == 6)
					{
						turnEnd = true;
						std::cout << "Discard a card." << std::endl;
						std::cout << "Enter the position of the card you want to discard with ";
						std::cout << "the first position starting on the left with 1" << std::endl;
						std::cin >> playChoice;
						player1.Discard(deck1, playChoice);
					}
				}
			}

			std::cout << "Would you like to get a new hand and end your turn? Enter 0 for yes and 1 for no." << std::endl;
			std::cin >> playChoice;
			if (playChoice == 0)
			{
				player2.Mulligan(deck1);
				deck1.Deal(player2);
			}
			else if (playChoice == 1)
			{
				std::cout << "Player 2 chooses to keep their hand." << std::endl;
			}
			std::cout << "Player 2 begins and draws a card." << std::endl;
			deck1.Draw(player2);
		 turnEnd = false;
			while (!turnEnd)
			{
				std::cout << "These are the cards in your hand: " << std::endl;
				for (int i = 0; i < player2.m_handOfCards.size() - 1; i++)
				{
					std::cout << player2.m_handOfCards.at(i).GetValue() << ", ";
				}
				std::cout << "The top card in your stack is: " << player2.m_stackOfCards.back().GetValue() << std::endl;
				std::cout << "Enter 0 to draw a card and enter 1 to play a card to the stack." << std::endl;
				std::cin >> playChoice;
				if (playChoice == 0 && player2.m_handOfCards.size() < 7)
				{
					deck1.Draw(player2);
				}
				else if (playChoice == 1)
				{
					for (int i = 0; i < player2.m_handOfCards.size() - 1; i++)
					{
						std::cout << player2.m_handOfCards.at(i).GetValue() << ", ";
					}
					std::cout << "Enter the position of the card you want to play to the stack with ";
					std::cout << "the first position starting on the left with 1" << std::endl;
					std::cin >> playChoice;
					player1.AddCardToStack(playChoice);
				}
				if (player2.m_stackOfCards.back().GetValue() == 13)
				{
					gameEnded = true;
				}
				else
				{
					bool noPlays = true;
					for (int i = 0; i < player2.m_handOfCards.size() - 1; i++)
					{
						int temp = player2.m_handOfCards.at(i).GetValue();
						for (int i = 0; i < player2.m_handOfCards.size() - 1; i++)
						{
							if (temp == player2.m_stackOfCards.at(i).GetValue() + 1)
							{
								noPlays = false;
							}
						}
					}
					if (noPlays == true && player2.m_handOfCards.size() == 6)
					{
						turnEnd = true;
						std::cout << "Discard a card." << std::endl;
						std::cout << "Enter the position of the card you want to discard with ";
						std::cout << "the first position starting on the left with 1" << std::endl;
						std::cin >> playChoice;
						player2.Discard(deck1, playChoice);
					}
				}
			}
		}
	}


int main()
{
     Game game;
     game.playGame();
}