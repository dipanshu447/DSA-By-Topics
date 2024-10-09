# Queues

A Queue is an ordered list in which insertions are done at one end (**rear**) and deletions are done at other end (**front**). The first element to be inserted is the first one to be deleted. Hense, Its called **First in First out (FIFO)** or **Last in Last out (LILO)** list.

## Main Queue Operations

- void enQueue(int data) : Inserts an element at the end of queue (at rear)
- int deQueue() : Removes and returns the element from the front of the queue
- int front() : returns the element from front without removing it
- int rear() : returns the element from rear without removing it
- int size() : returns the size of queue
- int isEmpty() : returns true if queue is empty or false

## Implementations

- Queue Simple Circular Array 
- Queue Dynamic Circular Array 
- Queue Linked list

> There are two more implemenatations : Simple array queue and Dynamic queue array but they are not efficient as these above implemenations. Still I have written their algorithms for understaning!