#include <iostream>
#include <cstdlib>
#include<time.h>
#include "searchingAlgo.h"

const int max_size = 50;

int main() {


//[M]->[A]->[R]->[K]->NULL

//Node<char> *name1 = new_node('M');
//Node<char> *name2 = new_node('A');
//Node<char> *name3 = new_node('R');
//Node<char> *name4 = new_node('K');

//name1->next = name2;
//name2->next = name3;
//name3->next = name4;

//linearSearchLL(name1, 'K');

int newArr[max_size];
for(int i = 0; i < max_size; i++){
    newArr[i] = i;
}
binarySearchArr(newArr,max_size , 49);

Node<char> *name1 = new_node('M');
Node<char> *name2 = new_node('A');
Node<char> *name3 = new_node('R');
Node<char> *name4 = new_node('K');

name1->next = name2;
name2->next = name3;
name3->next = name4;

binarySearchLL(name1, 'A');

}