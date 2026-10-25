#include <iostream>
#include "searchingAlgo.h"

int main() {
    
    int prob1Arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14}; 
    int size1 = 10;
    int key1 = 18; 

    Node<int> *head = new_node(prob1Arr[0]);
    Node<int> *current = head; 
    for (int i = 1; i < size1; i++) { 
        current->next = new_node(prob1Arr[i]); 
        current = current->next; 
    }

    
    linearSearchAR(size1, key1, prob1Arr);
    linearSearchLL(head, key1);

    
    countOccurrencesAR(size1, key1, prob1Arr); 
    countOccurrencesLL(head, key1); 

    
    int prob3Arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18}; 
    int size3 = 10; 
    int key3 = 8; 

    
    binarySearchArr(prob3Arr, size3, key3);

    
    binarySearchRecursive(prob3Arr, 0, size3 - 1, key3);

    return 0;
}