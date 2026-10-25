#include <iostream>
#include "generalTree.h"

int main() {
    // Constructing the General Tree Nodes (Task 1)
    generalTree<char>* A = new generalTree<char>('A');

    generalTree<char>* B = new generalTree<char>('B');
    generalTree<char>* C = new generalTree<char>('C');
    generalTree<char>* D = new generalTree<char>('D');
    generalTree<char>* E = new generalTree<char>('E');
    generalTree<char>* F = new generalTree<char>('F');
    generalTree<char>* G = new generalTree<char>('G');

    A->addChild(B);
    A->addChild(C);
    A->addChild(D);
    A->addChild(E);
    A->addChild(F);
    A->addChild(G);

    generalTree<char>* H = new generalTree<char>('H');
    D->addChild(H);

    generalTree<char>* I = new generalTree<char>('I');
    generalTree<char>* J = new generalTree<char>('J');
    E->addChild(I);
    E->addChild(J);

    generalTree<char>* K = new generalTree<char>('K');
    generalTree<char>* L = new generalTree<char>('L');
    generalTree<char>* M = new generalTree<char>('M');
    F->addChild(K);
    F->addChild(L);
    F->addChild(M);

    generalTree<char>* N = new generalTree<char>('N');
    G->addChild(N);

    generalTree<char>* P = new generalTree<char>('P');
    generalTree<char>* Q = new generalTree<char>('Q');
    J->addChild(P);
    J->addChild(Q);

    //Task 3.2 Output
    std::cout << "Pre-order:  ";
    A->preOrder();
    std::cout << "\n";

    std::cout << "Post-order: ";
    A->postOrder();
    std::cout << "\n";

    std::cout << "In-order:   ";
    A->inOrder();
    std::cout << "\n\n";

    //Task 3.3 Output
    std::cout << "Task 3.3:\n";
    A->findData(1, 'J');
    std::cout << "\n";

    //Task 3.4 Output
    std::cout << "Task 3.4:\n";
    generalTree<char>* O = new generalTree<char>('O');
    G->addChild(O);
    A->findData(1, 'O');

    return 0;
}