/*
main.cpp: Since  the purpose of this lab is to give a proof of concept for each sorting method, the lab is set up in a functional program method.
		  The lab functionality is simple enough that it doesn't really require a lengthy class setup.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int RandomNumber()
{
	return (rand()%100) + 1;
}

void InitializeArray(int currentDataset[], int arraySize)
{
	for(int i = 0; i < arraySize; i++)
	{
		currentDataset[i] = RandomNumber();
	}

	cout << "Filled array!" << endl;
}

int main()
{
	//initialize datasets
	int dataset10[10];
	int dataset100[100];
	int dataset500[500];
	int dataset5000[5000];
	int dataset25000[25000];

	//put random numbers in each one, duplicate numbers may occur
	InitializeArray(dataset10, 10);
	InitializeArray(dataset100, 100);
	InitializeArray(dataset500, 500);
	InitializeArray(dataset5000, 5000);
	InitializeArray(dataset25000, 25000);

	//testing purposes only *remove before submission
	for(int i = 0; i < 10; i++)
	{
		cout << dataset10[i] << endl;
	}


	

    return 0;
}

