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
}

void PrintArray(int currentDataset[], int arraySize)
{
	for(int i=0; i < arraySize; i++)
	{
		cout << currentDataset[i] << endl;
	}
}

//Use pointers to reduce copies for larger arrays
void Swap(int *first, int *last)
{
	int temp = *first;
	*first = *last;
	*last = temp;
}

//Referenced geeksforgeeks code for implementation
void BubbleSort(int currentDataset[], int arraySize)
{
	for(int i = 0; i < arraySize-1; i++)
	{
		for(int j = 0; j < arraySize-i-1; j++)
		{
			if(currentDataset[j] > currentDataset[j+1])
			{
				Swap(&currentDataset[j], &currentDataset[j+1]);
			}
		}
	}
	cout << "Bubble sort for array size of: " << arraySize << endl;
}

//TODO: Fix Segmentation Fault (core dumped)
void InsertionSort(int currentDataset[], int arraySize)
{
	unsigned int i, j;
	int ref;

	for(i = 1; i  < arraySize; i++)
	{
		ref = currentDataset[i];
		j = i-1;

		while(j >= 0 && currentDataset[j] > ref)
		{
			currentDataset[j+1] = currentDataset[j];
			j = j-1;
		}
		currentDataset[j-1] = ref;
	}
}

/*void MergeSort(int currentDataset[], int arraySize)
{

}*/

/*void QuickSort(int currentDataset[], int arraySize)
{

}
*/
/*
void RadixSort(int currentDataset[], int arraySize)
{

}
*/
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
	/*InitializeArray(dataset100, 100);
	InitializeArray(dataset500, 500);
	InitializeArray(dataset5000, 5000);
	InitializeArray(dataset25000, 25000);*/

	/*BubbleSort(dataset10, 10);
	BubbleSort(dataset100, 100);
	BubbleSort(dataset500, 500);
	BubbleSort(dataset5000, 5000);
	BubbleSort(dataset25000, 25000);*/

	//InsertionSort(dataset10, 10);

	PrintArray(dataset10, 10);

    return 0;
}

