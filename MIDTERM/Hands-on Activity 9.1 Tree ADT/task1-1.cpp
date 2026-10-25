#include <iostream>

template <typename T>
class treeNode {
public:
    T data;
    treeNode<T>* firstChild;   // Pointer to the first child
    treeNode<T>* nextSibling;  // Pointer to the next sibling

    treeNode(T val) {
        data = val;
        firstChild = nullptr;
        nextSibling = nullptr;
    }

    // Function to attach a child node
    void addChild(treeNode<T>* child) {
        if (firstChild == nullptr) {
            firstChild = child;
        } else {
            treeNode<T>* temp = firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }
    }
};

int main() {
    
    treeNode<char>* A = new treeNode<char>('A');

    // Level 1: Children of A
    treeNode<char>* B = new treeNode<char>('B');
    treeNode<char>* C = new treeNode<char>('C');
    treeNode<char>* D = new treeNode<char>('D');
    treeNode<char>* E = new treeNode<char>('E');
    treeNode<char>* F = new treeNode<char>('F');
    treeNode<char>* G = new treeNode<char>('G');

    A->addChild(B);
    A->addChild(C);
    A->addChild(D);
    A->addChild(E);
    A->addChild(F);
    A->addChild(G);

    treeNode<char>* H = new treeNode<char>('H');
    D->addChild(H);

    treeNode<char>* I = new treeNode<char>('I');
    treeNode<char>* J = new treeNode<char>('J');
    E->addChild(I);
    E->addChild(J);

    treeNode<char>* K = new treeNode<char>('K');
    treeNode<char>* L = new treeNode<char>('L');
    treeNode<char>* M = new treeNode<char>('M');
    F->addChild(K);
    F->addChild(L);
    F->addChild(M);

    treeNode<char>* N = new treeNode<char>('N');
    G->addChild(N);

    treeNode<char>* P = new treeNode<char>('P');
    treeNode<char>* Q = new treeNode<char>('Q');
    J->addChild(P);
    J->addChild(Q);

    std::cout << "General Tree initialized successfully.\n";

    return 0;
}