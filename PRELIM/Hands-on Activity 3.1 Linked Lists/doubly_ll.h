#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

template <typename T>
DoubleList<T> *CreateNewNode (T newData){
    DoubleList<T> *newNode = new DoubleList<T>;
    newNode->data = newData;

    newNode-> next = nullptr;
    newNode-> prev = nullptr;
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){ 
    DoubleList<T> *tail;

    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    
    std::cout<< "Forward \n";

    while (currentNode != nullptr) {
        std::cout<<currentNode->data<<" ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout<<std::endl;

    std::cout<< "Backward: \n";

    while(tail != nullptr){
        std::cout<< tail-> data<<" ";
        tail = tail-> prev;
    }
    
    
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = *currentHead;
  
    (*currentHead)->prev = newNode;
    *currentHead = newNode;
}
template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    DoubleList<T>* newNode = CreateNewNode(newData);
    
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;

    newNode->prev = currentHead;
}

template <typename T>
void dllGenInsert(T newData, DoubleList<T>* currentHead){
        if(currentHead->prev == nullptr){
            std::cout<<"Previous Value Cannot be Null"<<std::endl;
            return;
        }
    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = currentHead->next;
    currentHead-> next -> prev = newNode;
    currentHead->next = newNode;
}

template <typename T>
void dllDelNode(T findData, DoubleList<T>** currentHead) {
    if(currentHead == nullptr || *currentHead == nullptr) return;

    DoubleList<T>* currNode = *currentHead;

    while (currNode != nullptr && currNode->data != findData) {
        currNode = currNode->next;
    }

    if (currNode == nullptr) return;

    if (currNode == *currentHead) {
        *currentHead = currNode->next;
    }
    
    if (currNode->prev != nullptr) {
        currNode->prev->next = currNode->next;
    }

    if (currNode->next != nullptr) {
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}

template <typename T>
void dllDeleteAllNodes(DoubleList<T> **head){
    DoubleList<T>* current = *head;

    while (current != nullptr) {
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif