#include <iostream>
using namespace std;

#define max 1000
#define STACK_EMPTY_ERROR -9999

class stackArr
{
private:
    int arr[max]; // stack array
    int top;      // stack index

public:
    stackArr() : top(-1) {}

    // returns true if the stack is full
    bool isFull()
    {
        if (top >= (max - 1))
        {
            return true;
        }
        return false;
    }

    // returns true if the stack is empty
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    // returns the size of stack
    int size()
    {
        return (top + 1);
    }

    // pushes an element in stack and increment the top
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = data;
    }

    // pop an element from the stack and decrement the top
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return STACK_EMPTY_ERROR;
        }
        int del = arr[top];
        --top;
        return del;
    }

    // peek the top element in stack and returns it
    int peek()
    {
        if (isEmpty())
        {
            return STACK_EMPTY_ERROR;
        }
        return arr[top];
    }

    // stack dont usually have a display operation but I made one to visualize a stack better
    void display()
    {
        if (isEmpty())
        {
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    // reset the stack top
    void deleteStack()
    {
        top = -1;
        return;
    }
};

int main()
{
    stackArr stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    // cout << stack.peek() << endl;

    cout << stack.pop() << endl;
    stack.display();

    return 0;
}