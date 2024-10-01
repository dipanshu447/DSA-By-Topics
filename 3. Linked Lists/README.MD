This will contains all types of linked list and its different types of operations.

## Summary

- **Singly Linked List:** One-way traversal, simple structure.
- **Doubly Linked List:** Two-way traversal, more complex but flexible.
- **Circular Linked List:** Loops back to the beginning, can be singly or doubly linked.

### All type of Linked List Node structure class :

**_Singly Linked list_** 

``` C++
class Node
{
public:
    int data; // data variable
    Node *next; // pointer to the next node

    Node(int data) : data(data), next(nullptr) {}
};

```
**_Doubly Linked list_**

``` C++
class Node
{
public:
    int data; // data variable
    Node *next; // pointer to the next node
    Node *prev; // pointer to the previous node 

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};
```
> _Circular Linked list has same node structure as Singly Linked list._
