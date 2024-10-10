#include <iostream>
using namespace std;

#define QUEUE_EMPTY_ERROR -999

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // returns true if empty
    bool isEmpty()
    {
        return (front == nullptr && rear == nullptr);
    }

    // returns the size of queue by traversing 
    int size()
    {

        if (isEmpty())
        {
            cout << "Underflow!!" << endl;
            return QUEUE_EMPTY_ERROR;
        }

        Node *temp = front;
        int count = 0;
        while (temp != rear)
        {
            count++;
            temp = temp->next;
        }

        if (temp == rear)
        {
            count++;
        }

        return count;
    }

    // returns the front element data
    int frontElement()
    {
        return front->data;
    }

    // returns the rear element data
    int rearElement()
    {
        return rear->data;
    }

    // adds a data in the queue
    void enQueue(int data)
    {
        Node *newNode = new Node(data);

        if (rear == nullptr)
        {
            rear = front = newNode;
        }

        rear->next = newNode; // make the current node point to newnode
        rear = newNode;       // then make the newnode the new rear pointer
    }

    // deletes a element from queue
    int deQueue()
    {

        if (isEmpty())
        {
            cout << "Underflow!!" << endl;
            return QUEUE_EMPTY_ERROR;
        }

        Node *delNode = front;
        int del = front->data;
        front = front->next;
        /*
        If the front becomes null, the rear should also be set to null. This is because both front and rear should be null when the queue is empty to maintain proper queue structure.
        */
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete delNode;
        return del;
    }

    // deletes the whole queue 
    void deleteQueue()
    {
        Node *del;
        while (front != nullptr) // iterates till front is null pointer
        {
            del = front;
            cout << "Deleted element : " << del->data << endl;
            front = front->next;
            delete del; // delete one node every iteration
        }
        front = rear = nullptr; // set both front and rear to nullptr once the queue is empty
    }

    // display to visualize the queue
    void display(){
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }

        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        
        
    }
};

int main()
{
    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

    cout << q.frontElement() << endl;
    cout << q.rearElement() << endl;
    q.display();
    cout << q.size() << endl;

    cout << "Deleted element : " << q.deQueue() << endl;
    cout << q.size() << endl;

    q.deleteQueue();

    return 0;
}