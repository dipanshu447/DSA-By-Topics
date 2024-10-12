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
        do
        {
            count++;
            temp = temp->next;
        } while (temp != front);

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
            rear->next = front; // rear->next points back at front which maintains its circular queue nature
        }
        else
        {
            rear->next = newNode; // make the current node point to newnode
            rear = newNode;       // then make the newnode the new rear pointer
            rear->next = front;   // rear->next points back at front which maintains its circular queue nature
        }
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
        /*
        If the front becomes null, the rear should also be set to null. This is because both front and rear should be null when the queue is empty to maintain proper queue structure.
        */
        if (front == rear)
        {
            delete delNode;
            front = rear = nullptr;
            return del;
        }

        front = front->next;
        rear->next = front; // updating the rear->next to point at updated front instead of pointing at the node which will be deleted

        delete delNode;
        return del;
    }

    // deletes the whole queue
    void deleteQueue()
    {
        Node *current = front, *del;
        do
        {
            del = current;
            cout << "Deleted element : " << del->data << endl;
            current = current->next;
            delete del; // delete one node every iteration
        } while (current != front);
        front = rear = nullptr; // set both front and rear to nullptr once the queue is empty
    }

    // display to visualize the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }

        Node *current = front;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
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

    cout << "Size : " << q.size() << endl;

    q.display();

    cout << "Dequeued element : " << q.deQueue() << endl;

    cout << "Size : " << q.size() << endl;
    q.display();
    q.deleteQueue();

    return 0;
}