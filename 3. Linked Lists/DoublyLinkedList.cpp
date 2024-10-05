#include <iostream>
using namespace std;

/*
Doubly Linked List: A linear data structure where each node points to both the next and previous nodes,
allowing two-way traversal.
*/

// Node class 
class Node
{
public:
    int data; // data variable
    Node *next; // pointer to the next node
    Node *prev; // pointer to the previous node 

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class doublylinkedlist
{
private:
    Node *head;

public:
    doublylinkedlist() : head(nullptr) {}

    // traverse the doubly linked list same as singly linked list
    void traversal()
    {
        Node *current = head;
        while (current != nullptr)
        {
            // cout << current->data << " <- ->";
            cout << current->data << " ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // traverse and returns the count of nodes
    int length()
    {
        Node *current = head;
        int count = 0;
        while (current->next != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // insert the newnode at the beginning
    void insertAtBeginning(int data)
    {
        Node *newnode = new Node(data);
        newnode->prev = nullptr;
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    // insert the newnode at end of doubly linked list
    void insertAtEnd(int data)
    {
        Node *newnode = new Node(data);
        newnode->next = nullptr;
        Node *current = head;
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        while (current->next != nullptr)
        {
            current = current->next;
        }

        newnode->prev = current;
        current->next = newnode;
    }

    // insert the node at the given position inputed by user
    void insertAtGivenPosition(int data, int position)
    {
        Node *newNode = new Node(data);

        if (position == 1)
        {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr)
            {
                head->prev = newNode;
            }

            head = newNode;
            return;
        }
        int k = 1;
        Node *prev = head;
        while (k < position - 1 && prev->next != nullptr)
        {
            prev = prev->next;
            k++;
        }

        if (k < position - 1)
        {
            cout << "Position doesn't exist!!!" << endl;
            return;
        }

        newNode->next = prev->next;
        newNode->prev = prev;

        if (prev->next != nullptr)
        {
            prev->next->prev = newNode;
        }

        prev->next = newNode;
    }

    // fucntion to find a node using the given value
    Node *findNode(int value)
    {
        Node *current = head;
        while (current != nullptr && value != current->data)
        {
            current = current->next;
        }
        return current;
    }

    // inserts a node at the given value using findNode()
    void insertAtGivenValue(int data, int value)
    {
        Node *newNode = new Node(data);
        Node *GivenNode = findNode(value);

        if (GivenNode == nullptr)
        {
            cout << "Not Found given node by the dumb user!" << endl;
            return;
        }

        if (GivenNode == head)
        {
            newNode->next = head;
            newNode->prev = nullptr;

            if (head->next != nullptr)
            {
                head->prev = newNode;
            }

            head = newNode;
            return;
        }

        newNode->next = GivenNode;
        newNode->prev = GivenNode->prev;

        if (GivenNode->prev != nullptr)
        {
            GivenNode->prev->next = newNode;
        }

        GivenNode->prev = newNode;
    }

    // inserts a node after the given value node
    void insertAfterGivenValue(int data, int value)
    {
        Node *newNode = new Node(data);
        Node *GivenNode = findNode(value);

        if (GivenNode == nullptr)
        {
            cout << "Not Found given node by the dumb user!" << endl;
            return;
        }

        newNode->next = GivenNode->next;
        newNode->prev = GivenNode;
        GivenNode->next = newNode;

        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }
    }

    // it deletes the first node
    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "Doubly Linked list is empty!!" << endl;
        }

        Node *temp = head;

        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    // it deletes the last node of doubly linked list
    void deleteLast()
    {

        if (head == nullptr)
        {
            cout << "Doubly Linked list is empty!!" << endl;
        }

        Node *temp, *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        temp = current->prev;
        temp->next = current->next;
        delete current;
    }

    // it deletes the node from the given position by user
    void deleteAtGivenPosition(int position)
    {
        Node *prev, *del = head;
        int k = 1;
        if (head == nullptr)
        {
            cout << "Doubly Linked List is empty!!!!" << endl;
            return;
        }

        if (position == 1)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete del;
            return;
        }

        while (k < position && del->next != nullptr)
        {
            del = del->next;
            k++;
        }

        if (del == nullptr)
        {
            cout << "Position not found" << endl;
            return;
        }

        prev = del->prev;
        prev->next = del->next;
        if (del->next != nullptr)
        {
            del->next->prev = prev;
        }
        delete del;
        return;
    }

    // it deletes the node from the given value node
    void deleteAtGivenValue(int value)
    {
        if (head == nullptr)
        {
            cout << "Doubly Linked List is empty!!!!" << endl;
            return;
        }

        Node *prev = head;
        Node *GivenNode = findNode(value);

        if (GivenNode == nullptr)
        {
            cout << "Node Not Found!!" << endl;
            return;
        }

        if (GivenNode == head)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete GivenNode;
            return;
        }

        prev = GivenNode->prev;
        prev->next = GivenNode->next;
        if (GivenNode->next != nullptr)
        {
            GivenNode->next->prev = prev;
        }
        delete GivenNode;
        return;
    }

    // it deletes the node after the given value node
    void deleteAfterGivenValue(int value)
    {
        if (head == nullptr)
        {
            cout << "Doubly Linked List is empty!!!!" << endl;
            return;
        }

        Node *GivenNode = findNode(value);

        if (GivenNode == nullptr)
        {
            cout << "Node Not Found!!" << endl;
            return;
        }

        Node *del = GivenNode->next;
        if (del == nullptr)
        {
            cout << "You are at the end of doubly linked list!!" << endl;
            return;
        }
        

        GivenNode->next = del->next;

        if (del->next != nullptr)
        {
            del->next->prev = GivenNode;
        }

        delete del;
        return;
    }
};

int main()
{
    doublylinkedlist list;

    list.insertAtBeginning(60);
    list.insertAtBeginning(50);
    list.insertAtBeginning(40);
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    // list.insertAtGivenPosition(35, 7);
    // list.insertAtGivenValue(35, 40);
    list.insertAfterGivenValue(35, 30);
    list.insertAtEnd(70);

    list.traversal();

    // list.deleteFirst();
    // list.deleteLast();
    // list.deleteAtGivenPosition(7);
    // list.deleteAtGivenValue(70);
    list.deleteAfterGivenValue(70);
    list.traversal();

    return 0;
}