#include <iostream>
#include <string>
using namespace std;

class StackOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T, int capacity>
class Stack {
private:
    T stack[capacity];
    int top;

public:
    Stack() : top(-1) {}

    void push(const T& item) {
        if (top >= capacity - 1) {
            throw StackOverflowException();
        }
        stack[++top] = item;
    }

    T pop() {
        if (top < 0) {
            throw StackUnderflowException();
        }
        return stack[top--];
    }
};

int main() {
    try {
        Stack<int, 3> stack; 

        stack.push(1);
        stack.push(2);
        stack.push(3);
        cout << "Pushed 3 items successfully" << endl;
        stack.push(4);
    } catch (const StackOverflowException& e) {
        cout << "Pushing to a full stack: " << e.what() << endl;
    }

    try {
        Stack<int, 3> stack; 
        stack.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Popping from an empty stack: " << e.what() << endl;
    }
}
