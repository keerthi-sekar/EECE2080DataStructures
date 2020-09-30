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
    Card(Card& c);
    Card(Card&& obj);
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
    bool Deal(Person player);
    bool Draw(Person player);

    private:
	std::vector<Card> m_deck;
	friend class Game;
	friend class Person;
};

class Person
{
    public:
    Person(std::string name);
    ~Person();
    std::string const GetName();
    bool AddCardToStack(int x);
    void Discard(Deck deck, int x);
    void Mulligan(Deck deck);

    private:
    std::string m_name;

	std::vector<Card> m_handOfCards;
	std::vector<Card> m_stackOfCards;

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