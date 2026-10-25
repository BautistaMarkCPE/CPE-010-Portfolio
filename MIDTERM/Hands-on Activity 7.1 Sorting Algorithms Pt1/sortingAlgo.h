#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <cstddef>
#include <utility>

template <typename T>
void bubbleSort(T arr[], size_t arrSize){
    for(size_t i = 0; i < arrSize - 1; i++){
        for(size_t j = 0; j < arrSize - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
int routineSmallest(T arr[], int K, const int arrSize){
    int position = K; 
    T smallestElem = arr[K];

    for(int j = K + 1; j < arrSize; j++){
        if(arr[j] < smallestElem){
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], size_t arrSize){
    int POS, temp, pass = 0;
    for(size_t i = 0; i < arrSize; i++){
        POS = routineSmallest(arr, static_cast<int>(i), static_cast<int>(arrSize));
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        pass++;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize){
    int K = 1, J, temp; 

    while(K < static_cast<int>(arrSize)){
        temp = arr[K];
        J = K - 1;

        while(J >= 0 && temp < arr[J]){
            arr[J + 1] = arr[J];
            J--;
        }

        arr[J + 1] = temp;
        K++;
    }
}

#endif