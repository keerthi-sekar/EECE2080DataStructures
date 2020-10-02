

#include "SomeThing.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

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
	//std::cout << "    Calling Move Constructor" << std::endl;
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
			m_deck.push_back(std::move(card));
			count++;
		}

		count = 1;

		while (i == 1 && count != 14)
		{
			Card card(count, i);
			m_deck.push_back(std::move(card));
			count++;
		}

		count = 1;

		while (i == 2 && count != 14)
		{
			Card card(count, i);
			m_deck.push_back(std::move(card));
			count++;
		}

		count = 1;

		while (i == 3 && count != 14)
		{
			Card card(count, i);
			m_deck.push_back(std::move(card));
			count++;
		}
	}

		/*for(int i = 0; i < m_deck.size() - 1; i++)
			{
				std::list<Card>::iterator it1 = m_deck.begin();
				std::list<Card>::iterator it2 = m_deck.begin();
				std::advance(it1, i);
				int j = i + rand() % (m_deck.size() - i);
				std::advance(it2, j);
				Card temp1 = std::move(*it1);
				Card temp2 = std::move(*it2);
				m_deck.insert(std::move(it2), temp1);
				m_deck.insert(std::move(it1), temp2);
				m_deck.erase(std::move(it1));
				m_deck.erase(std::move(it2));
			}*/
}

Deck::~Deck()
{
	//Do nothing for now
}

std::list<Card> Deck::GetDeck() { return m_deck; }

void Deck::Deal(Person &player)
{
	for (int i = 0; i < 5; i++)
	{
		player.m_handOfCards.push_back(std::move(m_deck.back()));
		m_deck.pop_back();
	}
}

bool Deck::Draw(Person &player)
{
	if (player.m_handOfCards.size() < 6)
	{
		player.m_handOfCards.push_back(std::move(m_deck.back()));
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

std::list<Card> Person::GetCardsInHand() { return m_handOfCards; }

/*void AddCardToHandObject4(Card  &c)
	{
		std::cout<<"   AddCardToHandObject4 :"<<c.GetValue()<<" "<<c.GetSuit()<<std::endl;
		//m_listOfCardsObject.push_front(std::move(c));
	}*/

bool Person::AddCardToStack(unsigned x)
{
	std::list<Card>::iterator it = m_handOfCards.begin();
	std::advance(it, x - 1);
	Card temp = std::move(*it);
	if (temp.GetValue() == m_stackOfCards.back().GetValue() + 1)
	{
		m_stackOfCards.push_back(std::move(temp));
		m_handOfCards.erase(std::move(it));
		return true;
	}
	else
	{
		std::cout << "Invalid move: Incorrect order in player stack." << std::endl;
		return false;
	}
}

void Person::Discard(Deck &deck, int x)
{
	std::list<Card>::iterator it = m_handOfCards.begin();
	std::advance(it, x);
	Card temp = std::move(*it);
	deck.m_deck.insert(std::move(deck.m_deck.begin()), temp);
	m_handOfCards.erase(std::move(it));
}

void Person::Mulligan(Deck &deck)
{
	std::list<Card>::iterator it = m_handOfCards.begin();
	for (int i = 0; i < m_handOfCards.size() - 1; i++)
	{
		it = m_handOfCards.begin();
		std::advance(it, i);
		Card temp = std::move(*it);
		deck.m_deck.insert(std::move(deck.m_deck.begin()), temp);
		m_handOfCards.erase(std::move(it));
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

	bool gameEnded = false;
	std::list<Card>::iterator it1 = player1.m_handOfCards.begin();
	std::list<Card>::iterator it2 = player2.m_handOfCards.begin();

	while (gameEnded == false)
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
			std::cout << "Player 1 begins and draws a card." << std::endl;
			deck1.Draw(player1);

		bool turnEnd = false;
		while (!turnEnd)
		{
			std::cout << "These are the cards in your hand: " << std::endl;
			for (int i = 0; i < player1.m_handOfCards.size() - 1; i++)
			{
				it1 = player1.m_handOfCards.begin();
				std::advance(it1, i);
				Card temp = std::move(*it1);
				std::cout << temp.GetValue() << ", ";
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
					it1 = player1.m_handOfCards.begin();
					std::advance(it1, i);
					Card temp = std::move(*it1);
					std::cout << temp.GetValue() << ", ";
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
				std::list<Card>::iterator it3 = player1.m_stackOfCards.begin();
				for (int i = 0; i < player1.m_handOfCards.size() - 1; i++)
				{
					it1 = player1.m_handOfCards.begin();
					std::advance(it1, i);
					Card tempCard = std::move(*it1);
					int temp = tempCard.GetValue();
					if (player1.m_stackOfCards.size() == 0)
					{
						it3 = player1.m_stackOfCards.begin();
						Card tempCard0 = std::move(*it3);
						if (temp == tempCard0.GetValue() + 1)
						{
							noPlays = false;
						}
					}
					else
					{
						for (int i = 0; i < player1.m_stackOfCards.size() - 1; i++)
						{
							it3 = player1.m_stackOfCards.begin();
							std::advance(it3, i);
							Card tempCard2 = std::move(*it3);
							if (temp == tempCard2.GetValue() + 1)
							{
								noPlays = false;
							}
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
		}

		std::cout << "Player 2 begins their turn." << std::endl;
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
			std::cout << "Player 2 begins and draws a card." << std::endl;
			deck1.Draw(player2);
		

		bool turnEnd = false;
		while (!turnEnd)
		{
			std::cout << "These are the cards in your hand: " << std::endl;
			for (int i = 0; i < player2.m_handOfCards.size() - 1; i++)
			{
				it2 = player2.m_handOfCards.begin();
				std::advance(it2, i);
				Card temp = std::move(*it2);
				std::cout << temp.GetValue() << ", ";
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
					it2 = player2.m_handOfCards.begin();
					std::advance(it2, i);
					Card temp = std::move(*it2);
					std::cout << temp.GetValue() << ", ";
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
				std::list<Card>::iterator it4 = player2.m_stackOfCards.begin();
				for (int i = 0; i < player2.m_handOfCards.size() - 1; i++)
				{
					it2 = player2.m_handOfCards.begin();
					std::advance(it2, i);
					Card tempCard = std::move(*it2);
					int temp = tempCard.GetValue();
					for (int i = 0; i < player2.m_stackOfCards.size() - 1; i++)
					{
						it4 = player2.m_stackOfCards.begin();
						std::advance(it4, i);
						Card tempCard2 = *it4;
						if (temp == tempCard2.GetValue() + 1)
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
}
