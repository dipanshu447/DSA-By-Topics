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

#### Other Types of Linked List - 

- A Memory-Efficient Linked List is more often called a **XOR Linked List** as this is totally dependent on the XOR Logic Gate and its properties.

    - [Original Journal from Sinha About Memory Efficent Linked List](https://www.linuxjournal.com/article/6828?page=0,1)
    - [Another Article with Implementation](https://cybercruddotnet.wordpress.com/2012/07/04/complicating-things-with-xor-linked-lists/)
    - [StackOverFlow Discusstion](https://stackoverflow.com/questions/35841620/what-is-a-memory-efficient-doubly-linked-list-in-c)
    
> Note : It's rarely used in practice due to the complexity they introduce, especially in debugging and portability.

- A skip list is a probabilistic alternative to balanced trees that maintains sorted order and allows efficient search, insert, and delete operations through multiple layers of linked lists.
    
    - [Lec 12 | MIT | By Prof. Erik Demaine Fall 2005 (Best Explaination)](https://www.youtube.com/watch?v=kBwUoWpeH_Q)

    - [Skip Lists Explained!! By Sumit Kumar (Great Article)](https://blog.reachsumit.com/posts/2020/07/skip-list/#conclusion)

    - [Geekforgeeks Article on Skip Lists](https://www.geeksforgeeks.org/skip-list/?ref=lbp)
