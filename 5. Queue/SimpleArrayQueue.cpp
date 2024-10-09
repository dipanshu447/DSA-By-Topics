#include <iostream>
using namespace std;

#define max 1000
#define QUEUE_ERROR_EMPTY -9999999

class Queue
{
private:
    int arr[max];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

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

    // add a element in the queue
    void enqueue(int data)
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
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    // cout << "Dequeue elment : "<< q.dequeue() << endl;
    // q.dequeue();

    // q.display();
    cout << "Peeka Bo : " << q.peek() << endl;
    cout << "Size : " << q.size() << endl;
    cout << "Front element : " << q.frontElement() << endl;
    cout << "Rear element : " << q.rearElement() << endl;
  

    return 0;
}