
#include <iostream>
#include <string>
#include <list>


static int guid = 1;

class Card

{

	public:
		Card(int value, int suit):m_value(value), m_suit(suit)
		{
			m_guid = guid;
			guid++;
		}
		virtual ~Card() {}

		Card( const Card &c)
		{
			std::cout<<"    BAD!!!! Copy Constructor being called.  I shouldn't really be callled!!!"<<std::endl;
			m_value = c.m_value;
			m_suit = c.m_suit;
			m_guid = guid;
			guid++;
		}

		int GetValue() const {return m_value;}
		int GetSuit() const {return m_suit;}


		Card(Card && obj)
		{
			std::cout <<"    Calling Move Constructor"<<std::endl;
			this->m_value = obj.m_value;
			this->m_suit = obj.m_suit;
			m_guid = obj.m_guid;
		}




	private:
		int m_value;
		int m_suit;
		int m_guid;
		Card(); // no default constructor


};



class Person
{
public:
	Person(std::string name) :m_name(name)
	{

	}

	std::string GetName() const
	{
		return m_name;
	}

	virtual ~Person()
	{
		std::cout << "Deleting " << m_name << std::endl;
	}

	void AddCardToHandPointer( Card * c)  
	{
		std::cout<<"   AddCardToHandPointer :"<<c->GetValue()<<" "<<c->GetSuit()<<std::endl;
		m_listOfCardsPointer.push_front(c);
	}

	void AddCardToHandObject1( Card  c)
	{
		std::cout<<"   AddCardToHandObject1 :"<<c.GetValue()<<" "<<c.GetSuit()<<std::endl;
		m_listOfCardsObject.push_front(c);
	}

	void AddCardToHandObject2( Card  c)
	{
		std::cout<<"   AddCardToHandObject2 :"<<c.GetValue()<<" "<<c.GetSuit()<<std::endl;
		m_listOfCardsObject.push_front(std::move(c));
	}

	void AddCardToHandObject3(Card  &c)
	{
		std::cout<<"   AddCardToHandObject3 :"<<c.GetValue()<<" "<<c.GetSuit()<<std::endl;
		m_listOfCardsObject.push_front(c);
	}

	void AddCardToHandObject4(Card  &c)
	{
		std::cout<<"   AddCardToHandObject4 :"<<c.GetValue()<<" "<<c.GetSuit()<<std::endl;
		m_listOfCardsObject.push_front(std::move(c));
	}


public: /// to illistrate a point making it public shoudl be private
	std::string m_name;
	std::list< Card *> m_stackOfCardsPointer;
	std::list< Card *> m_listOfCardsPointer;

	std::list< Card > m_stackOfCardsObject;
	std::list< Card > m_listOfCardsObject;



};

class Game
{
public:
	Game()
	{
		m_player1 = new Person("Player1");
		m_player2 = new Person("Player2");

		// For create the Cards in the masterCardList, and then seed the 
		// community deck
		// See - http://www.cplusplus.com/reference/cstdlib/rand/ for ideas of how to pick random
		// numbers

	}

	~Game()
	{
		delete m_player1;
		delete m_player2;
		
		//do a for each on masterCard list and delete the Cards

	}

private:
	Person * m_player1;
	Person * m_player2;

	std::list<Card *> m_masterCardList;  // Note not a const, as this is where we will
	// delete the memory


};


int main()
{
	
	Person * p1 = new Person("Huey 1");
	Person * p2 = new Person("Louie 2");
	Person * p3 = new Person("Dewey 3");

	Card * card1Pointer = new Card(1,1);
	Card * card2Pointer = new Card(1,2);
	std::cout<<"Calling Pointer Version"<<std::endl;
	p1->AddCardToHandPointer(card1Pointer);
	p1->AddCardToHandPointer(card2Pointer);
	std::cout<<"End Calling Pointer Version"<<std::endl;
	
	std::cout<<std::endl<<std::endl;

	Card card1Object = Card(1,1);
	std::cout<<"Calling Object Version1"<<std::endl;
	p1->AddCardToHandObject1(card1Object);
	std::cout<<"End Calling Object Version1"<<std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"Calling Object Version2"<<std::endl;
	p1->AddCardToHandObject2(card1Object);
	std::cout<<"End Calling Object Version2"<<std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"Calling Object Version3"<<std::endl;
	p1->AddCardToHandObject3(card1Object);
	std::cout<<"End Calling Object Version3"<<std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"Calling Object Version4"<<std::endl;
	p1->AddCardToHandObject4(card1Object);
	std::cout<<"End Calling Object Version4"<<std::endl;
	std::cout<<std::endl<<std::endl;



	std::cout<<"Stack\n";
    std::list<const Person *> stackOfPeople;
	std::cout<<"   Push "<<p1->GetName()<<std::endl;
	stackOfPeople.push_front(p1);
	std::cout<<"   Push "<<p2->GetName()<<std::endl;
	stackOfPeople.push_front(p2);
	std::cout<<"   Push "<<p3->GetName()<<std::endl;
	stackOfPeople.push_front(p3);

	for (const Person* p : stackOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	} 
	std::cout <<  std::endl;

    std::cout<<"Queue\n";
	std::list<const Person *> queueOfPeople;

	std::cout<<"   Enque "<<p1->GetName()<<std::endl;
	queueOfPeople.push_back(p1);
	std::cout<<"   Enque "<<p2->GetName()<<std::endl;
	queueOfPeople.push_back(p2);
	std::cout<<"   Enque "<<p3->GetName()<<std::endl;
	queueOfPeople.push_back(p3);

	for (const Person* p : queueOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}

	std::cout << "calling pop and Dequee" << std::endl;
	stackOfPeople.pop_front();
	queueOfPeople.pop_front();

	std::cout << "Stack" << std::endl;
	for (const Person* p : stackOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Queue" << std::endl;
	for (const Person* p : queueOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}

	std::cout << "calling clear methods" << std::endl;
	stackOfPeople.clear();
	queueOfPeople.clear();
	std::cout << "calling delete" << std::endl;
	delete p1;
	delete p2;
	delete p3;




    return 0;
}

