#include "PriorityQueue.h"

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
}

int main()
{
	//initialize datasets
	int dataset500[500];
	int dataset1000[1000];
	int dataset2000[2000];
	int dataset5000[5000];

    return 0;
}

