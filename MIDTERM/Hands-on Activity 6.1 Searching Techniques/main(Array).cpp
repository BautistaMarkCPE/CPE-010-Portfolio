#include <iostream>
#include <cstdlib>
#include<time.h>
#include "searchingAlgo.h"

const int max_size = 50;

int main() {

    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i <max_size ; i++){
        dataset[i] = rand();
        std::cout<< dataset[i] << " ";
    }
    std::cout<<std::endl;

    std::cout<< "What number to find: ";
    int choice;

    std::cin >> choice;

    linearSearchAR(max_size,choice, dataset);


}