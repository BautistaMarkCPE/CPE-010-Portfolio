#include <iostream>
#include "BST.h"

int main() {
    BinarySearchTree<int> bst(2);

    int sequence[] = {3, 9, 18, 0, 1, 4, 5};
    int size = sizeof(sequence) / sizeof(sequence[0]);

    std::cout << "Binary Search Tree constructed and populated successfully.\n";
    std::cout << "Inserted sequence: 2, ";
    for (int i = 0; i < size; i++) {
        bst.insert(sequence[i]);
        std::cout << sequence[i] << (i < size - 1 ? ", " : "\n");
    } 
    std::cout << "\n";

    std::cout << "In-order:   ";
    bst.inOrder();
    std::cout << "\n";

    std::cout << "Pre-order:  ";
    bst.preOrder();
    std::cout << "\n";

    std::cout << "Post-order: ";
    bst.postOrder();
    std::cout << "\n";

    return 0;
}