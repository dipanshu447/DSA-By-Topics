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

    // checks if the queue is full
    bool isFull()
    {
        return ((rear + 1) % QueueCapcity == front); // have the circular
    }

    // checks if the queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // returns the size of queue
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

        return (front - QueueCapcity) + (rear + 1); // cause its circular queue so front can at higher index and rear will be at start index so this will calculate accurate (but only in circular queue)
    }

    // returns the front value
    int frontElement()
    {
        return arr[front];
    }

    // returns the rear value
    int rearElement()
    {
        return arr[rear];
    }

    // double the size of queue if the queue is full and we need to input a queue inside queue
    void doubleQueue()
    {
        int *newArr = new int[QueueCapcity * 2]; // new doubled sized array
        int i = front;

        do
        {
            newArr[i] = arr[i];
            i = (i + 1) % QueueCapcity;
        } while (i != front); // copying everything inside the new array

        delete[] arr; // deleting the old array 
        QueueCapcity *= 2; // updating the capacity
        arr = newArr; // updating the old array pointer to point to new array
    }

    // add a element in the queue
    void enQueue(int data)
    {
        if (isFull())
        {
            doubleQueue();
        }

        rear = (rear + 1) % QueueCapcity; // circular increment for moving from one index to the next in a circular queue
        arr[rear] = data;
        if (front == -1)
        {
            front = rear;
        }
    }

    // removes one element from the queue
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

    // deletes the queue
    void deleteQueue()
    {
        delete[] arr;      // deletes the dynamic array
        front = rear = -1; // resets the front and rear pointer
    }

    // displays the queue elements (for visualization)
    void display()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }

        int i = front;
        do
        {
            if (i > rear)
            {
                break;
            } // if we already have printed all values in queue then we dont need to go further which
              // will result in garbage as we haven't full the queue
            cout << arr[i] << endl;
            i = (i + 1) % QueueCapcity;
        } while (i != front);
        // Note : This display traverse till the end of queue
    }
};

int main()
{
    Queue q(2);

    q.enQueue(10);
    q.enQueue(50);
    q.enQueue(20);
    q.enQueue(3);
    q.enQueue(50);
    q.enQueue(80);
    q.enQueue(10);
    // q.enQueue(50);
    cout << "Size of queue : " << q.size() << endl;
    q.display();

    return 0;
}