#include <iostream>
using namespace std;

#define QUEUE_ERROR_EMPTY -9999

class Queue
{
private:
    int *arr;
    int front, rear;
    int QueueCapcity;

public:
    Queue(int size) : front(-1), rear(-1), QueueCapcity(size)
    {
        arr = new int[QueueCapcity];
    }

    bool isFull()
    {
        return ((rear + 1) % QueueCapcity == front); // have the circular 
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    int size()
    {
        if (isEmpty())
        {
            return 0;
        }
        if (rear >= front)
        {
            return rear - front + 1;
        }
        
        return (front - QueueCapcity) + (rear + 1);
    }

    int frontElement()
    {
        return arr[front];
    }

    int rearElement()
    {
        return arr[rear];
    }

    void enQueue(int data)
    {
        if (isFull())
        {
            cout << "Overflow!" << endl;
            return;
        }
        else
        {
            rear = (rear + 1) % QueueCapcity; // circular increment for moving from one index to the next in a circular queue
            arr[rear] = data;
            if (front == -1)
            {
                front = rear;
            }
        }
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return QUEUE_ERROR_EMPTY;
        }

        int del = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % QueueCapcity;
        }
        return del;
    }

    void deleteQueue()
    {
        delete [] arr;
        front = rear = -1;
    }

    void display(){
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }
        
        for (int i = front; i != rear; i = (i+1) % QueueCapcity)
        {
            cout << arr[i] << endl;
        }
        
    }
};

int main()
{
    Queue q(5);
    
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);

    cout << q.size() << endl;

    q.display();

    q.deQueue();

    q.enQueue(22);

    q.display();

    return 0;
}