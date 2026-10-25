#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int SIZE = 100;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}

void copyArray(const int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int originalDataset[SIZE];
    int testArray[SIZE];

    srand(time(0));
    std::cout << "Original Unsorted Dataset: \n";
    for (int i = 0; i < SIZE; i++) {
        originalDataset[i] = rand() % 100; 
    }
    printArray(originalDataset, SIZE);

    copyArray(originalDataset, testArray, SIZE);
    shellSort(testArray, SIZE);
    std::cout << "Shell Sort Result:\n";
    printArray(testArray, SIZE);

    copyArray(originalDataset, testArray, SIZE);
    mergeSort(testArray, 0, SIZE - 1);
    std::cout << "Merge Sort Result: \n";
    printArray(testArray, SIZE);

    copyArray(originalDataset, testArray, SIZE);
    quickSort(testArray, 0, SIZE - 1);
    std::cout << "Quick Sort Result: \n";
    printArray(testArray, SIZE);

    std::cout << "Problem 1: Hybrid Quick Sort\n";

    int prob1Array[] = {48, 12, 87, 34, 4, 53, 29};
    int prob1Size = 7;

    std::cout << "Before Hybrid Quick Sort: ";
    printArray(prob1Array, prob1Size);
    
    hybridQuickSort(prob1Array, 0, prob1Size - 1);

    std::cout <<"After Hybrid Quick Sort: ";
    printArray(prob1Array, prob1Size);
    
    return 0;
}