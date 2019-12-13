/**
* Title : Algorithm Efficiency and Sorting
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 1
* Description : A main program to test
* sorting algorithms and their time analysis
*/




#include "sorting.h"
#include <iostream>

main() {
    sorting sorting;
    int arr1[] = {22, 11, 6, 7, 30, 2, 27, 24, 9, 1, 20, 17};
    int arr2[12];
    int arr3[12];
    //Copying elements of first to two other arrays
    for(int i = 0; i < 12; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    int compCount = 0;
    int moveCount = 0;
    //Using sorting algorithms to arrays
    sorting.quickSort(arr1, 0, 11, compCount, moveCount);
    sorting.printArray(arr1, 12 );
    sorting.insertionSort(arr2,12,compCount,moveCount);
    sorting.printArray(arr2, 12);
    sorting.hybridSort(arr3, 12, compCount, moveCount);
    sorting.printArray(arr3,12);
    //Performance analysis for sorting algorithms
    sorting.performanceAnalysis();

}
