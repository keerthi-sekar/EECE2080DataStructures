#include "PriorityQueue.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

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


int main()
{
	//initialize datasets
	int dataset500[500];
	int dataset1000[1000];
	int dataset2000[2000];
	int dataset5000[5000];

    InitializeArray(dataset500, 500);
    InitializeArray(dataset1000, 1000);
    InitializeArray(dataset2000, 2000);
    InitializeArray(dataset5000, 5000);
    
    //Insert ArrayBased
	auto t1 = Clock::now();
	ArrayBasedQueue data1(500);
    for(int i = 0; i < 500; i++)
    {
        data1.Insert(dataset500[i], i);
    }
	auto t2 = Clock::now();
	cout << "Insert ArrayBasedQueue 500" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;

	t1 = Clock::now();
	ArrayBasedQueue data2(1000);
    for(int i = 0; i < 1000; i++)
    {
        data2.Insert(dataset1000[i], i);
    }
	t2 = Clock::now();
	cout << "Insert ArrayBasedQueue 1000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
    
	t1 = Clock::now();
	ArrayBasedQueue data3(2000);
    for(int i = 0; i < 2000; i++)
    {
        data3.Insert(dataset2000[i], i);
    }
	t2 = Clock::now();
	cout << "Insert ArrayBasedQueue 2000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
    
	t1 = Clock::now();
	ArrayBasedQueue data4(5000);
    for(int i = 0; i < 5000; i++)
    {
        data4.Insert(dataset5000[i], i);
    }
	t2 = Clock::now();
	cout << "Insert ArrayBasedQueue 5000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
    //Delete ArrayBased
    for(int i = 0; i < 500; i++)
    {
        data1.Remove();
    }
	t2 = Clock::now();
	cout << "Delete ArrayBasedQueue 500" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();	  
    for(int i = 0; i < 1000; i++)
    {
        data2.Remove();
    }
	t2 = Clock::now();
	cout << "Delete ArrayBasedQueue 1000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
    for(int i = 0; i < 2000; i++)
    {
        data3.Remove();
    }
	t2 = Clock::now();
	cout << "Delete ArrayBasedQueue 2000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
    for(int i = 0; i < 5000; i++)
    {
        data4.Remove();
    }
	t2 = Clock::now();
	cout << "Delete ArrayBasedQueue 5000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;


    //Insert Heap
	t1 = Clock::now();
	Heap data5;
    for(int i = 0; i < 500; i++)
    {
        data5.Insert(dataset500[i]);
    }
	t2 = Clock::now();
	cout << "Insert Heap 500" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
	Heap data6;
    for(int i = 0; i < 1000; i++)
    {
        data6.Insert(dataset1000[i]);
    }
	t2 = Clock::now();
	cout << "Insert Heap 1000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
    Heap data7;
    for(int i = 0; i < 2000; i++)
    {
        data7.Insert(dataset2000[i]);
    }
	t2 = Clock::now();
	cout << "Insert Heap 2000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
    Heap data8;
    for(int i = 0; i < 5000; i++)
    {
        data8.Insert(dataset5000[i]);
    }
	t2 = Clock::now();
	cout << "Insert Heap 5000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();
    //Delete Heap
    for(int i = 0; i < 500; i++)
    {
        data5.Remove(i);
    }
	t2 = Clock::now();
	cout << "Delete Heap 500" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();	  
    for(int i = 0; i < 1000; i++)
    {
        data6.Remove(i);
    }
	t2 = Clock::now();
	cout << "Delete Heap 1000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();	
    for(int i = 0; i < 2000; i++)
    {
        data7.Remove(i);
    }
	t2 = Clock::now();
	cout << "Delete Heap 2000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
	
	t1 = Clock::now();	
    for(int i = 0; i < 5000; i++)
    {
        data8.Remove(i);
    }
	t2 = Clock::now();
	cout << "Delete Heap 5000" << endl;
	std::cout << "Delta t2 - t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanosecond" << std::endl;
			  
    return 0;
}
