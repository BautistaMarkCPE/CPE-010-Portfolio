#include<iostream>
#include<queue>

//prototype declaration
void display(std::queue<char> copyQ);

int main() {

    //create an object:
    std::queue<char> myQ;

    //use the enquque operation
    myQ.push('M');
    myQ.push('A');
    myQ.push('R');
    myQ.push('K');
    std::cout<<"current front is:"<<myQ.front()<<std::endl;
    std::cout<<"current back is:"<<myQ.back()<<std::endl;
    display(myQ);


    
    //use the dequeue operation

    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);   

    

    return 0;
}


void display(std::queue<char> copyQ){
    //create a copy of the queue
    std::queue<char> temp = copyQ;
    //loop until empty
    while(!temp.empty()){
        //display the front
        std::cout <<" "<< temp.front()<< " ";
        //dequeue the front
        temp.pop();
    }
    //add a new line 
    std::cout<<std::endl;
    }