// Double Ended Queue

#include <iostream>
using namespace std;

#define max 1000
#define QUEUE_ERROR_EMPTY -9999999

class QueueArr
{
private:
    int arr[max];
    int front, rear;

public:
    QueueArr() : front(-1), rear(-1) {}

    // returns true if queue is full 
    bool isFull()
    {
        return (rear == (max - 1));
    }

    // returns true if queue is empty 
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    // returns the size of queue
    int size()
    {
        return (rear + 1);
    }

    // returns the element located at front
    int frontElement(){
        return arr[front];
    }
    
    // returns the element located at rear
    int rearElement(){
        return arr[rear];
    }

    // add a element in the queue from rear (default)
    void enqueueR(int data)
    {
        if (isFull())
        {
            cout << "Overflow!" << endl;
            return;
        }
        if (front == -1)
        { // set front to 0 if its -1 so that it shows the queue is not empty otherwise it will create confusion
            front = 0;
        }
        arr[++rear] = data;
    }
    
    // add a element in the queue from front
    void enqueueF(int data)
    {
        if (isFull())
        {
            cout << "Overflow!" << endl;
            return;
        }
        
        if (front == -1 || front == 0)
        {
            return;
        }
        arr[--front] = data;
    }

    // removes a element by incrementing front in queue from front
    int dequeueF()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return QUEUE_ERROR_EMPTY;
        }
        return arr[front++];
    }
    
    // removes a element by decrementing rear in queue from rear
    int dequeueR()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return QUEUE_ERROR_EMPTY;
        }
        return arr[rear--];
    }

    // returns the first element of queue
    int peek()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return QUEUE_ERROR_EMPTY;
        }
        return arr[front];
    }

    // not a core operation of queue but this wil help visualize the queue better!
    void display()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void deleteQueue() {
        front = -1;
        rear = -1;
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class QueueLinkedList
{
private:
    Node *front;
    Node *rear;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

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
            return QUEUE_ERROR_EMPTY;
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

    // adds a data in the queue from rear
    void enQueueR(int data)
    {
        Node *newNode = new Node(data);

        if (rear == nullptr)
        {
            rear = front = newNode;
        }

        rear->next = newNode; // make the current node point to newnode
        rear = newNode;       // then make the newnode the new rear pointer
    }
    
    // adds a data in the queue from front
    void enQueueF(int data)
    {
        Node *newNode = new Node(data);

        if (rear == nullptr)
        {
            rear = front = newNode;
        }

        newNode->next = front; // make the current node point to newnode
        front = newNode;       // then make the newnode the new front pointer
    }

    // deletes a element from queue front
    int deQueueF()
    {
        if (isEmpty())
        {
            cout << "Underflow!!" << endl;
            return QUEUE_ERROR_EMPTY;
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
    
    // deletes a element from queue rear
    int deQueueR()
    {

        if (isEmpty())
        {
            cout << "Underflow!!" << endl;
            return QUEUE_ERROR_EMPTY;
        }

        Node *current = front;
        Node *delNode = rear;
        int del = rear->data;
        while (current->next != rear)
        {
            current = current->next;
        }
        
        current->next = nullptr;
        delete delNode;
        rear = current;
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
        cout << endl;
    }
};

int main()
{
    // Array opeartions of DEQueue 
    // QueueArr q;

    // q.enqueueR(10);
    // q.enqueueR(20);
    // q.enqueueR(30);
    // q.enqueueR(40);
    // q.enqueueR(50);
    // q.enqueueR(60);
    // cout << "Dequeue element from front damn " << q.dequeueF() << endl;
    // cout << "Dequeue element from Rear damn " << q.dequeueR() << endl;
    // q.enqueueF(5);
    // q.display();

    // Linked list opeartions of DEQueue
    QueueLinkedList q;

    q.enQueueR(10);
    q.enQueueR(20);
    q.enQueueR(30);
    q.enQueueR(40);
    q.enQueueF(5);
    q.enQueueF(3);
    q.enQueueR(60);
    q.enQueueF(1);
    cout << "Dequeue element from rear " << q.deQueueR() << endl;
    cout << "Dequeue element from front " << q.deQueueF() << endl;
    q.display();

    cout << "Dequeue element from rear " << q.deQueueR() << endl;
    cout << "Dequeue element from front " << q.deQueueF() << endl;
    q.display();

    return 0;
}