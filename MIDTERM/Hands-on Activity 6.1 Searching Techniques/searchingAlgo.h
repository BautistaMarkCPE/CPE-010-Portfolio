#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    int i= 0;
    while(i < size){
        if(dataFind == array[i]){
            std::cout<<"Searching is Successful\n";
            return;
        }
        i++;
    }
    std::cout<<"Searching is Unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    while(nodes != nullptr){
        if(nodes->data == dataFind){
            std::cout <<"The data: "<< nodes->data<< " Was Found Successfully.\n";
            return;
        }
        nodes = nodes->next;
    }
    std::cout<< "Searching is unsuccessful.\n";
}

template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low<= high){
        middle = (int)((low+high/2));
        if(dataFind == data[middle]){
            std::cout<<"the data was found\n";
            return;
        }
        else if( dataFind < data[middle]){
            high = middle -1;
        }
        else{
            low = middle+1;
        }
    }
    std::cout<<"the data was not found\n";
}

template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;
    while(fast != last && fast->next != last){
        slow = slow ->next;
        fast = fast ->next->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    Node<T>* last = nullptr;
    while(start != last){
        Node<T> *middle = getMiddle(start, last);
        if(middle->data == dataFind){
            std::cout<< "Searching Successful\n";
            return;
        }
        else if(middle->data >dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }
    std::cout<<"Searching is Unsuccessful\n";
}


template <typename T>
int countOccurrencesAR(int size, T dataFind, T array[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == dataFind) {
            count++;
        }
    }
    std::cout << "Array Search: Key '" << dataFind << "' found " << count << " times.\n";
    return count;
}


template <typename T>
int countOccurrencesLL(Node<T> *head, T dataFind) {
    int count = 0;
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == dataFind) {
            count++;
        }
        current = current->next;
    }
    std::cout << "Linked List Search: Key '" << dataFind << "' found " << count << " times.\n";
    return count;
}


template <typename T>
int binarySearchRecursive(T data[], int low, int high, T dataFind) {
    if (low > high) {
        std::cout << "Data was not found (Recursive)\n";
        return -1;
    }

    int middle = low + (high - low) / 2;

    if (data[middle] == dataFind) {
        std::cout << "The data was found at index " << middle << " (Recursive)\n";
        return middle;
    }
    else if (dataFind < data[middle]) {
        return binarySearchRecursive(data, low, middle - 1, dataFind);
    }
    else {
        return binarySearchRecursive(data, middle + 1, high, dataFind);
    }
}

#endif