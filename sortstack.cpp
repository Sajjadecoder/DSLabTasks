#include <iostream>
#include<stack>
using namespace std;

// Function to insert an element in a sorted way into the stack
void insertSorted(stack<int> &s, int element) {
    // Base case: If stack is empty or element is greater than the top element
    if (s.empty() || element > s.top()) {
        s.push(element);
        return;
    }

    // Remove the top element
    int temp = s.top();
    s.pop();

    // Recursive call to insert in sorted order
    insertSorted(s, element);

    // Push the top element back
    s.push(temp);
}

// Function to sort the stack
void sortStack(stack<int> &s) {
    // Base case: If stack is empty
    if (s.empty()) {
        return;
    }

    // Remove the top element
    int temp = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sortStack(s);

    // Insert the popped element back in sorted order
    insertSorted(s, temp);
}

// Helper function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // Push elements into the stack
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Original stack: ";
    printStack(s);

    // Sort the stack
    sortStack(s);

    cout << "Sorted stack: ";
    printStack(s);

    return 0;
}
