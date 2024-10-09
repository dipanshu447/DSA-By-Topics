#include <iostream>
using namespace std;

#define STACK_EMPTY_ERROR -9999

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class stack
{
    Node *top;

public:
    stack() : top(nullptr) {}

    // returns true if stack is empty or false if not
    bool isEmpty()
    {
        return (top == nullptr);
    }

    // returns the size of stack by traversing
    int size()
    {
        int count = 0;
        Node *temp = top;
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return STACK_EMPTY_ERROR;
        }

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // traverse the stack and print its value (Note: This is not included in core operation of stack. Its only for visualizing the stack)
    void display(){
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // push one element in stack
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (newNode == nullptr)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    // pop one element from stack and returns the popped value 
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return STACK_EMPTY_ERROR;
        }

        Node *delNode = top;
        int delVal = top->data;
        top = top->next;
        delete delNode;
        return delVal;
    }

    // it deletes the stack by freeing all the nodes and resetting the top to null pointer
    void deleteStack() {
        Node *del;
        Node *current = top;
        while (current != nullptr)
        {
            del = current;
            current = current->next;
            delete del;
        }
        top = nullptr;
    }
};

int main()
{
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Poped element : "<< s.pop() << endl;

    s.display();
    s.deleteStack();
    s.display();

    return 0;
}