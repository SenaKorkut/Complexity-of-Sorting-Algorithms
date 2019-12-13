/**
* Title : Algorithm Efficiency and Sorting
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 1
* Description : A header file to declare sorting functions
* and its necessary sub functions
*/


#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <iostream>
class sorting {

    public:
    void swapInteger(int& a, int& b, int& moveCount);
    int partition(int* arr, int first, int last, int&, int&);
    void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);
    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void hybridSort2(int *arr, int first, int last, int &compCount, int &moveCount);
    void hybridSort(int* arr, int size, int &compCount, int &moveCount);
    void printArray(int *arr, int size);
    void performanceAnalysis();
};

#endif // SORTING_H_INCLUDED
