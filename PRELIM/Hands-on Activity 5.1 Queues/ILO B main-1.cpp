#include<iostream>
#include "queueLL.h"

int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr; 

    // Check if empty at the start
    if (isEmpty(front)) {
        std::cout << "Queue is empty at the start.\n";
    }

    enqueue('M', &front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";
    enqueue('A', &front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";
    enqueue('R', &front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";
    enqueue('K', &front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";

    // CALL DISPLAY ALL HERE:
    std::cout << "Current Queue: ";
    displayAll(front);

    std::cout<<"testing the dequeue operator: \n";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data<<" " << "back: "<< back->data << "\n";
    dequeue(&front, &back);

    // Check if empty at the end
    if (isEmpty(front)) {
        std::cout << "Queue is empty again.\n";
    }

    dequeue(&front, &back);

    return 0;
}