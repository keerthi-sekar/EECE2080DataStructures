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

void Merge(int currentDataset[], int left, int m, int right)
{
	int n1, n2;
	n1 = m - left + 1;
	n2 = right - m;
	
	//temp arrays
	int L[n1], R[n2];

	//copy data to temps
	for(int i = 0; i < n1; i++)
	{
		L[i] = currentDataset[left + i];
	}
	for(int j = 0; j < n2; j++)
	{
		R[j] = currentDataset[m + 1 + j];
	}

	//Initial Index subarrays
	int i = 0;
	int j = 0;
	int k = left;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			currentDataset[k] = L[i];
			i++;
		}
		else
		{
			currentDataset[k] = R[j];
			j++;
		}
		k++;
	}

	//Copy rest of the L array if any
	while(i < n1)
	{
		currentDataset[k] = L[i];
		i++;
		k++;
	}

	//copy rest of R array
	while(j < n2)
	{
		currentDataset[k] = R[j];
		j++;
		k++;
	}

}

int Split(int currentDataset[], int start, int end)
{
    int i = (start - 1);
    int pivot = currentDataset[end];

    for(int j = start; j <= (end - 1); j++)
    {
        if(currentDataset[j] < pivot)
        {
            i++;
            swap(currentDataset[i], currentDataset[j]);
        }
    }

    swap(currentDataset[i+1], currentDataset[end]);
    return (i + 1);
}

//Referenced Textbook and slides
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
}

void InsertionSort(int currentDataset[], int arraySize)
{
	int i, j;
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
		currentDataset[j+1] = ref;
	}
}

//looked at textbook and tutorialspoint for help
void MergeSort(int currentDataset[], int left, int right)
{
	int m;
	if(left < right)
	{
		int m = (left + (right-1))/2;

		MergeSort(currentDataset, left, m);
		MergeSort(currentDataset, m+1, right);

		Merge(currentDataset, left, m, right);
	}
}

//looked at GeeksforGeeks for refernce 
void QuickSort(int currentDataset[], int start, int end)
{
    if(start < end)
    {
        int index = Split(currentDataset, start, end);

        QuickSort(currentDataset, start, index - 1);
        QuickSort(currentDataset, index + 1, end);
    }
}


int FindMax(int currentDataset[], int arraySize)
{
	int max = currentDataset[0];

	for(int i = 1; i < arraySize; i++)
	{
		if(currentDataset[i] > max)
		{
			max = currentDataset[i];
		}
	}

	return max;
}

void CountSort(int currentDataset[], int arraySize, int exp)
{
	int output[arraySize];
	int i, count[10] = {0};

	for(int i = 0; i < arraySize; i++)
	{
		count[(currentDataset[i]/exp) % 10]++;
	}
	for(int i = 1; i < 10; i++)
	{
		count[i] += count[i-1];
	}
	for(int i = arraySize-1; i >= 0; i--)
	{
		output[count[(currentDataset[i]/exp) % 10] - 1] = currentDataset[i];
		count[(currentDataset[i]/exp) % 10]--;
	}
	for(int i = 0; i < arraySize; i++)
	{
		currentDataset[i] = output[i];
	}
}

//Going to be honest, referred to geeksforgeeks for this one
void RadixSort(int currentDataset[], int arraySize)
{
	int max = FindMax(currentDataset, arraySize);

	for(int exp = 1; (max/exp) > 0; exp *=10)
	{
		CountSort(currentDataset, arraySize, exp);
	}
}

void ResetArrays(int dataset10[], int dataset100[], int dataset500[], int dataset5000[], int dataset25000[])
{
	InitializeArray(dataset10, 10);
	InitializeArray(dataset100, 100);
	InitializeArray(dataset500, 500);
	InitializeArray(dataset5000, 5000);
	InitializeArray(dataset25000, 25000);
}

int main()
{
	//initialize datasets
	int dataset10[10];
	int dataset100[100];
	int dataset500[500];
	int dataset5000[5000];
	int dataset25000[25000];

	//put random numbers in each array, duplicate numbers may occur
	ResetArrays(dataset10, dataset100, dataset500, dataset5000, dataset25000);

	BubbleSort(dataset10, 10);
	BubbleSort(dataset100, 100);
	BubbleSort(dataset500, 500);
	BubbleSort(dataset5000, 5000);
	BubbleSort(dataset25000, 25000);

	cout << "Finished Bubble Sort" << endl;

	ResetArrays(dataset10, dataset100, dataset500, dataset5000, dataset25000);

	InsertionSort(dataset10, 10);
	InsertionSort(dataset100, 100);
	InsertionSort(dataset500, 500);
	InsertionSort(dataset5000, 5000);
	InsertionSort(dataset25000, 25000);
	
	cout << "Finished Insertion Sort" << endl;

	ResetArrays(dataset10, dataset100, dataset500, dataset5000, dataset25000);

	MergeSort(dataset10, 0, 9);
	MergeSort(dataset100, 0, 99);
	MergeSort(dataset500, 0, 499);
	MergeSort(dataset5000, 0, 4999);
	MergeSort(dataset25000, 0, 24999);
	
	cout << "Finished Merge Sort" << endl;

	ResetArrays(dataset10, dataset100, dataset500, dataset5000, dataset25000);

	QuickSort(dataset10, 0, 10);
	QuickSort(dataset100, 0, 100);
	QuickSort(dataset500, 0, 500);
	QuickSort(dataset5000, 0, 5000);
	QuickSort(dataset25000, 0, 25000);
	
	cout << "Finished Quick Sort" << endl;

	ResetArrays(dataset10, dataset100, dataset500, dataset5000, dataset25000);

	RadixSort(dataset10, 10);
	RadixSort(dataset100, 100);
	RadixSort(dataset500, 500);
	RadixSort(dataset5000, 5000);
	RadixSort(dataset25000, 25000);
	
	cout << "Finished Radix Sort" << endl;
	
	PrintArray(dataset100, 100);
    return 0;
}

