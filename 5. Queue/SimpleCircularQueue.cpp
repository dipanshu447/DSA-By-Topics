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

    // add a element in the queue
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
        delete[] arr; // deletes the dynamic array 
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

        /*
        we cant create a display function using for loop in ciruclar queue because its increating back to front also and if we start from front
        we need to make it stop if it comes again at front but in for loop it will detect its already at start is front and it will stop the loop.
        So We have to use do while which will run it at least once this way it wont detect front at start and will stop the loop when front
        comes. 

        Here is the reference where i found solution to this problem :
        https://stackoverflow.com/questions/70267659/problem-with-display-function-inside-circular-queue
        */

        int i = front;
        do
        {
            cout << arr[i] << endl;
            i = (i+1) % QueueCapcity;
        } while (i != front);
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

    // cout << q.frontElement() << endl;
    // cout << q.rearElement() << endl;
    cout << "Size of Queue : "<< q.size() << endl;

    q.display();

    cout << "Deleted element : " << q.deQueue() << endl;

    q.enQueue(22);

    q.display();

    q.deleteQueue();
    // q.display();

    return 0;
}