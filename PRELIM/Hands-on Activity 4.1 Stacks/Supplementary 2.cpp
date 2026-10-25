#include <iostream>
#include <string>

class Node {
public:
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        Node* temp = top;
        char poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
};

bool isMatchingPairList(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkBalancedLinkedList(const std::string& expr) {
    LinkedListStack stack;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char topChar = stack.pop();
            if (!isMatchingPairList(topChar, ch)) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    std::string testCases[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    std::cout << "=== Linked List Stack Symbol Checker ===\n";
    for (const auto& expr : testCases) {
        bool isValid = checkBalancedLinkedList(expr);
        std::cout << "Expression: " << expr 
                  << " | Valid: " << (isValid ? "Y" : "N") << "\n";
    }

    return 0;
}