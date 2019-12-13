/**
* Title : Algorithm Efficiency and Sorting
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 1
* Description : A program to initialize functions of
* sorting algorithms and their time analysis
*/



#include <bits/stdc++.h>
#include "sorting.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

void sorting::swapInteger(int& a, int& b, int& moveCount) {
    int temp = a;
    a = b;
    b = temp;
    moveCount = moveCount + 3;
}
int sorting:: partition(int* arr, int first, int last, int &compCount, int &moveCount) {
	// place pivot in theArray[first]
   int pivot = arr[first];
   moveCount++;
	// initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {

      // move item from unknown to proper region
      compCount++;
      if (arr[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swapInteger(arr[firstUnknown], arr[lastS1], moveCount);
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swapInteger(arr[first], arr[lastS1], moveCount);
   return lastS1;
}
void sorting::quickSort(int* arr, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

    if (first < last) {

      // create the partition: S1, pivot, S2
      pivotIndex = partition(arr, first, last, compCount, moveCount);

      // sort regions S1 and S2
      quickSort(arr, first, pivotIndex-1, compCount, moveCount);
      quickSort(arr, pivotIndex+1, last, compCount, moveCount);
   }
}
void sorting::insertionSort(int *arr, int n, int &compCount, int &moveCount) {
    for ( int unsorted = 1; unsorted < n; unsorted++){
    int nextItem = arr[unsorted];
    moveCount++;
    int loc = unsorted;
    compCount++; // for checking while loop if condition is not true
        while ((loc > 0) && (arr[loc - 1] > nextItem)){
                compCount++;
                arr[loc] = arr[loc - 1];
                moveCount++;
                loc--;
        }
        // At this point, theArray[loc] is where nextItem belongs
    arr[loc] = nextItem; // Insert nextItem into sorted region
    moveCount++;
 }
}
void sorting::hybridSort(int* arr, int n, int &compCount, int &moveCount ) {
	hybridSort2(arr, 0, n-1, compCount, moveCount);
	}

void sorting::hybridSort2(int *arr, int first, int last, int &compCount, int &moveCount) {
    if(last-first < 10) {
        insertionSort(arr, last-first, compCount, moveCount);
    }
    else {
			//Quicksort if n >= 10
        int pivotIndex = partition(arr, first, last, compCount, moveCount);
        hybridSort2(arr, first, pivotIndex-1, compCount, moveCount);
        hybridSort2(arr, pivotIndex+1, last, compCount, moveCount);
    }
}
void sorting::printArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    }

void sorting::performanceAnalysis() {
    // To store elapsed time
    double quick[10];
    double insertion[10];
    double hybrid[10];
    // Declare necessary variables
	int compCount = 0;
	int moveCount = 0;

    //To store comparison and move counts
    int compQuick[10];
    int moveQuick[10];
    int compInsertion[10];
    int compHybrid[10];
    int moveInsertion[10];
    int moveHybrid[10];

    int n = 1500;
    int sizeCount = 0;
    while ( n <= 15000) {
        int arr1[n];
        for (int i = 0; i < n; i++) {
            arr1[i] = rand();
        }
        int arr2[n];
        int arr3[n];
        //Copying elements of first to two other arrays
        for(int i = 0; i < n; i++) {
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
        chrono::time_point< chrono::system_clock > startTime;
        chrono::duration< double, milli > elapsedTime;
        //Time Analysis For Quick Sort
        startTime = chrono::system_clock::now();
        quickSort(arr1, 0, n, compCount, moveCount);
        elapsedTime = chrono::system_clock::now() - startTime;
        compQuick[sizeCount] = compCount;
        moveQuick[sizeCount] = moveCount;
        quick[sizeCount] = elapsedTime.count();
        // Declare necessary variables
        compCount = 0;
        moveCount = 0;
        //Time Analysis For Insertion Sort
        startTime = chrono::system_clock::now();
        insertionSort(arr2, n, compCount, moveCount);
        elapsedTime = chrono::system_clock::now() - startTime;
        compInsertion[sizeCount] = compCount;
        moveInsertion[sizeCount] = moveCount;
        insertion[sizeCount] = elapsedTime.count();
        // Declare necessary variables
        compCount = 0;
        moveCount = 0;
         //Time Analysis For Hybrid Sort
        startTime = chrono::system_clock::now();
        hybridSort(arr3, n, compCount, moveCount);
        elapsedTime = chrono::system_clock::now() - startTime;
        compHybrid[sizeCount] = compCount;
        moveHybrid[sizeCount] = moveCount;
        hybrid[sizeCount] = elapsedTime.count();
        // Declare necessary variables
        compCount = 0;
        moveCount = 0;
        n = n +1500;
        sizeCount++;
    }

        //Print the list of time analysis
        n = 1500;
        cout << "-----------------------------------------------------"<<endl;
        cout << "Part a - Time analysis of Quick Sort" << endl;
        cout << "Array Size     Time Elapsed    compCount       moveCount" << endl;
        for (int i = 0; i < 10; i++) {
            //Print table
            cout << n << "\t\t" << quick[i] << "\t\t" << compQuick[i] << "\t\t" << moveQuick[i] << endl;
            n += 1500;
        }
        cout << "-----------------------------------------------------"<<endl;
        n = 1500;
        cout << "Part b - Time analysis of Insertion Sort" << endl;
        cout << "Array Size     Time Elapsed    compCount       moveCount" << endl;
        for (int i = 0; i < 10; i++) {
            cout << n << "\t\t" << insertion[i] << "\t\t" << compInsertion[i];
            std::cout.width(15); std::cout << std::right << moveInsertion[i] << '\n';
            n += 1500;
        }
        n = 1500;
        cout << "-----------------------------------------------------"<<endl;
        cout << "Part c - Time analysis of Hybrid Sort" << endl;
        cout << "Array Size     Time Elapsed    compCount       moveCount" << endl;
        for ( int i = 0; i <10; i++) {
            cout << n << "\t\t" << hybrid[i] << "\t\t" << compHybrid[i];
            std::cout.width(15); std::cout << std::right << moveHybrid[i] << '\n';
            n += 1500;
        }
        cout << "-----------------------------------------------------"<<endl;
    }


