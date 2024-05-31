#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 5
int size = 0;

// create a stack class
class Stack {
    private:
        int arr[MAX]; 
        int top; 

    public: 
    // empty constructor
    Stack() {
        top = -1;
    }

    bool is_empty() {
        return (top == -1); 
    }

    bool is_full() {
        return (top == MAX - 1);
    }

    void push(int number) {
        if (is_full()) {
            cout << "Stack is full. Cannot push element " << number << endl;
        } else {
            top++;
            arr[top] = number;
            cout << "Pushed element: " << number << " onto the stack" << endl;
        }
    }

    void pop() {
        if (is_empty()) {
            cout << "Stack is empty. Cannot pop element \n";
        } else {
            cout << "Popped element: " << arr[top] << endl;
            top--; 
        }
    }

    int get_top_element() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }
};

int main() {
    Stack myStack;
    // Push elements until the stack becomes full
    for (int i = 1; i <= 5; ++i) {
        myStack.push(i);
    }
    // Attempt to push more elements into the full stack
    myStack.push(6);
    // Pop all elements until the stack becomes empty
    while (!myStack.is_empty()) {
        myStack.pop();
    }
    return 0;}