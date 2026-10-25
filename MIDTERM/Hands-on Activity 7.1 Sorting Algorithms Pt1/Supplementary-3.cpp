//ALGORITHM CountVotesAndFindWinner
//BEGIN
// 1.) Define candidate names for identification 1 through 5

// 2.) Generate an array of 0 to 100 elements with random vote numbers from 1 to 5

// 3.) Sort the vote array in ascending order using selection sort

// 4.) Loop through the sorted array and count how many times each vote appears.

// 5.) Compare the total counts to determine which candidate received the highest number of votes.

// 6.) Display the sorted array, the final vote tallies and the winning candidate.
//END

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgo.h"

const int maxSize = 100; 

void displayArr(int arr[]);

int main() {
    int A[maxSize];
    int voteCounts[6] = {0}; 
    
    std::string candidates[6] = {
        "", 
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        A[i] = (rand() % 5) + 1;
    }


    selectionSort(A, maxSize);


    std::cout << "\n Sorted Votes \n";
    displayArr(A);


    for(int i = 0; i < maxSize; i++){
        voteCounts[A[i]]++;
    }


    int maxVotes = -1;
    int winner = 1;

    std::cout << "\n Vote Count Results \n";
    for(int c = 1; c <= 5; c++){
        std::cout << "Candidate " << c << " (" << candidates[c] << "): " 
                  << voteCounts[c] << " votes\n";
        
        if(voteCounts[c] > maxVotes){
            maxVotes = voteCounts[c];
            winner = c;
        }
    }

    std::cout << "\nWinner: Candidate " << winner << " - " 
              << candidates[winner] << " with " << maxVotes << " votes!\n";

    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if((i + 1) % 20 == 0) std::cout << "\n"; 
    }
    std::cout << std::endl;
}