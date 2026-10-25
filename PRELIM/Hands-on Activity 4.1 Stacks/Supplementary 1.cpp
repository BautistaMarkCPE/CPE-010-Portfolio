#include <iostream>
#include <string>

const int MAX_SIZE = 100;

class ArrayStack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char val) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }
};

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkBalancedArray(const std::string& expr) {
    ArrayStack stack;

    for (char ch : expr) {
        
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } 
     
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false; 
            }
            char topChar = stack.pop();
            if (!isMatchingPair(topChar, ch)) {
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

    std::cout << "=== Array Stack Symbol Checker ===\n";
    for (const auto& expr : testCases) {
        bool isValid = checkBalancedArray(expr);
        std::cout << "Expression: " << expr 
                  << " | Valid: " << (isValid ? "Y" : "N") << "\n";
    }

    return 0;
}