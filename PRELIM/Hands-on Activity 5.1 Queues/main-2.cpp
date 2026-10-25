#include <iostream>
#include "queueArr.h"

int main() {
    // creating an object
    QueueArr<int> q(5);

    // enqueue 10, 20, 30, 40, 50:
    q.Enqueue(1);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(2);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(3);
    q.Enqueue(4);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(5);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(6); // Will display "Queue is full"

    std::cout << "\nremoved: " << q.Dequeue() << std::endl;
    std::cout << "removed: " << q.Dequeue() << std::endl;

    q.clear();

    std::cout << "is the queue empty? " << (q.Empty() ? "yes" : "no") << std::endl;

    return 0;
}