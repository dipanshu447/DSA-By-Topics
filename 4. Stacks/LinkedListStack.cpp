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

    bool isEmpty()
    {
        return (top == nullptr);
    }

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

    void deleteStack() {}
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

    return 0;
}