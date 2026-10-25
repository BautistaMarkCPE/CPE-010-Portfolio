#ifndef GENERALTREE_H
#define GENERALTREE_H

#include <iostream>

template <typename T>
class generalTree {
private:
    T data;
    generalTree<T>* firstChild;
    generalTree<T>* nextSibling;

public:
    // Constructor
    generalTree(T val);

    // Core Tree Operations
    void addChild(generalTree<T>* child);
    
    // Traversals
    void preOrder();
    void postOrder();
    void inOrder();

    // Search Methods
    bool searchHelper(int choice, T key);
    void findData(int choice, T key);
};

// --- IMPLEMENTATION ---

template <typename T>
generalTree<T>::generalTree(T val) {
    data = val;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template <typename T>
void generalTree<T>::addChild(generalTree<T>* child) {
    if (firstChild == nullptr) {
        firstChild = child;
    } else {
        generalTree<T>* temp = firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

template <typename T>
void generalTree<T>::preOrder() {
    std::cout << data << " ";
    generalTree<T>* child = firstChild;
    while (child != nullptr) {
        child->preOrder();
        child = child->nextSibling;
    }
}

template <typename T>
void generalTree<T>::postOrder() {
    generalTree<T>* child = firstChild;
    while (child != nullptr) {
        child->postOrder();
        child = child->nextSibling;
    }
    std::cout << data << " ";
}

template <typename T>
void generalTree<T>::inOrder() {
    generalTree<T>* child = firstChild;
    if (child != nullptr) {
        child->inOrder();
    }
    std::cout << data << " ";
    if (child != nullptr) {
        child = child->nextSibling;
        while (child != nullptr) {
            child->inOrder();
            child = child->nextSibling;
        }
    }
}

template <typename T>
bool generalTree<T>::searchHelper(int choice, T key) {
    // Pre-order check
    if (choice == 1 && data == key) return true;

    generalTree<T>* child = firstChild;

    // In-order check
    if (choice == 2) {
        if (child != nullptr && child->searchHelper(choice, key)) return true;
        if (data == key) return true;
        if (child != nullptr) child = child->nextSibling;
    }

    while (child != nullptr) {
        if (child->searchHelper(choice, key)) return true;
        child = child->nextSibling;
    }

    // Post-order check
    if (choice == 3 && data == key) return true;

    return false;
}

template <typename T>
void generalTree<T>::findData(int choice, T key) {
    if (searchHelper(choice, key)) {
        std::cout << "\"" << key << " was found!\"\n";
    }
}

#endif