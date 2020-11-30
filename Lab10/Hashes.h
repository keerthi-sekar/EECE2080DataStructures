#include <cstddef>
#include <iostream>

using namespace std;

template <typename key, typename value>

class HNode
{
	public:
 	key key1;
	value value1;

	HNode(key key1, value value1)
	{
		this->key1 = key1;
		this->value1 = value1;
	}
};

template<typename key, typename value>

class Hash
{
	HNode<key,value> **array;
	int capacity;
	int size;

	public:
	Hash(int c = 100)
	{
		capacity = c;
		size = 0;

		array = new HNode<key, value>*[capacity];

		for (int i = 0; i < capacity; i++)
		{
			array[i] = NULL;
		}
	}

	int getIndex(key key1)
	{
		return key1 % capacity;
	}

	void AddItem(key key1, value value1)
	{
		HNode<key, value> *t = new HNode<key, value>(key1, value1);

		int index = getIndex(key1);
		
		while(array[index] != NULL && array[index]->key1 != key1 && array[index]-> key1 != -1)
		{
			index++;
			index %= capacity;
		}

		if(array[index] == NULL || array[index]->key1 == -1) 
		{
			size++;
			array[index] = t;
		}
	}

	value GetItem(int key1)
	{
		int index = getIndex(key1);
		int count = 0;

		while(array[index] != NULL)
		{
			count = 0;
			if(count++ > capacity)
			{
				return NULL;
			}

			if(array[index]->key1 == key1 )
			{
				return array[index]->value1;
				index++;
				index %= capacity;
			}

			return NULL;
		}
	}

	int getItems()
	{
		return size;
	}

	void PrintMap()
	{
		for(int i = 0 ; i < capacity ; i++) 
        { 
            if(array[i] != NULL && array[i]->key1 != -1) 
			{
                cout << "key = " << array[i]->key1 <<"  value = "<< array[i]->value1 << endl; 
			}
        } 
	}

};








