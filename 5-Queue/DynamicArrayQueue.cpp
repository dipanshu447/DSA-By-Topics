#include <iostream>
using namespace std;

#define QUEUE_ERROR_EMPTY -99999999

class Queue
{
private:
    int *arr;
    int front, rear, QueueCapacity;

public:
    Queue(int size) : front(-1), rear(-1), QueueCapacity(size)
    {
        arr = new int[QueueCapacity];
    }

    bool isFull()
    {
        return (rear == (QueueCapacity - 1));
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
    int frontElement()
    {
        return arr[front];
    }

    // returns the element located at rear
    int rearElement()
    {
        return arr[rear];
    }

    // doubles the size of queue
    void doubleQueue()
    {
        int *newArr = new int[QueueCapacity * 2]; // making a new array with double size

        for (int i = 0; i < QueueCapacity; i++) // copying all elments from old array to new array
        {
            newArr[i] = arr[i];
        }

        delete[] arr; // delete the pointer array memory
        QueueCapacity *= 2; // update the new capacity of queue
        arr = newArr; // making arr point to new arr
    }

    // add a element in the queue
    void enqueue(int data)
    {
        if (isFull())
        {
            // cout << "Overflow!" << endl;
            doubleQueue();
            // return;
        }
        if (front == -1)
        { // set front to 0 if its -1 so that it shows the queue is not empty otherwise it will create confusion
            front = 0;
        }
        arr[++rear] = data;
    }

    // removes a element by incrementing front in queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return QUEUE_ERROR_EMPTY;
        }
        return arr[front++];
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

    void deleteQueue()
    {
        delete[] arr;
        front = -1;
        rear = -1;
    }
};

int main()
{
    Queue q(2); // size 2

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // its working we added four elements in the queue whose size is 2 so doublequeue is working!!
    q.display();

    /*
        rest of the program is same as simple array queue only difference is,
            - it uses dynamic array with pointers
            - it doubles the size of array if its getting full
    */

    q.deleteQueue();
    q.display();

    return 0;
}