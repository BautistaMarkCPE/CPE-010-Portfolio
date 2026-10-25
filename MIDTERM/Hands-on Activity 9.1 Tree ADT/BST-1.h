#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    T Key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

public:
    // Constructor
    BinarySearchTree(T value);

    // Insertion Method
    void insert(T value);

    // Search / Finder Method
    bool search(T value);
    void findData(T value);

    // Traversal Methods
    void preOrder();
    void inOrder();
    void postOrder();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    Key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    if (value < Key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
        } else {
            left->insert(value);
        }
    } else if (value > Key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        } else {
            right->insert(value);
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::search(T value) {
    if (Key == value) {
        return true;
    }
    if (value < Key && left != nullptr) {
        return left->search(value);
    }
    if (value > Key && right != nullptr) {
        return right->search(value);
    }
    return false;
}

template <typename T>
void BinarySearchTree<T>::findData(T value) {
    if (search(value)) {
        std::cout << "\"" << value << " was found!\"\n";
    } else {
        std::cout << "\"" << value << " was not found!\"\n";
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << Key << " ";
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder() {
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << Key << " ";
    if (right != nullptr) {
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder() {
    if (left != nullptr) {
        left->postOrder();
    }
    if (right != nullptr) {
        right->postOrder();
    }
    std::cout << Key << " ";
}

#endif