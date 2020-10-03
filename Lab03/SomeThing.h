// TODO standard classes to be tested should be defined
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include <algorithm>
#include <random>

class Person;
class Card
{
    public: 
    Card(int value, int suit);
     ~Card();
    Card(const Card &c);
    Card(Card &&obj);
    int GetValue() const;
    int GetSuit() const;
   

    private:
    int m_value;
	int m_suit;
	int m_guid;
};

class Deck
{
    public:
    Deck();
    ~Deck();
    void Deal(Person &player);
    bool Draw(Person &player);
    std::list<Card> GetDeck();

    private:
	std::list<Card> m_deck;
	friend class Game;
	friend class Person;
};

class Person
{
    public:
    Person(std::string name);
    ~Person();
    std::string const GetName();
    bool AddCardToStack(unsigned x);
    void Discard(Deck &deck, int x);
    void Mulligan(Deck &deck);
    std::list<Card> GetCardsInHand();

    private:
    std::string m_name;

	std::list<Card> m_handOfCards;
	std::list<Card> m_stackOfCards;

    friend class Deck;
	friend class Game;
};

class Game
{
    public:
    Game();
    ~Game();
    void playGame();

    private:

};